// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2004 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/libxipc/xrl_pf_sudp.cc,v 1.32 2004/03/28 15:34:16 hodson Exp $"

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#include "libxorp/xorp.h"

#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/uio.h>

#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <string>

#include "xrl_module.h"

#include "libxorp/debug.h"
#include "libxorp/xlog.h"
#include "libxorp/callback.hh"
#include "libxorp/exceptions.hh"

#include "header.hh"
#include "xrl_error.hh"
#include "xrl_pf_sudp.hh"
#include "xrl_dispatcher.hh"
#include "xuid.hh"
#include "sockutil.hh"

// ----------------------------------------------------------------------------
// SUDP is "simple udp" - a minimalist and simple udp transport
// mechanism for XRLs.  It is intended as a placeholder to allow
// modules to start using XRL whilst we develop other mechanisms.
//
// Resolved names have protocol name "sudp" and specify addresses as
// "host/port"
//

// ----------------------------------------------------------------------------
// Constants

static char		SUDP_PROTOCOL_NAME[] = "sudp";
static string		SUDP_PROTOCOL = "sudp/1.0";

static const int	SUDP_REPLY_TIMEOUT_MS = 3000;
static const ssize_t	SUDP_RECV_BUFFER_BYTES = 32 * 1024;
static const ssize_t	SUDP_SEND_BUFFER_BYTES = SUDP_RECV_BUFFER_BYTES / 4;

const char* XrlPFSUDPSender::_protocol   = SUDP_PROTOCOL_NAME;
const char* XrlPFSUDPListener::_protocol = SUDP_PROTOCOL_NAME;

struct Request {
    XrlPFSender*		parent;		// Request creator
    XrlPFSender::SendCallback	cb;		// User Callback
    XUID			xuid;		// Unique Request ID
    XorpTimer			timeout;	// Timeout timer

    Request(XrlPFSender* p, const XrlPFSender::SendCallback& scb)
	: parent(p), cb(scb) {}
    bool operator==(const XUID& x) const { return xuid == x; }
};

// ----------------------------------------------------------------------------
// Utility Functions

static string
render_dispatch_header(const XUID& id, size_t content_bytes)
{
    HeaderWriter h;
    h.add("Protocol", SUDP_PROTOCOL);
    h.add("XUID", id.str());
    h.add("Content-Length", (uint32_t)content_bytes);
    return h.str();
}

static bool
parse_dispatch_header(string hdr, XUID& id, size_t& content_bytes)
{
    try {
	HeaderReader h(hdr);
	string protocol, sid;
	h.get("Protocol", protocol);
	h.get("XUID", sid);
	h.get("Content-Length", (uint32_t&)content_bytes);
	id = XUID(sid);
	return (protocol == SUDP_PROTOCOL);
    } catch (const HeaderReader::InvalidString&) {
	debug_msg("header invalid\n");
    } catch (const HeaderReader::NotFound&) {
	debug_msg("header missing fields\n");
    }
    return false;
}

static string
xrlerror_to_status(const XrlError& e)
{
    string r = c_format("%d", e.error_code());
    if (e.note().size()) {
	r += " " + e.note();
    }
    return r;
}

static XrlError
status_to_xrlerror(const string& status)
{
    uint32_t error_code = 0;

    string::const_iterator si = status.begin();
    while (si != status.end()) {
	if (xorp_isdigit(*si) == false)
	    break;
	error_code *= 10;
	error_code += *si - '0';
	si++;
    }

    if (si == status.begin()) {
	XLOG_ERROR("Missing XrlError::errorcode value");
	return XrlError(INTERNAL_ERROR,	"corrupt xrl response");
    }

    if (si == status.end())
	return XrlErrorCode(error_code);

    si++;
    return XrlError(XrlErrorCode(error_code), string(si, status.end()));
}

static string
render_response(const XrlError& e, const XUID& id, size_t content_bytes)
{
    HeaderWriter h;
    h.add("Protocol", SUDP_PROTOCOL);
    h.add("XUID", id.str());
    h.add("Status", xrlerror_to_status(e));
    h.add("Content-Length", (uint32_t)content_bytes);
    return h.str();
}

static bool
parse_response(const char* buf,
	       XrlError& e,
	       XUID& xuid,
	       size_t& header_bytes,
	       size_t& content_bytes) {
    try {
	HeaderReader h(buf);

	string protocol;
	h.get("Protocol", protocol);
	if (protocol != SUDP_PROTOCOL) return false;

	string status;
	h.get("Status", status);
	e = status_to_xrlerror(status);

	string xuid_str;
	h.get("XUID", xuid_str);
	xuid = XUID(xuid_str);
	h.get("Content-Length", (uint32_t&)content_bytes);
	header_bytes = h.bytes_consumed();

	return true;
    } catch (const HeaderReader::InvalidString&) {
	debug_msg("Invalid string");
    } catch (const HeaderReader::NotFound&) {
	debug_msg("Not found");
    } catch (const XUID::InvalidString&) {
	debug_msg("Failed to restore XUID from string");
    }
    return false;
}

// ----------------------------------------------------------------------------
// XrlPFUDPSender

int XrlPFSUDPSender::sender_fd;
int XrlPFSUDPSender::instance_count;

typedef map<const XUID, Request> XuidRequestMap;
static XuidRequestMap requests_pending;

XrlPFSUDPSender::XrlPFSUDPSender(EventLoop& e, const char* address_slash_port)
    throw (XrlPFConstructorError)
    : XrlPFSender(e, address_slash_port)
{
    string addr;
    uint16_t port;

    if (split_address_slash_port(address_slash_port, addr, port) != true ||
	address_lookup(addr, _destination.sin_addr) != true) {
	xorp_throw(XrlPFConstructorError,
		   c_format("Bad destination: %s\n", address_slash_port));
    }
#ifdef HAVE_SIN_LEN
    _destination.sin_len = sizeof(_destination);
#endif /* HAVE_SIN_LEN */
    _destination.sin_family = AF_INET;
    _destination.sin_port = htons(port);

    if (sender_fd <= 0) {
	debug_msg("Creating master socket\n");
	sender_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (sender_fd > 0) {
	    if (set_socket_sndbuf_bytes(sender_fd, SUDP_SEND_BUFFER_BYTES)
		< SUDP_SEND_BUFFER_BYTES) {
		close(sender_fd);
		sender_fd = 0;
		xorp_throw(XrlPFConstructorError,
			   c_format("Could not create master socket: "
				    "cannot set socket sending buffer to %d\n",
				    SUDP_SEND_BUFFER_BYTES));
	    }
	    _eventloop.add_selector(sender_fd, SEL_RD,
				    callback(&XrlPFSUDPSender::recv));
	} else {
	    xorp_throw(XrlPFConstructorError,
		       c_format("Could not create master socket: %s\n",
				strerror(errno)));
	}
    }
    instance_count++;
    debug_msg("Created XrlPFSUDPSender %s instance count %d sender_fd %d\n",
	      address_slash_port, instance_count, sender_fd);
}

XrlPFSUDPSender::~XrlPFSUDPSender()
{
    instance_count--;
    debug_msg("~XrlPFSUDPSender %p- instance count %d\n",
	      this, instance_count);

    if (instance_count == 0) {
	_eventloop.remove_selector(sender_fd, SEL_RD);
	close(sender_fd);
	sender_fd = 0;
    }

    // Delete requests associated with us, they cannot possibly be valid
    XuidRequestMap::iterator i = requests_pending.begin();
    while (i != requests_pending.end()) {
	if (i->second.parent == this) {
	    requests_pending.erase(i++);
	} else {
	    i++;
	}
    }
}

void
XrlPFSUDPSender::send(const Xrl& x, const XrlPFSender::SendCallback& cb)
{
    // Map request id to current object instance
    Request request(this, cb);
    assert(requests_pending.find(request.xuid) == requests_pending.end());

    pair<XuidRequestMap::iterator, bool> p =
	requests_pending.insert(XuidRequestMap::value_type(request.xuid,
							   request));
    if (p.second == false) {
	cb->dispatch(XrlError(SEND_FAILED, "Insufficient memory"), 0);
	return;
    }

    // Prepare data
    string xrl = x.str();
    string header = render_dispatch_header(request.xuid, xrl.size());
    string msg = header + xrl;

    ssize_t msg_bytes = msg.size();
    if (msg_bytes > SUDP_SEND_BUFFER_BYTES) {
	debug_msg("Message sent larger than transport method designed");
    } else if (sendto(sender_fd,
		      msg.data(), msg.size(), 0,
		      (sockaddr*)&_destination, sizeof(_destination))
	       != msg_bytes) {
	debug_msg("Write failed: %s\n", strerror(errno));
	requests_pending.erase(p.first);
	cb->dispatch(XrlError::SEND_FAILED(), 0);
	return;
    }

    XuidRequestMap::iterator& xi = p.first;

    xi->second.timeout =
	_eventloop.new_oneoff_after_ms(SUDP_REPLY_TIMEOUT_MS,
	    callback(this, &XrlPFSUDPSender::timeout_hook, request.xuid));
    debug_msg("XrlPFSUDPSender::send (qsize %u)\n",
	      (uint32_t)requests_pending.size());
}

bool
XrlPFSUDPSender::sends_pending() const
{
    XuidRequestMap::const_iterator i = requests_pending.begin();
    while (i != requests_pending.end()) {
	const XrlPFSender* parent = i->second.parent;
	if (parent == this)
	    return true;
	++i;
    }
    return false;
}

bool
XrlPFSUDPSender::alive() const
{
    return true;
}

const char*
XrlPFSUDPSender::protocol() const
{
    return _protocol;
}

void
XrlPFSUDPSender::timeout_hook(XUID xuid)
{
    map<const XUID, Request>::iterator i = requests_pending.find(xuid);
    assert (i != requests_pending.end());

    Request& r = i->second;
    SendCallback cb = r.cb;

    debug_msg("%p Erasing state for %s (timeout)\n",
	      this, r.xuid.str().c_str());

    requests_pending.erase(i);
    cb->dispatch(XrlError::REPLY_TIMED_OUT(), 0);
}

// ----------------------------------------------------------------------------
// XrlPFSUDPSender timer and selector hooks

void
XrlPFSUDPSender::recv(int fd, SelectorMask m)
{
    assert(fd == sender_fd);
    assert(m == SEL_RD);

    char buf[SUDP_RECV_BUFFER_BYTES + 1];

    ssize_t read_bytes = read(sender_fd, buf, SUDP_RECV_BUFFER_BYTES);
    if (read_bytes < 0) {
	// Read fail request will timeout
	debug_msg("read failed: %s\n", strerror(errno));
	return;
    }
    buf[read_bytes] = '\0';

    XrlError	err;
    XUID 	xuid;
    size_t 	content_bytes, header_bytes;

    if (parse_response(buf, err, xuid, header_bytes, content_bytes) != true) {
	debug_msg("response header parsing failed\n");
	return;
    } else if (content_bytes + header_bytes != (size_t)read_bytes) {
	debug_msg("header and data bytes != read_bytes (%u + %u != %d\n",
		  (uint32_t)header_bytes, (uint32_t)content_bytes, read_bytes);
    }

    debug_msg("Received %s\n", xuid.str().c_str());
    map<const XUID, Request>::iterator i = requests_pending.find(xuid);
    if (i == requests_pending.end()) {
	XLOG_WARNING("XRL Protocol Family SUDP: response arrived for XRL that appears to have timed out.");
	return;
    }

    // Unschedule timer
    i->second.timeout.unschedule();

    // Copy out state we'd like to use from request before deleting it.
    SendCallback cb = i->second.cb;

    debug_msg("Erasing state for %s (answered)\n",
	      i->second.xuid.str().c_str());
    requests_pending.erase(i);

    try {
	XrlArgs response(buf + header_bytes);
	cb->dispatch(err, &response);
    } catch (const InvalidString&) {
	debug_msg("Corrupt response: "
		  "header_bytes %u content_bytes %u\n\t\"%s\"\n",
		  (uint32_t)header_bytes,
		  (uint32_t)content_bytes,
		  buf + header_bytes);
	XrlError xe(INTERNAL_ERROR, "corrupt xrl response");
	cb->dispatch(xe, 0);
	return;
    }
}

// ----------------------------------------------------------------------------
// XrlPFUDPListener

XrlPFSUDPListener::XrlPFSUDPListener(EventLoop& e, XrlDispatcher* xr)
    throw (XrlPFConstructorError)
    : XrlPFListener(e, xr)
{
    debug_msg("XrlPFSUDPListener\n");
    if ((_fd = create_listening_ip_socket(UDP)) < 0) {
	xorp_throw(XrlPFConstructorError,
		   c_format("Could not allocate listening IP socket: %s",
			    strerror(errno)));
    }

    string addr;
    uint16_t port;
    if (get_local_socket_details(_fd, addr, port) == false) {
        close(_fd);
	xorp_throw(XrlPFConstructorError,
		   c_format("Could not get local socket details: %s",
			    strerror(errno)));
    }
    _addr = address_slash_port(addr, port);

    _eventloop.add_selector(_fd, SEL_RD,
			     callback(this, &XrlPFSUDPListener::recv));
}

XrlPFSUDPListener::~XrlPFSUDPListener()
{
    _eventloop.remove_selector(_fd);
    close(_fd);
}

void
XrlPFSUDPListener::recv(int fd, SelectorMask m)
{
    static char rbuf[SUDP_RECV_BUFFER_BYTES + 1];

    assert(fd == _fd);
    assert(m == SEL_RD);

    debug_msg("recv()\n");

    struct sockaddr sockfrom;
    socklen_t sockfrom_bytes = sizeof(sockfrom);

    errno = 0;
    ssize_t rbuf_bytes = recvfrom(_fd, rbuf, sizeof(rbuf) / sizeof(rbuf[0]),
				  0, &sockfrom, &sockfrom_bytes);
    if (errno == EAGAIN) {
	return;
    } else if (errno != 0) {
	debug_msg("recvfrom failed: %s\n", strerror(errno));
	return;
    }

    if (rbuf_bytes > SUDP_RECV_BUFFER_BYTES) {
	debug_msg("Packet too large (%d > %d) bytes\n",
		  rbuf_bytes, SUDP_RECV_BUFFER_BYTES);
	return;
    }
    rbuf[rbuf_bytes] = '\0';

    debug_msg("XXX %s\n", rbuf);

    size_t content_bytes;
    XrlArgs response;
    XrlError	e;
    XUID	xuid;
    if (parse_dispatch_header(rbuf, xuid, content_bytes) == true) {
	e = dispatch_command(rbuf + rbuf_bytes - content_bytes, response);
	debug_msg("response \"%s\"\n", response.str().c_str());
	send_reply(&sockfrom, e, xuid, &response);
    } else {
	// XXX log busted header.
    }
}

const XrlError
XrlPFSUDPListener::dispatch_command(const char* rbuf, XrlArgs& reply)
{
    const XrlDispatcher* d = dispatcher();
    assert(d != 0);

    try {
	Xrl xrl(rbuf);
	const string& command = xrl.command();
	const XrlArgs& args = xrl.args();
	return d->dispatch_xrl(command, args, reply);
    } catch (InvalidString& e) {
	debug_msg("Invalid string - failed to dispatch %s\n", rbuf);
    }
    return XrlError(INTERNAL_ERROR, "corrupt xrl");
}

void
XrlPFSUDPListener::send_reply(sockaddr*			sa,
			      const XrlError&		e,
			      const XUID&		xuid,
			      const XrlArgs* 	reply_args) {

#ifdef XRLPFSUDPPARANOIA
    static XUID last("00000000-00000000-00000000-00000000");
    assert(last != xuid);
    assert(last < xuid);
    last = xuid;
#endif

    string reply;
    if (reply_args != 0) {
	reply = reply_args->str();
    }
    const string header = render_response(e, xuid, reply.size());

    struct iovec v[2];
    v[0].iov_base = const_cast<char*>(header.c_str());
    v[0].iov_len = header.size();
    v[1].iov_base = const_cast<char*>(reply.c_str());
    v[1].iov_len = reply.size();

    msghdr m;
    memset(&m, 0, sizeof(m));
    m.msg_name = (caddr_t)sa;
    m.msg_namelen = sizeof(*sa);
    m.msg_iov = v;
    m.msg_iovlen = sizeof(v) / sizeof(v[0]);

    ssize_t v_bytes = v[0].iov_len + v[1].iov_len;
    if (v_bytes > SUDP_SEND_BUFFER_BYTES ||
	sendmsg(_fd, &m, 0) != v_bytes) {
	debug_msg("Failed to send reply (%d): %s\n", errno, strerror(errno));
    }
}

bool
XrlPFSUDPListener::response_pending() const
{
    // Responses are immediate for UDP
    return false;
}

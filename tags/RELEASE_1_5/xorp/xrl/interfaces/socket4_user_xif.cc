/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/socket4_user_xif.cc,v 1.16 2008/01/04 03:18:01 pavlin Exp $"

#include "socket4_user_xif.hh"

bool
XrlSocket4UserV0p1Client::send_recv_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	if_name,
	const string&	vif_name,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const vector<uint8_t>&	data,
	const RecvEventCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "socket4_user/0.1/recv_event");
    x.args().add("sockid", sockid);
    x.args().add("if_name", if_name);
    x.args().add("vif_name", vif_name);
    x.args().add("src_host", src_host);
    x.args().add("src_port", src_port);
    x.args().add("data", data);
    return _sender->send(x, callback(this, &XrlSocket4UserV0p1Client::unmarshall_recv_event, cb));
}


/* Unmarshall recv_event */
void
XrlSocket4UserV0p1Client::unmarshall_recv_event(
	const XrlError&	e,
	XrlArgs*	a,
	RecvEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4UserV0p1Client::send_inbound_connect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const string&	new_sockid,
	const InboundConnectEventCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "socket4_user/0.1/inbound_connect_event");
    x.args().add("sockid", sockid);
    x.args().add("src_host", src_host);
    x.args().add("src_port", src_port);
    x.args().add("new_sockid", new_sockid);
    return _sender->send(x, callback(this, &XrlSocket4UserV0p1Client::unmarshall_inbound_connect_event, cb));
}


/* Unmarshall inbound_connect_event */
void
XrlSocket4UserV0p1Client::unmarshall_inbound_connect_event(
	const XrlError&	e,
	XrlArgs*	a,
	InboundConnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(1));
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool accept;
    try {
	a->get("accept", accept);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &accept);
}

bool
XrlSocket4UserV0p1Client::send_outgoing_connect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const OutgoingConnectEventCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "socket4_user/0.1/outgoing_connect_event");
    x.args().add("sockid", sockid);
    return _sender->send(x, callback(this, &XrlSocket4UserV0p1Client::unmarshall_outgoing_connect_event, cb));
}


/* Unmarshall outgoing_connect_event */
void
XrlSocket4UserV0p1Client::unmarshall_outgoing_connect_event(
	const XrlError&	e,
	XrlArgs*	a,
	OutgoingConnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4UserV0p1Client::send_error_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const string&	error,
	const bool&	fatal,
	const ErrorEventCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "socket4_user/0.1/error_event");
    x.args().add("sockid", sockid);
    x.args().add("error", error);
    x.args().add("fatal", fatal);
    return _sender->send(x, callback(this, &XrlSocket4UserV0p1Client::unmarshall_error_event, cb));
}


/* Unmarshall error_event */
void
XrlSocket4UserV0p1Client::unmarshall_error_event(
	const XrlError&	e,
	XrlArgs*	a,
	ErrorEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlSocket4UserV0p1Client::send_disconnect_event(
	const char*	dst_xrl_target_name,
	const string&	sockid,
	const DisconnectEventCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "socket4_user/0.1/disconnect_event");
    x.args().add("sockid", sockid);
    return _sender->send(x, callback(this, &XrlSocket4UserV0p1Client::unmarshall_disconnect_event, cb));
}


/* Unmarshall disconnect_event */
void
XrlSocket4UserV0p1Client::unmarshall_disconnect_event(
	const XrlError&	e,
	XrlArgs*	a,
	DisconnectEventCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(0));
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/test_peer_xif.cc,v 1.1.1.1 2002/12/11 23:56:18 hodson Exp $"

#include "test_peer_xif.hh"

bool
XrlTestPeerV0p1Client::send_register(
	const char*	the_tgt, 
	const string&	coordinator, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/register");
    x.args().add("coordinator", coordinator);
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall0, cb));
}


/* Unmarshall register */
void
XrlTestPeerV0p1Client::unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_packetisation(
	const char*	the_tgt, 
	const string&	protocol, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/packetisation");
    x.args().add("protocol", protocol);
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall1, cb));
}


/* Unmarshall packetisation */
void
XrlTestPeerV0p1Client::unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_connect(
	const char*	the_tgt, 
	const string&	host, 
	const uint32_t&	port, 
	const CB2&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/connect");
    x.args().add("host", host);
    x.args().add("port", port);
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall2, cb));
}


/* Unmarshall connect */
void
XrlTestPeerV0p1Client::unmarshall2(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB2		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_listen(
	const char*	the_tgt, 
	const string&	address, 
	const uint32_t&	port, 
	const CB3&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/listen");
    x.args().add("address", address);
    x.args().add("port", port);
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall3, cb));
}


/* Unmarshall listen */
void
XrlTestPeerV0p1Client::unmarshall3(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB3		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_send(
	const char*	the_tgt, 
	const vector<uint8_t>&	data, 
	const CB4&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/send");
    x.args().add("data", data);
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall4, cb));
}


/* Unmarshall send */
void
XrlTestPeerV0p1Client::unmarshall4(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB4		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_disconnect(
	const char*	the_tgt, 
	const CB5&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/disconnect");
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall5, cb));
}


/* Unmarshall disconnect */
void
XrlTestPeerV0p1Client::unmarshall5(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB5		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_reset(
	const char*	the_tgt, 
	const CB6&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/reset");
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall6, cb));
}


/* Unmarshall reset */
void
XrlTestPeerV0p1Client::unmarshall6(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB6		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlTestPeerV0p1Client::send_terminate(
	const char*	the_tgt, 
	const CB7&	cb
)
{
    Xrl x(the_tgt, "test_peer/0.1/terminate");
    return _router->send(x, callback(this, &XrlTestPeerV0p1Client::unmarshall7, cb));
}


/* Unmarshall terminate */
void
XrlTestPeerV0p1Client::unmarshall7(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB7		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%d != 0)", a->size());
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

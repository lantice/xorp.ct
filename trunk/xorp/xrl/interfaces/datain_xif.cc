/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/datain_xif.cc,v 1.1.1.1 2002/12/11 23:56:17 hodson Exp $"

#include "datain_xif.hh"

bool
XrlDatainV0p1Client::send_receive(
	const char*	the_tgt, 
	const string&	peer, 
	const bool&	status, 
	const uint32_t&	secs, 
	const uint32_t&	micro, 
	const vector<uint8_t>&	data, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "datain/0.1/receive");
    x.args().add("peer", peer);
    x.args().add("status", status);
    x.args().add("secs", secs);
    x.args().add("micro", micro);
    x.args().add("data", data);
    return _router->send(x, callback(this, &XrlDatainV0p1Client::unmarshall0, cb));
}


/* Unmarshall receive */
void
XrlDatainV0p1Client::unmarshall0(
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
XrlDatainV0p1Client::send_error(
	const char*	the_tgt, 
	const string&	peer, 
	const string&	reason, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "datain/0.1/error");
    x.args().add("peer", peer);
    x.args().add("reason", reason);
    return _router->send(x, callback(this, &XrlDatainV0p1Client::unmarshall1, cb));
}


/* Unmarshall error */
void
XrlDatainV0p1Client::unmarshall1(
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
XrlDatainV0p1Client::send_closed(
	const char*	the_tgt, 
	const string&	peer, 
	const CB2&	cb
)
{
    Xrl x(the_tgt, "datain/0.1/closed");
    x.args().add("peer", peer);
    return _router->send(x, callback(this, &XrlDatainV0p1Client::unmarshall2, cb));
}


/* Unmarshall closed */
void
XrlDatainV0p1Client::unmarshall2(
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

/*
 * Copyright (c) 2002 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by '../scripts/clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/common_xif.cc,v 1.1.1.1 2002/12/11 23:56:17 hodson Exp $"

#include "common_xif.hh"

bool
XrlCommonV0p1Client::send_get_target_name(
	const char*	the_tgt, 
	const CB0&	cb
)
{
    Xrl x(the_tgt, "common/0.1/get_target_name");
    return _router->send(x, callback(this, &XrlCommonV0p1Client::unmarshall0, cb));
}


/* Unmarshall get_target_name */
void
XrlCommonV0p1Client::unmarshall0(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB0		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%d != 1)", a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string name;
    try {
	a->get("name", name);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &name);
}

bool
XrlCommonV0p1Client::send_get_version(
	const char*	the_tgt, 
	const CB1&	cb
)
{
    Xrl x(the_tgt, "common/0.1/get_version");
    return _router->send(x, callback(this, &XrlCommonV0p1Client::unmarshall1, cb));
}


/* Unmarshall get_version */
void
XrlCommonV0p1Client::unmarshall1(
	const XrlError&	e, 
	XrlArgs*	a, 
	CB1		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%d != 1)", a->size());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string version;
    try {
	a->get("version", version);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &version);
}

/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/redist4_xif.cc,v 1.5 2004/06/10 13:45:55 hodson Exp $"

#include "redist4_xif.hh"

bool
XrlRedist4V0p1Client::send_add_route(
	const char*	the_tgt,
	const IPv4Net&	dst,
	const IPv4&	nh,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	metric,
	const uint32_t&	ad,
	const string&	cookie,
	const AddRouteCB&	cb
)
{
    Xrl x(the_tgt, "redist4/0.1/add_route");
    x.args().add("dst", dst);
    x.args().add("nh", nh);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("metric", metric);
    x.args().add("ad", ad);
    x.args().add("cookie", cookie);
    return _sender->send(x, callback(this, &XrlRedist4V0p1Client::unmarshall_add_route, cb));
}


/* Unmarshall add_route */
void
XrlRedist4V0p1Client::unmarshall_add_route(
	const XrlError&	e,
	XrlArgs*	a,
	AddRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRedist4V0p1Client::send_delete_route(
	const char*	the_tgt,
	const IPv4Net&	network,
	const string&	cookie,
	const DeleteRouteCB&	cb
)
{
    Xrl x(the_tgt, "redist4/0.1/delete_route");
    x.args().add("network", network);
    x.args().add("cookie", cookie);
    return _sender->send(x, callback(this, &XrlRedist4V0p1Client::unmarshall_delete_route, cb));
}


/* Unmarshall delete_route */
void
XrlRedist4V0p1Client::unmarshall_delete_route(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRouteCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRedist4V0p1Client::send_starting_route_dump(
	const char*	the_tgt,
	const string&	cookie,
	const StartingRouteDumpCB&	cb
)
{
    Xrl x(the_tgt, "redist4/0.1/starting_route_dump");
    x.args().add("cookie", cookie);
    return _sender->send(x, callback(this, &XrlRedist4V0p1Client::unmarshall_starting_route_dump, cb));
}


/* Unmarshall starting_route_dump */
void
XrlRedist4V0p1Client::unmarshall_starting_route_dump(
	const XrlError&	e,
	XrlArgs*	a,
	StartingRouteDumpCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

bool
XrlRedist4V0p1Client::send_finishing_route_dump(
	const char*	the_tgt,
	const string&	cookie,
	const FinishingRouteDumpCB&	cb
)
{
    Xrl x(the_tgt, "redist4/0.1/finishing_route_dump");
    x.args().add("cookie", cookie);
    return _sender->send(x, callback(this, &XrlRedist4V0p1Client::unmarshall_finishing_route_dump, cb));
}


/* Unmarshall finishing_route_dump */
void
XrlRedist4V0p1Client::unmarshall_finishing_route_dump(
	const XrlError&	e,
	XrlArgs*	a,
	FinishingRouteDumpCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e);
	return;
    } else if (a && a->size() != 0) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 0);
	cb->dispatch(XrlError::BAD_ARGS());
	return;
    }
    cb->dispatch(e);
}

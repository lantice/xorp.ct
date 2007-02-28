/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/policy_redist6_xif.cc,v 1.6 2006/03/26 22:39:25 pavlin Exp $"

#include "policy_redist6_xif.hh"

bool
XrlPolicyRedist6V0p1Client::send_add_route6(
	const char*	dst_xrl_target_name,
	const IPv6Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const IPv6&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags,
	const AddRoute6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "policy_redist6/0.1/add_route6");
    x.args().add("network", network);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    x.args().add("nexthop", nexthop);
    x.args().add("metric", metric);
    x.args().add("policytags", policytags);
    return _sender->send(x, callback(this, &XrlPolicyRedist6V0p1Client::unmarshall_add_route6, cb));
}


/* Unmarshall add_route6 */
void
XrlPolicyRedist6V0p1Client::unmarshall_add_route6(
	const XrlError&	e,
	XrlArgs*	a,
	AddRoute6CB		cb
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
XrlPolicyRedist6V0p1Client::send_delete_route6(
	const char*	dst_xrl_target_name,
	const IPv6Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const DeleteRoute6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "policy_redist6/0.1/delete_route6");
    x.args().add("network", network);
    x.args().add("unicast", unicast);
    x.args().add("multicast", multicast);
    return _sender->send(x, callback(this, &XrlPolicyRedist6V0p1Client::unmarshall_delete_route6, cb));
}


/* Unmarshall delete_route6 */
void
XrlPolicyRedist6V0p1Client::unmarshall_delete_route6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteRoute6CB		cb
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

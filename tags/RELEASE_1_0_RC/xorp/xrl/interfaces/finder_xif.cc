/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/finder_xif.cc,v 1.15 2004/05/24 17:35:35 hodson Exp $"

#include "finder_xif.hh"

bool
XrlFinderV0p2Client::send_register_finder_client(
	const char*	the_tgt,
	const string&	instance_name,
	const string&	class_name,
	const bool&	singleton,
	const string&	in_cookie,
	const RegisterFinderClientCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/register_finder_client");
    x.args().add("instance_name", instance_name);
    x.args().add("class_name", class_name);
    x.args().add("singleton", singleton);
    x.args().add("in_cookie", in_cookie);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_register_finder_client, cb));
}


/* Unmarshall register_finder_client */
void
XrlFinderV0p2Client::unmarshall_register_finder_client(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterFinderClientCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string out_cookie;
    try {
	a->get("out_cookie", out_cookie);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &out_cookie);
}

bool
XrlFinderV0p2Client::send_unregister_finder_client(
	const char*	the_tgt,
	const string&	instance_name,
	const UnregisterFinderClientCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/unregister_finder_client");
    x.args().add("instance_name", instance_name);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_unregister_finder_client, cb));
}


/* Unmarshall unregister_finder_client */
void
XrlFinderV0p2Client::unmarshall_unregister_finder_client(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterFinderClientCB		cb
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
XrlFinderV0p2Client::send_set_finder_client_enabled(
	const char*	the_tgt,
	const string&	instance_name,
	const bool&	enabled,
	const SetFinderClientEnabledCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/set_finder_client_enabled");
    x.args().add("instance_name", instance_name);
    x.args().add("enabled", enabled);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_set_finder_client_enabled, cb));
}


/* Unmarshall set_finder_client_enabled */
void
XrlFinderV0p2Client::unmarshall_set_finder_client_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	SetFinderClientEnabledCB		cb
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
XrlFinderV0p2Client::send_finder_client_enabled(
	const char*	the_tgt,
	const string&	instance_name,
	const FinderClientEnabledCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/finder_client_enabled");
    x.args().add("instance_name", instance_name);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_finder_client_enabled, cb));
}


/* Unmarshall finder_client_enabled */
void
XrlFinderV0p2Client::unmarshall_finder_client_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	FinderClientEnabledCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    bool enabled;
    try {
	a->get("enabled", enabled);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &enabled);
}

bool
XrlFinderV0p2Client::send_add_xrl(
	const char*	the_tgt,
	const string&	xrl,
	const string&	protocol_name,
	const string&	protocol_args,
	const AddXrlCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/add_xrl");
    x.args().add("xrl", xrl);
    x.args().add("protocol_name", protocol_name);
    x.args().add("protocol_args", protocol_args);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_add_xrl, cb));
}


/* Unmarshall add_xrl */
void
XrlFinderV0p2Client::unmarshall_add_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrlCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    string resolved_xrl_method_name;
    try {
	a->get("resolved_xrl_method_name", resolved_xrl_method_name);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &resolved_xrl_method_name);
}

bool
XrlFinderV0p2Client::send_remove_xrl(
	const char*	the_tgt,
	const string&	xrl,
	const RemoveXrlCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/remove_xrl");
    x.args().add("xrl", xrl);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_remove_xrl, cb));
}


/* Unmarshall remove_xrl */
void
XrlFinderV0p2Client::unmarshall_remove_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveXrlCB		cb
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
XrlFinderV0p2Client::send_resolve_xrl(
	const char*	the_tgt,
	const string&	xrl,
	const ResolveXrlCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/resolve_xrl");
    x.args().add("xrl", xrl);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_resolve_xrl, cb));
}


/* Unmarshall resolve_xrl */
void
XrlFinderV0p2Client::unmarshall_resolve_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	ResolveXrlCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList resolutions;
    try {
	a->get("resolutions", resolutions);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &resolutions);
}

bool
XrlFinderV0p2Client::send_get_xrl_targets(
	const char*	the_tgt,
	const GetXrlTargetsCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_xrl_targets");
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_xrl_targets, cb));
}


/* Unmarshall get_xrl_targets */
void
XrlFinderV0p2Client::unmarshall_get_xrl_targets(
	const XrlError&	e,
	XrlArgs*	a,
	GetXrlTargetsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList target_names;
    try {
	a->get("target_names", target_names);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &target_names);
}

bool
XrlFinderV0p2Client::send_get_xrls_registered_by(
	const char*	the_tgt,
	const string&	target_name,
	const GetXrlsRegisteredByCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_xrls_registered_by");
    x.args().add("target_name", target_name);
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_xrls_registered_by, cb));
}


/* Unmarshall get_xrls_registered_by */
void
XrlFinderV0p2Client::unmarshall_get_xrls_registered_by(
	const XrlError&	e,
	XrlArgs*	a,
	GetXrlsRegisteredByCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList xrls;
    try {
	a->get("xrls", xrls);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &xrls);
}

bool
XrlFinderV0p2Client::send_get_ipv4_permitted_hosts(
	const char*	the_tgt,
	const GetIpv4PermittedHostsCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_ipv4_permitted_hosts");
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_ipv4_permitted_hosts, cb));
}


/* Unmarshall get_ipv4_permitted_hosts */
void
XrlFinderV0p2Client::unmarshall_get_ipv4_permitted_hosts(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv4PermittedHostsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList ipv4s;
    try {
	a->get("ipv4s", ipv4s);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &ipv4s);
}

bool
XrlFinderV0p2Client::send_get_ipv4_permitted_nets(
	const char*	the_tgt,
	const GetIpv4PermittedNetsCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_ipv4_permitted_nets");
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_ipv4_permitted_nets, cb));
}


/* Unmarshall get_ipv4_permitted_nets */
void
XrlFinderV0p2Client::unmarshall_get_ipv4_permitted_nets(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv4PermittedNetsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList ipv4nets;
    try {
	a->get("ipv4nets", ipv4nets);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &ipv4nets);
}

bool
XrlFinderV0p2Client::send_get_ipv6_permitted_hosts(
	const char*	the_tgt,
	const GetIpv6PermittedHostsCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_ipv6_permitted_hosts");
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_ipv6_permitted_hosts, cb));
}


/* Unmarshall get_ipv6_permitted_hosts */
void
XrlFinderV0p2Client::unmarshall_get_ipv6_permitted_hosts(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv6PermittedHostsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList ipv6s;
    try {
	a->get("ipv6s", ipv6s);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &ipv6s);
}

bool
XrlFinderV0p2Client::send_get_ipv6_permitted_nets(
	const char*	the_tgt,
	const GetIpv6PermittedNetsCB&	cb
)
{
    Xrl x(the_tgt, "finder/0.2/get_ipv6_permitted_nets");
    return _sender->send(x, callback(this, &XrlFinderV0p2Client::unmarshall_get_ipv6_permitted_nets, cb));
}


/* Unmarshall get_ipv6_permitted_nets */
void
XrlFinderV0p2Client::unmarshall_get_ipv6_permitted_nets(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv6PermittedNetsCB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0);
	return;
    } else if (a && a->size() != 1) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", (uint32_t)a->size(), 1);
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    XrlAtomList ipv6nets;
    try {
	a->get("ipv6nets", ipv6nets);
    } catch (const XrlArgs::XrlAtomNotFound&) {
	XLOG_ERROR("Atom not found");
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &ipv6nets);
}

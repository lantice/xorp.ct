/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_firewall_xif.cc,v 1.2 2008/04/27 23:08:06 pavlin Exp $"

#include "fea_firewall_xif.hh"

bool
XrlFeaFirewallV0p1Client::send_start_transaction(
	const char*	dst_xrl_target_name,
	const StartTransactionCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/start_transaction");
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_start_transaction, cb));
}


/* Unmarshall start_transaction */
void
XrlFeaFirewallV0p1Client::unmarshall_start_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	StartTransactionCB		cb
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
    uint32_t tid;
    try {
	a->get("tid", tid);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0);
	return;
    }
    cb->dispatch(e, &tid);
}

bool
XrlFeaFirewallV0p1Client::send_commit_transaction(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const CommitTransactionCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/commit_transaction");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_commit_transaction, cb));
}


/* Unmarshall commit_transaction */
void
XrlFeaFirewallV0p1Client::unmarshall_commit_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	CommitTransactionCB		cb
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
XrlFeaFirewallV0p1Client::send_abort_transaction(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const AbortTransactionCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/abort_transaction");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_abort_transaction, cb));
}


/* Unmarshall abort_transaction */
void
XrlFeaFirewallV0p1Client::unmarshall_abort_transaction(
	const XrlError&	e,
	XrlArgs*	a,
	AbortTransactionCB		cb
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
XrlFeaFirewallV0p1Client::send_add_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const AddEntry4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/add_entry4");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_add_entry4, cb));
}


/* Unmarshall add_entry4 */
void
XrlFeaFirewallV0p1Client::unmarshall_add_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry4CB		cb
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
XrlFeaFirewallV0p1Client::send_replace_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const ReplaceEntry4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/replace_entry4");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_replace_entry4, cb));
}


/* Unmarshall replace_entry4 */
void
XrlFeaFirewallV0p1Client::unmarshall_replace_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceEntry4CB		cb
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
XrlFeaFirewallV0p1Client::send_delete_entry4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv4Net&	src_network,
	const IPv4Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const DeleteEntry4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/delete_entry4");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_delete_entry4, cb));
}


/* Unmarshall delete_entry4 */
void
XrlFeaFirewallV0p1Client::unmarshall_delete_entry4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry4CB		cb
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
XrlFeaFirewallV0p1Client::send_delete_all_entries4(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const DeleteAllEntries4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/delete_all_entries4");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_delete_all_entries4, cb));
}


/* Unmarshall delete_all_entries4 */
void
XrlFeaFirewallV0p1Client::unmarshall_delete_all_entries4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries4CB		cb
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
XrlFeaFirewallV0p1Client::send_get_entry_list_start4(
	const char*	dst_xrl_target_name,
	const GetEntryListStart4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/get_entry_list_start4");
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_start4, cb));
}


/* Unmarshall get_entry_list_start4 */
void
XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_start4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListStart4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(2));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t token;
    bool more;
    try {
	a->get("token", token);
	a->get("more", more);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &token, &more);
}

bool
XrlFeaFirewallV0p1Client::send_get_entry_list_next4(
	const char*	dst_xrl_target_name,
	const uint32_t&	token,
	const GetEntryListNext4CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/get_entry_list_next4");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_next4, cb));
}


/* Unmarshall get_entry_list_next4 */
void
XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_next4(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListNext4CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 12) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(12));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    uint32_t rule_number;
    string ifname;
    string vifname;
    IPv4Net src_network;
    IPv4Net dst_network;
    uint32_t ip_protocol;
    uint32_t src_port_begin;
    uint32_t src_port_end;
    uint32_t dst_port_begin;
    uint32_t dst_port_end;
    string action;
    bool more;
    try {
	a->get("rule_number", rule_number);
	a->get("ifname", ifname);
	a->get("vifname", vifname);
	a->get("src_network", src_network);
	a->get("dst_network", dst_network);
	a->get("ip_protocol", ip_protocol);
	a->get("src_port_begin", src_port_begin);
	a->get("src_port_end", src_port_end);
	a->get("dst_port_begin", dst_port_begin);
	a->get("dst_port_end", dst_port_end);
	a->get("action", action);
	a->get("more", more);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &rule_number, &ifname, &vifname, &src_network, &dst_network, &ip_protocol, &src_port_begin, &src_port_end, &dst_port_begin, &dst_port_end, &action, &more);
}

bool
XrlFeaFirewallV0p1Client::send_add_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const AddEntry6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/add_entry6");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_add_entry6, cb));
}


/* Unmarshall add_entry6 */
void
XrlFeaFirewallV0p1Client::unmarshall_add_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	AddEntry6CB		cb
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
XrlFeaFirewallV0p1Client::send_replace_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const string&	action,
	const ReplaceEntry6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/replace_entry6");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    x.args().add("action", action);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_replace_entry6, cb));
}


/* Unmarshall replace_entry6 */
void
XrlFeaFirewallV0p1Client::unmarshall_replace_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	ReplaceEntry6CB		cb
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
XrlFeaFirewallV0p1Client::send_delete_entry6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const uint32_t&	rule_number,
	const string&	ifname,
	const string&	vifname,
	const IPv6Net&	src_network,
	const IPv6Net&	dst_network,
	const uint32_t&	ip_protocol,
	const uint32_t&	src_port_begin,
	const uint32_t&	src_port_end,
	const uint32_t&	dst_port_begin,
	const uint32_t&	dst_port_end,
	const DeleteEntry6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/delete_entry6");
    x.args().add("tid", tid);
    x.args().add("rule_number", rule_number);
    x.args().add("ifname", ifname);
    x.args().add("vifname", vifname);
    x.args().add("src_network", src_network);
    x.args().add("dst_network", dst_network);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("src_port_begin", src_port_begin);
    x.args().add("src_port_end", src_port_end);
    x.args().add("dst_port_begin", dst_port_begin);
    x.args().add("dst_port_end", dst_port_end);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_delete_entry6, cb));
}


/* Unmarshall delete_entry6 */
void
XrlFeaFirewallV0p1Client::unmarshall_delete_entry6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEntry6CB		cb
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
XrlFeaFirewallV0p1Client::send_delete_all_entries6(
	const char*	dst_xrl_target_name,
	const uint32_t&	tid,
	const DeleteAllEntries6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/delete_all_entries6");
    x.args().add("tid", tid);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_delete_all_entries6, cb));
}


/* Unmarshall delete_all_entries6 */
void
XrlFeaFirewallV0p1Client::unmarshall_delete_all_entries6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteAllEntries6CB		cb
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
XrlFeaFirewallV0p1Client::send_get_entry_list_start6(
	const char*	dst_xrl_target_name,
	const GetEntryListStart6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/get_entry_list_start6");
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_start6, cb));
}


/* Unmarshall get_entry_list_start6 */
void
XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_start6(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListStart6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0);
	return;
    } else if (a && a->size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(2));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    uint32_t token;
    bool more;
    try {
	a->get("token", token);
	a->get("more", more);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0);
	return;
    }
    cb->dispatch(e, &token, &more);
}

bool
XrlFeaFirewallV0p1Client::send_get_entry_list_next6(
	const char*	dst_xrl_target_name,
	const uint32_t&	token,
	const GetEntryListNext6CB&	cb
)
{
    Xrl x(dst_xrl_target_name, "fea_firewall/0.1/get_entry_list_next6");
    x.args().add("token", token);
    return _sender->send(x, callback(this, &XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_next6, cb));
}


/* Unmarshall get_entry_list_next6 */
void
XrlFeaFirewallV0p1Client::unmarshall_get_entry_list_next6(
	const XrlError&	e,
	XrlArgs*	a,
	GetEntryListNext6CB		cb
)
{
    if (e != XrlError::OKAY()) {
	cb->dispatch(e, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    } else if (a && a->size() != 12) {
	XLOG_ERROR("Wrong number of arguments (%u != %u)", XORP_UINT_CAST(a->size()), XORP_UINT_CAST(12));
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    uint32_t rule_number;
    string ifname;
    string vifname;
    IPv6Net src_network;
    IPv6Net dst_network;
    uint32_t ip_protocol;
    uint32_t src_port_begin;
    uint32_t src_port_end;
    uint32_t dst_port_begin;
    uint32_t dst_port_end;
    string action;
    bool more;
    try {
	a->get("rule_number", rule_number);
	a->get("ifname", ifname);
	a->get("vifname", vifname);
	a->get("src_network", src_network);
	a->get("dst_network", dst_network);
	a->get("ip_protocol", ip_protocol);
	a->get("src_port_begin", src_port_begin);
	a->get("src_port_end", src_port_end);
	a->get("dst_port_begin", dst_port_begin);
	a->get("dst_port_end", dst_port_end);
	a->get("action", action);
	a->get("more", more);
    } catch (const XrlArgs::BadArgs& e) {
	XLOG_ERROR("Error decoding the arguments: %s", e.str().c_str());
	cb->dispatch(XrlError::BAD_ARGS(), 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	return;
    }
    cb->dispatch(e, &rule_number, &ifname, &vifname, &src_network, &dst_network, &ip_protocol, &src_port_begin, &src_port_end, &dst_port_begin, &dst_port_end, &action, &more);
}

/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 */

#ident "$XORP: xorp/xrl/interfaces/fea_rawpkt6_client_xif.cc,v 1.11 2007/05/08 19:23:20 pavlin Exp $"

#include "fea_rawpkt6_client_xif.hh"

bool
XrlRawPacket6ClientV0p1Client::send_recv(
	const char*	dst_xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const IPv6&	src_address,
	const IPv6&	dst_address,
	const uint32_t&	ip_protocol,
	const int32_t&	ip_ttl,
	const int32_t&	ip_tos,
	const bool&	ip_router_alert,
	const bool&	ip_internet_control,
	const XrlAtomList&	ext_headers_type,
	const XrlAtomList&	ext_headers_payload,
	const vector<uint8_t>&	payload,
	const RecvCB&	cb
)
{
    Xrl x(dst_xrl_target_name, "raw_packet6_client/0.1/recv");
    x.args().add("if_name", if_name);
    x.args().add("vif_name", vif_name);
    x.args().add("src_address", src_address);
    x.args().add("dst_address", dst_address);
    x.args().add("ip_protocol", ip_protocol);
    x.args().add("ip_ttl", ip_ttl);
    x.args().add("ip_tos", ip_tos);
    x.args().add("ip_router_alert", ip_router_alert);
    x.args().add("ip_internet_control", ip_internet_control);
    x.args().add("ext_headers_type", ext_headers_type);
    x.args().add("ext_headers_payload", ext_headers_payload);
    x.args().add("payload", payload);
    return _sender->send(x, callback(this, &XrlRawPacket6ClientV0p1Client::unmarshall_recv, cb));
}


/* Unmarshall recv */
void
XrlRawPacket6ClientV0p1Client::unmarshall_recv(
	const XrlError&	e,
	XrlArgs*	a,
	RecvCB		cb
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

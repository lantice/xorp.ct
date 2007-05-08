/*
 * Copyright (c) 2001-2007 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/fea_rawpkt6_xif.hh,v 1.10 2007/02/16 22:47:38 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_FEA_RAWPKT6_XIF_HH__
#define __XRL_INTERFACES_FEA_RAWPKT6_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFeaRawpkt6"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlRawPacket6V0p1Client {
public:
    XrlRawPacket6V0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlRawPacket6V0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr SendCB;
    /**
     *  Send Xrl intended to:
     *
     *  Send an IPv6 packet on a raw socket.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param if_name the interface to send the packet on. It is essential for
     *  multicast. In the unicast case this field may be empty.
     *
     *  @param vif_name the vif to send the packet on. It is essential for
     *  multicast. In the unicast case this field may be empty.
     *
     *  @param src_address the IP source address.
     *
     *  @param dst_address the IP destination address.
     *
     *  @param ip_protocol the IP protocol number. It must be between 1 and
     *  255.
     *
     *  @param ip_ttl the IP TTL (hop-limit). If it has a negative value, the
     *  TTL will be set internally before transmission.
     *
     *  @param ip_tos the Type Of Service (IP traffic class for IPv6). If it
     *  has a negative value, the TOS will be set internally before
     *  transmission.
     *
     *  @param ip_router_alert if true, then add the IP Router Alert option to
     *  the IP packet.
     *
     *  @param ip_internet_control if true, then this is IP control traffic.
     *
     *  @param ext_headers_type a list of u32 integers with the types of the
     *  optional extention headers.
     *
     *  @param ext_headers_payload a list of payload data, one for each
     *  optional extention header. The number of entries must match
     *  ext_headers_type.
     *
     *  @param payload the payload, everything after the IP header and options.
     */
    bool send_send(
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
	const SendCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RegisterReceiverCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register to receive IPv6 packets. The receiver is expected to support
     *  raw_packet6_client/0.1 interface.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_target_name the receiver's XRL target name.
     *
     *  @param if_name the interface through which packets should be accepted.
     *
     *  @param vif_name the vif through which packets should be accepted.
     *
     *  @param ip_protocol the IP protocol number that the receiver is
     *  interested in. It must be between 0 and 255. A protocol number of 0 is
     *  used to specify all protocols.
     *
     *  @param enable_multicast_loopback if true then enable delivering of
     *  multicast datagrams back to this host (assuming the host is a member of
     *  the same multicast group.
     */
    bool send_register_receiver(
	const char*	dst_xrl_target_name,
	const string&	xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const bool&	enable_multicast_loopback,
	const RegisterReceiverCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterReceiverCB;
    /**
     *  Send Xrl intended to:
     *
     *  Unregister to receive IPv6 packets.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_target_name the receiver's XRL target name.
     *
     *  @param if_name the interface through which packets should not be
     *  accepted.
     *
     *  @param vif_name the vif through which packets should not be accepted.
     *
     *  @param ip_protocol the IP Protocol number that the receiver is not
     *  interested in anymore. It must be between 0 and 255. A protocol number
     *  of 0 is used to specify all protocols.
     */
    bool send_unregister_receiver(
	const char*	dst_xrl_target_name,
	const string&	xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const UnregisterReceiverCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr JoinMulticastGroupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Join an IPv6 multicast group.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_target_name the receiver's XRL target name.
     *
     *  @param if_name the interface through which packets should be accepted.
     *
     *  @param vif_name the vif through which packets should be accepted.
     *
     *  @param ip_protocol the IP protocol number that the receiver is
     *  interested in. It must be between 0 and 255. A protocol number of 0 is
     *  used to specify all protocols.
     *
     *  @param group_address the multicast group address to join.
     */
    bool send_join_multicast_group(
	const char*	dst_xrl_target_name,
	const string&	xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const IPv6&	group_address,
	const JoinMulticastGroupCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr LeaveMulticastGroupCB;
    /**
     *  Send Xrl intended to:
     *
     *  Leave an IPv6 multicast group.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     *
     *  @param xrl_target_name the receiver's XRL target name.
     *
     *  @param if_name the interface through which packets should not be
     *  accepted.
     *
     *  @param vif_name the vif through which packets should not be accepted.
     *
     *  @param ip_protocol the IP protocol number that the receiver is not
     *  interested in anymore. It must be between 0 and 255. A protocol number
     *  of 0 is used to specify all protocols.
     *
     *  @param group_address the multicast group address to leave.
     */
    bool send_leave_multicast_group(
	const char*	dst_xrl_target_name,
	const string&	xrl_target_name,
	const string&	if_name,
	const string&	vif_name,
	const uint32_t&	ip_protocol,
	const IPv6&	group_address,
	const LeaveMulticastGroupCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_send(
	const XrlError&	e,
	XrlArgs*	a,
	SendCB		cb
    );

    void unmarshall_register_receiver(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterReceiverCB		cb
    );

    void unmarshall_unregister_receiver(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterReceiverCB		cb
    );

    void unmarshall_join_multicast_group(
	const XrlError&	e,
	XrlArgs*	a,
	JoinMulticastGroupCB		cb
    );

    void unmarshall_leave_multicast_group(
	const XrlError&	e,
	XrlArgs*	a,
	LeaveMulticastGroupCB		cb
    );

};

#endif /* __XRL_INTERFACES_FEA_RAWPKT6_XIF_HH__ */

/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/finder_xif.hh,v 1.24 2008/01/04 03:17:56 pavlin Exp $
 */

#ifndef __XRL_INTERFACES_FINDER_XIF_HH__
#define __XRL_INTERFACES_FINDER_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifFinder"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlFinderV0p2Client {
public:
    XrlFinderV0p2Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlFinderV0p2Client() {}

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr RegisterFinderClientCB;
    /**
     *  Send Xrl intended to:
     *
     *  Register client with Finder. Once client has been registered Xrl
     *  registrations may proceed. Once Xrl registrations have have been
     *  completed the client needs to be enabled for the Finder to respond to
     *  queries about the client. Fails if instance_name is already registered,
     *  or another instance of the same class is registered as a singleton. The
     *  client must support the finder_client interface in order to be able to
     *  process messages from the finder.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_register_finder_client(
	const char*	dst_xrl_target_name,
	const string&	instance_name,
	const string&	class_name,
	const bool&	singleton,
	const string&	in_cookie,
	const RegisterFinderClientCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr UnregisterFinderClientCB;

    bool send_unregister_finder_client(
	const char*	dst_xrl_target_name,
	const string&	instance_name,
	const UnregisterFinderClientCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr SetFinderClientEnabledCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable resolution of Xrls associated with target. Disabling Xrls at
     *  present does not cause clients to flush state associated with target so
     *  cached entries in clients are unaffected by this Xrl. Caller must be
     *  client that registered Xrl.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_set_finder_client_enabled(
	const char*	dst_xrl_target_name,
	const string&	instance_name,
	const bool&	enabled,
	const SetFinderClientEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const bool*>::RefPtr FinderClientEnabledCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get enabled state information associated with finder client.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_finder_client_enabled(
	const char*	dst_xrl_target_name,
	const string&	instance_name,
	const FinderClientEnabledCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr AddXrlCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add resolved Xrl into system, fails if xrl is already registered.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_add_xrl(
	const char*	dst_xrl_target_name,
	const string&	xrl,
	const string&	protocol_name,
	const string&	protocol_args,
	const AddXrlCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr RemoveXrlCB;
    /**
     *  Send Xrl intended to:
     *
     *  Remove xrl
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_remove_xrl(
	const char*	dst_xrl_target_name,
	const string&	xrl,
	const RemoveXrlCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr ResolveXrlCB;
    /**
     *  Send Xrl intended to:
     *
     *  Resolve Xrl
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_resolve_xrl(
	const char*	dst_xrl_target_name,
	const string&	xrl,
	const ResolveXrlCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetXrlTargetsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of registered Xrl targets
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_xrl_targets(
	const char*	dst_xrl_target_name,
	const GetXrlTargetsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetXrlsRegisteredByCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of Xrls registered by target
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_xrls_registered_by(
	const char*	dst_xrl_target_name,
	const string&	target_name,
	const GetXrlsRegisteredByCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetIpv4PermittedHostsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of IPv4 hosts that clients should accept IPC requests from.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_ipv4_permitted_hosts(
	const char*	dst_xrl_target_name,
	const GetIpv4PermittedHostsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetIpv4PermittedNetsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of IPv4 nets that clients should accept IPC requests from.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_ipv4_permitted_nets(
	const char*	dst_xrl_target_name,
	const GetIpv4PermittedNetsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetIpv6PermittedHostsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of IPv6 hosts that clients should accept IPC requests from.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_ipv6_permitted_hosts(
	const char*	dst_xrl_target_name,
	const GetIpv6PermittedHostsCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const XrlAtomList*>::RefPtr GetIpv6PermittedNetsCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get list of IPv6 nets that clients should accept IPC requests from.
     *
     *  @param dst_xrl_target_name the Xrl target name of the destination.
     */
    bool send_get_ipv6_permitted_nets(
	const char*	dst_xrl_target_name,
	const GetIpv6PermittedNetsCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_register_finder_client(
	const XrlError&	e,
	XrlArgs*	a,
	RegisterFinderClientCB		cb
    );

    void unmarshall_unregister_finder_client(
	const XrlError&	e,
	XrlArgs*	a,
	UnregisterFinderClientCB		cb
    );

    void unmarshall_set_finder_client_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	SetFinderClientEnabledCB		cb
    );

    void unmarshall_finder_client_enabled(
	const XrlError&	e,
	XrlArgs*	a,
	FinderClientEnabledCB		cb
    );

    void unmarshall_add_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	AddXrlCB		cb
    );

    void unmarshall_remove_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	RemoveXrlCB		cb
    );

    void unmarshall_resolve_xrl(
	const XrlError&	e,
	XrlArgs*	a,
	ResolveXrlCB		cb
    );

    void unmarshall_get_xrl_targets(
	const XrlError&	e,
	XrlArgs*	a,
	GetXrlTargetsCB		cb
    );

    void unmarshall_get_xrls_registered_by(
	const XrlError&	e,
	XrlArgs*	a,
	GetXrlsRegisteredByCB		cb
    );

    void unmarshall_get_ipv4_permitted_hosts(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv4PermittedHostsCB		cb
    );

    void unmarshall_get_ipv4_permitted_nets(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv4PermittedNetsCB		cb
    );

    void unmarshall_get_ipv6_permitted_hosts(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv6PermittedHostsCB		cb
    );

    void unmarshall_get_ipv6_permitted_nets(
	const XrlError&	e,
	XrlArgs*	a,
	GetIpv6PermittedNetsCB		cb
    );

};

#endif /* __XRL_INTERFACES_FINDER_XIF_HH__ */

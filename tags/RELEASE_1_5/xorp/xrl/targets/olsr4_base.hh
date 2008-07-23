/*
 * Copyright (c) 2001-2008 XORP, Inc.
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/olsr4_base.hh,v 1.1 2008/04/24 15:20:36 bms Exp $
 */


#ifndef __XRL_TARGETS_OLSR4_BASE_HH__
#define __XRL_TARGETS_OLSR4_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlOlsr4Target"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlOlsr4TargetBase {
protected:
    XrlCmdMap* _cmds;

public:
    /**
     * Constructor.
     *
     * @param cmds an XrlCmdMap that the commands associated with the target
     *		   should be added to.  This is typically the XrlRouter
     *		   associated with the target.
     */
    XrlOlsr4TargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlOlsr4TargetBase();

    /**
     * Set command map.
     *
     * @param cmds pointer to command map to associate commands with.  This
     * argument is typically a pointer to the XrlRouter associated with the
     * target.
     *
     * @return true on success, false if cmds is null or a command map has
     * already been supplied.
     */
    bool set_command_map(XrlCmdMap* cmds);

    /**
     * Get Xrl instance name associated with command map.
     */
    const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    const char* version() const { return "olsr4/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get name of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_target_name(
	// Output values,
	string&	name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get version string from Xrl Target
     */
    virtual XrlCmdError common_0_1_get_version(
	// Output values,
	string&	version) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get status of Xrl Target
     */
    virtual XrlCmdError common_0_1_get_status(
	// Output values,
	uint32_t&	status,
	string&	reason) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Request clean shutdown of Xrl Target
     */
    virtual XrlCmdError common_0_1_shutdown() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target birth to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_birth(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Announce target death to observer.
     *
     *  @param target_class the target class name.
     *
     *  @param target_instance the target instance name.
     */
    virtual XrlCmdError finder_event_observer_0_1_xrl_target_death(
	// Input values,
	const string&	target_class,
	const string&	target_instance) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when a packet arrives
     *  from an IPv4 source.
     *
     *  @param sockid the identifier associated with socket where the event
     *  occurred.
     *
     *  @param if_name the interface name the packet arrived on, if known. If
     *  unknown, then it is an empty string.
     *
     *  @param vif_name the vif name the packet arrived on, if known. If
     *  unknown, then it is an empty string.
     *
     *  @param src_host the originating host.
     *
     *  @param src_port the originating IP port.
     *
     *  @param data the data received.
     */
    virtual XrlCmdError socket4_user_0_1_recv_event(
	// Input values,
	const string&	sockid,
	const string&	if_name,
	const string&	vif_name,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const vector<uint8_t>&	data) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when a connection
     *  request is received from an IPv4 source. It applies only to TCP
     *  sockets.
     *
     *  @param sockid the identifier associated with socket where the event
     *  occurred.
     *
     *  @param src_host the connecting host.
     *
     *  @param src_port the connecting IP port.
     *
     *  @param new_sockid the identifier associated with the new socket that
     *  has been created to handle the new connection.
     *
     *  @param accept if true, the connection request has been accepted,
     *  otherwise it has been rejected.
     */
    virtual XrlCmdError socket4_user_0_1_inbound_connect_event(
	// Input values,
	const string&	sockid,
	const IPv4&	src_host,
	const uint32_t&	src_port,
	const string&	new_sockid,
	// Output values,
	bool&	accept) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when an outgoing
     *  connection request originated by the local host is completed. It
     *  applies only to TCP sockets. Note that if the connection failed, the
     *  error_event will be dispatched instead.
     *
     *  @param sockid the identifier associated with socket where the event
     *  occurred.
     */
    virtual XrlCmdError socket4_user_0_1_outgoing_connect_event(
	// Input values,
	const string&	sockid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when an error occurs.
     *
     *  @param sockid the identifier associated with socket where the event
     *  occurred.
     *
     *  @param error a textual description of the error.
     *
     *  @param fatal indication of whether socket is shutdown because of error.
     */
    virtual XrlCmdError socket4_user_0_1_error_event(
	// Input values,
	const string&	sockid,
	const string&	error,
	const bool&	fatal) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Method invoked by target implementing socket4/0.1 when the peer has
     *  closed the connection. It applies only to TCP sockets. Note that the
     *  socket itself is left open and must be explicitly closed.
     *
     *  @param sockid the identifier associated with socket where the event
     *  occurred.
     */
    virtual XrlCmdError socket4_user_0_1_disconnect_event(
	// Input values,
	const string&	sockid) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Configure a policy filter.
     *
     *  @param filter the identifier of the filter to configure.
     *
     *  @param conf the configuration of the filter.
     */
    virtual XrlCmdError policy_backend_0_1_configure(
	// Input values,
	const uint32_t&	filter,
	const string&	conf) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Reset a policy filter.
     *
     *  @param filter the identifier of the filter to reset.
     */
    virtual XrlCmdError policy_backend_0_1_reset(
	// Input values,
	const uint32_t&	filter) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Push all available routes through all filters for re-filtering.
     */
    virtual XrlCmdError policy_backend_0_1_push_routes() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Start route redistribution for an IPv4 route.
     *
     *  @param network the route to advertise.
     *
     *  @param unicast whether the route is unicast.
     *
     *  @param multicast whether the route is multicast.
     *
     *  @param nexthop the nexthop of the route.
     *
     *  @param metric the metric of the route.
     *
     *  @param policytags the set of policy-tags associated with the route.
     */
    virtual XrlCmdError policy_redist4_0_1_add_route4(
	// Input values,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast,
	const IPv4&	nexthop,
	const uint32_t&	metric,
	const XrlAtomList&	policytags) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Terminate route redistribution for an IPv4 route.
     *
     *  @param network the route for which advertisements should cease.
     *
     *  @param unicast whether the route is unicast.
     *
     *  @param multicast whether the route is multicast.
     */
    virtual XrlCmdError policy_redist4_0_1_delete_route4(
	// Input values,
	const IPv4Net&	network,
	const bool&	unicast,
	const bool&	multicast) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable profiling
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_enable(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Disable profiling
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_disable(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get log entries.
     *
     *  @param pname profile variable
     *
     *  @param instance_name to send the profiling info to.
     */
    virtual XrlCmdError profile_0_1_get_entries(
	// Input values,
	const string&	pname,
	const string&	instance_name) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Clear the profiling entries
     *
     *  @param pname profile variable
     */
    virtual XrlCmdError profile_0_1_clear(
	// Input values,
	const string&	pname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  List all the profiling variables registered with this target.
     */
    virtual XrlCmdError profile_0_1_list(
	// Output values,
	string&	info) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/Disable tracing.
     *
     *  @param tvar trace variable.
     *
     *  @param enable set to true to enable, false to disable.
     */
    virtual XrlCmdError olsr4_0_1_trace(
	// Input values,
	const string&	tvar,
	const bool&	enable) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Clear all OLSR protocol databases.
     */
    virtual XrlCmdError olsr4_0_1_clear_database() = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the willingness-to-forward.
     *
     *  @param willingness the new willingness-to-forward.
     */
    virtual XrlCmdError olsr4_0_1_set_willingness(
	// Input values,
	const uint32_t&	willingness) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the willingness-to-forward.
     */
    virtual XrlCmdError olsr4_0_1_get_willingness(
	// Output values,
	uint32_t&	willingness) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the MPR_COVERAGE.
     *
     *  @param coverage the new MPR_COVERAGE value.
     */
    virtual XrlCmdError olsr4_0_1_set_mpr_coverage(
	// Input values,
	const uint32_t&	coverage) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the MPR_COVERAGE.
     */
    virtual XrlCmdError olsr4_0_1_get_mpr_coverage(
	// Output values,
	uint32_t&	coverage) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the TC_REDUNDANCY.
     */
    virtual XrlCmdError olsr4_0_1_set_tc_redundancy(
	// Input values,
	const string&	redundancy) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the TC_REDUNDANCY.
     */
    virtual XrlCmdError olsr4_0_1_get_tc_redundancy(
	// Output values,
	string&	redundancy) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Enable/disable TC fisheye mode.
     *
     *  @param enabled true to enable fisheye, false to disable it.
     */
    virtual XrlCmdError olsr4_0_1_set_tc_fisheye(
	// Input values,
	const bool&	enabled) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the current TC fisheye mode.
     */
    virtual XrlCmdError olsr4_0_1_get_tc_fisheye(
	// Output values,
	bool&	enabled) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the current HNA base cost metric.
     */
    virtual XrlCmdError olsr4_0_1_set_hna_base_cost(
	// Input values,
	const uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the current HNA base cost metric.
     */
    virtual XrlCmdError olsr4_0_1_get_hna_base_cost(
	// Output values,
	uint32_t&	metric) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the HELLO_INTERVAL.
     *
     *  @param interval the new HELLO_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_set_hello_interval(
	// Input values,
	const uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the HELLO_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_get_hello_interval(
	// Output values,
	uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the REFRESH_INTERVAL.
     *
     *  @param interval the new REFRESH_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_set_refresh_interval(
	// Input values,
	const uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the REFRESH_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_get_refresh_interval(
	// Output values,
	uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the TC_INTERVAL.
     *
     *  @param interval the new TC_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_set_tc_interval(
	// Input values,
	const uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the TC_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_get_tc_interval(
	// Output values,
	uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the MID_INTERVAL.
     *
     *  @param interval the new MID_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_set_mid_interval(
	// Input values,
	const uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the MID_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_get_mid_interval(
	// Output values,
	uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the HNA_INTERVAL.
     *
     *  @param interval the new HNA_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_set_hna_interval(
	// Input values,
	const uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the HNA_INTERVAL.
     */
    virtual XrlCmdError olsr4_0_1_get_hna_interval(
	// Output values,
	uint32_t&	interval) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the DUP_HOLD_TIME.
     *
     *  @param dup_hold_time the new DUP_HOLD_TIME.
     */
    virtual XrlCmdError olsr4_0_1_set_dup_hold_time(
	// Input values,
	const uint32_t&	dup_hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the DUP_HOLD_TIME.
     */
    virtual XrlCmdError olsr4_0_1_get_dup_hold_time(
	// Output values,
	uint32_t&	dup_hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the main address.
     *
     *  @param addr Our main IPv4 address which OLSR uses as a router ID.
     */
    virtual XrlCmdError olsr4_0_1_set_main_address(
	// Input values,
	const IPv4&	addr) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the main address.
     */
    virtual XrlCmdError olsr4_0_1_get_main_address(
	// Output values,
	IPv4&	addr) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Create an IPv4 address binding for OLSR. OLSR must be bound to a given
     *  protocol address on each interface, which means interface bindings in
     *  OLSRv1 must be keyed by interface name as well as protocol address.
     *  Only a single IPv4 address may be thus bound, and the address must be
     *  supplied when the binding is created. This is to workaround the lack of
     *  RFC 3927 link-scoped IPv4 capability in most IPv4 implementations. The
     *  addition of address is not instantaneous. OLSR has to instantiate state
     *  in the FEA to send and receive packets. Once instantiated, the address
     *  must be explicitly enabled with the set_binding_enabled XRL.
     *
     *  @param ifname the interface that owns vif that has addr
     *
     *  @param vifname virtual interface owning addr
     *
     *  @param local_addr the address to be added.
     *
     *  @param local_port the port to listen for control traffic on.
     *
     *  @param all_nodes_addr the address to use for transmission.
     *
     *  @param all_nodes_port the port to use for transmission.
     */
    virtual XrlCmdError olsr4_0_1_bind_address(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	local_addr,
	const uint32_t&	local_port,
	const IPv4&	all_nodes_addr,
	const uint32_t&	all_nodes_port) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Destroy an IPv4 address binding for OLSR.
     *
     *  @param ifname the interface to unbind.
     *
     *  @param vifname the vif to unbind.
     */
    virtual XrlCmdError olsr4_0_1_unbind_address(
	// Input values,
	const string&	ifname,
	const string&	vifname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the enabled state of an IPv4 address binding for OLSR.
     *
     *  @param ifname the interface to set enabled state for.
     *
     *  @param vifname the vif to set enabled state for.
     *
     *  @param enabled true if OLSR is to be configured administratively up on
     *  the interface, false if it is to be configured down.
     */
    virtual XrlCmdError olsr4_0_1_set_binding_enabled(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const bool&	enabled) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the state of an IPv4 address binding for OLSR.
     *
     *  @param ifname the interface to query.
     *
     *  @param vifname the vif to qurery
     *
     *  @param enabled true if OLSR is configured administratively up on the
     *  given interface.
     */
    virtual XrlCmdError olsr4_0_1_get_binding_enabled(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	// Output values,
	bool&	enabled) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Change the UDP address and port where OLSR listens for control traffic
     *  on this interface. In order to do this the process must tell the FEA to
     *  tear down and re-bind the control traffic socket.
     *
     *  @param ifname the name of the interface.
     *
     *  @param vifname the name of the vif.
     *
     *  @param local_addr the new local IPv4 address.
     *
     *  @param local_port the new local port number.
     */
    virtual XrlCmdError olsr4_0_1_change_local_addr_port(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	local_addr,
	const uint32_t&	local_port) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Change the address where OLSR sends control traffic on the given
     *  interface. By default OLSR will attempt to use the all-ones broadcast
     *  address. Currently multicast addresses are NOT supported.
     *
     *  @param ifname the name of the interface.
     *
     *  @param vifname the name of the vif.
     *
     *  @param all_nodes_addr the address to use.
     *
     *  @param all_nodes_port the port to use.
     */
    virtual XrlCmdError olsr4_0_1_change_all_nodes_addr_port(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const IPv4&	all_nodes_addr,
	const uint32_t&	all_nodes_port) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of interfaces currently configured for OLSR. Return a list
     *  of u32 type values. Each value is an internal ID that can be used with
     *  the get_interface_info XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_interface_list(
	// Output values,
	XrlAtomList&	interfaces) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the per-interface information for the given interface.
     *
     *  @param faceid interface ID returned by get_interface_list.
     *
     *  @param ifname the name of the interface.
     *
     *  @param vifname the name of the vif.
     *
     *  @param local_addr the IPv4 address where OLSR is listening.
     *
     *  @param local_port the UDP port where OLSR is listening.
     *
     *  @param all_nodes_addr the IPv4 address where OLSR sends packets.
     *
     *  @param all_nodes_port the UDP port where OLSR sends packets.
     */
    virtual XrlCmdError olsr4_0_1_get_interface_info(
	// Input values,
	const uint32_t&	faceid,
	// Output values,
	string&	ifname,
	string&	vifname,
	IPv4&	local_addr,
	uint32_t&	local_port,
	IPv4&	all_nodes_addr,
	uint32_t&	all_nodes_port) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Set the edge cost of an interface/vif.
     *
     *  @param ifname the name of the interface.
     *
     *  @param vifname the name of the vif.
     *
     *  @param cost the new edge cost of the interface.
     */
    virtual XrlCmdError olsr4_0_1_set_interface_cost(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	const uint32_t&	cost) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the per-interface statistics for the given interface.
     *
     *  @param ifname the interface to query.
     *
     *  @param vifname the vif to qurery
     *
     *  @param bad_packets the number of bad packets received.
     *
     *  @param bad_messages the number of bad messages received.
     *
     *  @param messages_from_self the number of messages which appeared to be
     *  from our own main address.
     *
     *  @param unknown_messages the number of messages which could not be
     *  decoded.
     *
     *  @param duplicates the number of messages which appeared to be
     *  duplicates, according to histogram based duplicate detection.
     *
     *  @param forwarded the number of messages which have been forwarded to
     *  the rest of the OLSR topology on this interface.
     */
    virtual XrlCmdError olsr4_0_1_get_interface_stats(
	// Input values,
	const string&	ifname,
	const string&	vifname,
	// Output values,
	uint32_t&	bad_packets,
	uint32_t&	bad_messages,
	uint32_t&	messages_from_self,
	uint32_t&	unknown_messages,
	uint32_t&	duplicates,
	uint32_t&	forwarded) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of one-hop links. Return a list of u32 type values. Each
     *  value is an internal ID that can be used with the get_link_info XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_link_list(
	// Output values,
	XrlAtomList&	links) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information for a one-hop link. TODO: Add ETX support.
     *
     *  @param linkid Link entry ID returned by get_link_list.
     *
     *  @param local_addr the interface address of the local end of this link.
     *
     *  @param remote_addr the interface address of the remote end of this
     *  link.
     *
     *  @param main_addr the main address of the neighbor at the remote end of
     *  this link.
     *
     *  @param link_type the type of this link.
     *
     *  @param sym_time the time in seconds for which this link will be
     *  considered symmetric.
     *
     *  @param asym_time the time in seconds for which this link will be
     *  considered asymmetric.
     *
     *  @param hold_time the time in seconds until this link expires.
     */
    virtual XrlCmdError olsr4_0_1_get_link_info(
	// Input values,
	const uint32_t&	linkid,
	// Output values,
	IPv4&	local_addr,
	IPv4&	remote_addr,
	IPv4&	main_addr,
	uint32_t&	link_type,
	uint32_t&	sym_time,
	uint32_t&	asym_time,
	uint32_t&	hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of one-hop neighbors. Return a list of u32 type values.
     *  Each value is an internal ID that can be used with the
     *  get_neighbor_info XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_neighbor_list(
	// Output values,
	XrlAtomList&	neighbors) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information for a one-hop neighbor.
     *
     *  @param nid Neighbor entry ID returned by get_neighbor_list.
     *
     *  @param main_addr the main address of this neighbor.
     *
     *  @param willingness the willingness of this neighbor to forward.
     *
     *  @param degree the number of symmetric strict neighbors of this
     *  neighbor, excluding one-hop neighbors and this node.
     *
     *  @param link_count the number of links to this neighbor.
     *
     *  @param twohop_link_count the number of two-hop links which transit this
     *  neighbor as next-hop.
     *
     *  @param is_advertised true if this neighbor is in the Advertised
     *  Neighbor Set of this node.
     *
     *  @param is_sym true if this neighbor is symmetric.
     *
     *  @param is_mpr true if this neighbor is selected as an MPR by this node.
     *
     *  @param is_mpr_selector true if this neighbor chooses this node as an
     *  MPR.
     */
    virtual XrlCmdError olsr4_0_1_get_neighbor_info(
	// Input values,
	const uint32_t&	nid,
	// Output values,
	IPv4&	main_addr,
	uint32_t&	willingness,
	uint32_t&	degree,
	uint32_t&	link_count,
	uint32_t&	twohop_link_count,
	bool&	is_advertised,
	bool&	is_sym,
	bool&	is_mpr,
	bool&	is_mpr_selector) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of two-hop links. Return a list of u32 type values. Each
     *  value is an internal ID that can be used with the get_twohop_link_info
     *  XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_twohop_link_list(
	// Output values,
	XrlAtomList&	twohop_links) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information for a two-hop link. TODO: Add ETX support.
     *
     *  @param tlid two-hop link ID returned by get_twohop_link_list.
     *
     *  @param last_face_id the internal interface ID where advertisement of
     *  this two-hop link was last seen.
     *
     *  @param nexthop_addr the main address of the one-hop neighbor where this
     *  two-hop link exists.
     *
     *  @param dest_addr the main address of the two-hop neighbor at the remote
     *  end of this link.
     *
     *  @param hold_time the time in seconds until this two-hop link expires.
     */
    virtual XrlCmdError olsr4_0_1_get_twohop_link_info(
	// Input values,
	const uint32_t&	tlid,
	// Output values,
	uint32_t&	last_face_id,
	IPv4&	nexthop_addr,
	IPv4&	dest_addr,
	uint32_t&	hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of two-hop neighbors. Return a list of u32 type values.
     *  Each value is an internal ID that can be used with the
     *  get_twohop_neighbor_info XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_twohop_neighbor_list(
	// Output values,
	XrlAtomList&	twohop_neighbors) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information for a two-hop neighbor.
     *
     *  @param tnid two-hop neighbor ID returned by get_twohop_neighbor_list.
     *
     *  @param main_addr the main address of this two-hop neighbor.
     *
     *  @param is_strict true if this two-hop neighbor is not also a two-hop
     *  neighbor.
     *
     *  @param link_count the number of two-hop links that exist to this
     *  two-hop neighbor.
     *
     *  @param reachability the number of MPR candidates which cover this
     *  two-hop neighbor.
     *
     *  @param coverage the number of selected MPRs which cover this two-hop
     *  neighbor.
     */
    virtual XrlCmdError olsr4_0_1_get_twohop_neighbor_info(
	// Input values,
	const uint32_t&	tnid,
	// Output values,
	IPv4&	main_addr,
	bool&	is_strict,
	uint32_t&	link_count,
	uint32_t&	reachability,
	uint32_t&	coverage) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of learned Multiple Interface Declaration (MID) entries.
     *  Return a list of u32 type values. Each value is an internal ID that can
     *  be used with the get_mid_entry XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_mid_entry_list(
	// Output values,
	XrlAtomList&	mid_entries) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information contained in a MID entry.
     *
     *  @param midid MID entry ID returned by get_mid_entry_list.
     *
     *  @param main_addr the main address of the OLSR node
     *
     *  @param iface_addr the interface address being advertised.
     *
     *  @param distance the distance measured between this node and the origin
     *  of the MID packet containing this entry.
     *
     *  @param hold_time the time in seconds until this entry expires.
     */
    virtual XrlCmdError olsr4_0_1_get_mid_entry(
	// Input values,
	const uint32_t&	midid,
	// Output values,
	IPv4&	main_addr,
	IPv4&	iface_addr,
	uint32_t&	distance,
	uint32_t&	hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of learned Topology Control (TC) entries. Return a list of
     *  u32 type values. Each value is an internal ID that can be used with the
     *  get_tc_entry XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_tc_entry_list(
	// Output values,
	XrlAtomList&	tc_entries) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information contained in a TC entry.
     *
     *  @param tcid TC entry ID returned by get_tc_entry_list.
     *
     *  @param destination the main address of the advertised destination.
     *
     *  @param lasthop the main address of the node advertising this entry.
     *
     *  @param distance the distance measured between this node and the origin
     *  of the TC packet containing this entry.
     *
     *  @param seqno the advertised sequence number of this entry.
     *
     *  @param hold_time the time in seconds until this entry expires.
     */
    virtual XrlCmdError olsr4_0_1_get_tc_entry(
	// Input values,
	const uint32_t&	tcid,
	// Output values,
	IPv4&	destination,
	IPv4&	lasthop,
	uint32_t&	distance,
	uint32_t&	seqno,
	uint32_t&	hold_time) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the list of learned external route (HNA) entries. Return a list of
     *  u32 type values. Each value is an internal ID that can be used with the
     *  get_hna_entry XRL.
     */
    virtual XrlCmdError olsr4_0_1_get_hna_entry_list(
	// Output values,
	XrlAtomList&	hna_entries) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Get the information contained in a HNA entry.
     *
     *  @param hnaid HNA entry ID returned by get_hna_entry_list.
     *
     *  @param destination the main address of the advertised destination.
     *
     *  @param lasthop the main address of the node advertising this entry.
     *
     *  @param distance the distance measured between this node and the origin
     *  of the TC packet containing this entry.
     *
     *  @param hold_time the time in seconds until this entry expires.
     */
    virtual XrlCmdError olsr4_0_1_get_hna_entry(
	// Input values,
	const uint32_t&	hnaid,
	// Output values,
	IPv4Net&	destination,
	IPv4&	lasthop,
	uint32_t&	distance,
	uint32_t&	hold_time) = 0;

private:
    const XrlCmdError handle_common_0_1_get_target_name(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_version(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_get_status(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_common_0_1_shutdown(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_birth(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_finder_event_observer_0_1_xrl_target_death(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_recv_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_inbound_connect_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_outgoing_connect_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_error_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_socket4_user_0_1_disconnect_event(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_configure(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_reset(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_backend_0_1_push_routes(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_redist4_0_1_add_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_policy_redist4_0_1_delete_route4(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_enable(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_disable(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_get_entries(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_clear(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_profile_0_1_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_trace(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_clear_database(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_willingness(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_willingness(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_mpr_coverage(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_mpr_coverage(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_tc_redundancy(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_tc_redundancy(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_tc_fisheye(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_tc_fisheye(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_hna_base_cost(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_hna_base_cost(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_hello_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_hello_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_refresh_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_refresh_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_tc_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_tc_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_mid_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_mid_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_hna_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_hna_interval(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_dup_hold_time(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_dup_hold_time(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_main_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_main_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_bind_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_unbind_address(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_binding_enabled(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_binding_enabled(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_change_local_addr_port(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_change_all_nodes_addr_port(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_interface_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_interface_info(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_set_interface_cost(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_interface_stats(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_link_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_link_info(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_neighbor_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_neighbor_info(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_twohop_link_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_twohop_link_info(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_twohop_neighbor_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_twohop_neighbor_info(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_mid_entry_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_mid_entry(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_tc_entry_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_tc_entry(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_hna_entry_list(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_olsr4_0_1_get_hna_entry(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif // __XRL_TARGETS_OLSR4_BASE_HH__

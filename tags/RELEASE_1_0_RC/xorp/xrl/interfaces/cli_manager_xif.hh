/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/cli_manager_xif.hh,v 1.12 2004/05/24 17:35:33 hodson Exp $
 */

#ifndef __XRL_INTERFACES_CLI_MANAGER_XIF_HH__
#define __XRL_INTERFACES_CLI_MANAGER_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifCliManager"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlCliManagerV0p1Client {
public:
    XrlCliManagerV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlCliManagerV0p1Client() {}

    typedef XorpCallback1<void, const XrlError&>::RefPtr EnableCliCB;
    /**
     *  Send Xrl intended to:
     *
     *  Enable/disable/start/stop the CLI.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param enable if true, then enable the CLI, otherwise disable it.
     */
    bool send_enable_cli(
	const char*	target_name,
	const bool&	enable,
	const EnableCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StartCliCB;

    bool send_start_cli(
	const char*	target_name,
	const StartCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr StopCliCB;

    bool send_stop_cli(
	const char*	target_name,
	const StopCliCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddEnableCliAccessFromSubnet4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add a subnet address to the list of subnet addresses enabled for CLI
     *  access. This method can be called more than once to add a number of
     *  subnet addresses.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param subnet_addr the subnet address to add.
     */
    bool send_add_enable_cli_access_from_subnet4(
	const char*	target_name,
	const IPv4Net&	subnet_addr,
	const AddEnableCliAccessFromSubnet4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddEnableCliAccessFromSubnet6CB;

    bool send_add_enable_cli_access_from_subnet6(
	const char*	target_name,
	const IPv6Net&	subnet_addr,
	const AddEnableCliAccessFromSubnet6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteEnableCliAccessFromSubnet4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete a subnet address from the list of subnet addresses enabled for
     *  CLI access.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param subnet_addr the subnet address to delete.
     */
    bool send_delete_enable_cli_access_from_subnet4(
	const char*	target_name,
	const IPv4Net&	subnet_addr,
	const DeleteEnableCliAccessFromSubnet4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteEnableCliAccessFromSubnet6CB;

    bool send_delete_enable_cli_access_from_subnet6(
	const char*	target_name,
	const IPv6Net&	subnet_addr,
	const DeleteEnableCliAccessFromSubnet6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddDisableCliAccessFromSubnet4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Add a subnet address to the list of subnet addresses disabled for CLI
     *  access. This method can be called more than once to add a number of
     *  subnet addresses.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param subnet_addr the subnet address to add.
     */
    bool send_add_disable_cli_access_from_subnet4(
	const char*	target_name,
	const IPv4Net&	subnet_addr,
	const AddDisableCliAccessFromSubnet4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddDisableCliAccessFromSubnet6CB;

    bool send_add_disable_cli_access_from_subnet6(
	const char*	target_name,
	const IPv6Net&	subnet_addr,
	const AddDisableCliAccessFromSubnet6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteDisableCliAccessFromSubnet4CB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete a subnet address from the list of subnet addresses disabled for
     *  CLI access.
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param subnet_addr the subnet address to delete.
     */
    bool send_delete_disable_cli_access_from_subnet4(
	const char*	target_name,
	const IPv4Net&	subnet_addr,
	const DeleteDisableCliAccessFromSubnet4CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteDisableCliAccessFromSubnet6CB;

    bool send_delete_disable_cli_access_from_subnet6(
	const char*	target_name,
	const IPv6Net&	subnet_addr,
	const DeleteDisableCliAccessFromSubnet6CB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr AddCliCommandCB;
    /**
     *  Send Xrl intended to:
     *
     *  Add a CLI command to the CLI manager
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param processor_name the name of the module that will process that
     *  command.
     *
     *  @param command_name the name of the command to add.
     *
     *  @param command_help the help for the command to add.
     *
     *  @param is_command_cd is true, the string that will replace the CLI
     *  prompt after we "cd" to that level of the CLI command-tree.
     *
     *  @param command_cd_prompt if
     *
     *  @param is_command_processor if true, this is a processing command that
     *  would be performed by processor_name.
     */
    bool send_add_cli_command(
	const char*	target_name,
	const string&	processor_name,
	const string&	command_name,
	const string&	command_help,
	const bool&	is_command_cd,
	const string&	command_cd_prompt,
	const bool&	is_command_processor,
	const AddCliCommandCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr DeleteCliCommandCB;
    /**
     *  Send Xrl intended to:
     *
     *  Delete a CLI command from the CLI manager
     *
     *  @param tgt_name Xrl Target name
     *
     *  @param processor_name the name of the module that sends the request.
     *
     *  @param command_name the name of the command to delete.
     */
    bool send_delete_cli_command(
	const char*	target_name,
	const string&	processor_name,
	const string&	command_name,
	const DeleteCliCommandCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_enable_cli(
	const XrlError&	e,
	XrlArgs*	a,
	EnableCliCB		cb
    );

    void unmarshall_start_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StartCliCB		cb
    );

    void unmarshall_stop_cli(
	const XrlError&	e,
	XrlArgs*	a,
	StopCliCB		cb
    );

    void unmarshall_add_enable_cli_access_from_subnet4(
	const XrlError&	e,
	XrlArgs*	a,
	AddEnableCliAccessFromSubnet4CB		cb
    );

    void unmarshall_add_enable_cli_access_from_subnet6(
	const XrlError&	e,
	XrlArgs*	a,
	AddEnableCliAccessFromSubnet6CB		cb
    );

    void unmarshall_delete_enable_cli_access_from_subnet4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEnableCliAccessFromSubnet4CB		cb
    );

    void unmarshall_delete_enable_cli_access_from_subnet6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteEnableCliAccessFromSubnet6CB		cb
    );

    void unmarshall_add_disable_cli_access_from_subnet4(
	const XrlError&	e,
	XrlArgs*	a,
	AddDisableCliAccessFromSubnet4CB		cb
    );

    void unmarshall_add_disable_cli_access_from_subnet6(
	const XrlError&	e,
	XrlArgs*	a,
	AddDisableCliAccessFromSubnet6CB		cb
    );

    void unmarshall_delete_disable_cli_access_from_subnet4(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteDisableCliAccessFromSubnet4CB		cb
    );

    void unmarshall_delete_disable_cli_access_from_subnet6(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteDisableCliAccessFromSubnet6CB		cb
    );

    void unmarshall_add_cli_command(
	const XrlError&	e,
	XrlArgs*	a,
	AddCliCommandCB		cb
    );

    void unmarshall_delete_cli_command(
	const XrlError&	e,
	XrlArgs*	a,
	DeleteCliCommandCB		cb
    );

};

#endif /* __XRL_INTERFACES_CLI_MANAGER_XIF_HH__ */

// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2003 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/mld6igmp/mld6igmp_node_cli.cc,v 1.4 2003/03/10 23:20:42 hodson Exp $"


//
// MLD6IGMP protocol CLI implementation
//


#include "mld6igmp_module.h"
#include "mld6igmp_private.hh"
#include "mld6igmp_member_query.hh"
#include "mld6igmp_node.hh"
#include "mld6igmp_node_cli.hh"
#include "mld6igmp_vif.hh"


//
// Exported variables
//

//
// Local constants definitions
//

//
// Local structures/classes, typedefs and macros
//

//
// Local variables
//

//
// Local functions prototypes
//



/**
 * Mld6igmpNodeCli::Mld6igmpNodeCli:
 * @mld6igmp_node: The MLD6IGMP node to use.
 * 
 * Mld6igmpNodeCli constructor.
 **/
Mld6igmpNodeCli::Mld6igmpNodeCli(Mld6igmpNode& mld6igmp_node)
    : ProtoNodeCli(mld6igmp_node.family(), mld6igmp_node.module_id()),
      _mld6igmp_node(mld6igmp_node)
{

}

Mld6igmpNodeCli::~Mld6igmpNodeCli()
{
    stop();
}

int
Mld6igmpNodeCli::start()
{
    if (add_all_cli_commands() < 0)
	return (XORP_ERROR);
    
    return (XORP_OK);
}

int
Mld6igmpNodeCli::stop()
{
    int ret_code = XORP_OK;
    
    if (delete_all_cli_commands() < 0)
	ret_code = XORP_ERROR;
    
    return (ret_code);
}

int
Mld6igmpNodeCli::add_all_cli_commands()
{
    // XXX: command "show" must have been installed by the CLI itself.
    
    if (mld6igmp_node().proto_is_igmp()) {
	add_cli_dir_command("show igmp", "Display information about IGMP");
	
	add_cli_command("show igmp group",
			"Display information about IGMP group membership",
			callback(this, &Mld6igmpNodeCli::cli_show_mld6igmp_group));
	add_cli_command("show igmp interface",
			"Display information about IGMP configured interfaces",
			callback(this, &Mld6igmpNodeCli::cli_show_mld6igmp_interface));
    }

    if (mld6igmp_node().proto_is_mld6()) {
	add_cli_dir_command("show mld", "Display information about MLD");
	
	add_cli_command("show mld group",
			"Display information about MLD group membership",
			callback(this, &Mld6igmpNodeCli::cli_show_mld6igmp_group));
	add_cli_command("show mld interface",
			"Display information about MLD configured interfaces",
			callback(this, &Mld6igmpNodeCli::cli_show_mld6igmp_interface));
    }
    
    return (XORP_OK);
}

//
// CLI COMMAND: "show mld interface [interface-name]"
// CLI COMMAND: "show igmp interface [interface-name]"
//
// Display information about the interfaces on which MLD/IGMP is configured.
//
int
Mld6igmpNodeCli::cli_show_mld6igmp_interface(const vector<string>& argv)
{
    string interface_name;
    
    // Check the optional argument
    if (argv.size()) {
	interface_name = argv[0];
	if (mld6igmp_node().vif_find_by_name(interface_name.c_str()) == NULL) {
	    cli_print(c_format("ERROR: Invalid interface name: %s\n",
			       interface_name.c_str()));
	    return (XORP_ERROR);
	}
    }
    
    cli_print(c_format("%-16s%-9s%-16s%8s%8s%8s\n",
		       "Interface", "State", "Querier",
		       "Timeout", "Version", "Groups"));
    for (uint16_t i = 0; i < mld6igmp_node().maxvifs(); i++) {
	Mld6igmpVif *mld6igmp_vif = mld6igmp_node().vif_find_by_vif_index(i);
	if (mld6igmp_vif == NULL)
	    continue;
	// Test if we should print this entry
	bool do_print = true;
	if (interface_name.size()) {
	    do_print = false;
	    if (mld6igmp_vif->name() == interface_name) {
		do_print = true;
	    }
	}
	if (! do_print)
	    continue;
	string querier_timeout_sec_string;
	if (mld6igmp_vif->const_other_querier_timer().is_set()) {
	    querier_timeout_sec_string = c_format(
		"%d",
		mld6igmp_vif->const_other_querier_timer().left_sec());
	} else {
	    querier_timeout_sec_string = "None";
	}
	
	cli_print(c_format("%-16s%-9s%-16s%8s%8d%8u\n",
			   mld6igmp_vif->name().c_str(),
			   mld6igmp_vif->state_string(),
			   cstring(mld6igmp_vif->querier_addr()),
			   querier_timeout_sec_string.c_str(),
			   mld6igmp_vif->proto_version(),
			   (uint32_t)mld6igmp_vif->members().size()));
    }
    
    return (XORP_OK);
}

//
// CLI COMMAND: "show mld group [group-name [...]]"
// CLI COMMAND: "show igmp group [group-name [...]]"
//
// Display information about MLD/IGMP group membership.
//
int
Mld6igmpNodeCli::cli_show_mld6igmp_group(const vector<string>& argv)
{
    vector<IPvX> groups;
    
    // Check the (optional) arguments, and create an array of groups to test
    for (size_t i = 0; i < argv.size(); i++) {
	try {
	    IPvX g(argv[i].c_str());
	    if (g.af() != family()) {
		cli_print(c_format("ERROR: Address with invalid address family: %s\n", argv[i].c_str()));
		return (XORP_ERROR);
	    }
	    if (! g.is_multicast()) {
		cli_print(c_format("ERROR: Not a multicast address: %s\n",
				   argv[i].c_str()));
		return (XORP_ERROR);
	    }
	    groups.push_back(g);
	} catch (InvalidString) {
	    cli_print(c_format("ERROR: Invalid IP address: %s\n",
			       argv[i].c_str()));
	    return (XORP_ERROR);
	}
    }
    
    cli_print(c_format("%-16s%-16s%-16s%-16s%8s\n",
		       "Interface", "Group", "Source",
		       "Last Reported", "Timeout"));
    for (uint16_t i = 0; i < mld6igmp_node().maxvifs(); i++) {
	const Mld6igmpVif *mld6igmp_vif = mld6igmp_node().vif_find_by_vif_index(i);
	if (mld6igmp_vif == NULL)
	    continue;
	list<MemberQuery *>::const_iterator iter;
	for (iter = mld6igmp_vif->members().begin();
	     iter != mld6igmp_vif->members().end();
	     ++iter) {
	    MemberQuery *member_query = *iter;
	    // Test if we should print this entry
	    bool do_print = true;
	    if (groups.size()) {
		do_print = false;
		for (size_t j = 0; j < groups.size(); j++) {
		    if (groups[j] == member_query->group()) {
			do_print = true;
			break;
		    }
		}
	    }
	    if (! do_print)
		continue;
	    
	    cli_print(c_format("%-16s%-16s%-16s%-16s%8d\n",
			       mld6igmp_vif->name().c_str(),
			       cstring(member_query->group()),
			       cstring(member_query->source()),
			       cstring(member_query->last_reported_host()),
			       member_query->timeout_sec()));
	}
    }
    
    return (XORP_OK);
}


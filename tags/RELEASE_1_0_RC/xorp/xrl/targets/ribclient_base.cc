/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 */

#ident "$XORP: xorp/xrl/targets/ribclient_base.cc,v 1.10 2004/05/24 17:35:44 hodson Exp $"


#include "ribclient_base.hh"


XrlRibclientTargetBase::XrlRibclientTargetBase(XrlCmdMap* cmds)
    : _cmds(cmds)
{
    if (_cmds)
	add_handlers();
}

XrlRibclientTargetBase::~XrlRibclientTargetBase()
{
    if (_cmds)
	remove_handlers();
}

bool
XrlRibclientTargetBase::set_command_map(XrlCmdMap* cmds)
{
    if (_cmds == 0 && cmds) {
        _cmds = cmds;
        add_handlers();
        return true;
    }
    if (_cmds && cmds == 0) {
	remove_handlers();
        _cmds = cmds;
        return true;
    }
    return false;
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            6, (uint32_t)xa_inputs.size(), "rib_client/0.1/route_info_changed4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed4(
	    xa_inputs.get_ipv4("addr"),
	    xa_inputs.get_uint32("prefix_len"),
	    xa_inputs.get_ipv4("nexthop"),
	    xa_inputs.get_uint32("metric"),
	    xa_inputs.get_uint32("admin_distance"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_changed4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 6) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            6, (uint32_t)xa_inputs.size(), "rib_client/0.1/route_info_changed6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_changed6(
	    xa_inputs.get_ipv6("addr"),
	    xa_inputs.get_uint32("prefix_len"),
	    xa_inputs.get_ipv6("nexthop"),
	    xa_inputs.get_uint32("metric"),
	    xa_inputs.get_uint32("admin_distance"),
	    xa_inputs.get_string("protocol_origin"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_changed6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid4(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            2, (uint32_t)xa_inputs.size(), "rib_client/0.1/route_info_invalid4");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid4(
	    xa_inputs.get_ipv4("addr"),
	    xa_inputs.get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_invalid4", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

const XrlCmdError
XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid6(const XrlArgs& xa_inputs, XrlArgs* /* pxa_outputs */)
{
    if (xa_inputs.size() != 2) {
	XLOG_ERROR("Wrong number of arguments (%u != %u) handling %s",
            2, (uint32_t)xa_inputs.size(), "rib_client/0.1/route_info_invalid6");
	return XrlCmdError::BAD_ARGS();
    }

    /* Return value declarations */
    try {
	XrlCmdError e = rib_client_0_1_route_info_invalid6(
	    xa_inputs.get_ipv6("addr"),
	    xa_inputs.get_uint32("prefix_len"));
	if (e != XrlCmdError::OKAY()) {
	    XLOG_WARNING("Handling method for %s failed: %s",
            		 "rib_client/0.1/route_info_invalid6", e.str().c_str());
	    return e;
        }
    } catch (const XrlArgs::XrlAtomNotFound& e) {
	XLOG_ERROR("Argument not found");
	return XrlCmdError::BAD_ARGS();
    }
    return XrlCmdError::OKAY();
}

void
XrlRibclientTargetBase::add_handlers()
{
	if (_cmds->add_handler("rib_client/0.1/route_info_changed4",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_changed4");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_changed6",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_changed6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_changed6");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_invalid4",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid4)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_invalid4");
	}
	if (_cmds->add_handler("rib_client/0.1/route_info_invalid6",
	    callback(this, &XrlRibclientTargetBase::handle_rib_client_0_1_route_info_invalid6)) == false) {
	    XLOG_ERROR("Failed to xrl handler finder://%s/%s", "ribclient", "rib_client/0.1/route_info_invalid6");
	}
	_cmds->finalize();
}

void
XrlRibclientTargetBase::remove_handlers()
{
	_cmds->remove_handler("rib_client/0.1/route_info_changed4");
	_cmds->remove_handler("rib_client/0.1/route_info_changed6");
	_cmds->remove_handler("rib_client/0.1/route_info_invalid4");
	_cmds->remove_handler("rib_client/0.1/route_info_invalid6");
}

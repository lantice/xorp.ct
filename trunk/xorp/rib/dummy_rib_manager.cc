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

#ident "$XORP: xorp/rib/dummy_rib_manager.cc,v 1.2 2003/09/27 22:49:32 mjh Exp $"

#include "rib_module.h"
#include "libxorp/xorp.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/utils.hh"
#include "dummy_rib_manager.hh"

RibManager::RibManager()
{
}

RibManager::~RibManager()
{
}

int
RibManager::start()
{
    return XORP_OK;
}

int
RibManager::stop()
{
    return XORP_OK;
}

ProcessStatus 
RibManager::status(string&) const
{
    return PROC_READY;
}

void 
RibManager::register_interest_in_target(const string& tgt_class)
{
    UNUSED(tgt_class);
}

int 
RibManager::new_vif(const string& vifname, const Vif& vif, string& err)
{
    UNUSED(vifname);
    UNUSED(vif);
    UNUSED(err);
    return XORP_OK;
}

int 
RibManager::delete_vif(const string& vifname, string& err)
{
    UNUSED(vifname);
    UNUSED(err);
    return XORP_OK;
}

int 
RibManager::add_vif_address(const string& vifname, 
			    const IPv4& addr,
			    const IPNet<IPv4>& net,
			    string& err)
{
    UNUSED(vifname);
    UNUSED(addr);
    UNUSED(net);
    UNUSED(err);
    return XORP_OK;
}

int 
RibManager::add_vif_address(const string& vifname, 
			    const IPv6& addr,
			    const IPNet<IPv6>& net,
			    string& err)
{
    UNUSED(vifname);
    UNUSED(addr);
    UNUSED(net);
    UNUSED(err);
    return XORP_OK;
}

int 
RibManager::delete_vif_address(const string& vifname, 
			       const IPv4& addr,
			       string& err)
{
    UNUSED(vifname);
    UNUSED(addr);
    UNUSED(err);
    return XORP_OK;
}

int 
RibManager::delete_vif_address(const string& vifname, 
			       const IPv6& addr,
			       string& err)
{
    UNUSED(vifname);
    UNUSED(addr);
    UNUSED(err);
    return XORP_OK;
}

void 
RibManager::make_errors_fatal()
{
}

int 
RibManager::no_fea()
{
    return XORP_OK;
}

int 
RibManager::add_rib_client(const string&, int,
			   bool, bool)
{
    return XORP_OK;
}

int 
RibManager::delete_rib_client(const string&, int,
			      bool, bool)
{
    return XORP_OK;
}

int 
RibManager::enable_rib_client(const string&, int,
			      bool, bool)
{
    return XORP_OK;
}

int 
RibManager::disable_rib_client(const string&, int,
			       bool, bool)
{
    return XORP_OK;
}

void 
RibManager::target_death(const string&, const string&)
{
}

/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'tgt-gen'.
 *
 * $XORP: xorp/xrl/targets/test_fea_ifmgr_mirror_base.hh,v 1.3 2004/05/24 17:35:45 hodson Exp $
 */


#ifndef __XRL_INTERFACES_TEST_FEA_IFMGR_MIRROR_BASE_HH__
#define __XRL_INTERFACES_TEST_FEA_IFMGR_MIRROR_BASE_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XrlTestFeaIfmgrMirrorTarget"

#include "libxorp/xlog.h"
#include "libxipc/xrl_cmd_map.hh"

class XrlTestFeaIfmgrMirrorTargetBase {
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
    XrlTestFeaIfmgrMirrorTargetBase(XrlCmdMap* cmds = 0);

    /**
     * Destructor.
     *
     * Dissociates instance commands from command map.
     */
    virtual ~XrlTestFeaIfmgrMirrorTargetBase();

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
    inline const string& name() const { return _cmds->name(); }

    /**
     * Get version string of instance.
     */
    inline const char* version() const { return "test_fea_ifmgr_mirror/0.0"; }

protected:

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Register remote mirror of interface state.
     */
    virtual XrlCmdError ifmgr_replicator_0_1_register_ifmgr_mirror(
	// Input values,
	const string&	clientname) = 0;

    /**
     *  Pure-virtual function that needs to be implemented to:
     *
     *  Register remote mirror of interface state.
     */
    virtual XrlCmdError ifmgr_replicator_0_1_unregister_ifmgr_mirror(
	// Input values,
	const string&	clientname) = 0;

private:
    const XrlCmdError handle_ifmgr_replicator_0_1_register_ifmgr_mirror(const XrlArgs& in, XrlArgs* out);

    const XrlCmdError handle_ifmgr_replicator_0_1_unregister_ifmgr_mirror(const XrlArgs& in, XrlArgs* out);

    void add_handlers();
    void remove_handlers();
};

#endif /* __XRL_INTERFACES_TEST_FEA_IFMGR_MIRROR_BASE_HH__ */

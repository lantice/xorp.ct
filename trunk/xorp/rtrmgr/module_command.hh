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

// $XORP: xorp/rtrmgr/module_command.hh,v 1.5 2003/05/30 04:42:09 mjh Exp $

#ifndef __RTRMGR_MODULE_COMMAND_HH__
#define __RTRMGR_MODULE_COMMAND_HH__

#include "template_commands.hh"

class TaskManager;
class Validation;

class ModuleCommand : public Command {
public:
    typedef enum {NO_STATUS_METHOD, STATUS_BY_XRL} StatusMethod;
    typedef enum {NO_SHUTDOWN_METHOD, SHUTDOWN_BY_XRL} ShutdownMethod;
    ModuleCommand(const string &cmd_name, TemplateTree& ct);
    ~ModuleCommand() {}
    void add_action(const list <string> &action,
		    const XRLdb& xrldb) throw (ParseError);
    //    void set_path(const string &path);
    //    void set_depends(const string &depends);
    int  execute(TaskManager& taskmgr) const;
    Validation* startup_validation(TaskManager &taskmgr) const;
    Validation* ready_validation(TaskManager &taskmgr) const;

    bool execute_completed() const;
    
    const string& name() const {return _modname;}
    const string& path() const {return _modpath;}
    const list <string>& depends() const {return _depends;}
    int start_transaction(ConfigTreeNode& ctn,
			  TaskManager& task_manager) const;
    int end_transaction(ConfigTreeNode& ctn,
			TaskManager& task_manager) const;
    StatusMethod status_method() const { return _status_method;}
    ShutdownMethod shutdown_method() const { return _shutdown_method;}
    string str() const;

protected:
    void exec_complete(const XrlError& err, 
		       XrlArgs* xrlargs);

    void action_complete(const XrlError& err, 
			 XrlArgs* args,
			 ConfigTreeNode *ctn,
			 Action *action,
			 string cmd);

private:
    TemplateTree& _tt;
    string _modname;
    string _modpath;
    list <string> _depends;
    Action *_startcommit;
    Action *_endcommit;
    StatusMethod _status_method;
    ShutdownMethod _shutdown_method;
    bool _execute_done;
};

#endif

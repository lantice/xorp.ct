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

// $XORP: xorp/rtrmgr/cli.hh,v 1.3 2003/03/10 23:20:58 hodson Exp $

#ifndef __RTRMGR_CLI_HH__
#define __RTRMGR_CLI_HH__

#include <list>
#include <map>
#include "cli/cli_node.hh"
#include "cli/cli_client.hh"
#include "libxipc/xrl_error.hh"

class ConfigTree;
class SlaveConfigTree;
class ConfigTreeNode;
class SlaveConfigTreeNode;
class OpCommandList;

enum CliModeType {
    CLI_MODE_NONE = 0,
    CLI_MODE_OPERATIONAL = 1,
    CLI_MODE_CONFIGURE = 2,
    CLI_MODE_TEXTENTRY = 3
};

class CommandTreeNode;
class CommandTree;
class RouterCLI;
class XorpShell;
class XrlAtomList;

class RouterCLI {
public:
    RouterCLI::RouterCLI(XorpShell& xorpsh,
			 CliNode& cli_node);
    //    void add_command(const string& cmd);
    bool is_config_mode() const;
    void commit_done_by_user(int uid);
    void add_command_tree(const string& cmd, const CommandTree& tree);
    void clear_command_set();
    int configure_func(const char *,
		       const char *,
		       uint32_t,		
		       const char *command_global_name,
		       const vector<string>& argv);
    void enter_config_done(const XrlError& e);
    void got_config_users(const XrlError& e, const XrlAtomList* users);
    void new_config_user(uid_t user_id);
    void leave_config_done(const XrlError& e);
    void notify_user(const string& alert, bool urgent);
    int exit_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    int edit_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    int text_entry_func(const char *,
			const char *,
			uint32_t,		
			const char *command_global_name,
			const vector<string>& argv);
    int delete_func(const char *,
		    const char *,
		    uint32_t,		
		    const char *command_global_name,
		    const vector<string>& argv);
    int set_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    int immediate_set_func(const char *,
			   const char *,
			   uint32_t,		
			   const char *command_global_name,
			   const vector<string>& argv);
    int commit_func(const char *,
		    const char *,
		    uint32_t,		
		    const char *command_global_name,
		    const vector<string>& argv);
    void commit_done(int status, const string& err_msg);

    int show_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    int op_mode_func(const char *,
		     const char *,
		     uint32_t,		
		     const char *command_global_name,
		     const vector<string>& argv);
    int save_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    void save_done(const XrlError& e);
    int load_func(const char *,
		  const char *,
		  uint32_t,		
		  const char *command_global_name,
		  const vector<string>& argv);
    void load_communicated(const XrlError& e);
    void load_done(int status, const string& response);

    typedef XorpCallback2<void, bool, const string&>::RefPtr OpModeCallback;
    void op_mode_cmd_done(bool success, const string& result);

private:
    void reset_path();
    void set_path(string path);
    void apply_path_change();
    void add_static_configure_mode_commands();
    void set_prompt(const string& line1, 
		    const string& line2);
    void config_mode_prompt();
    void idle_ui();
    void reenable_ui();

    string pathstr() const;
    string pathstr2() const;
    void operational_mode();
    void add_op_mode_commands(CliCommand *root);
    void configure_mode();
    void text_entry_mode();
    void add_command_subtree(CliCommand *current_cli_node,
			     const CommandTreeNode *current_command_node,
			     const CLI_PROCESS_CALLBACK *cli_process_callback,
			     string path, int depth);
    void add_immediate_commands(CliCommand *current_cli_node,
				const CommandTreeNode *current_command_node,
				const list <string>& cmd_names,
				bool include_intermediates,
				const CLI_PROCESS_CALLBACK *cb,
				string path);
    void add_edit_subtree();
    void add_delete_subtree();
    void add_set_subtree();
    void add_show_subtree();

    void display_config_mode_users() const;
    void display_alerts();

    string run_set_command(string path,  const vector<string>& argv);

    void check_for_rtrmgr_restart();
    void verify_rtrmgr_restart(const XrlError& e, const uint32_t* pid);

    SlaveConfigTree* config_tree();
    OpCommandList* op_cmd_list();

    XorpShell& _xorpsh;

    SlaveConfigTreeNode *_current_config_node;

    CliNode& _cli_node;
    CliClient& _cli_client;
    CliModeType _mode;
    CliCommand *_set_node;
    CliCommand *_show_node;
    CliCommand *_edit_node;
    CliCommand *_delete_node;
    CliCommand *_run_node;
    list <string> _path;
    list <uint32_t> _config_mode_users;
    list <string> _alerts;
    int _nesting_depth; /* for text_entry mode: number of brackets deep */
    bool _changes_made; /* indicates there are uncommitted changes */
};

#endif // __RTRMGR_CLI_HH__

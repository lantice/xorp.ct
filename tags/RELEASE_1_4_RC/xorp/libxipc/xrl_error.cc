// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2007 International Computer Science Institute
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

#ident "$XORP: xorp/libxipc/xrl_error.cc,v 1.12 2006/10/12 01:24:49 pavlin Exp $"

#include "xrl_module.h"

#include "libxorp/xorp.h"
#include "libxorp/c_format.hh"

#include "xrl_error.hh"


class XrlErrlet {
public:
    XrlErrlet(XrlErrorCode n, const char *s) : _error_code(n), _error_msg(s)
    {
	if (find(n)) abort(); // programming error, definitely
	_next = _errlet_head; // plumb in entry
	_errlet_head = this;
    }

    static const XrlErrlet* find(uint32_t error_code) {
	for (const XrlErrlet* e = _errlet_head; e != 0; e = e->_next) {
	    if (e->_error_code == XrlErrorCode(error_code)) return e;
	}
	return 0;
    }

    inline XrlErrorCode error_code() const	{ return _error_code; }
    inline const char*  error_msg() const	{ return _error_msg; }

protected:
    XrlErrorCode _error_code;
    const char*  _error_msg;

    // Node for list of all known errlets
    XrlErrlet*	   _next;
    // Head pointer for all known errlets
    static XrlErrlet* _errlet_head;
};

XrlErrlet* XrlErrlet::_errlet_head = 0;

// Macro that glues together XrlErrlet and XrlError
#define XRL_ERROR_GLUE(ename, oname, reason)				      \
static const XrlErrlet ename(oname, reason); 				      \
static const XrlError E_##oname(&ename);				      \
const XrlError& XrlError::oname() { return E_##oname; }

// Dispatch Method Errors - generated by user callback
// NB BAD_ARGS and COMMAND_FAILED have additional magic at the end of this file
XRL_ERROR_GLUE(okay, OKAY, "Okay");
XRL_ERROR_GLUE(bad_args, BAD_ARGS, "Bad argument(s)");
XRL_ERROR_GLUE(command_failed, COMMAND_FAILED, "Command failed");

// Transport Errors - generated by transport library
XRL_ERROR_GLUE(resolve_failed, RESOLVE_FAILED, "Resolve failed");
XRL_ERROR_GLUE(no_finder, NO_FINDER, "Finder not present/ready");
XRL_ERROR_GLUE(no_such_method, NO_SUCH_METHOD, "No such method");

XRL_ERROR_GLUE(send_failed, SEND_FAILED, "Transport failed");
XRL_ERROR_GLUE(reply_timed_out, REPLY_TIMED_OUT, "Reply timed out");
XRL_ERROR_GLUE(send_failed_transient, SEND_FAILED_TRANSIENT, "Transient transport failure");

XRL_ERROR_GLUE(internal_error, INTERNAL_ERROR, "Internal error");

XrlError::XrlError() : _errlet(&okay) {}

XrlError::XrlError(const XrlErrlet* errlet) : _errlet(errlet) {}

XrlError::XrlError(XrlErrorCode errcode, const string& note)
    : _note(note)
{
    _errlet = XrlErrlet::find(errcode);
    if (_errlet == 0) {
	_errlet = &internal_error;
	_note = c_format("Errorcode %d unknown", errcode);
	if (note.empty() == false)
	    _note += " " + note;
    }
}

bool
XrlError::known_code(uint32_t errcode)
{
    return (XrlErrlet::find(errcode) != 0);
}

XrlErrorCode
XrlError::error_code() const
{
    return _errlet->error_code();
}

const char*
XrlError::error_msg() const
{
    return _errlet->error_msg();
}

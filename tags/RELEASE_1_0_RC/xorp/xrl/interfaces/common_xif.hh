/*
 * Copyright (c) 2001-2004 International Computer Science Institute
 * See LICENSE file for licensing, conditions, and warranties on use.
 *
 * DO NOT EDIT THIS FILE - IT IS PROGRAMMATICALLY GENERATED
 *
 * Generated by 'clnt-gen'.
 *
 * $XORP: xorp/xrl/interfaces/common_xif.hh,v 1.11 2004/05/24 17:35:33 hodson Exp $
 */

#ifndef __XRL_INTERFACES_COMMON_XIF_HH__
#define __XRL_INTERFACES_COMMON_XIF_HH__

#undef XORP_LIBRARY_NAME
#define XORP_LIBRARY_NAME "XifCommon"

#include "libxorp/xlog.h"
#include "libxorp/callback.hh"

#include "libxipc/xrl.hh"
#include "libxipc/xrl_error.hh"
#include "libxipc/xrl_sender.hh"


class XrlCommonV0p1Client {
public:
    XrlCommonV0p1Client(XrlSender* s) : _sender(s) {}
    virtual ~XrlCommonV0p1Client() {}

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr GetTargetNameCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get name of Xrl Target
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_target_name(
	const char*	target_name,
	const GetTargetNameCB&	cb
    );

    typedef XorpCallback2<void, const XrlError&, const string*>::RefPtr GetVersionCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get version string from Xrl Target
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_version(
	const char*	target_name,
	const GetVersionCB&	cb
    );

    typedef XorpCallback3<void, const XrlError&, const uint32_t*, const string*>::RefPtr GetStatusCB;
    /**
     *  Send Xrl intended to:
     *
     *  Get status of Xrl Target
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_get_status(
	const char*	target_name,
	const GetStatusCB&	cb
    );

    typedef XorpCallback1<void, const XrlError&>::RefPtr ShutdownCB;
    /**
     *  Send Xrl intended to:
     *
     *  Request clean shutdown of Xrl Target
     *
     *  @param tgt_name Xrl Target name
     */
    bool send_shutdown(
	const char*	target_name,
	const ShutdownCB&	cb
    );

protected:
    XrlSender* _sender;

private:
    void unmarshall_get_target_name(
	const XrlError&	e,
	XrlArgs*	a,
	GetTargetNameCB		cb
    );

    void unmarshall_get_version(
	const XrlError&	e,
	XrlArgs*	a,
	GetVersionCB		cb
    );

    void unmarshall_get_status(
	const XrlError&	e,
	XrlArgs*	a,
	GetStatusCB		cb
    );

    void unmarshall_shutdown(
	const XrlError&	e,
	XrlArgs*	a,
	ShutdownCB		cb
    );

};

#endif /* __XRL_INTERFACES_COMMON_XIF_HH__ */

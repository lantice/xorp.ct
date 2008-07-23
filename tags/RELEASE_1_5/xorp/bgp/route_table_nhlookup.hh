// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2008 XORP, Inc.
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

// $XORP: xorp/bgp/route_table_nhlookup.hh,v 1.17 2008/01/04 03:15:25 pavlin Exp $

#ifndef __BGP_ROUTE_TABLE_NHLOOKUP_HH__
#define __BGP_ROUTE_TABLE_NHLOOKUP_HH__

#include "route_table_base.hh"
#include "libxorp/ref_trie.hh"
#include "next_hop_resolver.hh"

template<class A>
class MessageQueueEntry {
public:
    MessageQueueEntry(const InternalMessage<A>* add_msg,
		      const InternalMessage<A>* delete_msg);
    MessageQueueEntry(const MessageQueueEntry& original);
    ~MessageQueueEntry();
    typedef enum op {
	ADD = 1,
	REPLACE = 2
    } Op;
    Op type() const {
	if (_add_msg!=NULL && _delete_msg==NULL) return ADD;
	if (_add_msg!=NULL && _delete_msg!=NULL) return REPLACE;
	abort();
    }
    const InternalMessage<A>* add_msg() const {return _add_msg;}
    const SubnetRoute<A>* added_route() const {return _add_msg->route();}

    const InternalMessage<A>* delete_msg() const {return _delete_msg;}
    const SubnetRoute<A>* deleted_route() const {return _delete_msg->route();}
    const IPNet<A>& net() const {return _add_msg->route()->net();}
    string str() const;
private:
    void copy_in(const InternalMessage<A>* add_msg,
		 const InternalMessage<A>* delete_msg);

    InternalMessage<A>* _add_msg;
    InternalMessage<A>* _delete_msg;

    //These references are to ensure that the SubnetRoutes from the
    //add and delete messages don't get deleted before we're done with
    //them.
    SubnetRouteConstRef<A> _added_route_ref;
    SubnetRouteConstRef<A> _deleted_route_ref;
};

template<class A>
class NhLookupTable : public BGPRouteTable<A>  {
public:
    NhLookupTable(string tablename,
		  Safi safi,
		  NextHopResolver<A> *nexthop_resolver,
		  BGPRouteTable<A> *parent);
    int add_route(const InternalMessage<A> &rtmsg,
		  BGPRouteTable<A> *caller);
    int replace_route(const InternalMessage<A> &old_rtmsg,
		      const InternalMessage<A> &new_rtmsg,
		      BGPRouteTable<A> *caller);
    int delete_route(const InternalMessage<A> &rtmsg, 
		     BGPRouteTable<A> *caller);
    int push(BGPRouteTable<A> *caller);
    const SubnetRoute<A> *lookup_route(const IPNet<A> &net,
				       uint32_t& genid) const;
    void route_used(const SubnetRoute<A>* route, bool in_use);
    
    virtual void RIB_lookup_done(const A& nexthop, 
			 const set <IPNet<A> >& nets,
			 bool lookup_succeeded);

    RouteTableType type() const {return NHLOOKUP_TABLE;}
    string str() const;
private:
    //access the message queue by subnet or an address on the subnet
    RefTrie<A, const MessageQueueEntry<A> > _queue_by_net;
    //access the message queue by nexthop
    multimap <A, const MessageQueueEntry<A>*> _queue_by_nexthop;

    NextHopResolver<A>* _next_hop_resolver;

    /**
     * Add the message queue entry to both queues.
     */
    void add_to_queue(const A& nexthop, const IPNet<A>& net,
		      const MessageQueueEntry<A> &mqe);

    /**
     * Lookup subnet in the _queue_by_net.
     *
     * @param nexthop if non zero compare against the net that is found.
     * @param net to lookup.
     * @return a message queue entry if found else zero.
     */
    const MessageQueueEntry<A> *
    lookup_in_queue(const A& nexthop, const IPNet<A>& net) const;

    /**
     * Find the message queue entry and remove from both queues.
     */
    void remove_from_queue(const A& nexthop, const IPNet<A>& net);
};

#endif // __BGP_ROUTE_TABLE_NHLOOKUP_HH__

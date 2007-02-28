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

#ident "$XORP: xorp/bgp/bgp_trie.cc,v 1.18 2006/03/16 00:03:27 pavlin Exp $"

// #define DEBUG_LOGGING

#include "bgp_module.h"
#include "bgp_trie.hh"

template<class A>
ChainedSubnetRoute<A>::
ChainedSubnetRoute(const SubnetRoute<A>& route,
		   const ChainedSubnetRoute<A>* prev)
    : SubnetRoute<A>(route)
{
    if (prev != NULL) {
	set_prev(prev);
	set_next(prev->next());
	_prev->set_next(this);
	_next->set_prev(this);
    } else {
	_prev = this;
	_next = this;
    }
}

template<class A>
ChainedSubnetRoute<A>::
ChainedSubnetRoute(const ChainedSubnetRoute<A>& original)
    : SubnetRoute<A>(original)
{
    _prev = &original;
    _next = original.next();
    original.set_next(this);
    _next->set_prev(this);
}

template<class A>
bool
ChainedSubnetRoute<A>::unchain() const {
    _prev->set_next(_next);
    _next->set_prev(_prev);
    return _next != this;
}

/*************************************************************************/

template<class A>
BgpTrie<A>::BgpTrie()
{
}

template<class A>
BgpTrie<A>::~BgpTrie()
{
    if (this->route_count() > 0) {
	XLOG_FATAL("BgpTrie being deleted while still containing data\n");
    }
}

template<class A>
typename BgpTrie<A>::iterator
BgpTrie<A>::insert(const IPNet& net, const SubnetRoute<A>& route)
{
    typename PathmapType::iterator pmi = _pathmap.find(route.attributes());
    const ChainedSubnetRoute* found = (pmi == _pathmap.end()) ? NULL : pmi->second;
    ChainedSubnetRoute* chained_rt 
	= new ChainedSubnetRoute(route, found);

    debug_msg("storing route for %s with attributes %p", net.str().c_str(),
	   route.attributes());

    // The trie will copy chained_rt.  The copy constructor will insert
    // the copy into the chain after chained_rt.
    iterator iter = ((RouteTrie*)this)->insert(net, *chained_rt);

    if (found == NULL) {
	debug_msg(" on new chain");
	_pathmap[route.attributes()] = &(iter.payload());
    }
    debug_msg("\n");
    chained_rt->unchain();
    chained_rt->unref();
    return iter;
}

template<class A>
void
BgpTrie<A>::erase(const IPNet& net)
{
    // unlink the node from the _pathmap chain
    iterator iter = this->lookup_node(net);
    XLOG_ASSERT(iter != this->end());
    const ChainedSubnetRoute *found = &(iter.payload());
    XLOG_ASSERT(iter.key() == net);
    XLOG_ASSERT(found->net() == net);

    debug_msg("deleting route for %s with attributes %p", net.str().c_str(),
	   found->attributes());
    typename PathmapType::iterator pmi = _pathmap.find(found->attributes());
    XLOG_ASSERT(pmi != _pathmap.end());
    if (pmi->second == found) {		// this was the head node
	if (found->next() == found) {	 // it's the only node in the chain
	    _pathmap.erase(pmi);
	    debug_msg(" and erasing chain\n");
	} else {			// there are other nodes
	    _pathmap[found->attributes()] = found->next();
	    found->unchain();
	    debug_msg(" chain remains but head moved\n");
	}
    } else {
	found->unchain();
	debug_msg(" chain remains\n");
    }
    debug_msg("\n");

    // now delete it from the Actual Trie
    ((RouteTrie*)this)->erase(iter);
}

template<class A>
void
BgpTrie<A>::delete_all_nodes()			
{
    while (_pathmap.empty() == false)
	_pathmap.erase(_pathmap.begin());
    ((RouteTrie*)this)->delete_all_nodes();
}

template class BgpTrie<IPv4>;
template class BgpTrie<IPv6>;

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

#ident "$XORP: xorp/rib/rt_tab_redist.cc,v 1.6 2003/05/29 17:59:10 pavlin Exp $"

#include "rib_module.h"
#include "libxorp/xlog.h"

#include "rt_tab_expect.hh"

/*--------------------------------------------------------------------*/

template <typename A>
class ExpectedRouteChange
{
public:
    ExpectedRouteChange(bool add, const IPRouteEntry<A>& route);
    bool matches_add(const IPRouteEntry<A>& route) const;
    bool matches_delete(const IPRouteEntry<A>* route) const;
    string str() const;

private:
    bool _add; 			// true = add, false = delete.
    IPRouteEntry<A> _route;
};

template<class A>
ExpectedRouteChange<A>::ExpectedRouteChange<A>(bool add,
					       const IPRouteEntry<A>& route)
    : _add(add), _route(route)
{
}

template<class A>
bool
ExpectedRouteChange<A>::matches_add(const IPRouteEntry<A>& route) const
{
    if (!_add)
	return false;
    if (route.net() != _route.net())
	return false;
    IPNextHop<A> *expected_nh = dynamic_cast<IPNextHop<A>*>(_route.nexthop());
    assert(expected_nh != NULL);

    IPNextHop<A> *actual_nh = dynamic_cast<IPNextHop<A>*>(route.nexthop());
    assert(actual_nh != NULL);

    if ((expected_nh->addr()) != (actual_nh->addr()))
	return false;
    return true;
}

template<class A>
bool
ExpectedRouteChange<A>::matches_delete(const IPRouteEntry<A>* route) const
{
    if (_add)
	return false;
    if (route->net() != _route.net())
	return false;
    IPNextHop<A> *expected_nh = dynamic_cast<IPNextHop<A>*>(_route.nexthop());
    assert(expected_nh != NULL);

    IPNextHop<A> *actual_nh = dynamic_cast<IPNextHop<A>*>(route->nexthop());
    assert(actual_nh != NULL);

    if ((expected_nh->addr()) != (actual_nh->addr()))
	return false;
    return true;
}

template<class A>
string
ExpectedRouteChange<A>::str() const
{
    string s;
    if (_add)
	s = "Add of ";
    else
	s = "Delete of ";
    s += _route.str();
    return s;
}


/*--------------------------------------------------------------------*/

template<class A>
ExpectTable<A>::ExpectTable<A>(const string&   tablename,
			       RouteTable<A>*  parent)
    : RouteTable<A>(tablename)
{
    _parent = parent;

    // plumb ourselves into the table graph
    _parent->set_next_table(this);

    //there's no downstream table
    _next_table = NULL;
}

template<class A>
ExpectTable<A>::~ExpectTable<A>()
{
    XLOG_ASSERT(_expected.empty());
}

template<class A>
void
ExpectTable<A>::expect_add(const IPRouteEntry<A>& route)
{
    _expected.push_back(ExpectedRouteChange<A>(true, route));
}

template<class A>
void
ExpectTable<A>::expect_delete(const IPRouteEntry<A>& route)
{
    _expected.push_back(ExpectedRouteChange<A>(false, route));
}

template<class A>
int
ExpectTable<A>::add_route(const IPRouteEntry<A>& 	route,
			  RouteTable<A>* 		caller)
{
    XLOG_ASSERT(caller == _parent);
    printf("DT[%s]: Adding route %s\n", _tablename.c_str(),
	   route.str().c_str());
    if (_expected.empty()) {
	fprintf(stderr, "ExpectTable: unexpected add_route received\n");
	abort();
    }
    if (_expected.front().matches_add(route)) {
	_expected.pop_front();
	return XORP_OK;
    }
    fprintf(stderr, "ExpectTable: add_route received, but not what was expected\n");
    fprintf(stderr, "Expected: %s\n", _expected.front().str().c_str());
    fprintf(stderr, "Received: Add of %s\n", route.str().c_str());
    abort();
    return XORP_ERROR;
}

template<class A>
int
ExpectTable<A>::delete_route(const IPRouteEntry<A>* 	route,
			  RouteTable<A>* 		caller)
{
    XLOG_ASSERT(caller == _parent);
    printf("DT[%s]: Deleting route %s\n", _tablename.c_str(),
	   route->str().c_str());
    if (_expected.empty()) {
	fprintf(stderr, "ExpectTable: unexpected delete_route received\n");
	abort();
    }
    if (_expected.front().matches_delete(route)) {
	_expected.pop_front();
	return XORP_OK;
    }
    fprintf(stderr, "ExpectTable: delete_route received, but not what was expected\n");
    fprintf(stderr, "Expected: %s\n", _expected.front().str().c_str());
    fprintf(stderr, "Received: Delete of %s\n", route->str().c_str());
    abort();
    return XORP_ERROR;
}

template<class A>
const IPRouteEntry<A> *
ExpectTable<A>::lookup_route(const IPNet<A>& net) const
{
    return _parent->lookup_route(net);
}

template<class A>
const IPRouteEntry<A> *
ExpectTable<A>::lookup_route(const A& addr) const
{
    return _parent->lookup_route(addr);
}

template<class A>
void
ExpectTable<A>::replumb(RouteTable<A> *old_parent,
		       RouteTable<A> *new_parent)
{
    XLOG_ASSERT(_parent == old_parent);
    _parent = new_parent;
}

template<class A>
RouteRange<A>*
ExpectTable<A>::lookup_route_range(const A& addr) const
{
    return _parent->lookup_route_range(addr);
}

template<class A> string
ExpectTable<A>::str() const
{
    string s;
    s = "-------\nExpectTable: " + _tablename + "\n";
    s += "parent = " + _parent -> tablename() + "\n";
    return s;
}

template class ExpectTable<IPv4>;
template class ExpectTable<IPv6>;

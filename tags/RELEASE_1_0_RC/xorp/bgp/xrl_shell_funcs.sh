#!/bin/sh

#
# $XORP: xorp/bgp/xrl_shell_funcs.sh,v 1.7 2004/03/24 19:34:31 atanu Exp $
#

CALLXRL=${CALLXRL:-../libxipc/call_xrl}

local_config()
{
    echo -n "local_config" $*
#    $CALLXRL  "finder://bgp/bgp/0.1/local_config?localhost:txt=$1&port:i32=$2&as_num:i32=$3&id:ipv4=$4&version:i32=$5&holdtime:i32=$6"
    $CALLXRL  "finder://bgp/bgp/0.2/local_config?as:u32=$1&id:ipv4=$2"
}

add_peer()
{
    echo -n "add_peer" $*
#    $CALLXRL "finder://bgp/bgp/0.1/add_peer?peer:txt=$1&as:i32=$2&port:i32=$3&next_hop:ipv4=$4"	
    $CALLXRL "finder://bgp/bgp/0.2/add_peer?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4&as:u32=$5&next_hop:ipv4=$6&holdtime:u32=$7"
}

delete_peer()
{
    echo -n "delete_peer" $*
#    $CALLXRL "finder://bgp/bgp/0.1/delete_peer?peer:txt=$1&as:i32=$2"
    $CALLXRL "finder://bgp/bgp/0.2/delete_peer?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4&as:u32=$5"
}

enable_peer()
{
    echo -n "enable_peer" $*
#    $CALLXRL "finder://bgp/bgp/0.1/enable_peer?peer:txt=$1&as:i32=$2"
    $CALLXRL "finder://bgp/bgp/0.2/enable_peer?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4"
}

set_parameter()
{
    echo -n "set_parameter" $*
#    $CALLXRL "finder://bgp/bgp/0.2/set_parameter?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4&parameter:txt=$5"

    $CALLXRL "finder://bgp/bgp/0.2/set_parameter?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4&parameter:txt=$5"
}

disable_peer()
{
    echo -n "disable_peer" $*
#    $CALLXRL "finder://bgp/bgp/0.1/disable_peer?peer:txt=$1&as:i32=$2"
    $CALLXRL "finder://bgp/bgp/0.2/disable_peer?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4"
}

next_hop_rewrite_filter()
{
    echo -n "next_hop_rewrite_filter" $*
    $CALLXRL "finder://bgp/bgp/0.2/next_hop_rewrite_filter?local_ip:txt=$1&local_port:u32=$2&peer_ip:txt=$3&peer_port:u32=$4&next_hop:ipv4=$5"
}

register_rib()
{
    echo -n "register_rib" $*
    $CALLXRL "finder://bgp/bgp/0.2/register_rib?name:txt=$1"
}

originate_route4()
{
    echo -n "originate_route4" $*
    $CALLXRL "finder://bgp/bgp/0.2/originate_route4?nlri:ipv4net=$1&next_hop:ipv4=$2&unicast:bool=$3&multicast:bool=$4"
}

originate_route6()
{
    echo -n "originate_route6" $*
    $CALLXRL "finder://bgp/bgp/0.2/originate_route6?nlri:ipv6net=$1&next_hop:ipv6=$2&unicast:bool=$3&multicast:bool=$4"
}

withdraw_route4()
{
    echo -n "withdraw_route4" $*
    $CALLXRL "finder://bgp/bgp/0.2/withdraw_route4?nlri:ipv4net=$1&unicast:bool&=$2multicast:bool=$3"
}

withdraw_route6()
{
    echo -n "withdraw_route6" $*
    $CALLXRL "finder://bgp/bgp/0.2/withdraw_route6?nlri:ipv6net=$1&unicast:bool&=$2multicast:bool=$3"
}

shutdown()
{
    echo -n "shutdown" $*
    $CALLXRL "finder://bgp/common/0.1/shutdown"
}

time_wait_seconds()
{
    # If there are less than 200 PCB's in TIMEWAIT then return 0.

    local twc
    twc=`netstat -n | grep TIME_WAIT | grep 19999 | wc -l`
    if [ $twc -lt 200 ]
    then
	echo "0"
	return
    fi

    local tw os

    os=`uname -s`
    case $os in
	Linux)
	tw=`sysctl -n net.ipv4.tcp_fin_timeout 2>/dev/null`
	if [ $? -eq 0 ] ; then
	    echo $tw
	    return
	fi
	;;

	FreeBSD)
	local msl
	msl=`sysctl -n net.inet.tcp.msl 2>/dev/null`
	if [ $? -eq 0 ] ; then
	    # Timewait is 2 * msl and msl is in milliseconds
	    tw=`expr $msl + $msl + 1`
	    tw=`expr $tw / 1000`
	    echo $tw
	    return
	fi
	;;

	*)
	# All other OS: use the default value below
	;;
    esac

    # Defailt to 60 seconds
    echo "60"
}

# We have arguments.
if [ $# != 0 ]
then
    $*
fi


# Local Variables:
# mode: shell-script
# sh-indentation: 4
# End:

// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001-2005 International Computer Science Institute
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

// $XORP: xorp/fea/mfea_proto_comm.hh,v 1.13 2005/12/08 01:54:57 pavlin Exp $


#ifndef __FEA_MFEA_PROTO_COMM_HH__
#define __FEA_MFEA_PROTO_COMM_HH__


//
// Multicast-related raw protocol communications.
//

#include "libxorp/xorp.h"

#ifdef HAVE_SYS_UIO_H
#include <sys/uio.h>
#endif

#include "libxorp/eventloop.hh"
#include "libproto/proto_unit.hh"


//
// Constants definitions
//

//
// Structures/classes, typedefs and macros
//

class MfeaNode;


/**
 * @short A class for socket I/O communication.
 * 
 * Each protocol 'registers' for socket I/O and gets assigned one object
 * of this class.
 */
class ProtoComm : public ProtoUnit {
public:
    /**
     * Constructor for given MFEA node, IP protocol, and module ID
     * (@ref xorp_module_id).
     * 
     * @param mfea_node the MFEA node (@ref MfeaNode) this entry belongs to.
     * @param ipproto the IP protocol number (e.g., IPPROTO_PIM for PIM).
     * @param module_id the module ID (@ref xorp_module_id) for the protocol.
     */
    ProtoComm(MfeaNode& mfea_node, int ipproto, xorp_module_id module_id);
    
    /**
     * Destructor
     */
    virtual ~ProtoComm();
    
    /**
     * Start the @ref ProtoComm.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		start();
    
    /**
     * Stop the @ref ProtoComm.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		stop();

    /**
     * Get the IP protocol number.
     * 
     * @return the IP protocol number.
     */
    int		ipproto() const { return (_ipproto); }
    
    /**
     * Get the protocol socket.
     * 
     * The protocol socket is specific to the particular protocol of
     * this entry.
     * 
     * @return the socket value if valid, otherwise XORP_ERROR.
     */
    XorpFd	proto_socket() const { return (_proto_socket); }
    
    /**
     * Open an protocol socket.
     * 
     * The protocol socket is specific to the particular protocol of
     * this entry.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		open_proto_socket();
    
    /**
     * Add the method to read from the protocol socket.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		add_proto_socket_callback();

    /**
     * Close the protocol socket.
     * 
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		close_proto_socket();
    
    /**
     * Set/reset the "Header Included" option (for IPv4) on the protocol
     * socket.
     * 
     * If set, the IP header of a raw packet should be created
     * by the application itself, otherwise the kernel will build it.
     * Note: used only for IPv4.
     * In RFC-3542, IPV6_PKTINFO has similar functions,
     * but because it requires the interface index and outgoing address,
     * it is of little use for our purpose. Also, in RFC-2292 this option
     * was a flag, so for compatibility reasons we better not set it
     * here; instead, we will use sendmsg() to specify the header's field
     * values.
     * 
     * @param is_enabled if true, set the option, otherwise reset it.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		ip_hdr_include(bool is_enabled);
    
    /**
     * Enable/disable receiving information about a packet received on the
     * protocol socket.
     * 
     * If enabled, values such as interface index, destination address and
     * IP TTL (a.k.a. hop-limit in IPv6), and hop-by-hop options will be
     * received as well.
     * 
     * @param is_enabled if true, set the option, otherwise reset it.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		recv_pktinfo(bool is_enabled);
    
    /**
     * Set the default TTL (or hop-limit in IPv6) for the outgoing multicast
     * packets on the protocol socket.
     * 
     * @param ttl the desired IP TTL (a.k.a. hop-limit in IPv6) value.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		set_multicast_ttl(int ttl);
    
    /**
     * Set/reset the "Multicast Loop" flag on the protocol socket.
     * 
     * If the multicast loopback flag is set, a multicast datagram sent on
     * that socket will be delivered back to this host (assuming the host
     * is a member of the same multicast group).
     * 
     * @param is_enabled if true, set the loopback, otherwise reset it.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		set_multicast_loop(bool is_enabled);
    
    /**
     * Set default interface for outgoing multicast on the protocol socket.
     * 
     * 
     * @param vif_index the vif index of the interface to become the default
     * multicast interface.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		set_default_multicast_vif(uint32_t vif_index);
    
    /**
     * Join a multicast group on an interface.
     * 
     * @param vif_index the vif index of the interface to join the multicast
     * group.
     * @param group the multicast group to join.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		join_multicast_group(uint32_t vif_index, const IPvX& group);
    
    /**
     * Leave a multicast group on an interface.
     * 
     * @param vif_index the vif index of the interface to leave the multicast
     * group.
     * @param group the multicast group to leave.
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		leave_multicast_group(uint32_t vif_index, const IPvX& group);
    
    /**
     * Read data from a protocol socket, and then call the appropriate protocol
     * module to process it.
     *
     * This is called as a IoEventCb callback.
     * @param fd file descriptor that with event caused this method to be
     * called.
     * @param m mask representing event type.
     */
    void	proto_socket_read(XorpFd fd, IoEventType type);
    
    /**
     * Send a packet on a protocol socket.
     * 
     * @param vif_index the vif index of the vif that will be used to send-out
     * the packet.
     * @param src the source address of the packet.
     * @param dst the destination address of the packet.
     * @param ip_ttl the TTL (a.k.a. Hop-limit in IPv6) of the packet.
     * If it has a negative value, the TTL will be set here or by the
     * lower layers.
     * @param ip_tos the TOS (a.k.a. Traffic Class in IPv6) of the packet.
     * If it has a negative value, the TOS will be set here or by the lower
     * layers.
     * @param is_router_alert if true, then the IP packet with the data
     * should have the Router Alert option included.
     * @param databuf the data buffer.
     * @param datalen the length of the data in @ref databuf.
     * @param error_msg the error message (if error).
     * @return XORP_OK on success, otherwise XORP_ERROR.
     */
    int		proto_socket_write(uint32_t vif_index,
				   const IPvX& src, const IPvX& dst,
				   int ip_ttl, int ip_tos,
				   bool is_router_alert,
				   const uint8_t *databuf, size_t datalen,
				   string& error_msg);
    
    /**
     * Set/reset the flag whether to ignore the receiving my own packets.
     * 
     * @param v if true, ignore my own packets on receiving, otherwise don't
     * ignore them.
     */
    void	set_ignore_my_packets(bool v) { _ignore_my_packets = v; }
    
    /**
     * Get the module ID (@ref xorp_module_id) for the protocol that created
     * this entry.
     * 
     * @return the module ID (@ref xorp_module_id) of the protocol that created
     * this entry.
     */
    xorp_module_id module_id() const { return (_module_id); }
    
    
private:
    // Private functions
    MfeaNode&	mfea_node() const	{ return (_mfea_node);	}
    bool	ignore_my_packets() const { return (_ignore_my_packets); }
    
    // Private state
    MfeaNode&	  _mfea_node;	// The MFEA node I belong to
    int		  _ipproto;	// The protocol number (IPPROTO_*)
    xorp_module_id _module_id;	// The corresponding module id (XORP_MODULE_*)
    XorpFd	  _proto_socket;   // The socket for protocol message
    uint8_t*	  _rcvbuf0;	// Data buffer0 for receiving
    uint8_t*	  _sndbuf0;	// Data buffer0 for sending
    uint8_t*	  _rcvbuf1;	// Data buffer1 for receiving
    uint8_t*	  _sndbuf1;	// Data buffer1 for sending
    uint8_t*	  _rcvcmsgbuf;	// Control recv info (IPv6 only)
    uint8_t*	  _sndcmsgbuf;	// Control send info (IPv6 only)
#ifdef HAVE_STRUCT_MSGHDR
    struct msghdr _rcvmh;	// The msghdr structure used by recvmsg()
    struct msghdr _sndmh;	// The msghdr structure used by sendmsg()
#endif
    struct iovec  _rcviov[2];	// The rcvmh scatter/gatter array
    struct iovec  _sndiov[2];	// The sndmh scatter/gatter array
    struct sockaddr_in  _from4;	// The source addr of recvmsg() msg (IPv4)
    struct sockaddr_in  _to4;	// The dest.  addr of sendmsg() msg (IPv4)
#ifdef HAVE_IPV6
    struct sockaddr_in6 _from6;	// The source addr of recvmsg() msg (IPv6)
    struct sockaddr_in6 _to6;	// The dest.  addr of sendmsg() msg (IPv6)
#endif
    bool	_ignore_my_packets; // If true, ignore packets originated by me
};

//
// Global variables
//


//
// Global functions prototypes
//

#endif // __FEA_MFEA_PROTO_COMM_HH__
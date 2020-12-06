/*-
 *   BSD LICENSE
 *
 *   Copyright(c) 2020 Chongqing University of Posts and Telecommunications. 
 *	 All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in
 *       the documentation and/or other materials provided with the
 *       distribution.
 *     * Neither the name of CQUPT Corporation nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _CIP_CONVERTION_H_
#define _CIP_CONVERTION_H_

#include <rte_ip.h>
/**
* Notice: !!!
* All data structure define in the file of rte_ip.h .
* All CIP codes define in files as show above
*/

/* -------------------------------- Ethernet header convertion -------------------------------- */

/**
 * Convert Ethernet header in IPv4 packet to IPv6 packet .
 *
 * The return is NULL , you should make sure that all the line has character of '\' ,
 * else complie will be failed
 *
 * @param eth_hdr
 *   The macro of Ethernet header in IPv4 packet , which ready to be converted .
 * @param eth_hdr6
 *   The macro of Ethernet header in IPv6 packet , which used to save the lastes data .
 */
#define IPV4_TO_IPV6_ETHER_HDR( eth_hdr , eth_hdr6 ) 									\
do {																					\
	/* Write MAC address to IPv6 packet	*/												\
	( eth_hdr6 ) -> s_addr.addr_bytes[ 0 ] = ( eth_hdr ) -> s_addr.addr_bytes[ 0 ];		\
	( eth_hdr6 ) -> d_addr.addr_bytes[ 1 ] = ( eth_hdr ) -> d_addr.addr_bytes[ 1 ];		\
	( eth_hdr6 ) -> s_addr.addr_bytes[ 2 ] = ( eth_hdr ) -> s_addr.addr_bytes[ 2 ];		\
	( eth_hdr6 ) -> d_addr.addr_bytes[ 3 ] = ( eth_hdr ) -> d_addr.addr_bytes[ 3 ];		\
	( eth_hdr6 ) -> s_addr.addr_bytes[ 4 ] = ( eth_hdr ) -> s_addr.addr_bytes[ 4 ];		\
	( eth_hdr6 ) -> d_addr.addr_bytes[ 5 ] = ( eth_hdr ) -> d_addr.addr_bytes[ 5 ];		\
	/* Write the type of IPv6 packet to ethernet ( define in rte_ip.h )	*/				\
	( eth_hdr6 ) -> ether_type = swap_uint16( ETHER_TYPE_IPv6 );						\
} while( 0 )

/* -------------------------------- Ethernet header convertion -------------------------------- */


/* ----------------------------------- IP header convertion ----------------------------------- */
/**
 * Convert Ethernet header in IPv4 packet to IPv6 packet .
 *
 * The return is NULL , you should make sure that all the line has character of '\' ,
 * else complie will be failed
 *
 * @param ipv4_hd
 *   The macro of IPv4 header in IPv4 packet , which ready to be converted .
 * @param eth_hdr6
 *   The macro of IPv6 header in IPv6 packet , which used to save the lastes data .
 * @param tmp
 *	 Temporary variable
 */
#define IPV4_TO_IPV6_IP_HDR( ipv4_hd , ipv6_hd , tmp )										\
do {																						\
	/* Convert the IP header of IPv4 packet to IPv6 packet */								\
	( ( ipv4_hd ) ) -> total_length = swap_uint16( ( ( ipv4_hd ) ) -> total_length );		\
	( ipv6_hd ) -> vtc_flow = htonl( 6 << 28 | 0x00 << 20 | 4 );							\
	( tmp ) = ( ( ipv4_hd ) -> total_length 												\		
		- ( ( ( ipv4_hd ) -> version_ihl ) & 0x0f ) * 4 );									\
	( ipv6_hd ) -> payload_len = htons( tmp );												\
	( ipv6_hd ) -> proto = ( ipv4_hd ) -> next_proto_id;									\
	( ipv6_hd ) -> hop_limits = ( ipv4_hd ) -> time_to_live;								\
	( tmp ) = swap_uint32( ( ipv4_hd ) -> dst_addr );										\
																							\
	/* Intializing the prefix of IPv6 address ( define in rte_ip.h ) */						\
	/* Attention: in order to avoid drop packets , do not delete these codes . */			\
	( ipv6_hd ) -> src_addr[ 0 ]  = ( ipv6_hd ) -> dst_addr[ 0 ]  = IPV6_PREFIX_00;			\
	( ipv6_hd ) -> src_addr[ 1 ]  = ( ipv6_hd ) -> dst_addr[ 1 ]  = IPV6_PREFIX_01;			\
	( ipv6_hd ) -> src_addr[ 2 ]  = ( ipv6_hd ) -> dst_addr[ 2 ]  = IPV6_PREFIX_02;			\
	( ipv6_hd ) -> src_addr[ 3 ]  = ( ipv6_hd ) -> dst_addr[ 3 ]  = IPV6_PREFIX_03;			\
	( ipv6_hd ) -> src_addr[ 4 ]  = ( ipv6_hd ) -> dst_addr[ 4 ]  = IPV6_PREFIX_04;			\
	( ipv6_hd ) -> src_addr[ 5 ]  = ( ipv6_hd ) -> dst_addr[ 5 ]  = IPV6_PREFIX_05;			\
	( ipv6_hd ) -> src_addr[ 6 ]  = ( ipv6_hd ) -> dst_addr[ 6 ]  = IPV6_PREFIX_06;			\
	( ipv6_hd ) -> src_addr[ 7 ]  = ( ipv6_hd ) -> dst_addr[ 7 ]  = IPV6_PREFIX_07;			\
	( ipv6_hd ) -> src_addr[ 8 ]  = ( ipv6_hd ) -> dst_addr[ 8 ]  = IPV6_PREFIX_08;			\
	( ipv6_hd ) -> src_addr[ 9 ]  = ( ipv6_hd ) -> dst_addr[ 9 ]  = IPV6_PREFIX_09;			\
	( ipv6_hd ) -> src_addr[ 10 ] = ( ipv6_hd ) -> dst_addr[ 10 ] = IPV6_PREFIX_10;			\
	( ipv6_hd ) -> src_addr[ 11 ] = ( ipv6_hd ) -> dst_addr[ 11 ] = IPV6_PREFIX_11;			\
	/* User can delete the intialzation of this four elements ( define in rte_ip.h ) */		\
	/* ( ipv6_hd ) -> src_addr[ 12 ] = ( ipv6_hd ) -> dst_addr[ 12 ] = IPV6_PREFIX_12; */	\
	/* ( ipv6_hd ) -> src_addr[ 13 ] = ( ipv6_hd ) -> dst_addr[ 13 ] = IPV6_PREFIX_13; */	\
	/* ( ipv6_hd ) -> src_addr[ 14 ] = ( ipv6_hd ) -> dst_addr[ 14 ] = IPV6_PREFIX_14; */	\
	/* ( ipv6_hd ) -> src_addr[ 15 ] = ( ipv6_hd ) -> dst_addr[ 15 ] = IPV6_PREFIX_15; */	\
																							\
	if( IS_IPV4_MCAST( tmp ) ) {															\
	/* Intializing the prefix of IPv6 address ( define in rte_ip.h ) */						\
	/* Attention: in order to avoid drop packets , do not delete these codes .*/			\
		ipv6_hd -> dst_addr[ 0 ]  = IPV6_MUL_PREFIX_00;										\
		ipv6_hd -> dst_addr[ 1 ]  = IPV6_MUL_PREFIX_01;										\
		ipv6_hd -> dst_addr[ 2 ]  = IPV6_MUL_PREFIX_02;										\
		ipv6_hd -> dst_addr[ 3 ]  = IPV6_MUL_PREFIX_03;										\
		ipv6_hd -> dst_addr[ 4 ]  = IPV6_MUL_PREFIX_04;										\
		ipv6_hd -> dst_addr[ 5 ]  = IPV6_MUL_PREFIX_05;										\
		ipv6_hd -> dst_addr[ 6 ]  = IPV6_MUL_PREFIX_06;										\
		ipv6_hd -> dst_addr[ 7 ]  = IPV6_MUL_PREFIX_07;										\
		ipv6_hd -> dst_addr[ 8 ]  = IPV6_MUL_PREFIX_08;										\
		ipv6_hd -> dst_addr[ 9 ]  = IPV6_MUL_PREFIX_09;										\
		ipv6_hd -> dst_addr[ 10 ] = IPV6_MUL_PREFIX_10;										\
		ipv6_hd -> dst_addr[ 11 ] = IPV6_MUL_PREFIX_11;										\
		/* User can delete the intialzation of this four elements ( define in rte_ip.h )*/	\
		/* ipv6_hd -> src_addr[ 12 ] = ipv6_hd -> dst_addr[ 12 ] = IPV6_PREFIX_12; */		\
		/* ipv6_hd -> src_addr[ 13 ] = ipv6_hd -> dst_addr[ 13 ] = IPV6_PREFIX_13; */		\
		/* ipv6_hd -> src_addr[ 14 ] = ipv6_hd -> dst_addr[ 14 ] = IPV6_PREFIX_14; */		\
		/* ipv6_hd -> src_addr[ 15 ] = ipv6_hd -> dst_addr[ 15 ] = IPV6_PREFIX_15; */		\
	}																						\
																							\
	/* Converting IPv4 address to IPv6 address ( define in rte_ip.h ) */					\
	( tmp ) = ipv4_hd -> src_addr;															\
	ipv6_hd -> src_addr[ IP_ADDR_OFFSET + 0 ] = uint32_to_IPv4( ( tmp ) , 1 );				\
	ipv6_hd -> src_addr[ IP_ADDR_OFFSET + 1 ] = uint32_to_IPv4( ( tmp ) , 2 );				\
	ipv6_hd -> src_addr[ IP_ADDR_OFFSET + 2 ] = uint32_to_IPv4( ( tmp ) , 3 );				\
	ipv6_hd -> src_addr[ IP_ADDR_OFFSET + 3 ] = uint32_to_IPv4( ( tmp ) , 4 );				\
	( tmp ) = ipv4_hd -> dst_addr;															\
	ipv6_hd -> dst_addr[ IP_ADDR_OFFSET + 0 ] = uint32_to_IPv4( ( tmp ) , 1 );				\
	ipv6_hd -> dst_addr[ IP_ADDR_OFFSET + 1 ] = uint32_to_IPv4( ( tmp ) , 2 );				\
	ipv6_hd -> dst_addr[ IP_ADDR_OFFSET + 2 ] = uint32_to_IPv4( ( tmp ) , 3 );				\
	ipv6_hd -> dst_addr[ IP_ADDR_OFFSET + 3 ] = uint32_to_IPv4( ( tmp ) , 4 );				\
} while( 0 )

/* ----------------------------------- IP header convertion ----------------------------------- */

#endif

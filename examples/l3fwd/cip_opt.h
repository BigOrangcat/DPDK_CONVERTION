/**************************************************************
*
* Instructions: the file of opt.h used to choose the environment of 
*	working station, such as support IPv6
*
* Creating Date: 2020-6-30
* Author: 
*
***************************************************************/

#ifndef _CIPMESSAGEROUTER_H
#define _CIPMESSAGEROUTER_H

/*----------------------------------------------------------------------*/
//for this part, you can used in InternetHandler.c, encap.h, 

//if you want to send messge by IPv6, you should choose this option, but
//you must shut down the IPv4
#define OPEN_IPV6 0

//if you want to send messge by IPv4, you should choose this option, but
//you must shut down the IPv6
#define OPEN_IPV4 1

//if you want to see the packet during the process, you can open the function
#define PRINT_PACKET 0

//if you want to see the time of the process, you can open the function
#define PRINT_TEST_TIME 0

//if you want to see the time of the process, you can open the function
#define PRINT_UDP6_TIME 0

//if you want to see the time of the process, you can open the function
#define DPDK_SUPPORT 1


/*----------------------------------------------------------------------*/


#endif
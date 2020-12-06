/**************************************************************
*
* Instructions: the file of encap.h used to declear some information
*	and functions that are used in the CIP stack to create
*	encapsulation packet
*
* Creating Date: 2020-4-20
* Author: 
*
***************************************************************/
/*-------- system libary ---------*/

#ifndef ENCAP_H_
#define ENCAP_H_
#include <stdio.h>
#include <stdlib.h>

/*-------- system libary ---------*/

/*--------- local libary ---------*/

#include "typedefs.h"

/*-------- local libary ---------*/


/*--------- DPDK libary ---------*/

#include "cip_opt.h"

#ifdef DPDK_SUPPORT

    #include <stdint.h>
    #include <netinet/in.h>
    #include <rte_byteorder.h>
    #include <rte_mbuf.h>

    struct class_0_1_hdr {

        EIP_UINT16 item_count;
        EIP_UINT16 type_1_id;
        EIP_UINT16 length_1;
        EIP_UINT32 connection_id;
        EIP_UINT32 sequence_no;
        EIP_UINT16 type_2_id;
        EIP_UINT16 length_2;
        EIP_BYTE * data;

    } __attribute__((__packed__));

#endif

/*--------- DPDK libary ---------*/


/*----------- the struct of Ethernet encapsulation layer -----------*/

/****************** the header of encapsulation *********************/

typedef struct S_Encapsulation_Data {

    EIP_UINT16 nCommand_code;
    EIP_UINT16 nData_length;
    EIP_UINT32 nSession_handle;
    EIP_UINT32 nStatus;
    /* The sender context is not needed any more with the new minimum data copy design */
    /* EIP_UINT8 anSender_context[ SENDER_CONTEXT_SIZE ];  */
    EIP_UINT32 nOptions;

    /*Pointer to the communication buffer used for this message */
    EIP_UINT8 * m_acCommBufferStart;

    /*The current position in the communication buffer during the decoding process */       
    EIP_UINT8 * m_acCurrentCommBufferPos;  

} S_Encapsulation_Data;

/****************** the header of encapsulation ********************/

/**************** the interface of encapsulation *******************/

typedef struct S_Encapsulation_Interface_Information {

    EIP_UINT16 TypeCode;
    EIP_UINT16 Length;
    EIP_UINT16 EncapProtocolVersion;
    EIP_UINT16 CapabilityFlags;
    EIP_INT8 NameofService[ 17 ];

} S_Encapsulation_Interface_Information;

/**************** the interface of encapsulation ********************/


/****************** the informations of server ***********************/

#define IP_ADDRESS_MAX_LENGTH  15 

typedef struct S_Server_Information {

    EIP_UINT16 IdentityID;
    EIP_UINT16 EncapProtocolVersion;
    EIP_UINT16 pa_unPort;
    EIP_UINT16 VendorID;
    EIP_UINT16 DeviceType;
    EIP_UINT16 ProductCode;
    EIP_UINT16 ID_Status;
    EIP_UINT32 SerialNumber;
    EIP_INT8 * pa_unAddr;
    EIP_UINT16 registerSession;
    char server_ipv6_addr[ 30 ];
    S_Encapsulation_Interface_Information * interface_info;
    //S_CIP_Short_String ProductName;

} S_Server_Information;

/****************** the information of server ***********************/

/*----------- the struct of Ethernet encapsulation layer -----------*/


/*-------- the informations of Ethernet encapsulation layer --------*/

/*** defines ***/

//clearing the value of parameter
#define CLEARING 0
#define SETTING 1

//the maximun of length in ethernet buffer 
#define PC_OPENER_ETHERNET_BUFFER_SIZE 2048

//the length of encapsulation header
#define ENCAPSULATION_HEADER_LENGTH 24

//the length of encapsulation header
#define NUMBER_OF_SERVER 24

//#if OPEN_IPV4

//the port of communication
#define OPENER_ETHERNET_PORT 0xAF12

//#endif

//#if OPEN_IPV6

//the port of communication
//#define OPENER_ETHERNET_PORT 0xAF13

//#endif
//the port of communication
#define POINT_POINT_PORT 0x08AE


/*-------------------- Encapsulation Status ---------------------*/

// Volume 2 : Table 2-3.3 Error Codes
// Another time these documents are a bag of shit
// this table shows 16 bits status
// the type of these data is unsigned int: 32 bits
#define OPENER_ENCAP_STATUS_SUCCESS                     0x00000000
#define OPENER_ENCAP_STATUS_INVALID_COMMAND             0x00000001
#define OPENER_ENCAP_STATUS_INSUFFICIENT_MEM            0x00000002
#define OPENER_ENCAP_STATUS_INCORRECT_DATA              0x00000003
#define OPENER_ENCAP_STATUS_INVALID_SESSION_HANDLE      0x00000064
#define OPENER_ENCAP_STATUS_INVALID_LENGTH              0x00000065

// Exceptionnel
// There is no protocol version id in the header !!!
// Information available only in ListInfo fields (upper protocol)
#define OPENER_ENCAP_STATUS_UNSUPPORTED_PROTOCOL        0x00000069

/*-------------------- Encapsulation Status ---------------------*/


/*** defines ***/

#define ITEM_ID_LISTIDENTITY 0x000C

#define SUPPORTED_PROTOCOL_VERSION 1

/*Mask of which options are supported as of the current CIP 
* specs no other option value as 0 should be supported.*/
#define SUPPORTED_OPTIONS_MASK  0x00  

/*the position of the session handle within the encapsulation header*/
#define ENCAPSULATION_HEADER_SESSION_HANDLE_POS 4   

#define INVALID_SESSION -1

/*size of sender context in encapsulation header*/
#define SENDER_CONTEXT_SIZE 8                   

/*-----------Encapsulation Commands-------------*/
// Volume 2 : Table 2-3.2 Encapsulation Commands
// the type of these data is unsigned short: 16 bits

// Application keep alive
#define COMMAND_NOP                     0x0000
#define COMMAND_LISTSERVICES            0x0004
#define COMMAND_LISTIDENTITY            0x0063
#define COMMAND_LISTINTERFACES          0x0064
#define COMMAND_REGISTERSESSION         0x0065
#define COMMAND_UNREGISTERSESSION       0x0066
#define COMMAND_SENDRRDATA              0x006F
#define COMMAND_SENDUNITDATA            0x0070

/*-----------Encapsulation Commands-------------*/

/* definition of capability flags */
#define SUPPORT_CIP_TCP                 0x0020
#define SUPPORT_CIP_UDP_CLASS_0_OR_1    0x0100

/*According to EIP spec at least 2 delayed message requests schould be supporte */
#define ENCAP_NUMBER_OF_SUPPORTED_DELAYED_ENCAP_MESSAGES 2 

/* currently we only have the size of an encapsulation message */
#define ENCAP_MAX_DELAYED_ENCAP_MESSAGE_SIZE  ( ENCAPSULATION_HEADER_LENGTH + 39 + sizeof( OPENER_DEVICE_NAME ) ) 

/*-------- the informations of Ethernet encapsulation layer --------*/


/*---------------------- declearing functions ----------------------*/

/* creating a header of encapsulation packet */
int createEncapHeader( S_Encapsulation_Data * pa_stData ,
                        EIP_BYTE * pa_buf );

/* checking the command code whether is being defined or not */
bool isDefineCommond( EIP_UINT16 nCommand_code );

/* releasing a header of encapsulation packet from server */

int releaseEncapHeader( S_Encapsulation_Data * pa_recData 
                                                , int pac_len );

/* releasing the packet of list identity from server */
EIP_UINT16 createListIdentityRequest( S_Encapsulation_Data * pa_stData );

/* releasing the packet of list identity from server */
EIP_STATUS handleListIdentityRespone( S_Server_Information * ser_info ,
                    S_Encapsulation_Data * pa_recData , EIP_UINT16 pac_len );

/* creating the packet of Nop request */
EIP_UINT16 createNopRequest( S_Encapsulation_Data * pa_stData );

/* creating the packet of list service request */
EIP_UINT16 createListServiceRequest( S_Encapsulation_Data * pa_stData );


/* releasing the packet of list service from server */
EIP_STATUS handleListServiceRespone( S_Server_Information * ser_info ,
    S_Encapsulation_Data * pa_recData , EIP_UINT16 pac_len );

/* creating the packet of list interface request */
EIP_UINT16 createListInterfaceRequest( S_Encapsulation_Data * pa_stData );

/* releasing the packet of list interface from server */
EIP_STATUS handleListInterfaceRespone( S_Server_Information * ser_info ,
    S_Encapsulation_Data * pa_recData , EIP_UINT16 pac_len );

/* creating the packet of register session request */
EIP_UINT16 createRegisterSessionRequest( S_Encapsulation_Data * pa_stData );


/* releasing the packet of register session from server */
EIP_STATUS handleRegisterSessionRespone( S_Server_Information * ser_info ,
    S_Encapsulation_Data * pa_recData , EIP_UINT16 pac_len );

/* creating the packet of unregister session request */
EIP_UINT16 createUnRegisterSessionRequest( S_Encapsulation_Data * pa_stData );

/* releasing the packet of unregister session from server */
EIP_STATUS handleUnRegisterSessionRespone( S_Server_Information * ser_info ,
    S_Encapsulation_Data * pa_recData , EIP_UINT16 pac_len );

/* according to volume 2 3-2.2.1 CIP: transport Class 0 and Class 1 Packets */
/* creating CPF data and transmition in connection class 0/1 */
int createUnitData( EIP_BYTE * byte , EIP_UINT32 CIPProducedConnectionID , 
        EIP_UINT16 EIPSequenceCountConsuming , int data_len , EIP_BYTE * data );


EIP_UINT16 createIPv6Identity( EIP_BYTE * buf , EIP_BYTE * packet , int len , char * ipv4 );

EIP_UINT16 updateConnectionData( EIP_BYTE * buf , EIP_UINT32 connectionID ,
                                                                 int length );

/*---------------------- declearing functions ----------------------*/


#endif /*ENCAP_H_*/


#include <stdio.h>
#include <stdlib.h>

#ifndef _CIPCODE_H
#define _CIPCODE_H

/*--------- DPDK libary ---------*/

#include "cip_opt.h"

#ifdef DPDK_SUPPORT

  #include <stdint.h>
  #include <netinet/in.h>

  #include <rte_byteorder.h>
  #include <rte_mbuf.h>

#endif

/*--------- DPDK libary ---------*/

/*--------------CIPObjectLibrary---------------*/
// Volume 1 : Table 5-1.1 Object Specifications
// the type of these data is unsigned char: 8 bits
    
#define Object_Identity                     0x01
#define Object_MessageRouter                0x02
#define Object_DeviceNet                    0x03
#define Object_Assembly                     0x04
#define Object_Connection                   0x05
#define Object_ConnectionManager            0x06
#define Object_Object_Register              0x07
#define Object_DiscreteInputPoint           0x08
#define Object_DiscreteOutputPoint          0x09
#define Object_AnalogInputPoint             0x0A
#define Object_AnalogOutputPoint            0x0B
#define Object_PresenceSensing              0x0E
#define Object_Parameter                    0x0F
#define Object_ParameterGroup               0x10
#define Object_Group                        0x12
#define Object_DiscreteInputGroup           0x1D
#define Object_DiscreteOutputGroup          0x1E
#define Object_DiscreteGroup                0x1F
#define Object_AnalogInputGroup             0x20
#define Object_AnalogOutputGroup            0x21
#define Object_AnalogGroup                  0x22
#define Object_PositionSensor               0x23
#define Object_PositionControllerSupervisor 0x24
#define Object_PositionController           0x25
#define Object_BlockSequencer               0x26
#define Object_CommandBlock                 0x27
#define Object_MotorData                    0x28
#define Object_ControlSupervisor            0x29
#define Object_AcDcDrive                    0x2A
#define Object_AcknowledgeHandler           0x2B
#define Object_Overload                     0x2C
#define Object_SoftStart                    0x2D
#define Object_Selection                    0x2E
#define Object_SDeviceSupervisor            0x30
#define Object_SAnalogSensor                0x31
#define Object_SAnalogActuator              0x32
#define Object_SSingleStageController       0x33
#define Object_SGasCalibration              0x34
#define Object_TripPoint                    0x35
#define Object_File                         0x37
#define Object_SPartialPressure             0x38
#define Object_SafetySupervisor             0x39
#define Object_SafetyValidator              0x3A
#define Object_afetyDiscreteOutputPoint     0x3B
#define Object_SafetyDiscreteOutputGroup    0x3C
#define Object_SafetyDiscreteInputPoint     0x3D
#define Object_SafetyDiscreteInputGroup     0x3E
#define Object_SafetyDualChannelOutput      0x3F
#define Object_SSensorCalibration           0x40
#define Object_EventLog                     0x41
#define Object_MotionAxis                   0x42
#define Object_TimeSync                     0x43
#define Object_Modbus                       0x44
#define Object_DLR                          0x47
#define Object_QoS                          0x48
#define Object_ControlNet                   0xF0
#define Object_ControlNetKeeper             0xF1
#define Object_ControlNetScheduling         0xF2
#define Object_ConnectionConfiguration      0xF3
#define Object_Port                         0xF4
#define Object_TCPIPInterface               0xF5
#define Object_EtherNetLink                 0xF6
#define Object_CompoNetLink                 0xF7
#define Object_CompoNetRepeater             0xF8

/*--------------CIPObjectLibrary---------------*/


/*--------------- CIP Service Codes ---------------*/
// Volume 1 : Table A-3.1 CIP Service Codes and Names
// High bit 0 for query 1 for response
// the type of these data is unsigned char: 8 bits

#define Service_GetAttributesAll        0x01
#define Service_SetAttributeAll         0x02
#define Service_GetAttributeList        0x03
#define Service_SetAttributeList        0x04
#define Service_Reset                   0x05
#define Service_Start                   0x06
#define Service_Stop                    0x07
#define Service_Create                  0x08
#define Service_Delete                  0x09
#define Service_MultipleServicePacket   0x0A
#define Service_ApplyAttributes         0x0D
#define Service_GetAttributeSingle      0x0E
#define Service_SetAttributeSingle      0x10
#define Service_FindNextObjectInstance  0x11
#define Service_Restore                 0x15
#define Service_Save                    0x16
#define Service_NOP                     0x17
#define Service_GetMember               0x18
#define Service_SetMember               0x19
#define Service_InsertMember            0x1A
#define Service_RemoveMember            0x1B
#define Service_GroupSync               0x1C
#define Service_ForwardClose            0x4E
#define Service_UnconnectedSend         0x52
#define Service_ForwardOpen             0x54  
#define Service_LargeForwardOpen        0x5B

/*--------------- CIP Service Codes ---------------*/


/*------------- Identity Object Status -------------*/
// Volume 1 : Table 5-2.2 Identity Object Instance Attributes
// the type of these data is unsigned int: 32 bits

#define Obj_Status_NonExistant               0
#define Obj_Status_DeviceSelfTesting         1
#define Obj_Status_Standby                   2
#define Obj_Status_perational                3
#define Obj_Status_MajorRecoverableFault     4
#define Obj_Status_MajorUnRecoverableFault   5
#define Obj_Status_Default                   255

/*------------- Identity Object Status -------------*/


/*------------- CIP General Satus Code -------------*/
// Volume 1 : Table B-1.1 CIP General Status Codes
// the type of these data is unsigned int: 32 bits

#define General_Success                                         0
#define General_Connection_failure                              1
#define General_Resource_unavailable                            2
#define General_Invalid_parameter_value                         3
#define General_Path_segment_error                              4
#define General_Path_destination_unknown                        5
#define General_Partial_transfer                                6
#define General_Connection_lost                                 7
#define General_Service_not_supported                           8
#define General_Invalid_attribute_value                         9
#define General_Attribute_list_error                            10
#define General_Already_in_requested_mode_state                 11
#define General_Object_state_conflict                           12
#define General_Object_already_exists                           13
#define General_Attribute_not_settable                          14
#define General_Privilege_violation                             15
#define General_Device_state_conflict                           16
#define General_Reply_data_too_large                            17
#define General_Fragmentation_of_a_primitive_value              18
#define General_General_Not_enough_data                         19
#define General_Attribute_not_supported                         20
#define General_Too_much_data                                   21
#define General_Object_does_not_exist                           22
#define General_Service_fragmentation_sequence_not_in_progress  23
#define General_No_stored_attribute_data                        24
#define General_Store_operation_failure                         25
#define General_Routing_failure_request_packet_too_large        26
#define General_Routing_failure_response_packet_too_large       27
#define General_Missing_attribute_list_entry_data               28
#define General_Invalid_attribute_value_list                    29
#define General_Embedded_service_error                          30
#define General_Vendor_specific_error                           31
#define General_Invalid_parameter                               32
#define General_Write_once_value_or_medium_already_written      33
#define General_Invalid_reply_received                          34
#define General_Buffer_overflow                                 35
#define General_Invalid_message_format                          36
#define General_Key_failure_in_path                             37
#define General_Path_size_invalid                               38
#define General_Unexpected_attribute_in_list                    39
#define General_Invalid_Member_ID                               40
#define General_Member_not_settable                             41
#define General_Group_2_only_server_general_failure             42
#define General_Unknown_Modbus_error                            43
#define General_Attribute_not_gettable                          44

/*------------- CIP General Satus Code -------------*/



/*-------- Transport Class Trigger Attribute -------*/
// Volume 1 : Figure 3-4.2 Transport Class Trigger Attribute
// the type of these data is unsigned char: 8 bits

#define Class_Attribute_Cyclic              0x00
#define Class_Attribute_ChangeOfState       0x10
#define Class_Attribute_ApplicationObject   0x20

/*-------- Transport Class Trigger Attribute -------*/

#endif

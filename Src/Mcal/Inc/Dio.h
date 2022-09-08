/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *       File:  Dio.h
 *       Module:  Dio
 *
 *  Description:  Header file for Dio driver - TM4C123GH6PM Microcontroller.     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORTA_NUM                (uint8)0 /* PORTA */
#define PORTB_NUM                (uint8)1 /* PORTB */
#define PORTC_NUM                (uint8)2 /* PORTC */
#define PORTD_NUM                (uint8)3 /* PORTD */
#define PORTE_NUM                (uint8)4 /* PORTE */
#define PORTF_NUM                (uint8)5 /* PORTF */

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
	CHANNAL_A0= 0,CHANNAL_A1= 1, CHANNAL_A2, CHANNAL_A3, CHANNAL_A4, CHANNAL_A5, CHANNAL_A6, CHANNAL_A7
	, CHANNAL_B0, CHANNAL_B1, CHANNAL_B2, CHANNAL_B3, CHANNAL_B4, CHANNAL_B5, CHANNAL_B6, CHANNAL_B7
	, CHANNAL_C0,  CHANNAL_C1, CHANNAL_C2, CHANNAL_C3, CHANNAL_C4, CHANNAL_C5, CHANNAL_C6, CHANNAL_C7
	, CHANNAL_D0, CHANNAL_D1, CHANNAL_D2, CHANNAL_D3, CHANNAL_D4, CHANNAL_D5, CHANNAL_D6, CHANNAL_D7
	, CHANNAL_E0, CHANNAL_E1, CHANNAL_E2, CHANNAL_E3, CHANNAL_E4, CHANNAL_E5
	, CHANNAL_F0= 40, CHANNAL_F1, CHANNAL_F2, CHANNAL_F3, CHANNAL_F4
	
}Dio_ChannelType;

typedef uint8 Dio_PortType;
typedef uint8 Dio_LevelType;
typedef uint8 Dio_PortLevelType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
 
 void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
 
 Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
 
 void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);
 
 Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

 
#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/

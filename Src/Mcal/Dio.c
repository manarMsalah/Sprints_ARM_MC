/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
 *        \brief  Source file for Dio driver - TM4C123GH6PM Microcontroller.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Dio.h"

/**********************************************************************************************************************
 *  LOCAL MACROS CONSTANT\FUNCTION
 *********************************************************************************************************************/

/* GPIO Registers base addresses with adding 0x3fc mask*/
#define GPIO_PORTA_ADDRESS           0x400043FC
#define GPIO_PORTB_ADDRESS           0x400053FC
#define GPIO_PORTC_ADDRESS           0x400063FC
#define GPIO_PORTD_ADDRESS           0x400073FC
#define GPIO_PORTE_ADDRESS           0x400243FC
#define GPIO_PORTF_ADDRESS           0x400253FC

#define BITBAND_BASE_PERIPHERALS          0x40000000
#define BITBAND_ALIAS_BASE_PERIPHERALS    0x42000000

/* Bit banding equations according to datasheet.
***************************************************
 * bit_word_offset = (byte_offset x 32) + (bit_number x 4)
 *  bit_word_addr = bit_band_base + bit_word_offset
 */
/* Macro to calculate the location of a given bit in the bitband allias memory. */
#define BITBAND_TARGET_BIT_ADDRESS(register_base_address, bit_number) (BITBAND_ALIAS_BASE_PERIPHERALS + (((register_base_address) - BITBAND_BASE_PERIPHERALS)* 32) + ((bit_number)*4))



#define GPIO_PORTA_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 0)))
#define GPIO_PORTA_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 1)))
#define GPIO_PORTA_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 2)))
#define GPIO_PORTA_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 3)))
#define GPIO_PORTA_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 4)))
#define GPIO_PORTA_BIT5            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 5)))
#define GPIO_PORTA_BIT6            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 6)))
#define GPIO_PORTA_BIT7            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, 7)))
	
#define GPIO_PORTB_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 0)))
#define GPIO_PORTB_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 1)))
#define GPIO_PORTB_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 2)))
#define GPIO_PORTB_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 3)))
#define GPIO_PORTB_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 4)))
#define GPIO_PORTB_BIT5            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 5)))
#define GPIO_PORTB_BIT6            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 6)))
#define GPIO_PORTB_BIT7            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, 7)))
	
#define GPIO_PORTC_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 0)))
#define GPIO_PORTC_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 1)))
#define GPIO_PORTC_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 2)))
#define GPIO_PORTC_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 3)))
#define GPIO_PORTC_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 4)))
#define GPIO_PORTC_BIT5            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 5)))
#define GPIO_PORTC_BIT6            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 6)))
#define GPIO_PORTC_BIT7            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, 7)))
	
#define GPIO_PORTD_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 0)))
#define GPIO_PORTD_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 1)))
#define GPIO_PORTD_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 2)))
#define GPIO_PORTD_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 3)))
#define GPIO_PORTD_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 4)))
#define GPIO_PORTD_BIT5            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 5)))
#define GPIO_PORTD_BIT6            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 6)))
#define GPIO_PORTD_BIT7            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, 7)))
	
#define GPIO_PORTE_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 0)))
#define GPIO_PORTE_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 1)))
#define GPIO_PORTE_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 2)))
#define GPIO_PORTE_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 3)))
#define GPIO_PORTE_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 4)))
#define GPIO_PORTE_BIT5            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, 5)))
	
#define GPIO_PORTF_BIT0            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, 0)))
#define GPIO_PORTF_BIT1            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, 1)))
#define GPIO_PORTF_BIT2            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, 2)))
#define GPIO_PORTF_BIT3            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, 3)))
#define GPIO_PORTF_BIT4            *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, 4))) 


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)        
* \Description     : Read the level a given bin.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId - ID of DIO channel.                     
* \Parameters (out): Level of DIO channel                                                     
* \Return value:   : Dio_LevelType.                                   
*******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

	switch(ChannelId)
	{
		case CHANNAL_A0:   return  GPIO_PORTA_BIT0;	                   
	                     
		
		case CHANNAL_A1:   return  GPIO_PORTA_BIT1;	                   
	                     
		
		case CHANNAL_A2:   return  GPIO_PORTA_BIT2;	                   
	                     
		
		case CHANNAL_A3:   return  GPIO_PORTA_BIT3;		                  
	                     
		
		case CHANNAL_A4:   return  GPIO_PORTA_BIT4;		                   
	                     
		
		case CHANNAL_A5:   return  GPIO_PORTA_BIT5;		                   
	                     
											 
		case CHANNAL_A6:   return  GPIO_PORTA_BIT6;
	                     
											 
	  case CHANNAL_A7:   return  GPIO_PORTA_BIT7;		                   
	                     
											 
 	  case CHANNAL_B0:   return  GPIO_PORTB_BIT0;
	                     
		
		case CHANNAL_B1:   return  GPIO_PORTB_BIT1;	                
	                     
		
		case CHANNAL_B2:   return  GPIO_PORTB_BIT2;
	                     
		
		case CHANNAL_B3:   return  GPIO_PORTB_BIT3;
	                     
		
		case CHANNAL_B4:   return  GPIO_PORTB_BIT4;
	                     
		
		case CHANNAL_B5:   return  GPIO_PORTB_BIT5;
	                     
											 
		case CHANNAL_B6:   return  GPIO_PORTB_BIT6;
	                     
											 
	  case CHANNAL_B7:   return  GPIO_PORTB_BIT7;
	                     
											 
		case CHANNAL_C0:   return  GPIO_PORTC_BIT0;
	                     
		
		case CHANNAL_C1:   return  GPIO_PORTC_BIT1;
	                     
		
		case CHANNAL_C2:   return  GPIO_PORTC_BIT2;
	                     
		
		case CHANNAL_C3:   return  GPIO_PORTC_BIT3;
	                     
		
		case CHANNAL_C4:   return  GPIO_PORTC_BIT4;
	                     
		
		case CHANNAL_C5:   return  GPIO_PORTC_BIT5;
	                     
											 
		case CHANNAL_C6:   return  GPIO_PORTC_BIT6;
	                     
											 
	  case CHANNAL_C7:   return  GPIO_PORTC_BIT7;
	                     
											 
 		case CHANNAL_D0:   return  GPIO_PORTD_BIT0;
	                     
		
		case CHANNAL_D1:   return  GPIO_PORTD_BIT1;
	                     
		
		case CHANNAL_D2:   return  GPIO_PORTD_BIT2;
	                     
		
		case CHANNAL_D3:   return  GPIO_PORTD_BIT3;
	                     
		
		case CHANNAL_D4:   return  GPIO_PORTD_BIT4;
	                     
		
		case CHANNAL_D5:   return  GPIO_PORTD_BIT5;
	                     
											 
		case CHANNAL_D6:   return  GPIO_PORTD_BIT6;
	                     
											 
	  case CHANNAL_D7:   return  GPIO_PORTD_BIT7;
	                     
											 
		case CHANNAL_E0:   return  GPIO_PORTE_BIT0;
	                     
		
		case CHANNAL_E1:   return  GPIO_PORTE_BIT1;
	                     
		
		case CHANNAL_E2:   return  GPIO_PORTE_BIT2;
	                     
		
		case CHANNAL_E3:   return  GPIO_PORTE_BIT3;
	                     
		
		case CHANNAL_E4:   return  GPIO_PORTE_BIT4;
	                     
		
		case CHANNAL_E5:   return  GPIO_PORTE_BIT5;
	                     
											 
		case CHANNAL_F0:   return  GPIO_PORTF_BIT0;
	                     
		
		case CHANNAL_F1:   return  GPIO_PORTF_BIT1;
	                     
		
		case CHANNAL_F2:   return  GPIO_PORTF_BIT2;
	                     
		
		case CHANNAL_F3:   return  GPIO_PORTF_BIT3;
	                     
		
		case CHANNAL_F4:   return  GPIO_PORTF_BIT4;
	                     											 	 										                   		
	}
	return E_NOT_OK;

}

/******************************************************************************
* \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)        
* \Description     : write the given level value to a given bin.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId - ID of DIO channel.
                     Level - Level of DIO channel.
* \Parameters (out): None                                                      
* \Return value:   : void.                                  
*******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	
	Dio_PortType portNum;
	
	portNum= ChannelId/8;
	
	
	/*chNum= ChannelId%8;*/
	switch(portNum)
	{
		case PORTA_NUM: *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, ChannelId%8)))= Level;
		             break;
		
		case PORTB_NUM: *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, ChannelId%8)))= Level;
		             break;
		
		case PORTC_NUM: *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, ChannelId%8)))= Level;
		             break;
		
		case PORTD_NUM: *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, ChannelId%8)))= Level;
		             break;
		
		case PORTE_NUM: *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, ChannelId%8)))= Level;
		             break;
		
		case PORTF_NUM: *((volatile uint32 *)BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, ChannelId%8))= Level;
		             break;		
	}
		
	
}

/******************************************************************************
* \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)        
* \Description     : Read the value on a given port.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId - ID of DIO port.                     
* \Parameters (out): Port level                                                      
* \Return value:   : Dio_PortLevelType  
*                                                                    
*******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
	switch(PortId)
	{
		case PORTA_NUM: return *(volatile uint32 *)(GPIO_PORTA_ADDRESS);
		                
		
		case PORTB_NUM: return *(volatile uint32 *)(GPIO_PORTB_ADDRESS);
		                
		
		case PORTC_NUM: return *(volatile uint32 *)(GPIO_PORTC_ADDRESS);
		                
		
		case PORTD_NUM: return *(volatile uint32 *)(GPIO_PORTD_ADDRESS);
		                
		
		case PORTE_NUM: return *(volatile uint32 *)(GPIO_PORTE_ADDRESS);
		                
		
		case PORTF_NUM: return *(volatile uint32 *)(GPIO_PORTF_ADDRESS);	             	
		
	}
	return E_NOT_OK;
	
}

/******************************************************************************
* \Syntax          : void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)        
* \Description     : Write a given value to a given port.                                                                                                              
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : PortId - ID of DIO Port.
                     Level  _ Value of Port.
* \Parameters (out): None                                                      
* \Return value:   : void.                                  
*******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
		switch(PortId)
	{
		case PORTA_NUM: *(volatile uint32 *)(GPIO_PORTA_ADDRESS) = Level;
		                break;
		
		case PORTB_NUM: *(volatile uint32 *)(GPIO_PORTB_ADDRESS) = Level;
		                break;
		
		case PORTC_NUM: *(volatile uint32 *)(GPIO_PORTC_ADDRESS) = Level;
		                break;
		
		case PORTD_NUM: *(volatile uint32 *)(GPIO_PORTD_ADDRESS) = Level;
		                break;
		
		case PORTE_NUM: *(volatile uint32 *)(GPIO_PORTE_ADDRESS) = Level;
		                break;
		
		case PORTF_NUM: *(volatile uint32 *)(GPIO_PORTF_ADDRESS) = Level;
		                break;
	}
}
	

/******************************************************************************
* \Syntax          :  Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)        
* \Description     : flip the given bin level.                                                                                                               
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : ChannelId - ID of DIO channel.                     
* \Parameters (out): Level.                                                      
* \Return value:   : Dio_LevelType.                                  
*******************************************************************************/
 Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	 Dio_LevelType level = STD_IDLE;
	 Dio_PortType portNum;
	
	 portNum= ChannelId/8;
	
	
	/*chNum= ChannelId%8;*/
	switch(portNum)
	{
		case PORTA_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTA_ADDRESS, ChannelId%8)));
		             break;
		
		case PORTB_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTB_ADDRESS, ChannelId%8)));
		             break;
		
		case PORTC_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTC_ADDRESS, ChannelId%8)));
		             break;
		
		case PORTD_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTD_ADDRESS, ChannelId%8)));
		             break;
		
		case PORTE_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTE_ADDRESS, ChannelId%8)));
		             break;
		
		case PORTF_NUM: level = *((volatile uint32 *)(BITBAND_TARGET_BIT_ADDRESS(GPIO_PORTF_ADDRESS, ChannelId%8)));
		             break;		
	}
	
	if(level == STD_IDLE)
	{
		level = STD_ACTIVE;
	}
	else
	{
		level = STD_IDLE;
	}
	
	return level;
		
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/

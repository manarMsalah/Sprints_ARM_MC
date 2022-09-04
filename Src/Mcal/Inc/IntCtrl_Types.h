/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  IntCtrl
 *
 *  Description:  Data types used for IntCtrl module.     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
 /* enum to hold all the interrupts in the vector table. */
typedef enum{
	INTCTRL_RESET= 1,
	INTCTRL_NMI,
	INTCTRL_HARD_FAULT,
	INTCTRL_MEMORY_MANAGEMENT_FAULT,
	INTCTRL_BUS_FAULT,
	INTCTRL_USAGE_FAULT,
	INTCTRL_SVCALL= 11,
	INTCTRL_DEBUG_MONITOR,
	INTCTRL_PENDSV= 14,
	INTCTRL_SYSTICK,
	INTCTRL_GPIO_PORTA,
	INTCTRL_GPIO_PORTB,
	INTCTRL_GPIO_PORTC,
	INTCTRL_GPIO_PORTD,
	INTCTRL_GPIO_PORTE,
	INTCTRL_UART0,
	INTCTRL_UART1,
	INTCTRL_SSI0,
	INTCTRL_I2C0,
	INTCTRL_PWM0_FAULT,
	INTCTRL_PWM0_GENERATOR_0,
	INTCTRL_PWM0_GENERATOR_1,
	INTCTRL_PWM0_GENERATOR_2,
	INTCTRL_QEI0,
	INTCTRL_ADC0_SEQUENCE_0,
	INTCTRL_ADC0_SEQUENCE_1,
	INTCTRL_ADC0_SEQUENCE_2,
	INTCTRL_ADC0_SEQUENCE_3,
	INTCTRL_WATCHDOG_TIMER_0_AND_TIMER_1,
	INTCTRL_16_32_BIT_TIMER_0A,
	INTCTRL_16_32_BIT_TIMER_0B,
	INTCTRL_16_32_BIT_TIMER_1A,
	INTCTRL_16_32_BIT_TIMER_1B,
	INTCTRL_16_32_BIT_TIMER_2A,
	INTCTRL_16_32_BIT_TIMER_2B,
	INTCTRL_ANALOG_COMPARATOR_0,
	INTCTRL_ANALOG_COMPARATOR_1,
	INTCTRL_SYSTEM_CONTROL= 44,
	INTCTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL,
	INTCTRL_GPIO_PORTF,
	INTCTRL_UART2= 49,
	INTCTRL_SSI1,
	INTCTRL_16_32_BIT_TIMER_3A,
	INTCTRL_16_32_BIT_TIMER_3B,
	INTCTRL_I2C1,
	INTCTRL_QEI1,
	INTCTRL_CAN0,
	INTCTRL_CAN1,
	INTCTRL_HIBERNATION_MODULE= 59,
	INTCTRL_USB,
	INTCTRL_PWM_GENERATOR_3,
	INTCTRL_mDMA_SOFTWARE,
	INTCTRL_mDMA_ERROR,
	INTCTRL_ADC1_SEQUENCE_0,
	INTCTRL_ADC1_SEQUENCE_1,
	INTCTRL_ADC1_SEQUENCE_2,
	INTCTRL_ADC1_SEQUENCE_3,
	INTCTRL_SSI2= 73,
	INTCTRL_SSI3,
	INTCTRL_UART3,
	INTCTRL_UART4,
	INTCTRL_UART5,
	INTCTRL_UART6,
	INTCTRL_UART7,
	INTCTRL_I2C2= 84,
	INTCTRL_I2C3,
	INTCTRL_16_32_BIT_TIMER_4A,
	INTCTRL_16_32_BIT_TIMER_4B,
	INTCTRL_16_32_BIT_TIMER_5A= 108,
	INTCTRL_16_32_BIT_TIMER_5B,
	INTCTRL_32_64_BIT_TIMER_0A,
	INTCTRL_32_64_BIT_TIMER_0B,
	INTCTRL_32_64_BIT_TIMER_1A,
	INTCTRL_32_64_BIT_TIMER_1B,
	INTCTRL_32_64_BIT_TIMER_2A,
	INTCTRL_32_64_BIT_TIMER_2B,
	INTCTRL_32_64_BIT_TIMER_3A,
	INTCTRL_32_64_BIT_TIMER_3B,
	INTCTRL_32_64_BIT_TIMER_4A,
	INTCTRL_32_64_BIT_TIMER_4B,
	INTCTRL_32_64_BIT_TIMER_5A,
	INTCTRL_32_64_BIT_TIMER_5B,
	INTCTRL_SYSTEM_EXCEPTION_IMPRECISE,
	INTCTRL_PWM1_GENERATOR_0= 150,
	INTCTRL_PWM1_GENERATOR_1,
	INTCTRL_PWM1_GENERATOR_2,
	INTCTRL_PWM1_GENERATOR_3,
	INTCTRL_PWM1_FAULT	
}IntCtrl_InterruptType;




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/

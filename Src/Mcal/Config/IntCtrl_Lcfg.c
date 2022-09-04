/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  Source file for the IntCtrl configuration.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
 /* Configuration structure to enable and disable interrubts 
 * and assign the priority group and sub-group for all the interrupts in the vector table.
 */
 const INTCTRL_ConfigType IntCtrl_Configuration= {
	 
	 { {INTCTRL_RESET, INTCTRL_ENABLE_INTERRUPT, NOT_CONFIGURABLE, NOT_CONFIGURABLE},
	 
	   {INTCTRL_NMI, NOT_CONFIGURABLE, NOT_CONFIGURABLE, NOT_CONFIGURABLE},
		 
		 {INTCTRL_HARD_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_CONFIGURABLE, NOT_CONFIGURABLE},
		 
		 {INTCTRL_MEMORY_MANAGEMENT_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_BUS_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_USAGE_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SVCALL, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_DEBUG_MONITOR, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PENDSV, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SYSTICK, INTCTRL_ENABLE_INTERRUPT, 3, 0}, /* Enable SysTick interrupt, assign priority group by 1 and sub-group by 0. */
		 
     {INTCTRL_GPIO_PORTA, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_GPIO_PORTB, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_GPIO_PORTC, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_GPIO_PORTD, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_GPIO_PORTE, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_UART0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_UART1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SSI0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_I2C0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM0_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_PWM0_GENERATOR_0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_PWM0_GENERATOR_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM0_GENERATOR_2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_QEI0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ADC0_SEQUENCE_0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ADC0_SEQUENCE_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_ADC0_SEQUENCE_2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ADC0_SEQUENCE_3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_WATCHDOG_TIMER_0_AND_TIMER_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_16_32_BIT_TIMER_0A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_16_32_BIT_TIMER_0B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_1A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_1B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_2A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_2B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_ANALOG_COMPARATOR_0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ANALOG_COMPARATOR_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SYSTEM_CONTROL, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_GPIO_PORTF, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_UART2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SSI1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_16_32_BIT_TIMER_3A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_3B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_I2C1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_QEI1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_CAN0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_CAN1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_HIBERNATION_MODULE, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_USB, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM_GENERATOR_3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_mDMA_SOFTWARE, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_mDMA_ERROR, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ADC1_SEQUENCE_0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_ADC1_SEQUENCE_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_ADC1_SEQUENCE_2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_ADC1_SEQUENCE_3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SSI2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_SSI3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_UART3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_UART4, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_UART5, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_UART6, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_UART7, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_I2C2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_I2C3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_16_32_BIT_TIMER_4A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_16_32_BIT_TIMER_4B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_5A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_16_32_BIT_TIMER_5B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_0A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_0B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_32_64_BIT_TIMER_1A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_1B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_2A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_2B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
     {INTCTRL_32_64_BIT_TIMER_3A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_32_64_BIT_TIMER_3B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_4A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_4B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_5A, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_32_64_BIT_TIMER_5B, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_SYSTEM_EXCEPTION_IMPRECISE, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM1_GENERATOR_0, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM1_GENERATOR_1, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
	   {INTCTRL_PWM1_GENERATOR_2, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM1_GENERATOR_3, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE},
		 
		 {INTCTRL_PWM1_FAULT, INTCTRL_DISABLE_INTERRUPT, NOT_APPLICABLE, NOT_APPLICABLE} }
		 
 };
	 

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/




/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Source code for IntCtrl module.
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

#define INTCTRL_PRIORITY_BASE_ADDRESS            0xE000E000
#define APINT                                  *((volatile uint32*)(INTCTRL_PRIORITY_BASE_ADDRESS + 0xD0C))
	
/* Priority registers. */
#define INTCTRL_PRI0_REG             (*((volatile uint32 *)0xE000E400))
#define INTCTRL_PRI1_REG             (*((volatile uint32 *)0xE000E404))
#define INTCTRL_PRI2_REG             (*((volatile uint32 *)0xE000E408))
#define INTCTRL_PRI3_REG             (*((volatile uint32 *)0xE000E40C))
#define INTCTRL_PRI4_REG             (*((volatile uint32 *)0xE000E410))
#define INTCTRL_PRI5_REG             (*((volatile uint32 *)0xE000E414))
#define INTCTRL_PRI6_REG             (*((volatile uint32 *)0xE000E418))
#define INTCTRL_PRI7_REG             (*((volatile uint32 *)0xE000E41C))
#define INTCTRL_PRI8_REG             (*((volatile uint32 *)0xE000E420))
#define INTCTRL_PRI9_REG             (*((volatile uint32 *)0xE000E424))
#define INTCTRL_PRI10_REG            (*((volatile uint32 *)0xE000E428))
#define INTCTRL_PRI11_REG            (*((volatile uint32 *)0xE000E42C))
#define INTCTRL_PRI12_REG            (*((volatile uint32 *)0xE000E430))
#define INTCTRL_PRI13_REG            (*((volatile uint32 *)0xE000E434))
#define INTCTRL_PRI14_REG            (*((volatile uint32 *)0xE000E438))
#define INTCTRL_PRI15_REG            (*((volatile uint32 *)0xE000E43C))
#define INTCTRL_PRI16_REG            (*((volatile uint32 *)0xE000E440))
#define INTCTRL_PRI17_REG            (*((volatile uint32 *)0xE000E444))
#define INTCTRL_PRI18_REG            (*((volatile uint32 *)0xE000E448))
#define INTCTRL_PRI19_REG            (*((volatile uint32 *)0xE000E44C))
#define INTCTRL_PRI20_REG            (*((volatile uint32 *)0xE000E450))
#define INTCTRL_PRI21_REG            (*((volatile uint32 *)0xE000E454))
#define INTCTRL_PRI22_REG            (*((volatile uint32 *)0xE000E458))
#define INTCTRL_PRI23_REG            (*((volatile uint32 *)0xE000E45C))
#define INTCTRL_PRI24_REG            (*((volatile uint32 *)0xE000E460))
#define INTCTRL_PRI25_REG            (*((volatile uint32 *)0xE000E464))
#define INTCTRL_PRI26_REG            (*((volatile uint32 *)0xE000E468))
#define INTCTRL_PRI27_REG            (*((volatile uint32 *)0xE000E46C))
#define INTCTRL_PRI28_REG            (*((volatile uint32 *)0xE000E470))
#define INTCTRL_PRI29_REG            (*((volatile uint32 *)0xE000E474))
#define INTCTRL_PRI30_REG            (*((volatile uint32 *)0xE000E478))
#define INTCTRL_PRI31_REG            (*((volatile uint32 *)0xE000E47C))
#define INTCTRL_PRI32_REG            (*((volatile uint32 *)0xE000E480))
#define INTCTRL_PRI33_REG            (*((volatile uint32 *)0xE000E484))
#define INTCTRL_PRI34_REG            (*((volatile uint32 *)0xE000E488))

/* Priority registers for SCB. */
#define INTCTRL_SYSTEM_PRI1_REG      (*((volatile uint32 *)0xE000ED18))
#define INTCTRL_SYSTEM_PRI2_REG      (*((volatile uint32 *)0xE000ED1C))
#define INTCTRL_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))
	
/* Start position in the interrupt priority register. */
#define INTCTRL_PRIORITY_START_POSITION_5    5
#define INTCTRL_PRIORITY_START_POSITION_13   13
#define INTCTRL_PRIORITY_START_POSITION_21   21
#define INTCTRL_PRIORITY_START_POSITION_29   29

/* Mask for each start position. */
#define INTCTRL_PRIORITY_MASK_START_POSITION_5   0xFFFFFF1F
#define INTCTRL_PRIORITY_MASK_START_POSITION_13  0xFFFF1FFF
#define INTCTRL_PRIORITY_MASK_START_POSITION_21  0xFF1FFFFF
#define INTCTRL_PRIORITY_MASK_START_POSITION_29  0x1FFFFFFF


/* Interrupt set enable regesters. */
#define INTCTRL_EN0_REG              (*((volatile unsigned long *)0xE000E100))
#define INTCTRL_EN1_REG              (*((volatile unsigned long *)0xE000E104))
#define INTCTRL_EN2_REG              (*((volatile unsigned long *)0xE000E108))
#define INTCTRL_EN3_REG              (*((volatile unsigned long *)0xE000E10C))
#define INTCTRL_EN4_REG              (*((volatile unsigned long *)0xE000E110))
	
	
/* Group and sub-group compinations. */
#define INTCTRL_GROUP_COMPINATION_XXX         (uint8)4
#define INTCTRL_GROUP_COMPINATION_XXY         (uint8)5
#define INTCTRL_GROUP_COMPINATION_XYY         (uint8)6
#define INTCTRL_GROUP_COMPINATION_YYY         (uint8)7

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
 
static const INTCTRL_ConfigInterrupt * INTCTRL_IntPtr = NULL_PTR;

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
* \Syntax          : void IntCtrl_init(const INTCTRL_ConfigType* ConfigPtr)        
* \Description     : Initiate IntCtrl module according to the configuration.                                                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr - Pointer to post-build configuration data.                    
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
 void IntCtrl_init(const INTCTRL_ConfigType* ConfigPtr)
{
	
	INTCTRL_IntPtr= ConfigPtr-> Interrupt_Set;
	
	/* configure grouping and subgrouping int APINT register in SCB */
	APINT = (0xFA05 << 16)|(INTCTRL_GROUP_COMPINATION_XXX << 8);
	
	for(int i= 0; i< INTCTRL_NUMBER_OF_INTERRUPTS; i++)
	{
		if(INTCTRL_IntPtr[i].Int_Avalablity == INTCTRL_ENABLE_INTERRUPT)
		{
			
			/****************************** Set the priority of this interrupt. *************************************/
			if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_SYSTICK)
			{
				INTCTRL_SYSTEM_PRI3_REG = (INTCTRL_SYSTEM_PRI3_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTA)
			{
				INTCTRL_PRI0_REG = (INTCTRL_PRI0_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTB)
			{
				INTCTRL_PRI0_REG = (INTCTRL_PRI0_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTC)
			{
				INTCTRL_PRI0_REG = (INTCTRL_PRI0_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTD)
			{
				INTCTRL_PRI0_REG = (INTCTRL_PRI0_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTE)
			{
				INTCTRL_PRI1_REG = (INTCTRL_PRI1_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_UART0)
			{
				INTCTRL_PRI1_REG = (INTCTRL_PRI1_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_UART1)
			{
				INTCTRL_PRI1_REG = (INTCTRL_PRI1_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_SSI0)
			{
				INTCTRL_PRI1_REG = (INTCTRL_PRI1_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_I2C0)
			{
				INTCTRL_PRI2_REG = (INTCTRL_PRI2_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_PWM0_FAULT)
			{
				INTCTRL_PRI2_REG = (INTCTRL_PRI2_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_PWM0_GENERATOR_0)
			{
				INTCTRL_PRI2_REG = (INTCTRL_PRI2_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_PWM0_GENERATOR_1)
			{
				INTCTRL_PRI2_REG = (INTCTRL_PRI2_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_PWM0_GENERATOR_2)
			{
				INTCTRL_PRI3_REG = (INTCTRL_PRI3_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_QEI0)
			{
				INTCTRL_PRI3_REG = (INTCTRL_PRI3_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ADC0_SEQUENCE_0)
			{
				INTCTRL_PRI3_REG = (INTCTRL_PRI3_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ADC0_SEQUENCE_1)
			{
				INTCTRL_PRI3_REG = (INTCTRL_PRI3_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
						else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ADC0_SEQUENCE_2)
			{
				INTCTRL_PRI4_REG = (INTCTRL_PRI4_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ADC0_SEQUENCE_3)
			{
				INTCTRL_PRI4_REG = (INTCTRL_PRI4_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_WATCHDOG_TIMER_0_AND_TIMER_1)
			{
				INTCTRL_PRI4_REG = (INTCTRL_PRI4_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_0A)
			{
				INTCTRL_PRI4_REG = (INTCTRL_PRI4_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_0B)
			{
				INTCTRL_PRI5_REG = (INTCTRL_PRI5_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_1A)
			{
				INTCTRL_PRI5_REG = (INTCTRL_PRI5_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_1B)
			{
				INTCTRL_PRI5_REG = (INTCTRL_PRI5_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_2A)
			{
				INTCTRL_PRI5_REG = (INTCTRL_PRI5_REG & INTCTRL_PRIORITY_MASK_START_POSITION_29) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_29);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_16_32_BIT_TIMER_2B)
			{
				INTCTRL_PRI6_REG = (INTCTRL_PRI6_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ANALOG_COMPARATOR_0)
			{
				INTCTRL_PRI6_REG = (INTCTRL_PRI6_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_ANALOG_COMPARATOR_1)
			{
				INTCTRL_PRI6_REG = (INTCTRL_PRI6_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_SYSTEM_CONTROL)
			{
				INTCTRL_PRI7_REG = (INTCTRL_PRI7_REG & INTCTRL_PRIORITY_MASK_START_POSITION_5) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_5);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL)
			{
				INTCTRL_PRI7_REG = (INTCTRL_PRI7_REG & INTCTRL_PRIORITY_MASK_START_POSITION_13) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_13);
			}
			else if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_GPIO_PORTF)
			{
				INTCTRL_PRI7_REG = (INTCTRL_PRI7_REG & INTCTRL_PRIORITY_MASK_START_POSITION_21) | (INTCTRL_IntPtr[i].Int_Group_Priority << INTCTRL_PRIORITY_START_POSITION_21);
			}

					
			
			/******************************* Enable the corresponding interrupt. ************************************/
			if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_RESET && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_SYSTICK)
			{
				/* No need to enable interrupt because it is system interrupt. */
				
			}
			else if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_GPIO_PORTA && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_GPIO_PORTF)
			{
				/* Exception_Type= vector number
				 * Exception_Type - 16= interrupt number */
				INTCTRL_EN0_REG |=  (0x00000001 << (INTCTRL_IntPtr[i].Exception_Type - 16));
				
			}
			else if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_UART2 && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_UART7)
			{
				/* -32 to get the order of the bit in the EN_REG */
				INTCTRL_EN1_REG |=  (0x00000001 << ((INTCTRL_IntPtr[i].Exception_Type - 16) - 32)); 
				
			}
			else if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_I2C2 && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_32_64_BIT_TIMER_0B)
			{
				/* -64 to get the order of the bit in the EN_REG */
				INTCTRL_EN2_REG |=  (0x00000001 << ((INTCTRL_IntPtr[i].Exception_Type - 16) - 64));
				
			}
			else if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_32_64_BIT_TIMER_1A && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_SYSTEM_EXCEPTION_IMPRECISE)
			{
				/* -96 to get the order of the bit in the EN_REG */
				INTCTRL_EN3_REG |=  (0x00000001 << ((INTCTRL_IntPtr[i].Exception_Type - 16) - 96));
				
			}
			else if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_PWM1_GENERATOR_0 && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_PWM1_FAULT)
			{
				/* -128 to get the order of the bit in the EN_REG */
				INTCTRL_EN4_REG |=  (0x00000001 << ((INTCTRL_IntPtr[i].Exception_Type - 16) - 128));
				
			}
			
		}
		else
		{
				/* No need to disable the corresponding interrupt. */

			
		}
			
		
		
		
	}
	

	
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/

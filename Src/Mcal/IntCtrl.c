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
	
#define INTCTRL_SYSTEM_PRI1_REG      (*((volatile uint32 *)0xE000ED18))
#define INTCTRL_SYSTEM_PRI2_REG      (*((volatile uint32 *)0xE000ED1C))
#define INTCTRL_SYSTEM_PRI3_REG      (*((volatile uint32 *)0xE000ED20))
	
#define INTCTRL_SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define INTCTRL_SYSTICK_INTERRUPT_PRIORITY  3
#define INTCTRL_SYSTICK_PRIORITY_START_POSITION   29
	
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
			/* Set the priority of this interrupt. */
			if(INTCTRL_IntPtr[i].Exception_Type == INTCTRL_SYSTICK)
			{
				INTCTRL_SYSTEM_PRI3_REG = (INTCTRL_SYSTEM_PRI3_REG & INTCTRL_SYSTICK_PRIORITY_MASK) | (INTCTRL_SYSTICK_INTERRUPT_PRIORITY << INTCTRL_SYSTICK_PRIORITY_START_POSITION);
			}
			
			
			
			/* Enable the corresponding interrupt. */
			if(INTCTRL_IntPtr[i].Exception_Type >= INTCTRL_RESET && INTCTRL_IntPtr[i].Exception_Type <= INTCTRL_SYSTICK)
			{
				/* No need to enable interrupt because it is system interrupt. */
			}
			else
			{
				
			}
			
		}
		else
		{
				/* Disable the corresponding interrupt if need or do nothing. */

			
		}
			
		
		
		
	}
	

	
	
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/

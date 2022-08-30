/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
 *        \brief  Source file for Timer module.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
**********************************************************************************************************************/

/* SysTick Registers. */
#define SYSTICK_CTRL_REG          (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG        (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG       (*((volatile uint32 *)0xE000E018))
	
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
* \Syntax          : void Systick_start(Timer_ValueType tick_time)        
* \Description     : Enable and set SysTick timer.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : tick_time - tick time in millisecond.                     
* \Parameters (out): None                                                      
* \Return value:   : None.                                  
*******************************************************************************/
void Systick_start(Systick_ValueType tick_time)
{
	/* Disable SysTick timer by clearing ENABLE bit in the CTRL register. */
	SYSTICK_CTRL_REG = 0;
	/* To count tick time by second. */
	SYSTICK_RELOAD_REG = 15999999 * tick_time;
	
	SYSTICK_CURRENT_REG = 0;
	/* Use system clock by setting CLK_SRC bit in the CTRL register.
	 * Enable SysTick interrupt by setting INTEN bit in the CTRL register.
	 * Enable SysTick timer by setting ENABLE bit in the CTRL register. */
	SYSTICK_CTRL_REG = 0x07;
}


/******************************************************************************
* \Syntax          : void Systick_stop(void)        
* \Description     : Disable SysTick timer.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None.                     
* \Parameters (out): None.                                                     
* \Return value:   : None.                                  
*******************************************************************************/
void Systick_stop(void)
{
	/* Disable SysTick timer by clearing ENABLE bit in the CTRL register. */
	SYSTICK_CTRL_REG = 0;
}



/******************************************************************************
* \Syntax          : void SysTick_Handler(void)       
* \Description     : SysTick timer ISR.                                     
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None.                      
* \Parameters (out): None.                                                      
* \Return value:   : None.                                  
*******************************************************************************/
void SysTick_Handler(void)
{
	/* If Systick_setCallBack clled the value of Systick_Call_Back_Ptr will change to the call back funtion. */
	if(Systick_Call_Back_Ptr != NULL_PTR)
	{
		(*Systick_Call_Back_Ptr)();
	}
}


/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/

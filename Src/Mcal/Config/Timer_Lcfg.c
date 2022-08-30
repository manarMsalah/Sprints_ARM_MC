/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer_Lcfg.c
 *        \brief  Source file to set timer configuration.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Timer_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

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
* \Syntax          : void Systick_setCallBack(void)        
* \Description     : Function to set which function will call it back.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : void(*ptr2Fun)(void)  _ Pointer to function.                    
* \Parameters (out): None.                                                      
* \Return value:   : None.                                  
*******************************************************************************/
void Systick_setCallBack(void(*ptr2Fun)(void))
{
	Systick_Call_Back_Ptr = ptr2Fun;
}

/**********************************************************************************************************************
 *  END OF FILE: Timer_Lcfg.c
 *********************************************************************************************************************/

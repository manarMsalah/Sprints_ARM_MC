/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Appl.c
 *        \brief  Source file for Appl module.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"
#include "IntCtrl.h"
#include "Timer.h"
#include "Led.h"
#include "Switch.h"
#include "Appl.h"


/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define Enable_Global_Interrupt()    __asm("CPSIE I")
#define Disable_Global_Interrupt()   __asm("CPSID I")


#define TICK_TIME_BY_SECOND      1

#define SWITCH_1       CHANNAL_F4
#define SWITCH_2       CHANNAL_F0


/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint16 g_NewTickCount = 0;
uint8 g_NewTickFlag = 0;

uint16 g_OnTime = 0;
uint16 g_OffTime = 10;



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
* \Syntax          : void Appl_SetUp(void)        
* \Description     : Set drivers gonfigurations and start timer.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Appl_SetUp(void)
{
	Port_Init(&Port_Configuration);
	IntCtrl_init(&IntCtrl_Configuration);
	
	Enable_Global_Interrupt();
	
	Systick_setCallBack(Appl_NewTick);
	
	Systick_start(TICK_TIME_BY_SECOND);
	
}



/******************************************************************************
* \Syntax          : void Appl_NewTick(void)        
* \Description     : Calculate timer tick counts.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Appl_NewTick(void)
{
	g_NewTickCount++;
	g_NewTickFlag= 1;
	
}

/******************************************************************************
* \Syntax          : void Appl_SetOnAndOffTime(void)        
* \Description     : Set the logic of each switch to control the on and off time and start simulation of the LED.                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Appl_SetOnAndOffTime(void)
{
	
	while(1)
	{

	 if(Switch_getState(SWITCH_1) == SWITCH_PRESSED ) 
	 {
		 /* Start counting the 4 seconds of the long press on SW1. */
		 g_NewTickCount = 0;
		 
		 /* Wait for releasing the button or pressed for 4 seconds( if you want the simulation of the LED starts. */
	   while((Switch_getState(SWITCH_1) != SWITCH_RELEASED) && (g_NewTickCount < 4));
		 
		 if(g_NewTickCount == 4)
		 {
			 break;
		 }
		 
		 /* Each press on SW1 increase the ON time and decrease OFF time. */
		 if( g_OnTime < 10 && g_OffTime > 0)
		 {
			 g_OnTime++;
			 g_OffTime--;
		 } 
		 
	 }
	 else if(Switch_getState(SWITCH_2) == SWITCH_PRESSED )
	 {
		 /* Wait for releasing the button. */
		 while(Switch_getState(SWITCH_2) != SWITCH_RELEASED);
		 
		 /* Each press on SW2 decrease the ON time and increase OFF time. */
		 if( g_OnTime > 0 && g_OffTime < 10)
		 {
			 g_OnTime--;
			 g_OffTime++;
		 }
   
	 }
	 
  }
			
}


/******************************************************************************
* \Syntax          : void Led_Control(void)        
* \Description     : lights a LED for the given ON time, and dim it for the given OFF time.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None                                  
*******************************************************************************/
void Appl_LedControl(void)
{
	uint16 totalTime = g_OnTime + g_OffTime;
	
	g_NewTickCount= 0;
	
	Led_setOn();
	
	while(1)
	{
			if(g_NewTickFlag == 1)
			{
				if(g_NewTickCount == g_OnTime)
				{
					Led_setOff();
					g_NewTickFlag= 0;		      
				}

		    else if(g_NewTickCount == totalTime)
				{
					Led_setOn();
		    	g_NewTickFlag= 0;
		    	g_NewTickCount= 0;
				}
			}
			
			/* If you want to reset the on and off time. */
			if( Switch_getState(SWITCH_2) == SWITCH_PRESSED)
			{
				/* Wait for releasing the button. */
				while(Switch_getState(SWITCH_2) != SWITCH_RELEASED);
				
				Led_setOff();
				
				break;
			}

	}
		
}

/**********************************************************************************************************************
 *  END OF FILE: Appl.c
 *********************************************************************************************************************/

/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  IntCtrl
 *
 *  Description:  Header file for IntCtrl configuration.     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /* Number of interrupts according to the vector table. */
#define INTCTRL_NUMBER_OF_INTERRUPTS          (uint8)95


/* Enable or disable interrupt. */
#define INTCTRL_DISABLE_INTERRUPT               (uint8)0
#define INTCTRL_ENABLE_INTERRUPT                (uint8)1

/* random values for not applicable cases */
#define NOT_APPLICABLE             (uint8)200
#define RESERVED                   (uint8)201
#define NOT_CONFIGURABLE           (uint8)202

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* structure to hold the interupt configurations. */
typedef struct{
	IntCtrl_InterruptType Exception_Type;
	uint8 Int_Avalablity;
	uint8 Int_Group_Priority;
	uint8 Int_Sub_Group_Priority;
}INTCTRL_ConfigInterrupt;


/* structure hold array of strutures to make the settings for each interrupt. */
typedef struct{
	INTCTRL_ConfigInterrupt Interrupt_Set[INTCTRL_NUMBER_OF_INTERRUPTS];
}INTCTRL_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_CFG_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/

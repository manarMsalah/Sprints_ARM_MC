/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Appl.h
 *       Module:  Appl
 *
 *  Description:  Header file for Appl module.     
 *  
 *********************************************************************************************************************/
#ifndef APPL_H
#define APPL_H

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


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Appl_SetUp(void);

void Appl_NewTick(void);

void Appl_LedControl(uint16, uint16);
 
#endif  /* APPL_H */

/**********************************************************************************************************************
 *  END OF FILE: Appl.h
 *********************************************************************************************************************/
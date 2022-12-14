/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Switch.h
 *       Module:  Switch
 *
 *  Description:  Header file for Switch module.     
 *  
 *********************************************************************************************************************/
#ifndef SWITCH_H
#define SWITCH_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Dio.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 
/* Internal pull up resistor. */
#define SWITCH_PRESSED  STD_LOW
#define SWITCH_RELEASED STD_HIGH

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
 
Dio_LevelType Switch_getState(Dio_ChannelType Switch_Id);



 
#endif  /* SWITCH_H */

/**********************************************************************************************************************
 *  END OF FILE: Switch.h
 *********************************************************************************************************************/

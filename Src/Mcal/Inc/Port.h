/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  Port
 *
 *  Description:  Header file for port module.     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 #include "Std_Types.h"
#include "port_Cfg.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

 /* Macros for Port Status */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
/* Type definition for Port_PinType used by the PORT APIs */
typedef uint8 Port_PinType;

/* Type definition for Port_PinModeType used by the PORT APIs */
typedef uint8 Port_PinModeType;

/* Type definition for Port_PinOutputCurrentType used by the PORT APIs */
typedef uint8 Port_PinOutputCurrentType;

/*enum for Port_PinDirectionType*/
typedef enum
{
	/* Member Sets port pin as input */
	PORT_PIN_IN=0,
	/* Member Sets port pin as output */
	PORT_PIN_OUT=1
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    DISABLE=0,
    PULL_UP=1,
    PULL_DOWN=2
}Port_PinInternalAttach;

typedef struct
{
	uint8 Port_num;

	Port_PinType Pin_num;

	Port_PinDirectionType Pin_direction;

	Port_PinModeType Pin_mode;

	Port_PinInternalAttach resistor;

	uint8 PortPinLevelValue;
	
	Port_PinOutputCurrentType PortPinOutputCurrent;

}Port_ConfigChannel;


/* Data Structure required for initializing the port Driver */
typedef struct
{
	Port_ConfigChannel Channel[NUMBER_OF_CHANNELS];
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const Port_ConfigType Port_Configuration;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Function for port init API */
void Port_Init( const Port_ConfigType* ConfigPtr );
 
#endif  /* PORT_H */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/

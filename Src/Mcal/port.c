/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief  Source file for Port Module.
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/* GPIO Registers base addresses */
#define GPIO_PORTA_BASE_ADDRESS           0x40004000
#define GPIO_PORTB_BASE_ADDRESS           0x40005000
#define GPIO_PORTC_BASE_ADDRESS           0x40006000
#define GPIO_PORTD_BASE_ADDRESS           0x40007000
#define GPIO_PORTE_BASE_ADDRESS           0x40024000
#define GPIO_PORTF_BASE_ADDRESS           0x40025000

/* GPIO Registers offset addresses */
#define PORT_DATA_REG_OFFSET              0x3FC
#define PORT_DIR_REG_OFFSET               0x400
#define PORT_ALT_FUNC_REG_OFFSET          0x420
#define PORT_PULL_UP_REG_OFFSET           0x510
#define PORT_PULL_DOWN_REG_OFFSET         0x514
#define PORT_DIGITAL_ENABLE_REG_OFFSET    0x51C
#define PORT_LOCK_REG_OFFSET              0x520
#define PORT_COMMIT_REG_OFFSET            0x524
#define PORT_ANALOG_MODE_SEL_REG_OFFSET   0x528
#define PORT_CTL_REG_OFFSET               0x52C

#define SYSCTL_REGCGC2_REG        (*((volatile uint32 *)0x400FE108))
	
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static const Port_ConfigChannel * Port_PortChannels = NULL_PTR;

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
* \Syntax          : Port_Init( const Port_ConfigType* ConfigPtr )        
* \Description     : Function to Initialize the Port module.                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : ConfigPtr - Pointer to post-build configuration data.                    
* \Parameters (out): None                                                      
* \Return value:   : None
*
*******************************************************************************/
void Port_Init( const Port_ConfigType* ConfigPtr )
{
  /*point to the PB configuration structure using a global pointer.
  * This global pointer is global to be used by other functions to read the PB configuration structures
  * address of the first Channels structure --> Channels[0] */  
  Port_PortChannels = ConfigPtr->Channel; 
  
  /* point to the required Port Registers base address */
  volatile uint32 * Port_Ptr = NULL_PTR; 
  
  volatile uint32 delay = 0;
  uint8 i;
  
    /*for loop to cover all GPIO pins*/
    for(i=0;i<NUMBER_OF_CHANNELS;i++)
    {
      /* Point to the correct port base address according to the Port Id stored in the Port_Num member */
      switch(Port_PortChannels[i].Port_num)
      {
      case  0: Port_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
      break;
      case  1: Port_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
      break;
      case  2: Port_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
      break;
      case  3: Port_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
      break;
      case  4: Port_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
      break;
      case  5: Port_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
      break; 
      }
      
      /* Enable clock for PORT and allow time for clock to start*/
      SYSCTL_REGCGC2_REG |= (1 <<  Port_PortChannels[i].Port_num);
      delay=SYSCTL_REGCGC2_REG;
      
      if( i == PORTD_PIN0_ID_INDEX || i == PORTD_PIN7_ID_INDEX ) /* PD7 or PF0 */
      {
        /* Unlock the GPIOCR register */
        *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_LOCK_REG_OFFSET) = 0x4C4F434B;
        /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_COMMIT_REG_OFFSET) , Port_PortChannels[i].Pin_num);  
      }
      else if( i >= PORTC_PIN0_ID_INDEX && i <= PORTC_PIN3_ID_INDEX ) /* PC0 to PC3 */
      {
        /* Do Nothing ...  this is the JTAG pins */
      }
      else
      {
        /* Do Nothing ... No need to unlock the commit register for this pin */
      }
      
          
      
      /* Adjust the pin initial mode*/
      
      /* Modes for analog pins*/
      
      if(Port_PortChannels[i].Pin_mode == PORT_PIN_MODE_ADC || Port_PortChannels[i].Pin_mode == PORT_PIN_MODE_ANALOG_COMPARATOR_INPUT || Port_PortChannels[i].Pin_mode == PORT_PIN_MODE_USB_ANALOG )
      {
        /* Clear the corresponding bit in the GPIOAMSEL register to disable digital functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        /* Set the corresponding bit in the GPIODEN register to enable analog functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        
      }
      else
      {
        /* Modes for digital pins*/
        
        /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        
        if(Port_PortChannels[i].Pin_mode == PORT_PIN_MODE_DIO)
        {
          /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[i].Pin_num);
          /* Clear the PMCx bits for this pin */
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortChannels[i].Pin_num * 4));
          /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        }
        else
        {
          /* Modes for digital pins except DIO */
          
          /* Enable Alternative function for this pin by set the corresponding bit in GPIOAFSEL register */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_ALT_FUNC_REG_OFFSET) , Port_PortChannels[i].Pin_num);
          /* Clear the PMCx bits for this pin as pre-step to Set them by the requested control number */
          *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << (Port_PortChannels[i].Pin_num * 4));
          
          switch(Port_PortChannels[i].Pin_mode)
          {                                          
          case PORT_PIN_MODE_DIO_GPT: 
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000007 << (Port_PortChannels[i].Pin_num * 4));
            break; 
            
          case PORT_PIN_MODE_PWM_MODULE0:  
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000004 << (Port_PortChannels[i].Pin_num * 4));                                    
            break;                                  
            
          case PORT_PIN_MODE_PWM_MODULE1: 
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000005 << (Port_PortChannels[i].Pin_num * 4));
            break;                        
            
          case PORT_PIN_MODE_QEI:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000006 << (Port_PortChannels[i].Pin_num * 4));
            break;
            
          case PORT_PIN_MODE_CAN: 
            /* Check pins for modes those have several control number */
            if(i == PORTF_PIN0_ID_INDEX || i == PORTF_PIN3_ID_INDEX)
            {
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000003 << (Port_PortChannels[i].Pin_num * 4));
            }
            else
            {
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (Port_PortChannels[i].Pin_num * 4));
            } 
            
            break;
            
          case PORT_PIN_MODE_SSI3:
          case PORT_PIN_MODE_UART:
          case PORT_PIN_MODE_JTAG:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000001 << (Port_PortChannels[i].Pin_num * 4));                     
            break;
            
          case  PORT_PIN_MODE_SSI:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000002 << (Port_PortChannels[i].Pin_num * 4));               
            break;
            
          case PORT_PIN_MODE_I2C:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000003 << (Port_PortChannels[i].Pin_num * 4));
            break;
            
            
          case PORT_PIN_MODE_UART1:
            /* Check pins for modes those have several control number */
            if( i == PORTB_PIN0_ID_INDEX || i == PORTB_PIN1_ID_INDEX )
            {
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000001 << (Port_PortChannels[i].Pin_num * 4));
            }
            else 
            {
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000002 << (Port_PortChannels[i].Pin_num * 4));
            }
            
            break;  
            
          case PORT_PIN_MODE_UART1_CONTROL:
            /* Check pins for modes those have several control number */
            if( i == PORTF_PIN0_ID_INDEX || i == PORTF_PIN1_ID_INDEX )
            { 
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000001 << (Port_PortChannels[i].Pin_num * 4));
            }
            else 
            {
              /* Set the PMCx bits for this pin by the mode control number*/
              *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (Port_PortChannels[i].Pin_num * 4));
            }
            
            break; 
            
          case PORT_PIN_MODE_USB_DIGITAL:
          case PORT_PIN_MODE_NMI:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000008 << (Port_PortChannels[i].Pin_num * 4));  
            break;
            
          case PORT_PIN_MODE_ANALOG_COMPARATOR_OUTPUT:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x00000009 << (Port_PortChannels[i].Pin_num * 4));
            break; 
            
          case PORT_PIN_MODE_CORE:
            /* Set the PMCx bits for this pin by the mode control number*/
            *(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_CTL_REG_OFFSET) |= (0x0000000E << (Port_PortChannels[i].Pin_num * 4));
            break;                       
          }  
          /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        }
      } 

/* Adjust the pin initial direction */  
      
      /*check the pin direction output or input*/
      if(Port_PortChannels[i].Pin_direction == PORT_PIN_OUT)
      {
        /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[i].Pin_num);
        
        /*  Adjust the initial value */
        /* check the initial value for output pins */
        if(Port_PortChannels[i].PortPinLevelValue == PORT_PIN_LEVEL_HIGH)
        {
          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET),Port_PortChannels[i].Pin_num); 
        }
        else if(Port_PortChannels[i].PortPinLevelValue == PORT_PIN_LEVEL_LOW)
        {
          /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DATA_REG_OFFSET),Port_PortChannels[i].Pin_num); 
        }
        else
        {
          /* Do Nothing */
        }
      }
      else if(Port_PortChannels[i].Pin_direction == PORT_PIN_IN)
      {
        /* clear the corresponding bit in the GPIODIR register to configure it as input pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_DIR_REG_OFFSET) , Port_PortChannels[i].Pin_num); 
        
        /* Adjust the internal resistor */
        /* Check the internal resistor for input pins pull-up or pull-down or disabled */
        if(Port_PortChannels[i].resistor == PULL_UP)
        {
          /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET),Port_PortChannels[i].Pin_num); 
        }
        else if(Port_PortChannels[i].resistor == PULL_DOWN)
        {
          /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET),Port_PortChannels[i].Pin_num);
        }
        else if(Port_PortChannels[i].resistor == DISABLE)
        {
          /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_UP_REG_OFFSET),Port_PortChannels[i].Pin_num);
          /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)Port_Ptr + PORT_PULL_DOWN_REG_OFFSET),Port_PortChannels[i].Pin_num);
          
        }
        else
        {
          /*No action needed*/
        }
      }
      else
      {
        /*No action needed*/
      }     
			
    }
    
  }


/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/

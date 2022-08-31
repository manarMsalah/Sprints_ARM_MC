
#include "Port.h"
#include "IntCtrl.h"
#include "Timer.h"
#include "Led.h"

#define Enable_Global_Interrupt()    __asm("CPSIE I")
#define Disable_Global_Interrupt()   __asm("CPSID I")


#define NUMBER_OF_SECONDS      1


int main (void)
{
	Port_Init(&Port_Configuration);
	IntCtrl_init(&IntCtrl_Configuration);
	
	Systick_setCallBack(Led_toggel);
	Enable_Global_Interrupt();
	Systick_start(NUMBER_OF_SECONDS);
	

	while(1)
	{
		
	}
	
	
	return 0;
}
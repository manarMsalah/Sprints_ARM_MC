
#include "Port.h"
#include "IntCtrl.h"
#include "Timer.h"
#include "Led.h"


int main (void)
{
	Port_Init(&Port_Configuration);
	IntCtrl_init(&IntCtrl_Configuration);
	
	Systick_setCallBack(Led_toggel);
	Systick_start(1);
	

	while(1)
	{
		
	}
	
	
	return 0;
}
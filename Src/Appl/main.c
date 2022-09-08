#include "Appl.h"
#include "led.h"

#define ON_TIME   3
#define OFF_TIME  7

int main (void)
{
	Appl_SetUp();
	
	while(1)
	{
		Appl_LedControl(ON_TIME, OFF_TIME);
	}
	
	return 0;
	
}


#include "Appl.h"


int main (void)
{
	Appl_SetUp();
	
	while(1)
	{
		Appl_SetOnAndOffTime();
		
		Appl_LedControl();
	}
	
	return 0;
	
}


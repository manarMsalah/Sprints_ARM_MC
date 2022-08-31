
#include "Appl.h"

#define ON_TIME   2
#define OFF_TIME  3

int main (void)
{
	Appl_SetUp();

	while(1)
	{
		Appl_LedControl(ON_TIME, OFF_TIME);
	}
	
	
	return 0;
}
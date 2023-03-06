#include "Delay.h"
#include <REGX52.H>
#include <intrins.h>
void Delay (unsigned int xms)  // ??1s
{
	unsigned char i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
			{
				while (--j);
			} while (--i);
	}
}




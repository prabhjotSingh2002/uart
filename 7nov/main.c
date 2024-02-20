#include"header7n.h"

#include <LPC21xx.H>
int main()
{
	int i;
 	IODIR0|=0xFF;

	while(1)
	{
	 	for(i=0;i<4;i++)
		{
		 IOSET0=IOSET0| ((1<<7)>>i)|  (1<<i);
		 delay_ms(400);
		}
		 delay_ms(400);
		for(i=0;i<4;i++)
		{
		 IOCLR0=IOCLR0| (16<<i)|  (8>>i);
		 delay_ms(400);
		}
		 delay_ms(400);
	}

}


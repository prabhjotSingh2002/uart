#include "header.h"
#define LED1 (1<<17)
#define LED2 (1<<18)

unsigned int count1,count2;
unsigned char temp;

/*#if 0
main()
{
 	uart0init(9600);

	configVic();
	
	en_uart0_interrupt();
	IODIR0|=LED1|LED2;

	while(1)
	{
	 	while(temp=='a')
		{
		 	IOCLR0=LED1;
			delay_mSec(100);
			IOSET0=LED1;
			delay_mSec(100);
		}

		while(temp=='b')
		{
		 	IOCLR0=LED2;
			delay_mSec(100);
			IOSET0=LED2;
			delay_mSec(100);
		}

		  count2++;
	}

}

#else
*/
main()
{
 	uart0init(9600);

	uart0TxString("\r\n MENU....");
	uart0TxString("\r\n A.ON LED 1....");
	uart0TxString("\r\n B.OFF LED 2....");
	uart0TxString("\r\n C.ON LED 1....");
	uart0TxString("\r\n D.OFF LED 2....");
	uart0TxString("\r\n OPTION....");
	configVic();
	
	en_uart0_interrupt();
	IODIR0|=LED1|LED2;

	while(1)
	{
		while(temp=='c')
		{
			IOSET0=LED2;
			delay_mSec(100);
		}
		while(temp=='d')
		{
			IOSET0=LED1;
			delay_mSec(100);
		}
	 	while(temp=='a')
		{
		 	IOCLR0=LED1;
			delay_mSec(100);
			IOSET0=LED1;
			delay_mSec(100);
		}

		while(temp=='b')
		{
		 	IOCLR0=LED2;
			delay_mSec(100);
			IOSET0=LED2;
			delay_mSec(100);
		}

		  count2++;
	}
}
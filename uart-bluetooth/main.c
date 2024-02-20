#include <LPC21xx.H>
#include "header.h"

#define LED1 (1<<17)
#define LED2 (1<<18)

unsigned char temp1,temp2;
int flag=0;
main()
{
 	
	uart1init(9600);
	uart0init(9600);
	IODIR0|=LED1|LED2;
	
	while(1)
	{
	 	uart1TxString("\r\nMENU");
		uart1TxString("\r\nA.LED1 ON");
		uart1TxString("\r\nB.LED1 OFF");
		uart1TxString("\r\nC.LED2 ON");
		uart1TxString("\r\nD.LED2 OFF");
		


		uart0TxString("\r\nMENU");
		uart0TxString("\r\nA.LED1 ON");
		uart0TxString("\r\nB.LED1 OFF");
		uart0TxString("\r\nC.LED2 ON");
		uart0TxString("\r\nD.LED2 OFF");
		
	
		if(flag==0)
		{
			
			uart1TxString("\r\nUSER-1 OPTION.......");
			temp2=uart1Rx();
			uart1Tx(temp2);

		

		    switch(temp2)
		    {
		 	 case 'a':IOCLR0=LED1;break;
			 case 'b':IOSET0=LED1;break;
			 case 'c':IOCLR0=LED2;break;
			 case 'd':IOSET0=LED2;break;
			 default: uart0TxString("\r\nWRONG OPTION");
		    }	 
		  	flag=1;
		}
		else
		{

			uart0TxString("\r\n USER 2OPTION.......");
			temp1=uart0Rx();
			uart0Tx(temp1);

			switch(temp1)
			{
		 		case 'a':IOCLR0=LED1;break;
				case 'b':IOSET0=LED1;break;
				case 'c':IOCLR0=LED2;break;
				case 'd':IOSET0=LED2;break;
				default: 	uart0TxString("\r\nWRONG OPTION");
			}
			flag=0;
		}
	   }

}



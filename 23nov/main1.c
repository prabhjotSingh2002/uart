#include <LPC21xx.H>
#include"header.h"

main()
{
 	unsigned char temp;
	unsigned char t1,t2;
	uart0_init(9600);

	while(1)
	{
	 uart0_tx_string("\r\nEnter char: ");
	 temp=uart0_rx();
	 uart0_tx(temp);//loopback

	 while(uart0_rx()!='\r');//waiting forenter key
	 uart0_tx_string("\r\nASCII: ");

	 //decimal
	 uart0_tx((temp/100)+48);
	 uart0_tx((temp/10)%10+48);
	 uart0_tx((temp%10)+48);


	 //hexadecimal
	 uart0_tx_string(" 0x");
	 t1=((temp&0xf0)>>4);

	 if(t1>9)
	 	  uart0_tx('A'+t1-10);
	 else
	 	 uart0_tx(t1+48);
	 t2=((temp&0x0f));
	 if(t2>9)
		 uart0_tx('A'+t2-10);
	 else
	 	 uart0_tx(t2+48);

	}

}


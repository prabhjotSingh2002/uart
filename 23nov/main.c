/*main UART0*/

#include"header.h"
#include<string.h>
main()
{
 	int a[]={15,60,30,15,15};
	unsigned int pclk=a[VPBDIV]*1000000;
	unsigned result=0,baud=9600;

	char vishal[]="VISHAL TU CHUTIYA HA OR TERA CHHOTA HA ";
	 int i=0;
	result=pclk/(16*baud);

	PINSEL0|=0X05;//P0.0->TXd0,p0.1->RxDO
	
	U0LCR=0X83;
	U0DLL=result&0xff;//extract lower bit
	U0DLM =(result>>8)&0xff;//extract higher 8 bit
	 U0LCR=0x03;


	 while(1)
	 {
	 if(i>=strlen(vishal))
	 {
			i=0;
	 }
	  U0THR=vishal[i];
	  i++;
	  while(((U0LSR>>5)&1)==0);
	  delay_ms(200);
	 }

																		  
}
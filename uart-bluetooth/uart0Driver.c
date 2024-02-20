//uart0_driver

#include <LPC21xx.H>

void uart0init(int baud)
{
 	int a[]={15,60,30,15,15};
	unsigned int pclk=a[VPBDIV]*1000000;
	unsigned int result=0;
	result=pclk/(16*baud);

	PINSEL0|=0x05;
	U0LCR=0x83;
	U0DLL=result&0xff;
	U0DLM=(result>>8)&0xff;
	U0LCR=0x03;

}

#define THRE ((U0LSR>>5)&1)
void uart0Tx(unsigned char data)
{
 	U0THR=data;
	 while(THRE==0);
}

#define RDR (U0LSR &1)
unsigned char uart0Rx(void)
{
 	while(RDR==0);
	return U0RBR;
}

void uart0TxString(char *ptr)
{
 	while(*ptr)
	{
	 	U0THR=*ptr;
		 while(THRE==0);
		 ptr++;
	}
}


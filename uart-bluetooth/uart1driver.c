//uart1_driver

#include <LPC21xx.H>

void uart1init(int baud)
{
 	int a[]={15,60,30,15,15};
	unsigned int pclk=a[VPBDIV]*1000000;
	unsigned int result=0;
	result=pclk/(16*baud);

	PINSEL0|=(0x5<<16);
	U1LCR=0x83;
	U1DLL=result&0xff;
	U1DLM=(result>>8)&0xff;
	U1LCR=0x03;

}

#define THRE ((U1LSR>>5)&1)
void uart1Tx(unsigned char data)
{
 	U1THR=data;
	 while(THRE==0);
}

#define RDR (U1LSR &1)
unsigned char uart1Rx(void)
{
 	while(RDR==0);
	return U1RBR;
}

void uart1TxString(char *ptr)
{
 	while(*ptr)
	{
	 	U1THR=*ptr;
		 while(THRE==0);
		 ptr++;
	}
}



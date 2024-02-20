//////UART DRIVEN CODE///////

#include <LPC21xx.H>

void uart0_init(unsigned int baud)
{
		int a[]={15,60,30,15,15};
		unsigned int pclk=a[VPBDIV]*1000000;
		unsigned int result=0;
		result=pclk/(16*baud);
 	
		PINSEL0|=0x05;//p0.0->TxDo ,po.1->RXD0
		U0LCR=0x83;
		U0DLL=result&0xff;//extract lower 8 bits
		U0LCR=0x03;


}

#define THRE ((U0LSR>>5)&1)

void uart0_tx(unsigned char data)
{
 	U0THR=data;
	while(THRE==0);

}

void uart0_tx_string(char *ptr)
{
 	while(*ptr)
	{
		 U0THR=*ptr;
		 while(THRE==0);
		 ptr++;
	}
}


#define RDR (U0LSR&1)

unsigned char uart0_rx(void)
{
 	while(RDR==0);
	return U0RBR;

}


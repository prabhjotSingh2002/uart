#include"header.h"

extern unsigned int count2;
extern unsigned int temp;

void uart0Handler(void) __irq
{
 	int r=U0IIR;//MANDATORY IN ISR
	count2++;

	if(r&4)
	{
	 	//if data is recived
		temp=U0RBR;
		U0THR=temp;//loopback
	}
	if(r&2)
	{
	 	//if data is transmitted
	}
	VICVectAddr=0;//to finish isr execution
}

void configVic(void)
{
 	VICIntSelect=0;
	VICVectCntl0=6|(1<<5);
	VICVectAddr0=(int)uart0Handler;
	VICIntEnable|=(1<<6);
}

void en_uart0_interrupt(void)
{
 	U0IER=0x3;//En TX & Rx interrupt

}
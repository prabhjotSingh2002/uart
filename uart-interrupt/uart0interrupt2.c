#include"header.h"

extern unsigned int count2;
extern unsigned int temp;

int n=0;

void uart0Handler(void) __irq
{
 	int r=U0IIR;//MANDATORY IN ISR
	count2++;

	if(r&4)
	{
	 	//if data is recived
		temp=U0RBR;
		U0THR=temp;//loopback

		
		if('0'<=temp && temp<='9')
		{
			n=n*10+temp-48;	
		}
		else if(temp=='\r')
		{
				uart0TxString("\r\n");
				printBin(n);
				n=0;
		}
		else
		{
			uart0TxString("\r\n");
			printBin(temp);
		}
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


#include"header.h"

#define LED1 (1<<17)
#define LED2 (1<<18)
#define LED3 (1<<19)

void configVicExt(void)
{
	PINSEL1|=0x1;
	
 	VICIntSelect=0;
	VICVectCntl1=14|(1<<5);
	VICVectAddr1=(int)EINT0ISR;
	VICIntEnable|=(1<<14);
}

void enableExtIntr(void)
{
	  EXTINT|=(1<<0);  //clearing  EXTERNAL INTERRUPT 0	 flag
	  EXTMODE|=(1<<0);//MAKING IT EDGE SENSITIVE
	  EXTPOLAR|=0;//making it for falling edge

}

void  EINT0ISR(void)__irq
{
	int i,j;
	IODIR0|=LED1|LED2|LED3;

	IOCLR0=LED1|LED2|LED3;
	
	for(i=0;i<100000;i++)
	{
	 for(j=0;j<100000;j++);
	}	

	IOSET0=LED1|LED2|LED3;


	 // Clear the interrupt flag
    EXTINT |= (1 << 0);
	  VICVectAddr=0X0;
}
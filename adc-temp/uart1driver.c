//uart1_driver

#include <LPC21xx.H>
#include"header.h"

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

void uart1RxString(char *p,int bytes)
{ 
	int i=0;
	for(i=0;i<bytes;i++)
	{
	 	while(RDR==0);
		p[i]=U1RBR;
		if(p[i]=='\r')
		     break;
		uart1Tx(p[i]);//loopback
	}
	p[i]='\0';
}

void strrev1(char *p,char *q)
{
		char t;
 		while(p<q)
		{
		 	t=*p;
			*p=*q;
			*q=t;
			p++;q--;
		}
}
void intToStr1(char *s,int num)
{
	int i=0;
 	char *p=s,*q=0;
	if(num<0)
	{
		s[0]='-';
		num=-num;
	      i=1;
		p=s+1;
	}
	while(num)
	{
	 	s[i]=(num%10)+'0';
		i++;
		num=num/10;
	}
	q=s+i-1;
	strrev1(p,q);
	s[i]='\0';

}

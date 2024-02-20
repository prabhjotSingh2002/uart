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

void uart0RxString(char *p,int bytes)
{ 
	int i=0;
	for(i=0;i<bytes;i++)
	{
	 	while(RDR==0);
		p[i]=U0RBR;
		if(p[i]=='\r')
		     break;
		uart0Tx(p[i]);//loopback
	}
	p[i]='\0';
}

void uart0txString(char *ptr)
{
 	while(*ptr)
	{
	 	U0THR=*ptr;
		 while(THRE==0);
		 ptr++;
	}
}

void strrev2(char *p,char *q)
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

void sprintf2(char *s,float n)
{
	int num=n,i;
	i=sprintf1(s,num);
	s[i++]='.';
	num=n*1000;
	num=num%1000;
	sprintf1(s+i,num);
}


int sprintf1(char *s,int num)
{
	int i=0;
 	char *p=s,*q=0;
	if(num==0)
	{
	 	s[0]='0';
		s[1]=0;
		return 1;
	}

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
	strrev2(p,q);
	s[i]='\0';
	return i;
}


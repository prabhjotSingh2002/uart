#include <LPC21xx.H>

void  delay_Sec(unsigned int sec)
{
	
	int a[]={15,30,60,15,15};

 	T0PC=0;
	T0PR=a[VPBDIV]*	1000000-1;
	T0TC=0;
	T0TCR=1;

	 while(T0TC<sec);

	T0TCR=0;

}

void  delay_mSec(unsigned int ms)
{
	
	int a[]={15,30,60,15,15};

 	T0PC=0;
	T0PR=a[VPBDIV]*	1000-1;
	T0TC=0;
	T0TCR=1;

	 while(T0TC<ms);

	T0TCR=0;

}

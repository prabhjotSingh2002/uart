/*lcd 4-bit driver*/


#include"header.h"



#define RS (1<<17)// RS
#define RW (1<<18)// RW
#define EN (1<<19)// EN


void init(void)
{
		IODIR1|=0x00FE0000;
		PINSEL2=0;//TO SET GPIO
		lcd_cmd(0x02);//4bit mode enable
		
		lcd_cmd(0x03);//enable single line	  for 4bit
		lcd_cmd(0x28);//enable double line	   for 4 bit
		lcd_cmd(0x0E);//enable cursor
		lcd_cmd(0x01);//clear screen & set cursor to home position 

}

void lcd_cmd(unsigned char cmd)
{
			  
			 unsigned int temp;
		  
		  //for first nibble
		  IOCLR1|=0x00FE0000;
		  temp=(cmd & 0xF0)<<16;
			IOSET1|=temp;//setting data
			IOCLR1|=RS;//clearing RS
			IOCLR1|=RW;//clearing RW
			IOSET1|=EN;//setting enable
			 delayms(2);
			 IOCLR1|=EN;//clearing EN


			  //for second nibble
			 IOCLR1|=0x00FE0000;
		  temp=(cmd & 0x0F)<<20;
			IOSET1|=temp;//setting data
			IOCLR1|=RS;//clearing RS
			IOCLR1|=RW;//clearing RW
			IOSET1|=EN;//setting enable
			 delayms(2);
			 IOCLR1|=EN;//clearing EN


}

void lcd_data(unsigned char data)
{
			 unsigned int temp;
		  
		  //for first nibble
		  IOCLR1|=0x00FE0000;
		  temp=(data & 0xF0)<<16;
			IOSET1|=temp;//setting data
			IOSET1|=RS;//setting RS
			IOCLR1|=RW;//clearing RW
			IOSET1|=EN;//setting enable
			 delayms(2);
			 IOCLR1|=EN;//clearing EN


			  //for second nibble
			 IOCLR1|=0x00FE0000;
		  temp=(data & 0x0F)<<20;
			IOSET1|=temp;//setting data
			IOSET1|=RS;//setting RS
			IOCLR1|=RW;//clearing RW
			IOSET1|=EN;//setting enable
			 delayms(2);
			 IOCLR1|=EN;//clearing EN
}

void String(char *p)
{
 	while(*p)
	{
	 	 lcd_data(*p);
		 p++;
	}

}

void lcd_Integer(int num)
{
	int a[10],i;
 	if(num==0)//checking if num is zero
	{
	 lcd_data('0');
	}
	if(num<0)//checking num is +ve or -ve
	{
	 	lcd_data('-');
		num=-num;
	}
	i=0;
	while(num>0)//storing into buffer
	{
			a[i]=num%10+48;
	 		 num=num/10;
			 i++;
	}
	for(--i;i>=0;i--)
	{
	 	lcd_data(a[i]);
	}
}

void lcd_Float(float n)
{
	int num=n;
	int deci=(n-num)*1000;
	int a[15],i;
 	if(num==0)//checking if num is zero
	{
	 lcd_data('0');
	}
	if(num<0)//checking num is +ve or -ve
	{
	 	lcd_data('-');
		num=-num;
	}
	i=0;
	while(num>0)//storing into buffer
	{
			a[i]=num%10+48;
	 		 num=num/10;
			 i++;
	}

	a[i]='.';

	while(deci>0)//storing into buffer
	{
			a[i]=num%10+48;
	 		 num=num/10;
			 i++;
	}

	for(--i;i>=0;i--)
	{
	 	lcd_data(a[i]);
	}
}

int strlen(char *p)
{
 	int len=0;
	while(p[len])
		len++;
	return len;
}

void scrollPrint(char *p,char *q)
{
 /*	int i=0;
	for(i=0;i<16;i++)
	{
	 	lcd_cmd(0x80+i);
	    String(p);
		delayms(1000);
		lcd_cmd(0x1);
	}*/
	 int i,j;
	 int plen=strlen(p),qlen=strlen(q);

	 for(i=0;i<16;i++)
	 {
	 	lcd_cmd(0x80+i);
	  	for(j=0;j<plen;j++)
		{
			  if(i+j>15)
			  {
				lcd_cmd(0x80+(i+j)%16);				
			  }
			  lcd_data(p[j]);
		}

	   if(q)
	   {
			lcd_cmd(0xC0+i);
			for(j=0;j<qlen;j++)
			{
				if(i+j>15)
			  	{
					lcd_cmd(0xC0+(i+j)%16);				
			  	}
			  	lcd_data(q[j]);
			}
		}
			delayms(1000);
			lcd_cmd(0x01);
	 }

}


#include "header.h"

#define RS (1<<17)// RS
#define RW (1<<18)// RW
#define EN (1<<19)// EN


void init(void)
{
		IODIR1|=0x00FE0000;
		PINSEL1=0;//TO SET GPIO
		lcd_cmd(0x02);//4bit mode enable
		lcd_cmd(0x0E);//enable cursor
		lcd_cmd(0x03);//enable single line	  for 4bit
		lcd_cmd(0x28);//enable double line	   for 4 bit
		lcd_cmd(0x01);//clear screen & set cursor to home position 

}

void lcd_cmd(unsigned char cmd)
{
			  
			 unsigned int temp;
		  
		  //for first nibble
		  IOCLR1=0x00FE0000;
		  temp=(cmd & 0xF0)<<16;
			IOSET1=temp;//setting data
			IOCLR1=RS;//clearing RS
			IOCLR1=RW;//clearing RW
			IOSET1=EN;//setting enable
			 delay_ms(2);
			 IOCLR1=EN;//clearing EN


			  //for second nibble
			 IOCLR1=0x00FE0000;
		  temp=(cmd & 0x0F)<<20;
			IOSET1=temp;//setting data
			IOCLR1=RS;//clearing RS
			IOCLR1=RW;//clearing RW
			IOSET1=EN;//setting enable
			 delay_ms(2);
			 IOCLR1=EN;//clearing EN


}

void lcd_data(unsigned char data)
{
			 unsigned int temp;
		  
		  //for first nibble
		  IOCLR1=0x00FE0000;
		  temp=(data & 0xF0)<<16;
			IOSET1=temp;//setting data
			IOSET1=RS;//setting RS
			IOCLR1=RW;//clearing RW
			IOSET1=EN;//setting enable
			 delay_ms(2);
			 IOCLR1=EN;//clearing EN


			  //for second nibble
			 IOCLR1=0x00FE0000;
		  temp=(data & 0x0F)<<20;
			IOSET1=temp;//setting data
			IOSET1=RS;//setting RS
			IOCLR1=RW;//clearing RW
			IOSET1=EN;//setting enable
			 delay_ms(2);
			 IOCLR1=EN;//clearing EN
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

//CGRAM funcn

unsigned char a[]={0x17,0x14,0x14,0x1f,0x05,0x05,0x1d};

void lcd_cgram(void)
{
		int i;
	   lcd_cmd(0x40);//starting address of cgram  for page0

	   for(i=0;i<8;i++)
	   {
				  lcd_data(a[i]);
	   }
}


#include "headerLcd.h"

#define RS (1<<8) //p0.8
#define RW (1<<9) //p0.9
#define EN (1<<10) //p0.10

void lcd_cmd(unsigned char cmd)
{
 IOCLR0=0x7ff;
 IOSET0=cmd;

 IOCLR0=RS;
 IOCLR0=RW;
 IOSET0=EN;

 delay_mSec(20);
 IOCLR0=EN;
}

void lcd_data(unsigned char data)
{

	IOCLR0=0;
	IOSET0=data;

	IOSET0=RS;
	IOCLR0=RW;
	IOSET0=EN;

	delay_mSec(20);
	IOCLR0=EN;
}

void init()
{

 	IODIR0=0X7ff;
	lcd_cmd(0x38);//double line enable in 8-bit mode
	lcd_cmd(0x0E);//enable cursor
	lcd_cmd(0x01);//clrscr
}


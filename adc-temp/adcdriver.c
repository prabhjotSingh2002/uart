/*adc-driver*/

//#include <LPC21xx.H>
#include "header.h"

void adc_init(void)
{
 	PINSEL1|=0x15400000;
	ADCR=0x00200400;

}

#define DONE ((ADDR>>31)&1)

int adc_read(int ch_num)
{
 	int res=0;
	ADCR|=(1<<ch_num);//SELECT CHANNEL NUMBER
	ADCR|=(1<<24); //START ADC CONVERT NOW
	while(DONE==0);
	ADCR^=(1<<24);//stop adc conv
	ADCR^=(1<<ch_num);//deselect channel no
	res=(ADDR>>6)&0x3ff;//extract result
	return res;
}


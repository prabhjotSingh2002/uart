#include"header.h"
#include<string.h>


main()
{
	char name[]="VECTOR";
	int i,j,l;
	init();
 
	
	l=strlen(name);

	while(1)
	{
		   for(i=0;i<32;i++)
		   {

				for(j=0;j<l;j++)
				{
											
					if(i+j>31)
					{
						lcd_cmd(0x80+(i+j)%32);
					}
					else if(i+j>15)
					{
					 lcd_cmd(0xC0+(i+j)%16);
					}
					else if(i+j<=15)
					{
						lcd_cmd(0x80+(i+j)%16);
					}
				
				 	lcd_data(name[j]);
				}
				delay_ms(300);
				lcd_cmd(0x01);
		   }

	}	

}


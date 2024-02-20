#include"header.h"
//#include <LPC21xx.H>

void eraseString(char *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	 	s[i]=0;
	}
	
}

float vout,tempr;
main()
{			
    int adcval;
    char s[20]={0};
    char a[20]={0};
    
    init();
    adc_init();
    uart0init(9600);
    while(1)
    {
        adcval=adc_read(1);
        lcd_cmd(0x80);
        String("adccval ");
        sprintf1(s,adcval);
        String(s);
         //delayms(500);      
        

        vout=(adcval *3.3f)/1023.0f;
		tempr=(vout-0.5f)/0.01f;

          sprintf2(a,tempr);
         uart0TxString(a);

           lcd_cmd(0xC0);
            String("tempr ");
            String(a);
             delayms(500);
          
    /*    lcd_cmd(0x01);
        tempr=(vout-0.5)/0.01;//get tempr
        uart0TxString("\r\n");//new line
        uart0TxString("TEMP: ");
        sprintf2(s,tempr);
        uart0TxString(s);
        
        String(" temp ");
            String(s);
        
        delayms(800);	 */
      
      lcd_cmd(0x01); 
	   // delayms(300);  
	  eraseString(a,20);
	  eraseString(s,20) ; 
        uart0TxString("\r\n");//new line
    }

}




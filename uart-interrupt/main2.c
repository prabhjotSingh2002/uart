#include "header.h"

unsigned char temp;

unsigned int count1,count2;

/*for binary printing*/
void printBin(int num)
{
	 int i,r;
	 for(i=31;i>=0;i--)
	 {
	 	r=(num>>i) & 1;
	  	uart0Tx(r+'0');
	 }
	 uart0TxString("\r\n");
}

main()
{
	uart0init(9600);
	
	configVic();
	en_uart0_interrupt();

	while(1)
	{
	 	/*n=(temp-'0')+n*10;
		if()
		{
		} */
		
	}

}


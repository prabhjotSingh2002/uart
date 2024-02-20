#include"header.h"

int arr[3][3];
int player=1;
int i=0,j=0,c=1;

main()
{
	uart1init(9600);
	uart0init(9600);
	uart1TxString("TIC-TAC-TOE\r\n\n");
	uart0TxString("TIC-TAC-TOE\r\n\n");
    while(1)
    {
       // system("clear");
	   
        //printf("\tTIC-TAC-TOE\n\n");

        
        for(i=0,c=1;i<3;i++)
        {
           // printf("\t\t");
			//uart1TxString("");
	   		//uart0TxString("");
            for(j=0;j<3;j++,c++)
            {
                if(arr[i][j]==0)
                {
                    //printf(" %d ",c);
					uart1TxString("      ");
					uart1Tx(c+48);
					uart0TxString("      ");
	   				uart0Tx(c+48);
                }
                else if(arr[i][j]==1)
                {
                    //printf(" X ");
					uart1TxString("      ");
					uart1TxString(" X ");
					uart0TxString("      ");
	   				uart0TxString(" X  ");
                }
                else if(arr[i][j]==2)
                {
                    //printf(" 0 ");
					uart1TxString("      ");
					uart1TxString(" 0 ");
					uart0TxString("      ");
	   				uart0TxString(" 0 ");
                }
                
                if(j!=2)
                {
                    //printf("|");
					uart1TxString("|");
	   				uart0TxString("|");
                }
            }
            //printf("\n");
			uart1TxString("\r\n");
	   		uart0TxString("\r\n");
            if(i!=2)
            {
                //printf("\t\t------------\n");
				uart1TxString("      ---------------\r\n");
	   			uart0TxString("      ---------------\r\n");
            }
        }
        winning();
        tie();
        record();
    }
    
    // printf("\n\n");
    // printf("\t\t 1 | 2 |  3 \n");
    // printf("\t\t------------\n");
    // printf("\t\t 4 | 5 |  6 \n");
    // printf("\t\t------------\n");
    // printf("\t\t 7 | 8 |  9 \n");

}




#include"header.h"

extern int player;
extern int arr[3][3];

void record()
{
    int pos;
    
   // printf("\n\n\t\t PLAYER %d Enter your choice: ",player);
	
	if(player==1)
	{
		  uart0TxString("\r\n\n PLAYER ");
		  uart0Tx(player+48);
		  uart0TxString(" Enter your choice: \r\n");
		   uart1TxString(" \r\n");

		// scanf("%d",&pos);
		  pos=uart0Rx()-48;
	}
	else if(player==2)
	{
		  uart1TxString("\r\n\n PLAYER ");
		  uart1Tx(player+48);
		  uart1TxString(" Enter your choice: \r\n");

		   uart0TxString(" \r\n");
		   //scanf("%d",&pos);
		  pos=uart1Rx()-48;
	}

	//uart1TxString("\t\t------------\n");
	//uart0TxString("\t\t------------\n");
    //scanf("%d",&pos);

    if(pos>0 && pos<10)
    {
        if(arr[(pos-1)/3][(pos-1)%3]==0)
        {
            if(player==1)
            {
                arr[(pos-1)/3][(pos-1)%3]=1;
                player=2;
            }
            else if (player==2)
            {
                arr[(pos-1)/3][(pos-1)%3]=2;
                player=1;
            }
        }
        else
        {
			player==1?uart0TxString("\r\n\n PLEASE ENTER CORRECT POSITION\r\n"):uart1TxString("\r\n\n PLEASE ENTER CORRECT POSITION\r\n");
            //printf("\n\n\t\t PLEASE ENTER CORRECT POSITION\n");
            //sleep(1);
        }
        
    }
    else
    {
		player==1?uart0TxString("\r\n\n PLEASE ENTER CORRECT POSITION\r\n"):uart1TxString("\r\n\n PLEASE ENTER CORRECT POSITION\r\n");
        //printf("\n\n\t\t PLEASE ENTER CORRECT POSITION\n");
        //sleep(1);
    }
    
}


#include"header.h"

extern int player;
extern int arr[3][3];

void tie()
{
    int i,j,flag=0;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(arr[i][j]==0)
            {
                flag=1;
            }
        }
    }
    if(flag==0)
    {
        //printf("\n\t\t TIE\n");
		uart1TxString("\r\n TIE\r\n");
	   	uart0TxString("\r\n TIE\r\n");

        //sleep(2);
        exit(0);
    }
}


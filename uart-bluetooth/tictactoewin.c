#include"header.h"

extern int player;
extern int arr[3][3];

void winning()
{
    //////////////player 1 win/////////////////

    if((arr[0][0]==1) &&(arr[0][1]==1)&&(arr[0][2]==1))
    {
        //printf("\r\n PLAYER 1 WIN!!!\r\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
       //leep(2);
        exit(0);
    }
    else if((arr[1][0]==1) &&(arr[1][1]==1)&&(arr[1][2]==1))
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
      //sleep(2);
        exit(0);
    }
    else if((arr[2][0]==1) &&(arr[2][1]==1)&&(arr[2][2]==1))
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
	uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
      //sleep(2);
        exit(0);
    }
    else if((arr[0][0]==1) &&(arr[1][0]==1)&&(arr[2][0]==1))
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
      //sleep(2);
        exit(0);
    }
    else if((arr[0][1]==1) &&(arr[1][1]==1)&&(arr[2][1]==1))
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
        exit(0);
    }
    else if((arr[0][2]==1) &&(arr[1][2]==1)&&(arr[2][2]==1))
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][0]==1) &&(arr[1][1]==1)&&(arr[2][2]==1))    
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][2]==1) &&(arr[1][1]==1)&&(arr[2][0]==1))    
    {
        //printf("\n\t\t PLAYER 1 WIN!!!\n");
		uart1TxString("\r\n PLAYER 1 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 1 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }


///////////////////////////player 2 win

    if((arr[0][0]==2) &&(arr[0][1]==2)&&(arr[0][2]==2))
    {
     
		//printf("\r\n PLAYER 2 WIN!!!\r\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[1][0]==2) &&(arr[1][1]==2)&&(arr[1][2]==2))
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[2][0]==2) &&(arr[2][1]==2)&&(arr[2][2]==2))
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][0]==2) &&(arr[1][0]==2)&&(arr[2][0]==2))
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][1]==2) &&(arr[1][1]==2)&&(arr[2][1]==2))
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][2]==2) &&(arr[1][2]==2)&&(arr[2][2]==2))
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][0]==2) &&(arr[1][1]==2)&&(arr[2][2]==2))    
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }
    else if((arr[0][2]==2) &&(arr[1][1]==2)&&(arr[2][0]==2))    
    {
        //printf("\n\t\t PLAYER 2 WIN!!!\n");
		uart1TxString("\r\n PLAYER 2 WIN!!!\r\n");
	   	uart0TxString("\r\n PLAYER 2 WIN!!!\r\n");
        //sleep(2);
        exit(0);
    }

}
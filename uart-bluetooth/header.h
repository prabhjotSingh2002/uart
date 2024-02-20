

#include <LPC21xx.H>


void uart1init(int baud);
void uart1Tx(unsigned char data);
unsigned char uart1Rx(void);
void uart1TxString(char *ptr);


void uart0init(int baud);	  
void uart0Tx(unsigned char data);
unsigned char uart0Rx(void);
void uart0TxString(char *ptr);



////////////////////tic tac toe/////////////////
#include<stdio.h>
#include<stdlib.h>
//#include<unistd.h>


void record(void);

void winning(void);
void tie(void);
/////////////////////////////////////////////




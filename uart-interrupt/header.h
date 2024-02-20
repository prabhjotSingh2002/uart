

#include <LPC21xx.H>


void uart1init(int baud);
void uart1Tx(unsigned char data);
unsigned char uart1Rx(void);
void uart1TxString(char *ptr);


void uart0init(int baud);	  
void uart0Tx(unsigned char data);
unsigned char uart0Rx(void);
void uart0TxString(char *ptr);


void  delay_mSec(unsigned int ms);
void  delay_Sec(unsigned int sec);

void en_uart0_interrupt(void);
void configVic(void);
void uart0Handler(void) __irq;

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void init(void);

void printBin(int num);



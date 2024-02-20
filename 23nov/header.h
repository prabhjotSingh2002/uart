#include <LPC21xx.H>

void delay_sec(unsigned int sec);
void delay_ms(unsigned int ms);


unsigned char uart0_rx(void);
void uart0_tx_string(char *ptr);
void uart0_tx(unsigned char data);
void uart0_init(unsigned int baud);


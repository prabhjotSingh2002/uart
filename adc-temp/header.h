#include <LPC21xx.H>

void uart1init(int baud);
void uart1Tx(unsigned char data);
unsigned char uart1Rx(void);
void uart1TxString(char *ptr);
void intToStr1(char *s,int num);
void strrev1(char *p,char *q);
void uart1RxString(char *p,int bytes);

void delaysec(unsigned int sec);
void delayms(unsigned int ms);

void lcd_cmd(unsigned char cmd);
void lcd_data(unsigned char data);
void lcd_init(void);

void adc_init(void);

int adc_read(int ch_num);

void uart0init(int baud);
void uart0Tx(unsigned char data);
unsigned char uart0Rx(void);
void uart0RxString(char *p,int bytes);
void uart0TxString(char *ptr);
void strrev2(char *p,char *q);
void sprintf1(char *s,int num);
void sprintf2(char *s,float n);

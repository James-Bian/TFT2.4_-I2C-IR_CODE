#ifndef _UART_H_
#define _UART_H_

#ifndef uchar
#define uchar unsigned char
#endif

extern uchar Uart_SBUF;

void Uart_Init(void);
void Uart_SendData(uchar SendData);

#endif
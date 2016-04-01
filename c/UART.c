#include "uart.h"
#include "REG52.h"
#include "intrins.h" 

uchar Uart_SBUF;
void Uart_Init(void)
{
	SCON=0X50;			//设置为工作方式1
	TMOD|=0X20;			//设置计数器工作方式2
	PCON =0X80;			//波特率加倍
	TH1=0XF3;			//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	//ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					    //打开计数器
	TI=1;
	//PS=1;
}

void Uart_SendData(uchar SendData)
{
  SBUF=SendData;
  while (!TI);	        //等待发送数据完成
  TI = 0;
}

void Uart_Int() interrupt 4
{
	if(RI==1)
	{
	 Uart_SBUF  =SBUF;
	 RI = 0;             //清除接收中断标志位
	 }	
}

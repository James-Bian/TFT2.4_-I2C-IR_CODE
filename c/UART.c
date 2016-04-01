#include "uart.h"
#include "REG52.h"
#include "intrins.h" 

uchar Uart_SBUF;
void Uart_Init(void)
{
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD|=0X20;			//���ü�����������ʽ2
	PCON =0X80;			//�����ʼӱ�
	TH1=0XF3;			//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	//ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					    //�򿪼�����
	TI=1;
	//PS=1;
}

void Uart_SendData(uchar SendData)
{
  SBUF=SendData;
  while (!TI);	        //�ȴ������������
  TI = 0;
}

void Uart_Int() interrupt 4
{
	if(RI==1)
	{
	 Uart_SBUF  =SBUF;
	 RI = 0;             //��������жϱ�־λ
	 }	
}

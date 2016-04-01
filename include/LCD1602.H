/*******************************************************************
       LCD1602 ͷ�ļ�

  1������LCD�����ӿڶ�Ӧ��MCU����
  2����������������

/*******************************************************************/

#ifndef _LCD1602_H_
#define _LCD1602_H_

#define LCD1602_8PIN

/*Include the Head files*/
#include<reg52.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN�ڶ���
**********************************/
#define LCD1602_DATAPINS P0   //use 8pins
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

/**********************************
��������
**********************************/
/*��51��Ƭ��12MHZʱ���µ���ʱ����*/
void Lcd1602_Delay1ms(uint c);   //��� 0us
/*LCD1602д��8λ�����Ӻ���*/
void LcdWriteCom(uchar com);
/*LCD1602д��8λ�����Ӻ���*/	
void LcdWriteData(uchar dat)	;
/*LCD1602��ʼ���ӳ���*/		
void LcdInit();	
/*LCD1602æ���*/
bit Lcd_Busy(void);	
/*LCD1602��ʾʱ��*/
void Lcd_Display_TIME(void);
/*LCD1602��ʾ����*/
void Lcd_Display_DATE(void);
/*LCD1602��ʾ�¶�*/
void Lcd_Display_temp(int temp);
					  

#endif
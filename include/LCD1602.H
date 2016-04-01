/*******************************************************************
       LCD1602 头文件

  1、定义LCD操作接口对应的MCU引脚
  2、操作函数声明；

/*******************************************************************/

#ifndef _LCD1602_H_
#define _LCD1602_H_

#define LCD1602_8PIN

/*Include the Head files*/
#include<reg52.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN口定义
**********************************/
#define LCD1602_DATAPINS P0   //use 8pins
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;

/**********************************
函数声明
**********************************/
/*在51单片机12MHZ时钟下的延时函数*/
void Lcd1602_Delay1ms(uint c);   //误差 0us
/*LCD1602写入8位命令子函数*/
void LcdWriteCom(uchar com);
/*LCD1602写入8位数据子函数*/	
void LcdWriteData(uchar dat)	;
/*LCD1602初始化子程序*/		
void LcdInit();	
/*LCD1602忙检测*/
bit Lcd_Busy(void);	
/*LCD1602显示时间*/
void Lcd_Display_TIME(void);
/*LCD1602显示日期*/
void Lcd_Display_DATE(void);
/*LCD1602显示温度*/
void Lcd_Display_temp(int temp);
					  

#endif
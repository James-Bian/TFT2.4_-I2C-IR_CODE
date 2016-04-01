#ifndef _GUI_H_
#define _GUI_H_

//---����ͷ�ļ�---//
#include <reg52.H>
#include"lcd_drive.h"
#include "DS1302.h"
#include "ir.h"
#include "temp.h"
#include "AT24C02.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---��ʾͼƬ���������---//
//#define PICTURE_SHOW

//---��ʾ32*29�ĺ���---//
#define CHAR32_SHOW

//---��ʾ19x24�ĺ���---//
//#define CHAR14_SHOW

//---��ʾASCII���Ӧ���ַ�---//
#define USE_ASCII

#define TIME_DISPLAY

//---����ȫ�ֱ���---//
void GUI_Dot(uint x, uint y, uint color);  //����
//void GUI_Box(uint sx, uint sy, uchar ex, uint ey, uint color);   //������
//void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color);//������
void GUI_Write32CnChar(uint x, uint y, uchar *cn, uint wordColor, uint backColor);	 
//void GUI_Write14CnChar(uint x,uint y,uchar *cn,uint wordColor,uint backColor);	 
//void GUI_ShowPicture(uint x, uint y, uchar wide, uint high);
void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor); //���ַ�����ʽһ�����*Pָ��ĵ�Ԫ
void GUI_WriteASCII_SINGLE(uint x, uint y, uchar p, uint wordColor, uint backColor); //��ʾ����ASCII�ַ����������ַ���Ҫ��ʾ�����ַ���ʾЧ�ʲ���

void GUI_TimeDisplay(uint x_Start, uint y_start,uint Time_wordColor, uint Time_backColor); //��ʾʱ��
void GUI_IR_VALUE_DISPLAY_16X24(uint x, uint y, uchar IRcode, uint wordColor, uint backColor);  //��ʾIR��ֵ��
void GUI_TEMPERATUER_DISPLAY_16X24(uint x, uint y, int temp, uint wordColor, uint backColor);  //��ʾ�¶�
void GUI_AT24C02_DISPLAY_16X24(uint x, uint y, uint wordColor, uint backColor) ;  //��ʾAT24C02������¶�

#endif

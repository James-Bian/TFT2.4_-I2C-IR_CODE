#ifndef _GUI_H_
#define _GUI_H_

//---包含头文件---//
#include <reg52.H>
#include"lcd_drive.h"
#include "DS1302.h"
#include "ir.h"
#include "temp.h"
#include "AT24C02.h"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

//---显示图片，定义这个---//
//#define PICTURE_SHOW

//---显示32*29的汉字---//
#define CHAR32_SHOW

//---显示19x24的汉字---//
//#define CHAR14_SHOW

//---显示ASCII码对应的字符---//
#define USE_ASCII

#define TIME_DISPLAY

//---定义全局变量---//
void GUI_Dot(uint x, uint y, uint color);  //画点
//void GUI_Box(uint sx, uint sy, uchar ex, uint ey, uint color);   //画方框
//void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color);//画线条
void GUI_Write32CnChar(uint x, uint y, uchar *cn, uint wordColor, uint backColor);	 
//void GUI_Write14CnChar(uint x,uint y,uchar *cn,uint wordColor,uint backColor);	 
//void GUI_ShowPicture(uint x, uint y, uchar wide, uint high);
void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor); //以字符串格式一次输出*P指向的单元
void GUI_WriteASCII_SINGLE(uint x, uint y, uchar p, uint wordColor, uint backColor); //显示单个ASCII字符，遇到多字符需要显示，单字符显示效率不高

void GUI_TimeDisplay(uint x_Start, uint y_start,uint Time_wordColor, uint Time_backColor); //显示时间
void GUI_IR_VALUE_DISPLAY_16X24(uint x, uint y, uchar IRcode, uint wordColor, uint backColor);  //显示IR键值；
void GUI_TEMPERATUER_DISPLAY_16X24(uint x, uint y, int temp, uint wordColor, uint backColor);  //显示温度
void GUI_AT24C02_DISPLAY_16X24(uint x, uint y, uint wordColor, uint backColor) ;  //显示AT24C02保存的温度

#endif

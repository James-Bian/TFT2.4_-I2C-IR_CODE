#ifndef __LCD_DRIVE_H
#define __LCD_DRIVE_H


#include <reg52.h>

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

#ifndef ulong
#define ulong  unsigned long
#endif

//---定义使用的IO口---//
sbit	    TFT_RST = P3^3;   //复位
sbit	    TFT_CS  = P2^7;	  //片选
sbit	    TFT_RS  = P3^2;	  //数据或命令选择端,1为数据，0为命令
sbit	    TFT_WR  = P2^5;	  //写执行控制端口
sbit      TFT_RD  = P2^6;   //读写控制端口

#define     TFT_DATAPORT  P0    

//---定义颜色的宏---//
#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x001F
#define RED            0xF800
#define MAGENTA        0xF81F
#define GREEN          0x07E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0		 //定义颜色的宏

//---定义屏的大小---//
#define TFT_XMAX ((uint)239)//		//设置TFT屏的大小
#define TFT_YMAX ((uint)319)//

//-- 声明全局函数 --//
void TFT_WriteCmd(uint cmd);     //写入命令，16位
void TFT_WriteData(uint dat);    //写入数据，16位
void TFT_Init(void);             //初始化显示屏
void TFT_SetWindow(uint xStart, uint yStart, uint xEnd, uint yEnd); //设置显示窗口，依次连续填入pixel
void TFT_ClearScreen(uint color);                                   //以color逐个渲染pixel
void TFT_WriteColorData(uint color);                                //在设置窗口情况下，直接点亮以color点亮pixel
void WriteData(uint i);                                             //写入命令，8位有效
void WriteComm(uint i);																							//写入数据，8位有效
																
#endif

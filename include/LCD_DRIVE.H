#ifndef __LCD_DRIVE_H
#define __LCD_DRIVE_H


#include <reg52.h>

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint
#define uint  unsigned int
#endif

#ifndef ulong
#define ulong  unsigned long
#endif

//---����ʹ�õ�IO��---//
sbit	    TFT_RST = P3^3;   //��λ
sbit	    TFT_CS  = P2^7;	  //Ƭѡ
sbit	    TFT_RS  = P3^2;	  //���ݻ�����ѡ���,1Ϊ���ݣ�0Ϊ����
sbit	    TFT_WR  = P2^5;	  //дִ�п��ƶ˿�
sbit      TFT_RD  = P2^6;   //��д���ƶ˿�

#define     TFT_DATAPORT  P0    

//---������ɫ�ĺ�---//
#define WHITE          0xFFFF
#define BLACK          0x0000
#define BLUE           0x001F
#define RED            0xF800
#define MAGENTA        0xF81F
#define GREEN          0x07E0
#define CYAN           0x7FFF
#define YELLOW         0xFFE0		 //������ɫ�ĺ�

//---�������Ĵ�С---//
#define TFT_XMAX ((uint)239)//		//����TFT���Ĵ�С
#define TFT_YMAX ((uint)319)//

//-- ����ȫ�ֺ��� --//
void TFT_WriteCmd(uint cmd);     //д�����16λ
void TFT_WriteData(uint dat);    //д�����ݣ�16λ
void TFT_Init(void);             //��ʼ����ʾ��
void TFT_SetWindow(uint xStart, uint yStart, uint xEnd, uint yEnd); //������ʾ���ڣ�������������pixel
void TFT_ClearScreen(uint color);                                   //��color�����Ⱦpixel
void TFT_WriteColorData(uint color);                                //�����ô�������£�ֱ�ӵ�����color����pixel
void WriteData(uint i);                                             //д�����8λ��Ч
void WriteComm(uint i);																							//д�����ݣ�8λ��Ч
																
#endif
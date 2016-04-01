#include"gui.h"


//---���ֵ��ֿ�ͷ�ļ�---//
#include"charcode.h"

//---���Ҫ��ʾͼƬ��������ͷ�ļ�---//
#ifdef PICTURE_SHOW

#include"picture.h"

#endif

/****************************************************************************
*��������GUI_Dot
*��  �룺x�����X���ꣻ
*      * y�����Y����
*      * color�������ɫ
*��  ����
*��  �ܣ�����������Ϳ����ɫ��
****************************************************************************/	  

void GUI_Dot(uint x, uint y, uint color)
{  
	uchar i;

	TFT_SetWindow(x, y, x+2, y+2);  //��������

	for(i=0; i<9; i++)
	{
		TFT_WriteData(color);
	}
}

///****************************************************************************
//*��������GUI_Box
//*��  �룺sx����ʼX����, sy����ʵY����, 
//*      * ex����ֹX����, ey����ֹY����,
//*      * color���������ɫ
//*��  ����
//*��  �ܣ���һ������Ϳ����ɫ��
//****************************************************************************/	  
//void GUI_Box(uint sx, uint sy, uchar ex, uint ey, uint color)
//{ 
//	uint temp;   
//	TFT_SetWindow(sx, sy, ex, ey); 
//  sx = ex - sx + 1;
//	sy = ey - sy + 1;
//	while (sx--)
//	{
//	 	temp = sy;
//		while (temp--)
//	 	{	
//			TFT_WriteData(color);
//		}
//	}
//}

/****************************************************************************
*��������GUI_Line 
*��  �룺xStart���ߵ���ʼX����,
*      * yStart���ߵ���ʵY����,
*      * xEnd���ߵ���ֹX����,
*      * yEnd���ߵ���ֹY����,
*      * color����������ɫ
*��  ����
*��  �ܣ���һ��ֱ��
****************************************************************************/	  

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color)
{
	uint t;  
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;  
	int incx, incy;  
	uint row, col;  
	delta_x = xEnd - xStart;//������������  
	delta_y = yEnd - yStart;  
	col = xStart;  
	row = yStart;  
	if (delta_x > 0)
	{
		incx=1;//���õ�������
	} 	  
	else    
	{  
	    if (delta_x == 0)
		{
			incx = 0;//��ֱ�� 
		} 		 
	    else 
			{
				incx = -1;
				delta_x = -delta_x;
			}  
	}  
	if (delta_y > 0)
	{
		incy = 1;
	}	  
	else  
	{  
	    if (delta_y == 0)
		{
			incy = 0;//ˮƽ��  
		} 
	    else 
		{
			incy = -1;
			delta_y = -delta_y;
		}  
	}  
	if (delta_x > delta_y)
	{ 
		distance = delta_x;//ѡȡ��������������  
	}
	else
	{
		distance = delta_y; 
	} 	
	for (t=0; t<=distance+1; t++)  
	{                                     //�������  
	    GUI_Dot(col, row, color);
	    xerr += delta_x;  
	    yerr += delta_y;  
	  	if(xerr > distance)  
	    {  
	        xerr -= distance;  
	        col += incx;  
	    }  
	    if(yerr > distance)  
	    {  
	        yerr -= distance;  
	        row += incy;  
	    }  
	}  
}

/****************************************************************************
*��������GUI_WriteCnChar 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * *cn��Ҫ��ʾ���ַ���
*      * wordColor���������ɫ
*      * backColor��������ɫ
*��  ����
*��  �ܣ�д���ſ��庺��
****************************************************************************/	  

#ifdef CHAR32_SHOW

void GUI_Write32CnChar(uint x, uint y, uchar *cn, uint wordColor, uint backColor)	 
{  
	uchar i, j, wordNum;
	uint color;
	while (*cn != '\0')
	{
		TFT_SetWindow(x, y, x+31, y+28);
		for (wordNum=0; wordNum<20; wordNum++)
		{	//wordNumɨ���ֿ������
			if ((CnChar32x29[wordNum].Index[0]==*cn)
			     &&(CnChar32x29[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<116; i++) 
				{	//MSK��λ��
					color=CnChar32x29[wordNum].Msk[i];
					for(j=0;j<8;j++) 
					{
						if((color&0x80)==0x80)
						{
							TFT_WriteData(wordColor);
						} 						
						else
						{
							TFT_WriteData(backColor);
						} 
						color<<=1;
					}//for(j=0;j<8;j++)����
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)���� 	
		cn += 2;
		x += 32;
	}
}
#endif

/****************************************************************************
*��������GUI_WriteEnChar 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * *cn��Ҫ��ʾ���ַ���
*      * wordColor���������ɫ
*      * backColor��������ɫ
*��  ����
*��  �ܣ�д�ĺ�����ĸ
****************************************************************************/	  
#ifdef CHAR14_SHOW

void GUI_Write14CnChar(uint x,uint y,uchar *cn,uint wordColor,uint backColor)	 
{  
	uchar i, j, wordNum;
	uint color;
	while (*cn != '\0')
	{
		TFT_SetWindow(x, y, x+23, y+18);
		for (wordNum=0; wordNum<20; wordNum++)
		{	//wordNumɨ���ֿ������
			if ((CnChar19x24[wordNum].Index[0]==*cn)
			     &&(CnChar19x24[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<57; i++) 
				{	//MSK��λ��
					color=CnChar19x24[wordNum].Msk[i];
					for(j=0;j<8;j++) 
					{
						if((color&0x80)==0x80)
						{
							TFT_WriteData(wordColor);
						} 						
						else
						{
							TFT_WriteData(backColor);
						} 
						color<<=1;
					}//for(j=0;j<8;j++)����
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)���� 	
		cn += 2;
		x += 24;
	}
}

#endif 
/****************************************************************************
*��������GUI_WriteASCII 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * *p��Ҫ��ʾ���ַ���
*      * wordColor���������ɫ
*      * backColor��������ɫ
*��  ����
*��  �ܣ�д16X24��ASCII�ַ�
****************************************************************************/	  

#ifdef USE_ASCII

void GUI_WriteASCII(uint x, uint y, uchar *p, uint wordColor, uint backColor)
{
	uchar j, wordByte,wordNum;
	uint color;
	while(*p != '\0')
	{
		wordNum = *p - 32;
		TFT_SetWindow(x,y,x+15, y+23);
		for (wordByte=0; wordByte<48; wordByte++)
		{
			color = ASCII16x24[wordNum][wordByte];
			for (j=0; j<8; j++) 
			{
				if ((color&0x80) == 0x80)
				{
					TFT_WriteData(wordColor);
				} 						
				else
				{
					TFT_WriteData(backColor);
				} 	
				color <<= 1;
			}
		}
		p++;
		x +=16;
	}
}
#endif

/****************************************************************************
*��������GUI_WriteASCII 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * p��Ҫ��ʾ���ַ�
*      * wordColor���������ɫ
*      * backColor��������ɫ
*��  ����
*��  �ܣ�д16X24��ASCII�ַ�
****************************************************************************/	  


void GUI_WriteASCII_SINGLE(uint x, uint y, uchar p, uint wordColor, uint backColor)
{
	uchar j, wordByte,wordNum;
	uint color;	
	
		wordNum = p - 32;
		TFT_SetWindow(x,y,x+15, y+23);
		for (wordByte=0; wordByte<48; wordByte++)
		{
			color = ASCII16x24[wordNum][wordByte];
			for (j=0; j<8; j++) 
			{
				if ((color&0x80) == 0x80)
				{
					TFT_WriteData(wordColor);
				} 						
				else
				{
					TFT_WriteData(backColor);
				} 	
				color <<= 1;
			}
		}	
	
}


/****************************************************************************
*��������GUI_ShowPicture 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * wide��ͼƬ�Ŀ��
*      * high��ͼƬ�ĸ߶�
*��  ����
*��  �ܣ���һ��ֱ��
****************************************************************************/	  
#ifdef PICTURE_SHOW

void GUI_ShowPicture(uint x, uint y, uchar wide, uint high)
{
	uint temp = 0, tmp = 0, num = 0;
	TFT_SetWindow(x, y, x+wide-1, y+high-1);
	num = wide * high * 2;
	do
	{  
		temp = pic[tmp + 1];
		temp = temp << 8;
		temp = temp | pic[tmp];
		TFT_WriteData(~temp);             //�����ʾ
		tmp += 2;
	}
	while(tmp < num);	
}

#endif

#ifdef TIME_DISPLAY

/****************************************************************************
*��������GUI_TimeDisplay 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * Time_wordColor��������ɫ
*      * Time_backColor�����ֱ���ɫ
*��  ����
*��  �ܣ�ָ��λ����ʾRTCʱ��
****************************************************************************/	 
void GUI_TimeDisplay(uint x_Start, uint y_start,uint Time_wordColor, uint Time_backColor)
 {
	 GUI_WriteASCII(x_Start, y_start, HOUR, Time_wordColor, Time_backColor);
	 GUI_WriteASCII(x_Start+32, y_start, ":", Time_wordColor, Time_backColor);
	 GUI_WriteASCII(x_Start+48, y_start, MINUTE, Time_wordColor, Time_backColor);
	 GUI_WriteASCII(x_Start+80, y_start, ":", Time_wordColor, Time_backColor);
	 GUI_WriteASCII(x_Start+96, y_start, SECOND, Time_wordColor, Time_backColor);
 }
 
 /****************************************************************************
*��������GUI_IR_VALUE_DISPLAY 
*��  �룺x����ʾ��ʼX����
*      * y����ʾ��ʼY����
*      * Time_wordColor��������ɫ
*      * Time_backColor�����ֱ���ɫ
*��  ����
*��  �ܣ�ָ��λ����ʾIR��ֵ
****************************************************************************/	
void GUI_IR_VALUE_DISPLAY_16X24(uint x, uint y, uchar IRcode, uint wordColor, uint backColor) //ָ��λ����ʾIR��ֵ
{
	uchar IrValueH,IrValueL,temp;
  IrValueH=IRcode>>4;	 	 	//��λ
	IrValueL=IRcode&0x0F;		//��λ
	if(IrValueH>9)
	{
			temp=0x37+IrValueH;	//����ֵת��Ϊ����ʾ��ASCII��
			IrValueH=temp;
	}
	else
		{
			temp=0x30+IrValueH;	//����ֵת��Ϊ����ʾ��ASCII��
			IrValueH=temp;
		}	
	if(IrValueL>9)
		{
			temp=0x37+IrValueL;	//����ֵת��Ϊ����ʾ��ASCII��
			IrValueL=temp;
		}
	else
		{
			temp=0x30+IrValueL;	//����ֵת��Ϊ����ʾ��ASCII��
			IrValueL=temp;
		}	
	
	GUI_WriteASCII_SINGLE(x,    y, IrValueH, wordColor, backColor); //��ʾ��λ��
	GUI_WriteASCII_SINGLE(x+16, y, IrValueL, wordColor, backColor); //��ʾ��λ��	
}	  
#endif

void GUI_TEMPERATUER_DISPLAY_16X24(uint x, uint y, int temp, uint wordColor, uint backColor)  //��ʾ�¶�
{
	unsigned char datas[] = {0, 0, 0, 0, 0}; //��������
	unsigned char Temp_Symbol;
	float tp; 
		 
	if(temp< 0)				    //���¶�ֵΪ����
  	{
	  //��Ϊ��ȡ���¶���ʵ���¶ȵĲ��룬���Լ�1����ȡ�����ԭ��
		Temp_Symbol='-';
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
 
  	}
 	else   //�¶�Ϊ����
  	{	
    Temp_Symbol='+';			
		tp=temp;//��Ϊ���ݴ�����С�������Խ��¶ȸ���һ�������ͱ���
		//����¶���������ô����ô������ԭ����ǲ���������
		temp=tp*0.0625*100+0.5;	
		//������С�����*100��+0.5���������룬��ΪC���Ը�����ת��Ϊ���͵�ʱ���С����
		//��������Զ�ȥ���������Ƿ����0.5����+0.5֮�����0.5�ľ��ǽ�1�ˣ�С��0.5�ľ�
		//�����0.5��������С������档
	}
	datas[0] = temp / 10000;
	datas[1] = temp % 10000 / 1000;
	datas[2] = temp % 1000 / 100;
	datas[3] = temp % 100 / 10;     //С����1λ
	datas[4] = temp % 10;           //С����2λ

	GUI_WriteASCII_SINGLE(x,       y, Temp_Symbol , wordColor, backColor);   //��ʾ���ţ�
	//GUI_WriteASCII_SINGLE(x+16,    y, datas[0]+'0', wordColor, backColor); //��ʾ��λ
	GUI_WriteASCII_SINGLE(x+16,    y, datas[1]+'0', wordColor, backColor);   //��ʾʮλ
  GUI_WriteASCII_SINGLE(x+32,    y, datas[2]+'0', wordColor, backColor);   //��ʾ��λ
  GUI_WriteASCII_SINGLE(x+48,    y,          '.', wordColor, backColor);   //��ʾ���
	GUI_WriteASCII_SINGLE(x+64,    y, datas[3]+'0', wordColor, backColor);   //��ʾС����
	GUI_WriteASCII_SINGLE(x+80,    y, datas[4]+'0', wordColor, backColor);   //��ʾС����	
}

#if 1
void GUI_AT24C02_DISPLAY_16X24(uint x, uint y, uint wordColor, uint backColor) 
{
	int tem;
	if(IIC_ReceiveDataFromDevice(AT24C02_READ,1))
	  {
		 tem=IIC_DATA;
	  }
	//else printf("read erro");
		if(IIC_ReceiveDataFromDevice(AT24C02_READ,2))
	  {
		 tem=(tem<<8)+IIC_DATA;
	  }		
	//else printf("read erro");
	GUI_TEMPERATUER_DISPLAY_16X24(x, y, tem, wordColor, backColor);	
}

#else
void GUI_AT24C02_DISPLAY_16X24(uint x, uint y, uint wordColor, uint backColor) 
{
	int tem;
	tem=IIC_Read_Data_From_Address(1);
	tem=(tem<<8)+IIC_Read_Data_From_Address(2);
	GUI_TEMPERATUER_DISPLAY_16X24(x, y, tem, wordColor, backColor);	
}

#endif
#include"gui.h"


//---汉字的字库头文件---//
#include"charcode.h"

//---如果要显示图片就添加这个头文件---//
#ifdef PICTURE_SHOW

#include"picture.h"

#endif

/****************************************************************************
*函数名：GUI_Dot
*输  入：x：点的X坐标；
*      * y：点的Y坐标
*      * color：点的颜色
*输  出：
*功  能：给单个像素涂上颜色。
****************************************************************************/	  

void GUI_Dot(uint x, uint y, uint color)
{  
	uchar i;

	TFT_SetWindow(x, y, x+2, y+2);  //单个像素

	for(i=0; i<9; i++)
	{
		TFT_WriteData(color);
	}
}

///****************************************************************************
//*函数名：GUI_Box
//*输  入：sx：起始X坐标, sy：其实Y坐标, 
//*      * ex：终止X坐标, ey：终止Y坐标,
//*      * color：方框的颜色
//*输  出：
//*功  能：给一个区域涂上颜色。
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
*函数名：GUI_Line 
*输  入：xStart：线的起始X坐标,
*      * yStart：线的其实Y坐标,
*      * xEnd：线的终止X坐标,
*      * yEnd：线的终止Y坐标,
*      * color：线条的颜色
*输  出：
*功  能：画一条直线
****************************************************************************/	  

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color)
{
	uint t;  
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;  
	int incx, incy;  
	uint row, col;  
	delta_x = xEnd - xStart;//计算坐标增量  
	delta_y = yEnd - yStart;  
	col = xStart;  
	row = yStart;  
	if (delta_x > 0)
	{
		incx=1;//设置单步方向
	} 	  
	else    
	{  
	    if (delta_x == 0)
		{
			incx = 0;//垂直线 
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
			incy = 0;//水平线  
		} 
	    else 
		{
			incy = -1;
			delta_y = -delta_y;
		}  
	}  
	if (delta_x > delta_y)
	{ 
		distance = delta_x;//选取基本增量坐标轴  
	}
	else
	{
		distance = delta_y; 
	} 	
	for (t=0; t<=distance+1; t++)  
	{                                     //画线输出  
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
*函数名：GUI_WriteCnChar 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * *cn：要显示的字符串
*      * wordColor：字体的颜色
*      * backColor：背景颜色
*输  出：
*功  能：写二号楷体汉字
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
		{	//wordNum扫描字库的字数
			if ((CnChar32x29[wordNum].Index[0]==*cn)
			     &&(CnChar32x29[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<116; i++) 
				{	//MSK的位数
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
					}//for(j=0;j<8;j++)结束
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)结束 	
		cn += 2;
		x += 32;
	}
}
#endif

/****************************************************************************
*函数名：GUI_WriteEnChar 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * *cn：要显示的字符串
*      * wordColor：字体的颜色
*      * backColor：背景颜色
*输  出：
*功  能：写四号字字母
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
		{	//wordNum扫描字库的字数
			if ((CnChar19x24[wordNum].Index[0]==*cn)
			     &&(CnChar19x24[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<57; i++) 
				{	//MSK的位数
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
					}//for(j=0;j<8;j++)结束
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)结束 	
		cn += 2;
		x += 24;
	}
}

#endif 
/****************************************************************************
*函数名：GUI_WriteASCII 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * *p：要显示的字符串
*      * wordColor：字体的颜色
*      * backColor：背景颜色
*输  出：
*功  能：写16X24的ASCII字符
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
*函数名：GUI_WriteASCII 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * p：要显示的字符
*      * wordColor：字体的颜色
*      * backColor：背景颜色
*输  出：
*功  能：写16X24的ASCII字符
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
*函数名：GUI_ShowPicture 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * wide：图片的宽度
*      * high：图片的高度
*输  出：
*功  能：画一条直线
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
		TFT_WriteData(~temp);             //逐点显示
		tmp += 2;
	}
	while(tmp < num);	
}

#endif

#ifdef TIME_DISPLAY

/****************************************************************************
*函数名：GUI_TimeDisplay 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * Time_wordColor：文字颜色
*      * Time_backColor：文字背景色
*输  出：
*功  能：指定位置显示RTC时间
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
*函数名：GUI_IR_VALUE_DISPLAY 
*输  入：x：显示起始X坐标
*      * y：显示起始Y坐标
*      * Time_wordColor：文字颜色
*      * Time_backColor：文字背景色
*输  出：
*功  能：指定位置显示IR键值
****************************************************************************/	
void GUI_IR_VALUE_DISPLAY_16X24(uint x, uint y, uchar IRcode, uint wordColor, uint backColor) //指定位置显示IR键值
{
	uchar IrValueH,IrValueL,temp;
  IrValueH=IRcode>>4;	 	 	//高位
	IrValueL=IRcode&0x0F;		//低位
	if(IrValueH>9)
	{
			temp=0x37+IrValueH;	//将数值转换为该显示的ASCII码
			IrValueH=temp;
	}
	else
		{
			temp=0x30+IrValueH;	//将数值转换为该显示的ASCII码
			IrValueH=temp;
		}	
	if(IrValueL>9)
		{
			temp=0x37+IrValueL;	//将数值转换为该显示的ASCII码
			IrValueL=temp;
		}
	else
		{
			temp=0x30+IrValueL;	//将数值转换为该显示的ASCII码
			IrValueL=temp;
		}	
	
	GUI_WriteASCII_SINGLE(x,    y, IrValueH, wordColor, backColor); //显示高位；
	GUI_WriteASCII_SINGLE(x+16, y, IrValueL, wordColor, backColor); //显示高位；	
}	  
#endif

void GUI_TEMPERATUER_DISPLAY_16X24(uint x, uint y, int temp, uint wordColor, uint backColor)  //显示温度
{
	unsigned char datas[] = {0, 0, 0, 0, 0}; //定义数组
	unsigned char Temp_Symbol;
	float tp; 
		 
	if(temp< 0)				    //当温度值为负数
  	{
	  //因为读取的温度是实际温度的补码，所以减1，再取反求出原码
		Temp_Symbol='-';
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		//留两个小数点就*100，+0.5是四舍五入，因为C语言浮点数转换为整型的时候把小数点
		//后面的数自动去掉，不管是否大于0.5，而+0.5之后大于0.5的就是进1了，小于0.5的就
		//算由�0.5，还是在小数点后面。
 
  	}
 	else   //温度为正数
  	{	
    Temp_Symbol='+';			
		tp=temp;//因为数据处理有小数点所以将温度赋给一个浮点型变量
		//如果温度是正的那么，那么正数的原码就是补码它本身
		temp=tp*0.0625*100+0.5;	
		//留两个小数点就*100，+0.5是四舍五入，因为C语言浮点数转换为整型的时候把小数点
		//后面的数自动去掉，不管是否大于0.5，而+0.5之后大于0.5的就是进1了，小于0.5的就
		//算加上0.5，还是在小数点后面。
	}
	datas[0] = temp / 10000;
	datas[1] = temp % 10000 / 1000;
	datas[2] = temp % 1000 / 100;
	datas[3] = temp % 100 / 10;     //小数第1位
	datas[4] = temp % 10;           //小数第2位

	GUI_WriteASCII_SINGLE(x,       y, Temp_Symbol , wordColor, backColor);   //显示符号；
	//GUI_WriteASCII_SINGLE(x+16,    y, datas[0]+'0', wordColor, backColor); //显示百位
	GUI_WriteASCII_SINGLE(x+16,    y, datas[1]+'0', wordColor, backColor);   //显示十位
  GUI_WriteASCII_SINGLE(x+32,    y, datas[2]+'0', wordColor, backColor);   //显示个位
  GUI_WriteASCII_SINGLE(x+48,    y,          '.', wordColor, backColor);   //显示点号
	GUI_WriteASCII_SINGLE(x+64,    y, datas[3]+'0', wordColor, backColor);   //显示小数点
	GUI_WriteASCII_SINGLE(x+80,    y, datas[4]+'0', wordColor, backColor);   //显示小数点	
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
#include"gui.h"


//---ºº×ÖµÄ×Ö¿âÍ·ÎÄ¼ş---//
#include"charcode.h"

//---Èç¹ûÒªÏÔÊ¾Í¼Æ¬¾ÍÌí¼ÓÕâ¸öÍ·ÎÄ¼ş---//
#ifdef PICTURE_SHOW

#include"picture.h"

#endif

/****************************************************************************
*º¯ÊıÃû£ºGUI_Dot
*Êä  Èë£ºx£ºµãµÄX×ø±ê£»
*      * y£ºµãµÄY×ø±ê
*      * color£ºµãµÄÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£º¸øµ¥¸öÏñËØÍ¿ÉÏÑÕÉ«¡£
****************************************************************************/	  

void GUI_Dot(uint x, uint y, uint color)
{  
	uchar i;

	TFT_SetWindow(x, y, x+2, y+2);  //µ¥¸öÏñËØ

	for(i=0; i<9; i++)
	{
		TFT_WriteData(color);
	}
}

///****************************************************************************
//*º¯ÊıÃû£ºGUI_Box
//*Êä  Èë£ºsx£ºÆğÊ¼X×ø±ê, sy£ºÆäÊµY×ø±ê, 
//*      * ex£ºÖÕÖ¹X×ø±ê, ey£ºÖÕÖ¹Y×ø±ê,
//*      * color£º·½¿òµÄÑÕÉ«
//*Êä  ³ö£º
//*¹¦  ÄÜ£º¸øÒ»¸öÇøÓòÍ¿ÉÏÑÕÉ«¡£
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
*º¯ÊıÃû£ºGUI_Line 
*Êä  Èë£ºxStart£ºÏßµÄÆğÊ¼X×ø±ê,
*      * yStart£ºÏßµÄÆäÊµY×ø±ê,
*      * xEnd£ºÏßµÄÖÕÖ¹X×ø±ê,
*      * yEnd£ºÏßµÄÖÕÖ¹Y×ø±ê,
*      * color£ºÏßÌõµÄÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£º»­Ò»ÌõÖ±Ïß
****************************************************************************/	  

void GUI_Line(uint xStart, uint yStart, uchar xEnd, uint yEnd, uint color)
{
	uint t;  
	int xerr = 0, yerr = 0, delta_x, delta_y, distance;  
	int incx, incy;  
	uint row, col;  
	delta_x = xEnd - xStart;//¼ÆËã×ø±êÔöÁ¿  
	delta_y = yEnd - yStart;  
	col = xStart;  
	row = yStart;  
	if (delta_x > 0)
	{
		incx=1;//ÉèÖÃµ¥²½·½Ïò
	} 	  
	else    
	{  
	    if (delta_x == 0)
		{
			incx = 0;//´¹Ö±Ïß 
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
			incy = 0;//Ë®Æ½Ïß  
		} 
	    else 
		{
			incy = -1;
			delta_y = -delta_y;
		}  
	}  
	if (delta_x > delta_y)
	{ 
		distance = delta_x;//Ñ¡È¡»ù±¾ÔöÁ¿×ø±êÖá  
	}
	else
	{
		distance = delta_y; 
	} 	
	for (t=0; t<=distance+1; t++)  
	{                                     //»­ÏßÊä³ö  
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
*º¯ÊıÃû£ºGUI_WriteCnChar 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * *cn£ºÒªÏÔÊ¾µÄ×Ö·û´®
*      * wordColor£º×ÖÌåµÄÑÕÉ«
*      * backColor£º±³¾°ÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£ºĞ´¶şºÅ¿¬Ìåºº×Ö
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
		{	//wordNumÉ¨Ãè×Ö¿âµÄ×ÖÊı
			if ((CnChar32x29[wordNum].Index[0]==*cn)
			     &&(CnChar32x29[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<116; i++) 
				{	//MSKµÄÎ»Êı
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
					}//for(j=0;j<8;j++)½áÊø
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)½áÊø 	
		cn += 2;
		x += 32;
	}
}
#endif

/****************************************************************************
*º¯ÊıÃû£ºGUI_WriteEnChar 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * *cn£ºÒªÏÔÊ¾µÄ×Ö·û´®
*      * wordColor£º×ÖÌåµÄÑÕÉ«
*      * backColor£º±³¾°ÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£ºĞ´ËÄºÅ×Ö×ÖÄ¸
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
		{	//wordNumÉ¨Ãè×Ö¿âµÄ×ÖÊı
			if ((CnChar19x24[wordNum].Index[0]==*cn)
			     &&(CnChar19x24[wordNum].Index[1]==*(cn+1)))
			{
				for(i=0; i<57; i++) 
				{	//MSKµÄÎ»Êı
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
					}//for(j=0;j<8;j++)½áÊø
				}    
			}
		} //for (wordNum=0; wordNum<20; wordNum++)½áÊø 	
		cn += 2;
		x += 24;
	}
}

#endif 
/****************************************************************************
*º¯ÊıÃû£ºGUI_WriteASCII 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * *p£ºÒªÏÔÊ¾µÄ×Ö·û´®
*      * wordColor£º×ÖÌåµÄÑÕÉ«
*      * backColor£º±³¾°ÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£ºĞ´16X24µÄASCII×Ö·û
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
*º¯ÊıÃû£ºGUI_WriteASCII 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * p£ºÒªÏÔÊ¾µÄ×Ö·û
*      * wordColor£º×ÖÌåµÄÑÕÉ«
*      * backColor£º±³¾°ÑÕÉ«
*Êä  ³ö£º
*¹¦  ÄÜ£ºĞ´16X24µÄASCII×Ö·û
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
*º¯ÊıÃû£ºGUI_ShowPicture 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * wide£ºÍ¼Æ¬µÄ¿í¶È
*      * high£ºÍ¼Æ¬µÄ¸ß¶È
*Êä  ³ö£º
*¹¦  ÄÜ£º»­Ò»ÌõÖ±Ïß
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
		TFT_WriteData(~temp);             //ÖğµãÏÔÊ¾
		tmp += 2;
	}
	while(tmp < num);	
}

#endif

#ifdef TIME_DISPLAY

/****************************************************************************
*º¯ÊıÃû£ºGUI_TimeDisplay 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * Time_wordColor£ºÎÄ×ÖÑÕÉ«
*      * Time_backColor£ºÎÄ×Ö±³¾°É«
*Êä  ³ö£º
*¹¦  ÄÜ£ºÖ¸¶¨Î»ÖÃÏÔÊ¾RTCÊ±¼ä
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
*º¯ÊıÃû£ºGUI_IR_VALUE_DISPLAY 
*Êä  Èë£ºx£ºÏÔÊ¾ÆğÊ¼X×ø±ê
*      * y£ºÏÔÊ¾ÆğÊ¼Y×ø±ê
*      * Time_wordColor£ºÎÄ×ÖÑÕÉ«
*      * Time_backColor£ºÎÄ×Ö±³¾°É«
*Êä  ³ö£º
*¹¦  ÄÜ£ºÖ¸¶¨Î»ÖÃÏÔÊ¾IR¼üÖµ
****************************************************************************/	
void GUI_IR_VALUE_DISPLAY_16X24(uint x, uint y, uchar IRcode, uint wordColor, uint backColor) //Ö¸¶¨Î»ÖÃÏÔÊ¾IR¼üÖµ
{
	uchar IrValueH,IrValueL,temp;
  IrValueH=IRcode>>4;	 	 	//¸ßÎ»
	IrValueL=IRcode&0x0F;		//µÍÎ»
	if(IrValueH>9)
	{
			temp=0x37+IrValueH;	//½«ÊıÖµ×ª»»Îª¸ÃÏÔÊ¾µÄASCIIÂë
			IrValueH=temp;
	}
	else
		{
			temp=0x30+IrValueH;	//½«ÊıÖµ×ª»»Îª¸ÃÏÔÊ¾µÄASCIIÂë
			IrValueH=temp;
		}	
	if(IrValueL>9)
		{
			temp=0x37+IrValueL;	//½«ÊıÖµ×ª»»Îª¸ÃÏÔÊ¾µÄASCIIÂë
			IrValueL=temp;
		}
	else
		{
			temp=0x30+IrValueL;	//½«ÊıÖµ×ª»»Îª¸ÃÏÔÊ¾µÄASCIIÂë
			IrValueL=temp;
		}	
	
	GUI_WriteASCII_SINGLE(x,    y, IrValueH, wordColor, backColor); //ÏÔÊ¾¸ßÎ»£»
	GUI_WriteASCII_SINGLE(x+16, y, IrValueL, wordColor, backColor); //ÏÔÊ¾¸ßÎ»£»	
}	  
#endif

void GUI_TEMPERATUER_DISPLAY_16X24(uint x, uint y, int temp, uint wordColor, uint backColor)  //ÏÔÊ¾ÎÂ¶È
{
	unsigned char datas[] = {0, 0, 0, 0, 0}; //¶¨ÒåÊı×é
	unsigned char Temp_Symbol;
	float tp; 
		 
	if(temp< 0)				    //µ±ÎÂ¶ÈÖµÎª¸ºÊı
  	{
	  //ÒòÎª¶ÁÈ¡µÄÎÂ¶ÈÊÇÊµ¼ÊÎÂ¶ÈµÄ²¹Âë£¬ËùÒÔ¼õ1£¬ÔÙÈ¡·´Çó³öÔ­Âë
		Temp_Symbol='-';
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
		//ÁôÁ½¸öĞ¡Êıµã¾Í*100£¬+0.5ÊÇËÄÉáÎåÈë£¬ÒòÎªCÓïÑÔ¸¡µãÊı×ª»»ÎªÕûĞÍµÄÊ±ºò°ÑĞ¡Êıµã
		//ºóÃæµÄÊı×Ô¶¯È¥µô£¬²»¹ÜÊÇ·ñ´óÓÚ0.5£¬¶ø+0.5Ö®ºó´óÓÚ0.5µÄ¾ÍÊÇ½ø1ÁË£¬Ğ¡ÓÚ0.5µÄ¾Í
		//ËãÓÉÏ0.5£¬»¹ÊÇÔÚĞ¡ÊıµãºóÃæ¡£
 
  	}
 	else   //ÎÂ¶ÈÎªÕıÊı
  	{	
    Temp_Symbol='+';			
		tp=temp;//ÒòÎªÊı¾İ´¦ÀíÓĞĞ¡ÊıµãËùÒÔ½«ÎÂ¶È¸³¸øÒ»¸ö¸¡µãĞÍ±äÁ¿
		//Èç¹ûÎÂ¶ÈÊÇÕıµÄÄÇÃ´£¬ÄÇÃ´ÕıÊıµÄÔ­Âë¾ÍÊÇ²¹ÂëËü±¾Éí
		temp=tp*0.0625*100+0.5;	
		//ÁôÁ½¸öĞ¡Êıµã¾Í*100£¬+0.5ÊÇËÄÉáÎåÈë£¬ÒòÎªCÓïÑÔ¸¡µãÊı×ª»»ÎªÕûĞÍµÄÊ±ºò°ÑĞ¡Êıµã
		//ºóÃæµÄÊı×Ô¶¯È¥µô£¬²»¹ÜÊÇ·ñ´óÓÚ0.5£¬¶ø+0.5Ö®ºó´óÓÚ0.5µÄ¾ÍÊÇ½ø1ÁË£¬Ğ¡ÓÚ0.5µÄ¾Í
		//Ëã¼ÓÉÏ0.5£¬»¹ÊÇÔÚĞ¡ÊıµãºóÃæ¡£
	}
	datas[0] = temp / 10000;
	datas[1] = temp % 10000 / 1000;
	datas[2] = temp % 1000 / 100;
	datas[3] = temp % 100 / 10;     //Ğ¡ÊıµÚ1Î»
	datas[4] = temp % 10;           //Ğ¡ÊıµÚ2Î»

	GUI_WriteASCII_SINGLE(x,       y, Temp_Symbol , wordColor, backColor);   //ÏÔÊ¾·ûºÅ£»
	//GUI_WriteASCII_SINGLE(x+16,    y, datas[0]+'0', wordColor, backColor); //ÏÔÊ¾°ÙÎ»
	GUI_WriteASCII_SINGLE(x+16,    y, datas[1]+'0', wordColor, backColor);   //ÏÔÊ¾Ê®Î»
  GUI_WriteASCII_SINGLE(x+32,    y, datas[2]+'0', wordColor, backColor);   //ÏÔÊ¾¸öÎ»
  GUI_WriteASCII_SINGLE(x+48,    y,          '.', wordColor, backColor);   //ÏÔÊ¾µãºÅ
	GUI_WriteASCII_SINGLE(x+64,    y, datas[3]+'0', wordColor, backColor);   //ÏÔÊ¾Ğ¡Êıµã
	GUI_WriteASCII_SINGLE(x+80,    y, datas[4]+'0', wordColor, backColor);   //ÏÔÊ¾Ğ¡Êıµã	
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
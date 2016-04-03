#include <REG52.H>
#include "lcd_drive.h"
#include "gui.h"
#include "DS1302.h"
#include "uart.h"
#include <stdio.h>
#include "ir.h"
#include "temp.h"
#include "touch.h"
#include "time.h"
#include "AT24C02.h"

sbit Input_P10=P1^0;
// test;
// fetch testing;
<<<<<<< HEAD
// add new owersdf
=======
// another changes
>>>>>>> 98e64b0334ef33c6b03f10409d9fa9b1de08526f

void main(void)
{   
		long x, y;
	
	  TFT_Init();
	  Uart_Init();
	  IrInit();
	  IIC_Init();
	  Ds1302Init();
	  Ds18b20Init();
	  Ds18b20ReadTemp();
	  Time0_Init();
	
	  printf("TFT彩屏测试程序\r\n");
	
   	TFT_ClearScreen(~BLACK);
	
    GUI_Write32CnChar(0, 0, "吴小慧", ~CYAN, ~0x0000);	
		GUI_WriteASCII (0, 30 ,"RTC Reads:" , ~CYAN, ~BLACK);
		Ds1302ReadTime();	
		GUI_TimeDisplay(0, 54 , ~CYAN, ~BLACK);		
	  GUI_WriteASCII (0, 78 ,"Temperature:" , ~CYAN, ~BLACK);
	  
		GUI_TEMPERATUER_DISPLAY_16X24(0, 102, Ds18b20ReadTemp(), ~CYAN, ~BLACK);	
	  GUI_WriteASCII (0, 126 ,"IRcode:0x" , ~YELLOW, ~BLACK);
		GUI_WriteASCII (0, 150 ,"AT24C:" , ~RED, ~BLACK);
	//	GUI_ShowPicture(5, 146, 112, 150);	
   do
		{ 
			if(RTC_Timer_OK==1)
			{
				ET0=0;
				RTC_Timer_OK=0;
				Ds1302ReadTime();	
			  GUI_TimeDisplay(0, 54 , ~CYAN, ~BLACK);			
			  printf("读取RTC时间\r\n");
				ET0=1;			 
				
			}
			if(Temp_Timer_OK==1)
			 {
				Temp_Timer_OK=0;
				ET0=0;
			  GUI_TEMPERATUER_DISPLAY_16X24(0, 102, Ds18b20ReadTemp(), ~CYAN, ~BLACK);	
				ET0=1;
			  printf("读取DS18B20传感器温度\r\n");				
			 }
		  if(IR_EVENT==1)
			 {
				IR_EVENT=0;
				GUI_IR_VALUE_DISPLAY_16X24(144, 126, IrValue[1],  ~YELLOW, ~BLACK);	
				GUI_IR_VALUE_DISPLAY_16X24(176, 126, IrValue[0],  ~YELLOW, ~BLACK);	
				GUI_IR_VALUE_DISPLAY_16X24(208, 126, IrValue[2],  ~YELLOW, ~BLACK);	
				printf("接收到新的红外遥控按键码\r\n");	
			 }
			
			if(IrValue[2]==0x07)
			{
				IrValue[2]=0;
				AT24C02_Temp_Save();	
			}
			 			 
			if(IrValue[2]==0x15)
			{
				IrValue[2]=0;
				GUI_AT24C02_DISPLAY_16X24(96, 150,  ~RED, ~BLACK);		
			}	
			
			if(TOUCH_PEN==0)
		  	{
				//--如果触摸跟显示发生偏移，可以根据显示AD值--//
				//--调整下面公式里面的数值--//
				TOUCH_XPT_ReadXY();
				x = xpt_xy.x;
				x = (x - 176) * 240 / 3676 ; 
				y =	xpt_xy.y;
				y = (y - 160) * 319 / 3580;

				if (x > 239 )
				{
					x = 239;
				}
				if (y > 319)
				{
					y = 319;
				}
					GUI_Dot((uint)x , (uint)y, ~RED);
				}			
			
		}
		while(1);
}
	

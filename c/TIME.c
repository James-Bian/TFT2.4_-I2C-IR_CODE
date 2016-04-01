#include "time.h"

#define Time_SET 200

unsigned char Temp_Timer_OK=0;
unsigned char RTC_Timer_OK=0;
unsigned int Time_CNT=0;

void Time0_Init()
{
 TMOD|=0x01; //定时器0，方式1,16位定时器；
 TH0=0;
 TL0=0; 	
 ET0=1;
 TR0=1; 
 EA=1; 	
}

void Time0_Int() interrupt 1
{
 TH0=0x8F;
 TL0=0xFF;
 Time_CNT++;
 RTC_Timer_OK=1;
 if(Time_CNT==Time_SET)	
  {
    Temp_Timer_OK=1;
		Time_CNT=0;
	}
}




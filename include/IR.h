#ifndef _IR_H_
#define _IR_H_

//---包含头文件---//
#include<reg52.h>
#include<intrins.h>
#include<stdio.h>


sbit IRIN=P1^1;


extern unsigned char IrValue[6];	  //用来存放读取到的红外值
extern unsigned char IR_Time;
extern unsigned char IR_EVENT;
extern unsigned char IR_Value_Temp;

void IrInit();
void Delay1ms()	;	    //1ms延迟
void Delay140us();		//0.14ms时间延迟；0.56ms时间内采集3-4次，准确判断逻辑1或者0

#endif
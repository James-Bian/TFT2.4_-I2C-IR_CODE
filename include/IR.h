#ifndef _IR_H_
#define _IR_H_

//---����ͷ�ļ�---//
#include<reg52.h>
#include<intrins.h>
#include<stdio.h>


sbit IRIN=P1^1;


extern unsigned char IrValue[6];	  //������Ŷ�ȡ���ĺ���ֵ
extern unsigned char IR_Time;
extern unsigned char IR_EVENT;
extern unsigned char IR_Value_Temp;

void IrInit();
void Delay1ms()	;	    //1ms�ӳ�
void Delay140us();		//0.14msʱ���ӳ٣�0.56msʱ���ڲɼ�3-4�Σ�׼ȷ�ж��߼�1����0

#endif
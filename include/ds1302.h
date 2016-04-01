#ifndef __DS1302_H_
#define __DS1302_H_

//---����ͷ�ļ�---//
#include<reg52.h>
#include<intrins.h>


//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//---����MCU��ds1302ͨѶ��ʹ�õ�IO��---//
sbit DSIO=P3^4;
sbit RST=P3^5;
sbit SCLK=P3^6;

//---����ȫ�ֱ���--//
extern uchar TIME[7];	//����ȫ�ֱ���
extern uchar HOUR[3],MINUTE[3],SECOND[3];

//---����ȫ�ֺ���---//
void Ds1302Write(uchar addr, uchar dat);
uchar Ds1302Read(uchar addr);
void Ds1302Init();
void Ds1302ReadTime();

#endif
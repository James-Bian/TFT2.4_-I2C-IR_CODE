#ifndef __TEMP_H_
#define __TEMP_H_

#include<reg52.h>
#include "AT24C02.h"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

//--����ʹ�õ�IO��--//
sbit DSPORT=P3^7;

//--����ȫ�ֺ���--//
void TempDelay1ms(uint );
uchar Ds18b20Init();
void Ds18b20WriteByte(uchar com);
uchar Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
int Ds18b20ReadTemp();
void AT24C02_Temp_Save(void);

#endif

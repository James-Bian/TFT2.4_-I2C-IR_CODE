#ifndef _AT24C02_H_
#define _AT24C02_H_

#include<reg52.h>
#include"IIC.H"

//---�ض���ؼ���---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#define AT24C02_READ  0xa1	        //������ָ�����λΪ1010������λΪA2 A1 A0 W/P   ���һλΪ1ʱΪд
#define AT24C02_WRITE 0xa0			    //д����ָ��


//--����ȫ�ֺ���--//
void IIC_Write_Data_To_Address(uchar DATA,uchar Address);
uchar IIC_Read_Data_From_Address(uchar Address);

#endif

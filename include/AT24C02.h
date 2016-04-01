#ifndef _AT24C02_H_
#define _AT24C02_H_

#include<reg52.h>
#include"IIC.H"

//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

#define AT24C02_READ  0xa1	        //读操作指令，高四位为1010，第四位为A2 A1 A0 W/P   最后一位为1时为写
#define AT24C02_WRITE 0xa0			    //写操作指令


//--声明全局函数--//
void IIC_Write_Data_To_Address(uchar DATA,uchar Address);
uchar IIC_Read_Data_From_Address(uchar Address);

#endif

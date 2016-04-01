#ifndef IIC_H
#define IIC_H

#include <intrins.h>
#include <reg52.h>
#ifndef uchar 
#define uchar unsigned char
#endif

//*****************************
// Define the IIC bus ports
//*****************************

sbit IIC_SCL = P2^1;           //IIC CLOCK BUS
sbit IIC_SDA = P2^0;           //IIC DATA BUS

extern uchar IIC_DATA;         //Buffer for the IIC data received£»

//*****************************
// Declaim the functions using
//*****************************
void Time_Delay(void);
void IIC_Init(void);
void IIC_Start(void);
void IIC_Stop(void);
bit IIC_Check_Ack(void);
void IIC_SendAck(bit a);
void IIC_Send_Date(uchar DATA);
uchar IIC_Recieve_Data(void);
bit IIC_SendDataToDevice(uchar Data,uchar Sladd,uchar subadd);
bit IIC_ReceiveDataFromDevice(uchar Sladd_Read,uchar subadd);

#endif
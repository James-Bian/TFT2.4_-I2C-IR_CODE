#include"AT24C02.h"

void Time_5ms(void)
{
	unsigned char i, j;

	i = 59;
	j = 90;
	do
	{
		while (--j);
	} while (--i);

}
/*
//*****************************************************************
//       Write data to the address in terminal
//Description : Write data to address terminal
//Argument    £ºDATA,the data ready to write
                Address,the internal address for the DATA to write
                WriteCMD, the Write command of the device
//Returns     £ºnone
//Note        : none
//*****************************************************************
*/

void IIC_Write_Data_To_Address(uchar DATA,uchar Address)
{
  IIC_Start();
	IIC_Send_Date(AT24C02_WRITE);
	IIC_Check_Ack();
	IIC_Send_Date(Address);
	IIC_Check_Ack();
	IIC_Send_Date(DATA);
	IIC_Check_Ack();
	IIC_Stop();
	Time_5ms();                            //This time must be reserved for the device to save the datas;
}

/*
//*****************************************************************
//                  read data from the terminal
//Description : read data from the terminal
//Argument    £ºAddress,the internal address for the DATA to read
                ReadCMD, the read command of the device
//Returns     £ºdata
//Note        : none
//*****************************************************************
*/
uchar IIC_Read_Data_From_Address(uchar Address)
{  
	uchar temp;
  IIC_Start();
	IIC_Send_Date(AT24C02_WRITE);
	IIC_Check_Ack();
	IIC_Send_Date(Address);
	IIC_Check_Ack();
	IIC_Start();
	IIC_Send_Date(AT24C02_READ);
	IIC_Check_Ack();	
	temp=IIC_Recieve_Data();
	IIC_SendAck(1);
	IIC_Stop();	
	return temp;
}

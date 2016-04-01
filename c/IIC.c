#include "IIC.H"

bit   IIC_Ack_State;
uchar IIC_DATA;

void Delay_5ms(void)
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
//        To get a time delay
//Description ��To get a time delay
//Argument    ��m decides the different time delay
//Returns     ��none
//Note        : The delay time depens on the system clock��the 
                delay time varies when the clock changes
//*****************************************************************
*/
void Time_Delay(void)
{
  _nop_();
	_nop_();
	_nop_();
}

/*
//*****************************************************************
//        Initial the IIC bus
//Description ��Initial the IIC bus
//Argument    ��none
//Returns     ��none
//Note        : none
//*****************************************************************
*/
void IIC_Init(void)
{
  IIC_SCL = 1;
  IIC_SDA = 1;
}	


/*
//*****************************************************************
//        Make a start signal for the bus
//Description ��Declaim the start of data transformation
//Argument    ��none
//Returns     ��none
//Note        : none
//*****************************************************************
*/

void IIC_Start(void)
{
  IIC_SCL = 1;
  IIC_SDA = 1;
  Time_Delay();
  IIC_SDA = 0;
	Time_Delay();
	IIC_SCL = 0;                 //ready for the SDA to change
	Time_Delay();
}

/*
//*****************************************************************
//        Make a stop signal for the bus
//Description ��Declaim the stop of data transformation
//Argument    ��none
//Returns     ��none
//Note        : none
//*****************************************************************
*/
void IIC_Stop(void)
{ 
  IIC_SDA = 0;
  IIC_SCL = 1;	
	Time_Delay();
	IIC_SDA = 1;
	Time_Delay();
}
/*
//*****************************************************************
//        Check the Ack on the data bus
//Description ��Check the Ack signal after data transformation
//Argument    ��none
//Returns     ��none
//Note        : none
//*****************************************************************
*/
bit IIC_Check_Ack(void)
{
  uchar errtime=255;	
  IIC_SDA = 1;     // release the data bus for the slaver to generate an acknowledge
	Time_Delay();
  IIC_SCL = 1;
	while((IIC_SDA==1)&&(errtime>0))
	  {
			errtime--;
			if(errtime==0)
			{
			  IIC_Stop();
				return 1;			
			}			
	  }
	Time_Delay();
	IIC_SCL = 0;
	Time_Delay();
	return 0;
}	
/*
//*****************************************************************
//       Make an Ack on the data bus
//Description ��To make an Ack on the data bus afer host receive 
                date to acknowledge the sender, Ack Yes or No,
//Argument    ��a
//Returns     ��none
//Note        : none
//*****************************************************************
*/
void IIC_SendAck(bit a)
{
	if(a==1)
	{
	 IIC_SDA = 1;
	}
	else 
	{
		IIC_SDA = 0;
	}
	Time_Delay();	
  IIC_SCL = 1;	
	Time_Delay();
	IIC_SCL = 0;
	Time_Delay();	
}
/*
//*****************************************************************
//       To send 8 bits data to the terminal
//Description �TTo send 8 bits data to the terminal
//Argument    ��DATA
//Returns     ��none
//Note        : none
//*****************************************************************
*/
void IIC_Send_Date(uchar DATA)
{
  uchar i,temp;
	temp=DATA;
	//IIC_SCL = 0;
	//Time_Delay();
	for(i=0;i<=7;i++)
	  {
		  IIC_SDA=(bit)(temp&0x80);
		  temp<<=1;
			Time_Delay();
	    IIC_SCL = 1;
			Time_Delay(); 			
		  IIC_SCL = 0;
			Time_Delay();	
		}
}

/*
//*****************************************************************
//       To receive 8 bits data from the terminal
//Description �TTo receive 8 bits data from the terminal
//Argument    ��none
//Returns     ��8bits data
//Note        : none
//*****************************************************************
*/

uchar IIC_Recieve_Data(void)
{
  uchar i,temp;
	IIC_SDA = 1;         //release the bus for the terminal
	//IIC_SCL = 0;
	Time_Delay();
	for(i=0;i<=7;i++)
	  {
			IIC_SCL = 1;
			Time_Delay();
			temp<<=1;
			temp|=(uchar)(IIC_SDA);			
			IIC_SCL = 0;
			Time_Delay();				
		 }
	return temp;		
}

/*
//*****************************************************************
//       To send 8 bits data to address in the terminal
//Description : To send 8 bits data to address in the terminal
//Argument    ��Data  - data ready to send;
                Sladd - device address;
                Subadd- space address in the device;
//Returns     ��successful or not
//Note        : none
//*****************************************************************
*/
bit IIC_SendDataToDevice(uchar Data,uchar Sladd_Write,uchar subadd)
{
  IIC_Start();
	IIC_Send_Date(Sladd_Write);
	if(IIC_Check_Ack())
	  {
		  return 0;		
		}
	IIC_Send_Date(subadd);
	if(IIC_Check_Ack())
	  {
		  return 0;		
		}
	IIC_Send_Date(Data);
	if(IIC_Check_Ack())
	  {
		  return 0;		
		}
	IIC_Stop();		
	Delay_5ms();                            //This time must be reserved for the device to save the data;
	return 1;
}

/*
//*****************************************************************
//       To receive 8 bits data from the address in the terminal
//Description : To receive 8 bits data from the address in the terminal
//Argument    ��Sladd - device address;
                Subadd- space address in the device;
//Returns     ��data
//Note        : none
//*****************************************************************
*/
bit IIC_ReceiveDataFromDevice(uchar Sladd_Read,uchar subadd)
{  
	IIC_Start();
	IIC_Send_Date(Sladd_Read-1);
	if(IIC_Check_Ack())
	{
	  return 0;	
	}
	IIC_Send_Date(subadd);
	if(IIC_Check_Ack())
	{
	  return 0;	
	}
	IIC_Start();
	IIC_Send_Date(Sladd_Read);
	if(IIC_Check_Ack())
	{
	  return 0;	
	}
	IIC_DATA=IIC_Recieve_Data();
	IIC_SendAck(1);
	IIC_Stop();	
	return 1;
}





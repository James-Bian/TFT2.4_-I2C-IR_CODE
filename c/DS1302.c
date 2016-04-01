#include"ds1302.h"
#include"KEY.h"
#include"ir.h"

//---DS1302写入和读取时分秒的地址命令---//
//---秒分时日月周年 最低位读写位;-------//
uchar code READ_RTC_ADDR[7]  = {0x81, 0x83, 0x85, 0x87, 0x89, 0x8b, 0x8d}; 
uchar code WRITE_RTC_ADDR[7] = {0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c};

//---DS1302时钟初始化2013年1月1日星期二12点00分00秒。---//
//---存储顺序是秒分时日月周年,存储格式是用BCD码---//
uchar TIME[] = {0x12, 0x12, 0x12, 0x26, 0x02, 0x05, 0x16};
uchar HOUR[3],MINUTE[3],SECOND[3];

/*******************************************************************************
* 函 数 名         : Ds1302Write
* 函数功能		   : 向DS1302命令（地址+数据）
* 输    入         : addr,dat
* 输    出         : 无
*******************************************************************************/

void Ds1302Write(uchar addr, uchar dat)
{
	uchar n;
	RST = 0;
	_nop_();  //声明一个空函数，做延迟使用；

	SCLK = 0;//先将SCLK置低电平。
	_nop_();
	RST = 1; //然后将RST(CE)置高电平，CE置高电平，才允许操作IC；
	_nop_();

	for (n=0; n<8; n++)//开始传送八位地址命令 ，先发送一位数据到DSIO端口，然后拉高CLK，触发SD1302读取一位数据；
	{
		DSIO = addr & 0x01;//数据从低位开始传送
		addr >>= 1;
		SCLK = 1;//数据在上升沿时，DS1302读取数据
    	_nop_();
		SCLK = 0;
		_nop_();
	}
	for (n=0; n<8; n++)//写入8位数据
	{
		DSIO = dat & 0x01;
		dat >>= 1;
		SCLK = 1;//数据在上升沿时，DS1302读取数据
		_nop_();
		SCLK = 0;
		_nop_();	
	}	
		 
	RST = 0;//传送数据结束，操作结束，需要CE拉低，防止电平干扰；
	_nop_();
}

/*******************************************************************************
* 函 数 名         : Ds1302Read
* 函数功能		   : 读取一个地址的数据
* 输    入         : addr
* 输    出         : dat
*******************************************************************************/

uchar Ds1302Read(uchar addr)
{
	uchar n,dat=0,dat1=0;
	RST = 0;
	_nop_();

	SCLK = 0;//先将SCLK置低电平。
	_nop_();
	RST = 1;//然后将RST(CE)置高电平。
	_nop_();
	//先传送8位地址，然后开始读取数据；

	for(n=0; n<8; n++)//开始传送八位地址命令
	{
		DSIO = addr & 0x01;//数据从低位开始传送
		addr >>= 1;
		SCLK = 1;//数据在上升沿时，DS1302读取数据
		_nop_();
		SCLK = 0;//DS1302下降沿时，放置数据
		_nop_();
	}
	_nop_();
	for(n=0; n<8; n++)//读取8位数据
	{
		dat1 = DSIO&0x01;//从最低位开始接收
		//dat = (dat>>1) | (dat1<<7);
		dat+=dat1<<n;
		SCLK = 1;
		_nop_();
		SCLK = 0;//DS1302下降沿时，放置数据
		_nop_();
	}

	RST = 0;
	_nop_();	//以下为DS1302复位的稳定时间,必须的。
	DSIO = 0;
	_nop_();
	DSIO = 0;
	_nop_();
	DSIO = 1;
	_nop_();


	return dat;	
}

/*******************************************************************************
* 函 数 名         : Ds1302Init
* 函数功能		   : 初始化DS1302.
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Ds1302Init()
{
 
//	uchar n;
/*	Ds1302Write(0x8E,0X00);		 //禁止写保护，就是关闭写保护功能
	for (n=0; n<7; n++)//写入7个字节的时钟信号：分秒时日月周年
	{
		Ds1302Write(WRITE_RTC_ADDR[n],TIME[n]);	
	}
*/
	Ds1302Write(0x8E,0x80);		 //打开写保护功能
	RST=0;
}

/*******************************************************************************
* 函 数 名         : Ds1302ReadTime
* 函数功能		   : 读取时钟信息
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/

void Ds1302ReadTime()
{
	uchar n;
	for (n=0; n<7; n++)//读取7个字节的时钟信号：分秒时日月周年
	{
		TIME[n] = Ds1302Read(READ_RTC_ADDR[n]);
	}
	
	HOUR[0]    = '0'+(TIME[2]/16);
	HOUR[1]    = '0'+(TIME[2]&0x0F);
	HOUR[2]    = '\0';//结束符
	
	MINUTE[0]  = '0'+(TIME[1]/16);
	MINUTE[1]  = '0'+(TIME[1]&0x0F);
	MINUTE[2]  = '\0';//结束符
	
	SECOND[0]  = '0'+(TIME[0]/16);
	SECOND[1]  = '0'+(TIME[0]&0x0F);	
  SECOND[2]  = '\0';//结束符
}


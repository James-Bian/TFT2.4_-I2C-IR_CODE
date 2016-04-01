#ifndef _BEEP_H_
#define _BEEP_H_

#include <REG52.H>    
#include <INTRINS.H> 
#include "ir.h"   
//本例采用89C52, 晶振为11.0592MHZ    
//关于如何编制音乐代码, 其实十分简单,各位可以看以下代码.    
//频率常数即音乐术语中的音调,而节拍常数即音乐术语中的多少拍;    
//所以拿出谱子, 试探编吧!  

//定义蜂鸣器输出端口
sbit Beep =  P1^7 ; 

//函数声明；
void delay (unsigned char m);
void Music_delayms(unsigned char a);
void Play_music(void); 

#endif
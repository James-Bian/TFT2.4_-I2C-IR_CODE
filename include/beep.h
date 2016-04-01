#ifndef _BEEP_H_
#define _BEEP_H_

#include <REG52.H>    
#include <INTRINS.H> 
#include "ir.h"   
//��������89C52, ����Ϊ11.0592MHZ    
//������α������ִ���, ��ʵʮ�ּ�,��λ���Կ����´���.    
//Ƶ�ʳ��������������е�����,�����ĳ��������������еĶ�����;    
//�����ó�����, ��̽���!  

//�������������˿�
sbit Beep =  P1^7 ; 

//����������
void delay (unsigned char m);
void Music_delayms(unsigned char a);
void Play_music(void); 

#endif
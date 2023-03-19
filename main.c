#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "HR_SC.h"

sbit Motorleft = P3^2;
sbit Motorright = P3^6;
sbit Motorright_PWM = P3^7;
sbit Motorleft_PWM = P3^3;
unsigned char Counter,Compare_left, Compare_right;
unsigned char Bzz;
void main()
{
	Motorright = 1;
	Motorleft = 1;
	P1_3 = 1;
	P1_2 = 0;
	P1_0 = 0;
	Timer0Init();
	Init_Timer0();
	Init_UART();
	while(1)
	{
		P1_0 = !P1_0;
		Bzz++;
	}
		
}

void Timer0_Routine() interrupt 1
{

	TL0 = 0xA4;				//???????
	TH0 = 0xFF;				//设置定时器初始值
	Counter++;
	Counter%=100;
	if(Compare_left||Compare_right)
	{
		if(Counter > Compare_left)
		{
			
			Motorleft_PWM = 1;//停
		}
		else
		{
			Motorleft_PWM = 0;
		}
		if(Counter > Compare_right)
		{
			Motorright_PWM = 1;//停
		}
		else
		{
			Motorright_PWM = 0;
		}
	}
	else
	{
		Motorright_PWM = Motorleft_PWM = 1;
	}
	

}


void UART_Rountine(void) interrupt 4
{
	unsigned char Recv;
	if(RI==1)
	{
		RI=0;
		Recv = SBUF; 
		if(Recv == '1')
		{
			Compare_left = Compare_right = 45;//1速
		}
		else if(Recv == '2')
		{
			Compare_left = Compare_right = 60;//2速
		}
		else if(Recv == '3')
		{
			Compare_left = Compare_right = 80;//3速
		}
		else if(Recv == 'l')
		{
			Compare_left  = 0;//左拐
		}
		else if(Recv == 'r')
		{
			Compare_right = 0;//右拐
		}
		else if(Recv == 's')//直行
		{
			if(Compare_left > Compare_right)
			{
				Compare_right = Compare_left;
			}
			else if(Compare_left < Compare_right)
			{
				Compare_left = Compare_right;
			}
		}
		else
		{
			Compare_left = Compare_right = 0;
		}

 
	}
}
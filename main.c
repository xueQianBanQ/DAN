#include <REGX52.H>
typedef unsigned char  u8;
typedef unsigned int  u16;
	
void delay_10us(u16 s)
{
	while(s--);
	
}
	
//void main()
//{
//	while(1)
//	{
//		if (P3_1 == 0)
//		{
//			P2_0 = 0;
//		}
//		else
//		{
//			P2_0 = 1;
//		}
//	}
//	
//}

////按一次独立按键LED灯变一次
//void main()
//{
//	P2_0 = 0;
//	while(1)
//	{
//		if(P3_1 == 0)
//		{
//			delay_10us(2000);//20ms = 100 * 10us * 20 = 2000
//			while(P3_1 == 0) ;//取消按独立按钮时的影响
//			delay_10us(2000);	
//			P2_0 = ~P2_0;
//		}
//	}
//}

//LED灯按二进制变化
void main()
{
	unsigned char number = 0;
	while(1)
	{
		if(P3_1 == 0)
		{
			delay_10us(2000);
			while(P3_1 == 0);
			delay_10us(2000);
			number++;
			P2 = ~number;
			
		}
	}
}
	
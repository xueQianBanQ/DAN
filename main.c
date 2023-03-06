#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h" 
#include "MatrixKey.h"


unsigned char KeyNum;
unsigned int passwords = 0;
unsigned char count = 0;
void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "password:>");
	LCD_ShowNum(2, 1, 0, 4);
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
				if(KeyNum <= 10)
			{
				if(count < 4)
				{
					KeyNum %= 10;
					passwords = passwords*10 + KeyNum;
					LCD_ShowNum(2, 1, passwords, 4);
					count++;
				}
				//LCD_ShowNum(2, 1, passwords, 4);
			}
			else if(KeyNum == 11)//È·ÈÏ¼ü
			{
				if(passwords == 1234)
				{
					LCD_ShowString(1, 14, "OK ");
					LCD_ShowNum(2, 1, 0, 4);
					count = 0;
					passwords = 0;
				}
				else
				{
					LCD_ShowString(1, 14, "ERR");
					LCD_ShowNum(2, 1, 0, 4);
					count = 0;
					passwords = 0;
				}
			}
			else if(KeyNum == 12)//³·Ïú
			{
				LCD_ShowNum(2, 1, 0, 4);
			}
		
		}
		
	}
}
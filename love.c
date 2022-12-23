#include <REGX52.H>

sbit RCK=P3^5;     //RCLK
sbit SCK=P3^6;     //SRCLK
sbit SER=P3^4;     //SER

void Delay (unsigned int xms)  // ??1s
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 100;//239
		do
		{
			while(--j);
		}while(--i);
	}
}

void _74HC595_WriteByte(unsigned char Byte)
{
	unsigned char i;
	for (i = 0; i < 8; i++)
	{
		SER=Byte&(0x80>>i);
		SCK = 1;
		SCK = 0;
	}
	RCK = 1;
	RCK = 0;
}

void MatrixLED_ShowColumn(unsigned char Column, unsigned char Data)
{
	_74HC595_WriteByte(Data);
	P0 = ~(0x80>>Column);
	Delay(1);
	P0 = 0xff;
}

//void main()
//{
//	SCK = 0;
//	RCK = 0;

//	while(1)
//	{
//		MatrixLED_ShowColumn(0, 0xa0);//1010 0000
//		MatrixLED_ShowColumn(0, 0xff);
//	}

//}

////第一种爱心
//void main()
//{
//	SCK = 0;
//	RCK = 0;

//	while(1)
//	{
//		MatrixLED_ShowColumn(0, 0x38);
//		MatrixLED_ShowColumn(1, 0x7c);
//		MatrixLED_ShowColumn(2, 0xfe);
//		MatrixLED_ShowColumn(3, 0x7f);
//		MatrixLED_ShowColumn(4, 0x7f);
//		MatrixLED_ShowColumn(5, 0xfe);
//        MatrixLED_ShowColumn(6, 0x7c);
//		MatrixLED_ShowColumn(7, 0x38);
//	}

//}

////小爱心
//void main()
//{
//	SCK = 0;
//	RCK = 0;

//	while(1)
//	{
//		MatrixLED_ShowColumn(0, 0x04);
//		MatrixLED_ShowColumn(1, 0x0e);
//		MatrixLED_ShowColumn(2, 0x07);
//		MatrixLED_ShowColumn(3, 0x0e);
//		MatrixLED_ShowColumn(4, 0x04);

//	}

//}


////两个小爱心
//void main()
//{
//	SCK = 0;
//	RCK = 0;

//	while(1)
//	{
//		MatrixLED_ShowColumn(0, 0x04);
//		MatrixLED_ShowColumn(1, 0x0e);
//		MatrixLED_ShowColumn(2, 0x07);
//		MatrixLED_ShowColumn(3, 0x4e);
//		MatrixLED_ShowColumn(4, 0xe4);
//		MatrixLED_ShowColumn(5, 0x70);
//		MatrixLED_ShowColumn(6, 0xe0);
//		MatrixLED_ShowColumn(7, 0x40);

//	}

//}




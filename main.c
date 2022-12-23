#include <REGX52.H>
	
void Delay (unsigned int xms)  // ясЁы1s
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;
		do
		{
			while(--j);
		}while(--i);
	}
}


void Delay1ms(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms--)
    {

	i = 2;
	j = 199;
	do
	{
		while (--j);
	} while (--i);
}
}


unsigned char Nixietable[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f };

void Nixietube(unsigned char Location, unsigned char Number)
{
	Location = 8 - Location;
	P2_2 = Location % 2;
	P2_3 = Location / 2 % 2;
	P2_4 = Location / 2 / 2 % 2;
	P0 = Nixietable[Number]; 
	Delay(1);
	P0 = 0x00;
}

//int main()

//{
//	while(1)
//	{
//		
//		Nixietube(1, 1);
//		Delay1ms(200);
//		Nixietube(2, 2);
//		Delay1ms(200);
//		Nixietube(3, 3);
//		Delay1ms(200);
//	}
//	return 0;

//}


int main()

{
	while(1)
	{
		
		Nixietube(1, 5);
		Nixietube(2, 2);
		Nixietube(3, 0);
		Nixietube(4, 1);
		Nixietube(5, 3);
		Nixietube(6, 1);
		Nixietube(7, 4);
	}
	return 0;

}



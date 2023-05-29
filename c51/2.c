#include <REGX52.H>
#include <INTRINS.H>

void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	while(1)
	{
		P0=0xFE;//1111 1110
		Delay500ms();
		P0=0xFD;//1111 1101
		Delay500ms();
		P0=0xFB;//1111 1011
		Delay500ms();
		P0=0xF7;//1111 0111
		Delay500ms();
		P0=0xEF;//1110 1111
		Delay500ms();
		P0=0xDF;//1101 1111
		Delay500ms();
		P0=0xBF;//1011 1111
		Delay500ms();
		P0=0x7F;//0111 1111
		Delay500ms();
	}
}

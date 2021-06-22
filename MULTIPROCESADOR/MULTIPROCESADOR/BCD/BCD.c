/*
 * BCD.c
 *
 * Created: 21/06/2021 07:34:04 p. m.
 *  Author: pablo
 */ 
#include <avr/io.h>

void BCD_init(char Port)
{
	if(Port == 'D')
	{
		DDRD |= 0xFF;
	}
	
	if(Port == 'B')
	{
		DDRB |= 0xFF;
	}
}

void BCD_init_7447(char Port)
{
	if(Port == 'D')
	{
		DDRD |= 0x0F;
	}
	
	if(Port == 'B')
	{
		DDRB |= 0x0F;
	}
}

int BCD_Type(char Type)
{
	if(Type == 'A')
	{
		return 1;
	}
	
	if(Type == 'C')
	{
		return 0;
	}
}

void BCD_Display_D(int num, int init)
{
	if(init == 1)
	{
		switch(num)
		{
			case 0:
			PORTD |= 0x01;
			case 1:
			PORTD |= 0x4F;
			case 2:
			PORTD |= 0x12;
			case 3:
			PORTD |= 0x06;
			case 4:
			PORTD |= 0x4C;
			case 5:
			PORTD |= 0x24;
			case 6:
			PORTD |= 0x60;
			case 7:
			PORTD |= 0x0F;
			case 8:
			PORTD |= 0x00;
			case 9:
			PORTD |= 0x0C;
			default:
			PORTD |= 0x00;
		}
	}
		
	if(init == 0)
	{
		switch(num)
		{
			case 0:
			PORTD |= 0x7E;
			case 1:
			PORTD |= 0x30;
			case 2:
			PORTD |= 0x6D;
			case 3:
			PORTD |= 0x79;
			case 4:
			PORTD |= 0x33;
			case 5:
			PORTD |= 0x5B;
			case 6:
			PORTD |= 0x1F;
			case 7:
			PORTD |= 0x70;
			case 8:
			PORTD |= 0x7F;
			case 9:
			PORTD |= 0x73;
			default:
			PORTD |= 0x00;
		}
	}
}

void BCD_Display_D_7447(int num)
{
	switch(num)
	{
		case 0:
		PORTD |= 0x00;
		case 1:
		PORTD |= 0x01;
		case 2:
		PORTD |= 0x02;
		case 3:
		PORTD |= 0x03;
		case 4:
		PORTD |= 0x04;
		case 5:
		PORTD |= 0x05;
		case 6:
		PORTD |= 0x06;
		case 7:
		PORTD |= 0x07;
		case 8:
		PORTD |= 0x08;
		case 9:
		PORTD |= 0x09;
		default:
		PORTD |= 0x00;
	}
}
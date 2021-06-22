/*
 * timer.c
 *
 * Created: 21/06/2021 07:05:31 p. m.
 *  Author: pablo
 */ 
#include <avr/io.h>
void Timer_0_Init()
{
	TCCR1B |= (1<<CS10);
}

void Timer_0_Init_Pin(int Pin, char Port)
{	
	if(Port == 'D')
	{
		DDRD |= (1<<Pin);
		TCCR1B |= (1<<CS10);	
	}
	
	if(Port == 'B')
	{
		DDRB |= (1<<Pin);
		TCCR1B |= (1<<CS10);
	}
}

void Timer_0_Count_PD(int Count, int Pin)
{
	TIFR1 &=~(0<<TOV1);
	TCNT1 = Count;
	PORTD |= (1<<Pin);
	while(!(TIFR1 &(1<<TOV1)));
}

void Timer_0_Count_ND(int Count, int Pin)
{
	TIFR1 &=~(0<<TOV1);
	TCNT1 = Count;
	PORTD &=~ (1<<Pin);
	while(!(TIFR1 &(1<<TOV1)));
}

void Timer_0_Count_PB(int Count, int Pin)
{
	TIFR1 &=~(0<<TOV1);
	TCNT1 = Count;
	PORTB |= (1<<Pin);
	while(!(TIFR1 &(1<<TOV1)));
}

void Timer_0_Count_NB(int Count, int Pin)
{
	TIFR1 &=~(0<<TOV1);
	TCNT1 = Count;
	PORTB &=~ (1<<Pin);
	while(!(TIFR1 &(1<<TOV1)));
}

void Timer_0_Count(int Count)
{
	TIFR1 &=~(0<<TOV1);
	TCNT1 = Count;
	while(!(TIFR1 &(1<<TOV1)));
}


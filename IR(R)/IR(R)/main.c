/*
 * IR(R).c
 *
 * Created: 10/06/2021 10:24:54 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL
#include "IRSTP/IRSTP.h"

int main(void)
{
	DDRB |=0x0F;
	PORTB|=0x00;
	int Cuenta = 0;
    while (1) 
    {
		Cuenta = IR_initR();
		if(Cuenta == 1)
		{
			_delay_ms(100);
			PORTB = 0x01;
		}
		
		if(Cuenta == 2)
		{
			_delay_ms(100);
			PORTB &=~ 0x01;
		}
		
		if(Cuenta == 3)
		{
			_delay_ms(100);
			PORTB = 0x02;
		}
		
		if(Cuenta > 3)
		{
			_delay_ms(100);
			PORTB &=~ 0x02;
		}
    }
}


/*
 * Hola_mundo.c
 *
 * Created: 07/05/2021 02:11:35 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#define	F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	DDRB |= (1<<PINB0);
	PORTB |= (0<<PINB0);
    
    while (1) 
    {
		PORTB |= (1<<PORTB0);
		_delay_ms(1000);
		PORTB &=~ (1<<PORTB0);
		_delay_ms(1000);
    }
}


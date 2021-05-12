/*
 * CONTROLAR UN LED V2.c
 *
 * Created: 12/05/2021 03:36:19 p. m.
 * Author : GIOVANNI 
 */ 
#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 1000000UL

int main(void)
{
	DDRB |=(1<<PINB0);                /* LED  */
	DDRD &=~(1<<PIND0)|(0<<PIND1);    /* Push buttons */
	PORTD |= (1<<1)|(1<<0);           /* Activa los resistores de pull-up en PD0, PD1 */
	
	while (1)
	{
		int salida = PIND;
		switch(salida){
			case 1:
			_delay_ms(50);
			PORTB&=~(1<<PORTB0);
			break;
			case 2:
			_delay_ms(50);
			PORTB|=(1<<PORTB0);
			break;
		}
		
	}
}
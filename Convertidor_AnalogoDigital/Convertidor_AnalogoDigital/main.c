/*
 * Convertidor_AnalogoDigital.c
 *
 * Created: 28/05/2021 05:26:04 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#define	F_CPU 1000000UL
#include <avr/interrupt.h>
#include <avr/delay.h>

int main(void)
{	
    DDRB = 0xFF;
	DDRD = 0xFF;
	//Para sacar todos los numeros
	ADMUX |=(1<<REFS0)|(1<<MUX1)|(1<<MUX0);	
	//Le decimos al registro por REFS0 que manejaremos la referencia del micro (5V)	
	//y que ademas de eso, usaremos el canal 2 del adc, por eso MUX1 = 1 = 0010 = 2 (osea el pin 2 del puerto c, wey)
	ADCSRA |= (1<<ADPS0)|(1<<ADPS1)|(1<<ADEN);
	//Al prescalador le daremos un divisor de 8, osea que para la frecuencia base, 1Mhz/8 = 125Khz
	sei();

    while (1) 
    {
		ADCSRA |=(1<<ADSC);
		while(ADCSRA &(1<<ADSC));
		PORTB = ADCL;
		PORTD = ADCH;
		_delay_ms(50);
	}
}


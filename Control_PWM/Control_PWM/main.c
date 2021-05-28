/*
 * Control_PWM.c
 *
 * Created: 28/05/2021 01:36:43 a. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>

volatile unsigned int incre = 5;		//Variable para aumentar el ancho del pulso PWM

ISR(INT0_vect){							//Detectamos la interrupcion para bajar el pulso
	cli();								//Inicialmente se desactivan para ejecutar el codigo secuencial
	_delay_ms(50);						//Delay antidebounce
	OCR1A = OCR1A - incre;				//OCR1A decrementa y se guarda en si mismo
	if(OCR1A <= 5){						//Si OCR1A baja menos del 5, entonces le devuelve el valor minimo
		OCR1A = 5;						//Osea wey, no va a bajar mas de 5, ¿apoco crees que existe un pulso de -5 para pwm?
	}									//¡Piensa, Mark, piensa!
	sei();								//Y activamos las interrupciones
}

ISR(INT1_vect){							//Lo mismo que arriba nomas que ahora para aumentar el ancho del pulso
	cli();
	_delay_ms(50);
	OCR1A = OCR1A + incre;
	if(OCR1A >= 250){					//Y no pasa de 250
		OCR1A = 250;
	}
	sei();
}
int main(void)
{
	DDRB |=(1<<PINB1);					//PIN DONDE SALE EL PWM 
	PORTD |=(1<<PIND3)|(1<<PIND2);		//PINES DE INTERRUPCIONES
	
	EICRA|=(1<<ISC11)|(1<<ISC01);		//HABILITACION DE PINES DE INTERRUPCION POR TRANSICION NEGATIVA
	EIMSK|=(1<<INT1)|(1<<INT0);			//HABILITAR AMBOS PINES INTERRUPCION
	
	OCR1A = 5;							//CARGALE 5 PORQUE ESA ES TU CALIFICACION XD (La verdad, es porque el valor maximo que alcanza es 255, entonces es mas factible usar multiplos de 5)
	TCCR1A|=(1<<COM1A1)|(1<<WGM10);		//FAST-PWM DE 8 BITS CON FRECUENCIA A 488Hz NO INVERTIDO
	TCCR1B|=(1<<WGM12)|(1<<CS11);		//N = 8 o 1MHz/8 = 125KHz frecuencia de conteo
	
	sei();								//Habilitacion de interrupciones globales
	
    while (1) 
    {
    }
}


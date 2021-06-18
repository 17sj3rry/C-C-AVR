/*
 * GccApplication2.c
 *
 * Created: 09/06/2021 11:40:42 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU 1000000UL	//Le decimos al codigo que usamos 1Mhz de reloj
#include "PWM/PWM.h"

int Pos = 100;
volatile unsigned int incre = 100;

ISR(INT0_vect){							//Detectamos la interrupcion para bajar el pulso
	cli();								//Inicialmente se desactivan para ejecutar el codigo secuencial
	_delay_ms(50);						//Delay antidebounce
	Pos = Pos - incre;					//Pos decrementa y se guarda en si mismo
	if(Pos <= 100){						//Si Pos baja menos del 100, entonces le devuelve el valor minimo
		Pos = 100;						//Osea wey, no va a bajar mas de 100, ¿apoco crees que existe un pulso de -100 para pwm?
	}									//¡Piensa, Mark, piensa!
	sei();								//Y activamos las interrupciones
}

ISR(INT1_vect){							//Lo mismo que arriba nomas que ahora para aumentar el ancho del pulso
	cli();
	_delay_ms(50);
	Pos = Pos + incre;
	if(Pos >= 2000){					//Y no pasa de 2000(2ms)
		Pos = 2000;
	}
	sei();
}

int main(void)
{
	PORTD |=(1<<PIND3)|(1<<PIND2);
	EICRA|=(1<<ISC11)|(1<<ISC01);		//HABILITACION DE PINES DE INTERRUPCION POR TRANSICION NEGATIVA
	EIMSK|=(1<<INT1)|(1<<INT0);
	sei();

    while (1) 
    {	
		SERVO_init_D(Pos,5);			//SERVO_init_X(y,z)
	}									//X = Puerto de salida (B o D); y = Posicion del servo; z = Pin de salida del puerto
}


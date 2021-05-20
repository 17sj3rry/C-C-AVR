/*
 * Timer_Mode_0.c
 *
 * Created: 19/05/2021 02:31:55 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>

int main(void)
	//Usa estas variables si quieres hacer los pulsos por frecuencia
{	//int Frec_Want = 0;
	//int Time_Want = (1/Frec_Want)*1000000;
	
	//Usa estas variables si quieres hacer los pulsos por tiempo
	int Time_Want = 65535;	//Tiempo en microsegundos
	int Time_Tot = 65535;	//Tiempo total (FFFF)	
	int Time_Used = Time_Tot - Time_Want;
	DDRD |= (1<<PIND5);
	TCCR1B |= (1<<CS10); //Configuramos el timer_= y con una frecuencia de 1MHz
   
    while (1) 
    {
		TIFR1 &=~(0<<TOV1);
		TCNT1 = Time_Used;
		while(!(TIFR1 &(1<<TOV1))){ //Mientras TOV1 = 0, QUEDATE AHI
			PORTD |= (1<<PORTD5);
		} 
		TIFR1 &=~(0<<TOV1);
		TCNT1 = Time_Used;
		while(!(TIFR1 &(1<<TOV1))){ //Mientras TOV1 = 0, QUEDATE AHI
			PORTD &=~ (1<<PORTD5);
		}
		
}
}

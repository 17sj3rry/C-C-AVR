/*
 * SERVO.c
 *
 * Created: 10/06/2021 12:14:03 a. m.
 *  Author: pablo
 */ 
#include "PWM.h"
#include <avr/io.h>
void SERVO_init_D( int Ang, int Out){
	DDRD |=(1<<Out);
	
	TCCR1B |= (1<<CS10); 
	
	TIFR1 &=~(0<<TOV1); //APagamos TOV1 para que no cuente
	TCNT1 = 65536 - Ang; //Le metemos el tiempo que queremos (maximo 65,535)
	PORTD |= (1<<Out); //Y ENCIENDE EL PUERTO PD5
	while(!(TIFR1 &(1<<TOV1))); //Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
		
	
	
	//UNA VEZ SALE DE AQUI(TOV1 = 1)
	TIFR1 &=~(0<<TOV1);//Apagamos TOV1 para que no cuente
	TCNT1 = 45535 + Ang;//Le metemos el tiempo que le falte para 20ms (50hz)
	PORTD &=~ (1<<Out); //Y EAPAGA EL PUERTO PD5
	while(!(TIFR1 &(1<<TOV1))); //Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
}

void SERVO_init_B( int Ang, int Out){
	DDRB |=(1<<Out);
	TCCR1B |= (1<<CS10);
	
	Ang = (Ang*2000/360) + 2000;
	int Aux_Ang = 65535 - Ang;


	TIFR1 &=~(0<<TOV1); //APagamos TOV1 para que no cuente
	TCNT1 = Aux_Ang; //Le metemos el tiempo que queremos (maximo 65,535)
	while(!(TIFR1 &(1<<TOV1))){ //Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
		PORTB |= (1<<Out); //Y ENCIENDE EL PUERTO 
	}
	
	//UNA VEZ SALE DE AQUI(TOV1 = 1)
	TIFR1 &=~(0<<TOV1);//APagamos TOV1 para que no cuente
	TCNT1 = Aux_Ang - 16000;//Le metemos el tiempo que le falte para 20ms (50hz)
	while(!(TIFR1 &(1<<TOV1))){ //Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
		PORTB &=~ (1<<Out); //Y EAPAGA EL PUERTO PD5
	}
}
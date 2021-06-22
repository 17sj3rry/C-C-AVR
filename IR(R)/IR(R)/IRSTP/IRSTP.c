/*
 * IRSTP.c
 *
 * Created: 10/06/2021 09:35:11 p. m.
 *  Author: pablo
 */ 
#include <avr/io.h>
#include <util/delay.h>

void IR_initT(int Pulses,int Output )//NO PASAR DE 15HZ!!
{
	
	DDRD |=(1<<Output);				//1 Pulso = 65,535
									//2 Pulsos = 32,768
	TCCR1B |= (1<<CS10);
	int Count = 0;

	TIFR1 &=~(0<<TOV1);				//Apagamos TOV1 para que no cuente
	TCNT1 = 65535 - Pulses;			//Le metemos el tiempo del pulso
	PORTD |= (1<<Output);			//Y ENCIENDE EL PUERTO PD
	while(!(TIFR1 &(1<<TOV1)));		//Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
	
	TIFR1 &=~(0<<TOV1);				//Apagamos TOV1 para que no cuente
	TCNT1 = 65535 - Pulses;			////Le metemos el tiempo del pulso
	PORTD &=~ (1<<Output);			//Y EAPAGA EL PUERTO PD5
	while(!(TIFR1 &(1<<TOV1)));	    //Mientras TOV1 = 0, QUEDATE AHI Y CUENTA
}

int IR_initR()
{
	DDRD  |=(0<<4);
	PORTD |=(1<<4);
	
	TIFR1 &=~(0<<TOV1);		
	TCCR1B |= (1<<CS10);
	TCNT1 = 0;
	TCNT0 = 0;
	for (int i = 0; i < 9 ; i+=1)
	{
		while(!(TIFR1 &(1<<TOV1)))
		{
			TCCR0B |=(1<<CS01)|(1<<CS02);	//Detecta cada flanco de subida
		}
	}
	return TCNT0; 
}
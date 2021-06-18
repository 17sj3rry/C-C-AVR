/*
 * ADC.c
 *
 * Created: 10/06/2021 11:11:54 a. m.
 *  Author: pablo
 */ 

#include <avr/io.h>
#include <util/delay.h>

void ADC_init()
{
	ADCSRA |= 0x07;

	ADMUX &=~ (1<<ADLAR);

	ADMUX |=  (1<<REFS0);
	ADMUX &=~ (1<<REFS1);
	
}

int ADC_Data(int channel)
{
	// Channel Selection //
	ADMUX &=~  0x0F;
	ADMUX |=  channel;
	
	// Start ADC
	ADCSRA |= (1<<ADEN);
	//_delay_us(10);

	// Start Sampling
	ADCSRA |= (1<<ADSC);

	//While Reading
	while( !(ADCSRA & (1<<ADIF)) );
	ADCSRA |= (1<<ADIF);	// Restart flag

	// Shutdown ADC n´Show value
	ADCSRA &=~ (1<<ADEN);

	return ADC;
}
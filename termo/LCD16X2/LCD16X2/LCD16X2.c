/*
 * LCD16X2.c
 *
 * Created: 28/07/2019 21:11:48
 *  Author: Pablo
 */ 
 
 #include "LCD16X2.h"

//Funcion para preparar el lcd
 void lcd_start()
 {
	PORTB &=~ (1<<PORTB0);	//Enviamos el cero
	_delay_us(1);			//Esperamos
	PORTB |=  (1<<PORTB0);	//Y le enviamos el 1 para iniciar la pantalla
 }

//Funcion para escribir en el lcd facil
 void lcd_write(uint8_t type, uint8_t inst_data)//Type es para saber si lo que se mete es escribible
 {
	if (type)
		PORTB |=  (1<<PORTB1);
	else
		PORTB &=~ (1<<PORTB1);

	PORTD = (PIND & 0x0F) | (inst_data & 0xF0);
	lcd_start();
	PORTD = (PIND & 0x0F) | ((inst_data<<4) & 0xF0);
	lcd_start();
	_delay_ms(2);
 }

//Funcion para iniciar el lcd
 void lcd_init()
 {
	DDRB  |=  (1<<DDB0) | (1<<DDB1);	
	DDRD  |=  0xF0;
	
	PORTB &=~ ((1<<PORTB0) | (1<<PORTB0));
	
	PORTD  = (PIND & 0x0F) | 0x30;

	_delay_ms(100);
	lcd_start();
	_delay_ms(5);
	lcd_start();
	_delay_us(100);
	lcd_start();
	_delay_us(100);

	PORTD = (PIND & 0x0F) | 0x20;
	
	lcd_start();
	_delay_us(100);

	lcd_write(LCD_INST, 0x2C);
	lcd_write(LCD_INST, 0x08);
	lcd_write(LCD_INST, 0x01);
	lcd_write(LCD_INST, 0x06);	
	
	lcd_write(LCD_INST, 0x0C);
 }

//Fucion para imprimir en la pantalla
void lcd_print(char *s)
{
	while(*s)
	{
		lcd_write(LCD_DATA, *s);
		s++;
	}
}

//Funcion para Inicar el ADC
void ADC_init()
{
	ADCSRA &=~0X07;
	ADCSRA = 0x07;

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
	_delay_us(10);	

	// Start Sampling
	ADCSRA |= (1<<ADSC);

	//While Reading
	while( !(ADCSRA & (1<<ADIF)) );
	ADCSRA |= (1<<ADIF);	// Restart flag 

	// Shutdown ADC n´Show value
	ADCSRA &=~ (1<<ADEN);

	return ADC;
}

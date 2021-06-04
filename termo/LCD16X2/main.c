/*
 * LCD16X2.c
 *
 * Created: 28/07/2019 21:01:10
 * Author : Pablo
 */ 
#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <util/delay.h>
#include "LCD16X2/LCD16X2.h"
#define	F_CPU 1000000UL	

char message[] = "Temp: ";
float Temp = 0;
float Temp_Deci = 0;
char Temp_Str[];
char Temp_Str_Deci[];
int main(void)
{
    lcd_init();
	ADC_init();
	while (1)
	{	//1 seg (real) = 66ms(CODIGO)
		
		lcd_write(LCD_INST, CLEAR);		//Numero de practica
		lcd_print("PRACTICA 13");
		_delay_ms(66);
		
		lcd_write(LCD_INST, LINE2);		//Mensaje de temperatura
		lcd_print(message);
		_delay_ms(33);
		
		Temp = ADC_Data(0)*150/1024 + 20;	//Conversion de ADC a Int y despues Char
		itoa(Temp,Temp_Str,10); 
		lcd_write(LCD_INST, LINE2 + 5);  
		lcd_print(Temp_Str);
		_delay_ms(33);
		
		lcd_write(LCD_INST, LINE2 + 7);		//Preparamos el punto decimal
		lcd_print(".");
		_delay_ms(33);
		
		Temp_Deci = Temp - round(Temp);		//Extraemos la parte decimal
					
		if(Temp_Deci < 1);
		Temp_Deci = Temp_Deci + 1;			//Si es menor a 1, le regresamos valor original

		itoa(Temp_Deci,Temp_Str_Deci,10);	//Imprimimos
		lcd_write(LCD_INST, LINE2 + 8);
		lcd_print(Temp_Str_Deci);
		_delay_ms(33);
		
		lcd_write(LCD_INST, LINE2 + 11);	//Y unidades
		lcd_print("'C");
		_delay_ms(33);
		
	}
}

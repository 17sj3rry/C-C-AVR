/*
 * CONTROL_DE_UN_LED.c
 *
 * Created: 12/05/2021 02:09:15 p. m.
 * Author : Pablo
 */ 
//-------------------------------------------------------------
//					ZONA DE LIBRERIAS
//-------------------------------------------------------------
#include <avr/io.h>			//llamamos a la librearia para usar el AVR
#define	F_CPU 1000000UL		//Y configuramos el reloj a 1MHZ
#include <util/delay.h>		//Para despues llamar a la libreria que nos habilita los retrasos
//-------------------------------------------------------------
int main(void)
{
//-------------------------------------------------------------
//					INICIO DE CONFIGURACIONES
//-------------------------------------------------------------

	DDRD |=(1<<PIND0);					//PIN DONDE ESTA CONECTADO UN LED
	DDRB |=(0<<PINB0)|(0<<PINB1);		//PIN DONDE ESTA CONECATADO UN BOTON
	PORTB |=(0<<1)|(0<<0);				//NIVELES DE SALIDA PARA EL PIN 1 Y 0 DEL PUERTO B
	int salida;							//CREAMOS UNA VARIABLE DEL TIPO ENTERO PARA HACER LECTURA DEL PUERTO
	
    while (1) 
    {
		//-------------------------------------------------------------
		//					INICIO DE CODIGO
		//-------------------------------------------------------------
		salida = PINB;					//Y ASOCIAMOS EL VALOR DE ESTA CON EL PUIERTO B (O LOS PINES DE ESTE )
		
		if(salida == 0x1){				// SI TENEMOS UN 1 EN LA ENTRADA DEL PUERTO
			_delay_ms(50);				//Delay anti-denouncing
			PORTD  |=(1<<PORTD0);		//PRENDEMOS UN LED
			
		}if(salida == 0x2){				//SI TENEMOS UN 2 A LA ENTRADA DEL PUERTO
			_delay_ms(50);				//Delay anti-debouncing
			PORTD  &=~(1<<PORTD0);		// APAGAMOS EL LED
		}
		//-------------------------------------------------------------
	}
}


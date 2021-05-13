/*
 * GccApplication1.c
 *
 * Created: 11/05/2021 01:39:15 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#define	F_CPU 1000000UL
#include <util/delay.h>

int main(void)
{
	//-----------------------------------------------
	//          ZONA DE DEFINICION DE PINES
	//-----------------------------------------------
	DDRB = 0x0F;
	PORTB = 0xFF;
	
	DDRD = 0xFF;
	PORTD = 0x00;
	//-----------------------------------------------
	
	//-----------------------------------------------
	//				VARIABLES A UTILIZAR
	//-----------------------------------------------
	int CODIN[2][4] = {{0X0E, 0X0D, 0X0B, 0X07}, // (CODIGO DE SALIDA) PARTE DEL CODIGO QUE NO SE MUEVE
					   {0XE0, 0XD0, 0XB0, 0X70}};// (CODIGO DE ENTRADA) PARTE DEL CODIGO QUE SE MUEVE
						   
	int i = 0;		//VARIABLE PARA MOVERSE EN LA PARTE NO MOVIL
	int j = 0;		//VARIABLE PARA MOVERSE EN LA PARTE MOVIL
	int codread;	//VARIABLE PARA ENVIAR EL CODIGO
	int in_code;	//VARIABLE PARA LEER EL CODIGO 

	//-----------------------------------------------
    while (1) 
    {
		//-----------------------------------------------
		//			ZONA DEL CODIGO
		//-----------------------------------------------
		for(i = 0; i <=4 ; i += 1){								//Creamos una sentencia de "for anidado" para crear los codigos (parte no movil)
			for(j = 0; j <=4 ; j += 1){							//Parte movil
				codread =CODIN[1][j] + CODIN[0][i];				//Creacion del codigo
		//CODIGO DE SALIDA = Parte Movil + Parte no movil	
		
				PORTB = codread;								//Sacamos el codigo
				_delay_ms(50);									//El atmega se hace pendejo 200ms
				in_code = PINB;									//Leemos el codigo que se metio
				
				//-----------------------------------------------------
				//			ZONA DEL CODIGO PARA LOS DATOS DE SALIDA
				//-----------------------------------------------------
				
				//PARTE PARA LA LINEA 1 DEL TECLADO HEXADECIMAL
				if (in_code==codread && in_code== 0xEE){		//Enviamos un (1) a la salida del puerto D
					PORTD = 0x01;
				}else if(in_code==codread && in_code== 0xDE){	//Enviamos un (2) a la salida del puerto D
					PORTD = 0x02;
				}else if(in_code==codread && in_code== 0xBE){	//Enviamos un (3) a la salida del puerto D
					PORTD = 0x03;
				}else if(in_code==codread && in_code== 0x7E){	//Enviamos un (10) a la salida del puerto D
					PORTD = 0x0A;
					
				//PARTE PARA LA LINEA 2 DEL TECLADO HEXADECIMAL	
				}else if (in_code==codread && in_code== 0xED){	//Enviamos un (4) a la salida del puerto D
					PORTD = 0x04;
				}else if(in_code==codread && in_code== 0xDD){	//Enviamos un (5) a la salida del puerto D
					PORTD = 0x05;
				}else if(in_code==codread && in_code== 0xBD){	//Enviamos un (6) a la salida del puerto D
					PORTD = 0x06;
				}else if(in_code==codread && in_code== 0x7D){	//Enviamos un (11) a la salida del puerto D
					PORTD = 0x0B;
				
				//PARTE PARA LA LINEA 3 DEL TECLADO HEXADECIMAL
				}else if (in_code==codread && in_code== 0xED){	//Enviamos un (4) a la salida del puerto D
					PORTD = 0x07;
				}else if(in_code==codread && in_code== 0xDD){	//Enviamos un (5) a la salida del puerto D
					PORTD = 0x08;
				}else if(in_code==codread && in_code== 0xBD){	//Enviamos un (6) a la salida del puerto D
					PORTD = 0x09;
				}else if(in_code==codread && in_code== 0x7D){	//Enviamos un (11) a la salida del puerto D
					PORTD = 0x0C;
				
				//PARTE PARA LA LINEA 4 DEL TECLADO HEXADECIMAL
				}else if (in_code==codread && in_code== 0xED){	//Enviamos un (4) a la salida del puerto D
					PORTD = 0x0E;
				}else if(in_code==codread && in_code== 0xDD){	//Enviamos un (5) a la salida del puerto D
					PORTD = 0x00;
				}else if(in_code==codread && in_code== 0xBD){	//Enviamos un (6) a la salida del puerto D
					PORTD = 0x0F;
				}else if(in_code==codread && in_code== 0x7D){	//Enviamos un (11) a la salida del puerto D
					PORTD = 0x0D;
				}
				}
			}
		}
    }



/*
 * MULTIPROCESADOR.c
 *
 * Created: 21/06/2021 04:59:13 p. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#include "TIMER_0/timer.h"
#include "BCD/BCD.h"
#define F_CPU 1000000UL

int main(void)
{
	Timer_0_Init();					//Prendemos el timer para contar internamente
	BCD_init_7447('D');				//Iniciamos el BCD y seleccionamos el puerto
	
	int i = 0;						//Variable de conteo para el timer
	int ib = 0;						//Variable de conteno para el bcd
	
    while (1) 
    {
		for(i = 0; i < 16 ; i+= 1)	//Va a contar 15 veces deteniendose 65.535ms por cuenta
		{							//65.535ms x 15 =~ 1s
		Timer_0_Count(65535);	
		}
		
		ib += 1;					//Una vez termina, cuenta 1 aqui
		
		BCD_Display_D_7447(ib);			//Y lo envia aqui para mostarlo en pantalla
    }
}


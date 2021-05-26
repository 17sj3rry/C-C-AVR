/*
 * Piano_Matricial.c
 *
 * Created: 25/05/2021 09:28:18 a. m.
 * Author : pablo
 */ 

#include <avr/io.h>
#define	F_CPU 1000000UL
#include <util/delay.h>
#include <math.h>
#define Do4ta  1914
#define DoS4ta  1804
#define Re4ta  1705
#define ReS4ta  1606
#define Mi4ta  1518
#define Fa4ta  1413
#define FaS4ta  1353
#define Sol4ta  1277
#define SolS4ta  1203
#define La4ta  1135
#define LaS4ta  1365
#define Si4ta  1013

int main(void)
{	DDRC = 0X1F;	//PUERTO QUE SACA EL CODIGO DE LECTURA
	PORTC = 0X00;
	
	PORTD = 0X1F;	//PUERTO QUE RECIBE EL CODIGO
	
	DDRB = (1<<1);	//PUERTO QUE GENERA LOS TONOS
	
    int PIANO_CODE_VAR[5] = {0x1E,0X1D,0X1B,0X17,0X0F};	//MATRIZ DE CODIGOS

	int Lwr_Asig,Entry_Asig,i,j;
	
	//Lwr: Codigo Movil/InMovil
	//Entry_Asig: Codigo de Lectura
	//i: Conteo inmovil
	//j: Conteo movil
	
	int Tone_Generator(int);	//Genera los tonos de manera automatica
	int Mute_Generator();		//Genera un silencio si no se presiona una tecla en especifico
	int Debouncer();			//Retraso general
	
    while (1) 
    {
		for(i = 0; i <= 4 ; i += 1){
			for(j = 0; j <= 4 ; j += 1){		
				Lwr_Asig = PIANO_CODE_VAR[j];	//Codigo Movil
				
				PORTC = PIANO_CODE_VAR[i];		//Codigo Inmovil
				Debouncer();
				Entry_Asig = PIND;
				
				if(i == 0){
					//Primera Octava(4ta Octava Equivalente)
					if (Entry_Asig == Lwr_Asig && Entry_Asig == 0X1E){		//Enviamos un (Do4ta) a la salida del puerto B
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Do4ta);}
	
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1D){	//Enviamos un (Do#4ta) a la salida del puerto B
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(DoS4ta);}
						
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1B){	//Enviamos un (Re4ta) a la salida del puerto B
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Re4ta);}
						
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X17){	//Enviamos un (Re#4ta) a la salida del puerto B
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(ReS4ta);}
						
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X0F){	//Enviamos un (Mi4ta) a la salida del puerto B
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Mi4ta);}
							
					}else if(Entry_Asig != Lwr_Asig ){Mute_Generator();}
					}
					
				if(i == 1){
					if (Entry_Asig == Lwr_Asig && Entry_Asig == 0X1E){		//Enviamos un (Fa4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Fa4ta);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1D){	//Enviamos un (Fa#4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(FaS4ta);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1B){	//Enviamos un (Sol4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Sol4ta);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X17){	//Enviamos un (Sol#4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(SolS4ta);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X0F){	//Enviamos un (La4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(La4ta);}
							
					}else if(Entry_Asig != Lwr_Asig ){Mute_Generator();}
					}
					
				if(i == 2){
					if (Entry_Asig == Lwr_Asig && Entry_Asig == 0X1E){		//Enviamos un (La#4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(LaS4ta);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1D ){	//Enviamos un (Si4ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Si4ta);}
							
					//Segunda Octava(5ta Octava equivalente)	
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1B){	//Enviamos un (Do5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Do4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X17){	//Enviamos un (Do#5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(DoS4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X0F){	//Enviamos un (Re5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Re4ta*2);}
							
					}else if(Entry_Asig != Lwr_Asig ){Mute_Generator();}
					}
					
				if(i == 3){	
					if (Entry_Asig == Lwr_Asig && Entry_Asig == 0X1E){		//Enviamos un (Re#5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(ReS4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1D){	//Enviamos un (Mi5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Mi4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1B){	//Enviamos un (Fa5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Fa4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X17){	//Enviamos un (Fa#5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(FaS4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X0F){	//Enviamos un (Sol5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Sol4ta*2);}
							
					}else if(Entry_Asig != Lwr_Asig ){Mute_Generator();}
					}
					
				if( i == 4){	
					if (Entry_Asig == Lwr_Asig && Entry_Asig == 0X1E ){		//Enviamos un (Sol#55ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(SolS4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1D ){	//Enviamos un (La5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(La4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X1B ){	//Enviamos un (La#5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(LaS4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X17 ){	//Enviamos un (Si5ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Si4ta*2);}
							
					}else if(Entry_Asig == Lwr_Asig && Entry_Asig == 0X0F ){	//Enviamos un (Do6ta) a la salida del puerto D
						while(Entry_Asig == Lwr_Asig){
							Debouncer();
							Entry_Asig = PIND;
							Tone_Generator(Do4ta*4);}
							
					}else if(Entry_Asig != Lwr_Asig ){Mute_Generator();}
					}
				}
			}
		}
	}

int Tone_Generator(int Note){				//Generamos los tonos
		TCCR1A |= (1<<COM1A0);
		OCR1A = Note;
		TCCR1B |=(1<<WGM12)|(1<<CS10);
}

int Mute_Generator(){						//Silenciamos los tonos
		TCCR1A &=~ (1<<COM1A0);
		OCR1A = 0;
		TCCR1B &=~(1<<WGM12)|(1<<CS10);
}

int Debouncer(){
	_delay_ms(20);
}
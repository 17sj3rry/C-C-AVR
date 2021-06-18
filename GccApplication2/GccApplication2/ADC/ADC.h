/*
 * ADC.h
 *
 * Created: 10/06/2021 11:11:23 a. m.
 *  Author: pablo
 */ 


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
// FUNCIONES DE ADC
void ADC_init();
int ADC_Data(int channel);

#endif /* ADC_H_ */
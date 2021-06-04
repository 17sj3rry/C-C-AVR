/*
 * LCD16X2.h
 *
 * Created: 28/07/2019 21:12:02
 *  Author: Pablo
 */ 


#ifndef LCD16X2_H_
#define LCD16X2_H_

#include <avr/io.h>
#include <util/delay.h>

// DEFINICIONES DE APOYO
#define LCD_INST	0
#define LCD_DATA	1

// LINEAS PARA HASTA 4 FILAS
#define LINE1		0x80
#define LINE2		0xC0
#define LINE3		0x94
#define LINE4		0xD4
#define CLEAR		0x01

// FUNCIONES BÁSICAS
void lcd_start();
void lcd_write(uint8_t type, uint8_t inst_data);
void lcd_init();

// FUNCIONES COMPUESTAS
void lcd_print(char *s);

// FUNCIONES DE ADC
void ADC_init();
int ADC_GetData(int channel);

#endif /* LCD16X2_H_ */
/*
 * timer.h
 *
 * Created: 21/06/2021 07:05:20 p. m.
 *  Author: pablo
 */ 


#ifndef TIMER_H_
#define TIMER_H_

void Timer_0_Init();
void Timer_0_Init_Pin(int Pin, char Port);
void Timer_0_Count(int Count);
void Timer_0_Count_PD(int Count, char Pin);
void Timer_0_Count_ND(int Count, char Pin);
void Timer_0_Count_PB(int Count, char Pin);
void Timer_0_Count_NB(int Count, char Pin);

#endif /* TIMER_H_ */
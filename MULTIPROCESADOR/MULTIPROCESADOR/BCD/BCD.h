/*
 * BCD.h
 *
 * Created: 21/06/2021 07:33:55 p. m.
 *  Author: pablo
 */ 


#ifndef BCD_H_
#define BCD_H_

void BCD_init(char Port);
void BCD_init_7447(char Port);
int BCD_Type(char Type);
void BCD_Display_D(int num, int Type);
void BCD_Display_D_7447(int num);

#endif /* BCD_H_ */
/*
 * TIMER.h
 *
 * Created: 8/13/2024 10:09:55 AM
 *  Author: ma273
 */ 


#ifndef TIMER_H_
#define TIMER_H_

/*
 * TIMER.c
 *
 * Created: 8/13/2024 10:09:38 AM
 *  Author: ma273
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

void Timer1_Init();
void Timer1_Start();
void Timer1_Stop();
ISR(TIMER1_OVF_vect);



#endif /* TIMER_H_ */
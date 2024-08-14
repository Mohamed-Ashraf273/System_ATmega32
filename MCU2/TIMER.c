/*
 * TIMER.c
 *
 * Created: 8/13/2024 10:09:38 AM
 *  Author: ma273
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include "regs.h"
#include "MCAL_UART.h"
#include "stdTypes.h"
#include "SERVO.h"
#include "HAL_LED.h"
#include <util/delay.h>

#define OVERFLOW_COUNT_7S 7  // Number of Timer1 overflows needed for 7 seconds
#define OVERFLOW_COUNT_12S 12 // Number of Timer1 overflows needed for 12 seconds

volatile uint16_t overflow_count = 0;
volatile u8 timer_active = 0; // Flag to start/stop the timer
volatile u8 action_7s_done = 0; // Flag to indicate if 7s action has been done

void Timer1_Init() {
	TCCR1A = 0; // Normal mode
	TCCR1B = (1 << CS11) | (1 << CS10); // Prescaler 64
	TIMSK |= (1 << TOIE1); // Enable Timer1 Overflow Interrupt
	sei(); // Enable global interrupts
}

void Timer1_Start() {
	// Set the timer_active flag to true
	timer_active = 1;
}

void Timer1_Stop() {
	// Set the timer_active flag to false
	timer_active = 0;
	// Reset overflow count and flags
	overflow_count = 0;
	action_7s_done = 0;
}

ISR(TIMER1_OVF_vect) {
	if (timer_active) {
		overflow_count++;
		
		if (overflow_count >= OVERFLOW_COUNT_7S && !action_7s_done) {
			// 7 seconds have passed
			action_7s_done = 1; // Mark 7s action as done
			// Move servo to 90 degrees
			TURN_ON_LED('D',6);
			Servo_Rotate(90);
		}
		
		if (overflow_count >= OVERFLOW_COUNT_12S) {
			// 12 seconds have passed
			Timer1_Stop();
			
			// Activate Watchdog Timer
			WDTCR = (1 << WDE) | (1 << WDP0); // Watchdog timeout of 16ms
			while (1); // Infinite loop to trigger watchdog reset
		}
	}
}
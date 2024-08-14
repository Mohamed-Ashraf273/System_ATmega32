#include <avr/io.h>
#include <avr/interrupt.h>
#include "regs.h"
#include "MCAL_E2PROM.h"
#include "MCAL_UART.h"
#include "stdTypes.h"
#include <util/delay.h>
#include "MCAL_DIO.h"

#define OVERFLOW_COUNT 7 // Number of Timer1 overflows needed for 7 seconds

volatile uint16_t overflow_count = 0;
volatile u8 timer_active = 0; // Flag to start/stop the timer

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
	// Reset overflow count
	overflow_count = 0;
}

ISR(TIMER1_OVF_vect) {
	
	if (timer_active) {
		overflow_count++;
		if (overflow_count >= OVERFLOW_COUNT) {
			
			// 7 seconds have passed
			// Write abnormal state to EEPROM
			EEPROM_write(0, 2);
			// Turn on LED as an indication
			DIO_vSetPinDirection('C', 2, 1);
			DIO_vSetPinValue('C', 2, 1);
			Timer1_Stop();
			// Activate Watchdog Timer
			WDTCR = (1 << WDE) | (1 << WDP0); // Watchdog timeout of 16ms
			while (1); // Infinite loop to trigger watchdog reset

		}
	}
}

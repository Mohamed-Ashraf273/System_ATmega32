/*
 * MCAL_ADC.c
 *
 * Created: 8/12/2024 6:54:48 PM
 *  Author: ma273
 */ 
#include "MCAL_DIO.h"
#include "MCAL_ADC.h"
#include <avr/io.h>


void ADC_init() {
	// Set reference voltage to AVCC and enable ADC
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_read(u8 channel) {
	// Select the ADC channel
	channel &= 0x07;
	ADMUX = (ADMUX & 0xF8) | channel;   // Clear MUX bits and set the channel
	ADCSRA |= (1 << ADSC);// Start the conversion
	while (ADCSRA & (1 << ADSC));//Wait for conversion to complete
	uint16_t result = ADC;// Read the ADC value
	return result;
}
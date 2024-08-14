#include <avr/io.h>
#include <util/delay.h>
#include "stdTypes.h"
#include "regs.h"
#define F_CPU 16000000UL // 16 MHz clock speed
#define SERVO_PIN     7 
#define SERVO_MIN     1000 // Pulse width for 0 degrees in us
#define SERVO_MAX     2000 // Pulse width for 180 degrees in us
#define SERVO_90      1500 // Pulse width for 90 degrees in us
#define OUTPUT 1
#define INPUT 0

void Servo_Init() {
	DIO_vSetPinDirection('D',SERVO_PIN,OUTPUT);
	
	TCCR2 = (1 << WGM20) | (1 << COM21) | (1 << CS21);
}

void Servo_SetAngle(uint8_t angle) {
	uint16_t pulse_width_us;
	uint8_t ocr2_value;

	// Map angle to pulse width (in us)
	if (angle == 90) {
		pulse_width_us = SERVO_90;
		} else if (angle < 90) {
		// Map angle from 0 to 90 degrees to pulse width range
		pulse_width_us = SERVO_MIN + (SERVO_90 - SERVO_MIN) * angle / 90;
		} else {
		// Map angle from 90 to 180 degrees to pulse width range
		pulse_width_us = SERVO_90 + (SERVO_MAX - SERVO_90) * (angle - 90) / 90;
	}
	
	// Calculate OCR2 value for pulse width
	// Timer2 frequency = F_CPU / 8 / 256 = 19531.25 Hz
	// PWM period = 1 / 50 Hz = 20 ms
	// Pulse width in Timer2 ticks = (pulse_width_us / PWM period) * 256
	ocr2_value = (pulse_width_us * 256 / 20000) - 1;
	
	OCR2 = ocr2_value;// Set the OCR2 register
}
void Servo_Rotate(u8 ang){
	for (uint8_t angle = 0; angle <= ang; angle++) {
		Servo_SetAngle(angle);
		_delay_ms(1500); // Wait for the servo to move
	}
}
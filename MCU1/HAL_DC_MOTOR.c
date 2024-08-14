/*
 * HAL_DC_MOTOR.c
 *
 * Created: 8/13/2024 1:20:28 AM
 *  Author: ma273
 */ 
#include "HAL_DC_MOTOR.h"
#define OUTPUT 1
#define INPUT 0
void motor_init(){
	// Set PB3/OC0 & A0 & A1 as output (PWM output pin)
	DIO_vSetPinDirection('B',MOTOR_PWM_PIN,OUTPUT);
	DIO_vSetPinDirection('C',MOTOR_PIN1,OUTPUT);
	DIO_vSetPinDirection('C',MOTOR_PIN2,OUTPUT);
	//clockwise direction
	DIO_vSetPinValue('C',MOTOR_PIN1,1);//set pin0
	DIO_vSetPinValue('C',MOTOR_PIN2,0);//clear pin1
	// Set Fast PWM mode with non-inverted output
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1 << CS01);
}
void motor_setspeed(u8 speed) {
	OCR0 = speed;  
}
/*
 * HAL_DC_MOTOR.h
 *
 * Created: 8/13/2024 1:20:44 AM
 *  Author: ma273
 */ 


#ifndef HAL_DC_MOTOR_H_
#define HAL_DC_MOTOR_H_

#include "MCAL_DIO.h"
#include "stdTypes.h"
#include <avr/io.h>
#define MOTOR_PIN1 0
#define MOTOR_PIN2 1
#define MOTOR_PWM_PIN 3//portb


void motor_init();
void motor_setspeed(u8 speed);




#endif /* HAL_DC_MOTOR_H_ */
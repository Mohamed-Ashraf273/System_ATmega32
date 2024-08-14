/*
 * SERVO.h
 *
 * Created: 8/13/2024 10:38:12 AM
 *  Author: ma273
 */ 


#ifndef SERVO_H_
#define SERVO_H_


void Servo_Init();

void Servo_SetAngle(uint16_t angle);
void Servo_Rotate(u8 ang);

#endif /* SERVO_H_ */
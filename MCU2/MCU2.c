/*
 * MCU1.c
 *
 * Created: 8/12/2024 12:16:18 PM
 *  Author: ma273
 */ 


#include "MCAL_DIO.h"
#include "MCAL_UART.h"
#include "HAL_DC_MOTOR.h"
#include "MCAL_ADC.h"
#include "HAL_LED.h"
#include "TIMER.h"
#include "SERVO.h"
#include <util/delay.h>
#define POT_PIN 7 //portb
#define RED_LED 0 //portc
#define YELLOW_LED 1 //portc
#define GREEN_LED 2 //porta
#define BUZZER 3 //portb
void shut_machine_down(u8 temp){
	motor_setspeed(0);
	while(1);
}
u8 checkMessage(u8 mess){
	u8 mess1 = uart_receive();
	if(mess == 's' && mess1 == 't'){
		shut_machine_down(mess);
		return 0;
	}
	return mess1/2.01;
}
void set_state(u8 temp){
	if(temp <= 20){// if temp less than 20 turn on green
		TURN_ON_LED('A',GREEN_LED);
		TURN_Off_LED('C',RED_LED);
		TURN_Off_LED('C',YELLOW_LED);
		DIO_vSetPinValue('A',BUZZER,1);
	}else{
		if(temp <= 40){// if temp greater than 20 and less than 40 turn on yellow
			TURN_Off_LED('A',GREEN_LED);
			TURN_Off_LED('C',RED_LED);
			TURN_ON_LED('C',YELLOW_LED);
			DIO_vSetPinValue('A',BUZZER,1);
		}else{
			if(temp <= 50){//Emergency state red is glow
				TURN_Off_LED('A',GREEN_LED);
				TURN_ON_LED('C',RED_LED);
				TURN_Off_LED('C',YELLOW_LED);
				DIO_vSetPinValue('A',BUZZER,0);
			}
		}
	}
}
int main(){
	uart_init();// initializing uart
	ADC_init();//initializing adc
	motor_init();//initializing motor
	Timer1_Init();//initializing Timer
	Servo_Init(); // initializing Servo
	DIO_vSetPinDirection('A',BUZZER,1);//set buzzer as output
	u8 Temprature = checkMessage(uart_receive());//read temp and check if the message is not to shutdown
	u8 pot = ADC_read(POT_PIN);//read potentiometer
	while(1){
		Temprature = checkMessage(uart_receive());//get temp value after checking if its a real temp value or a code to shut down
		set_state(Temprature);
		pot = ADC_read(POT_PIN);//read potentiometer
		if(Temprature < 50){
			motor_setspeed(pot);//take pot reading as speed of machine
			Timer1_Stop();
		}else{
			Timer1_Start();//start the timer to count
			motor_setspeed(0);
		}
	}
	return 0;
}
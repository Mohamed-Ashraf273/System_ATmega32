/*
 * MCU1.c
 *
 * Created: 8/12/2024 12:16:18 PM
 *  Author: ma273
 */ 

#include "TIMER.h"
#include "MCAL_DIO.h"
#include "MCAL_UART.h"
#include "MCAL_E2PROM.h"
#include "MCAL_ADC.h"
#include "HAL_TEMP_SENSEOR.h"
#include "HAL_DC_MOTOR.h"
#include <util/delay.h>
#define NORMAL 0
#define EMERGENCY 1
#define ABNORMAL 2
#define STATE 0
#define BUTTON 0 //portb, pin0
#define TEMPRATURE_CHANNEL 0
void shutDownMcu2(){
	uart_send('s');
	uart_send('t');
}
void set_state(uint16_t temp){
	temp = temp / 2.09;
	if(temp <= 20){//if temp less than 20 turn off the fan
		motor_setspeed(0);
		EEPROM_write(STATE,NORMAL);//set state as normal in eeprom
	}else{
		if(temp <= 40){
			u8 speed= (255/40)*temp;//calculate the range of the speed according to the temp
			motor_setspeed(speed);
		}else{
			if(temp <= 50){
				motor_setspeed(255);
			}else{
				motor_setspeed(255);
				EEPROM_write(STATE,EMERGENCY);//enter emergency state
				Timer1_Start();
			}
		}
	}
}
int main(){
	
	uart_init();//initializing UART
	ADC_init();//initializing ADC
	motor_init();//initialize motor fan
	Timer1_Init();//initializing timer
    uint16_t temperature = Get_Tempreature(TEMPRATURE_CHANNEL);//Read initial value of temperature
	EEPROM_write(STATE,NORMAL);//write normal state in e2prom as initial state
	DIO_vSetPinDirection('b',BUTTON,INPUT);//setting push button as input
	while(1){
		//read and check the button if it is pressed and temp between 40 and 50 then send a shut down message, if not it sends the temp
		if(DIO_vGetPinValue('b',BUTTON) && ((temperature/2.09) >= 40) && ((temperature/2.09)<=50)){
			shutDownMcu2();
		}
		temperature = Get_Tempreature(TEMPRATURE_CHANNEL);//get temp
		if((temperature/2.09)<50){
			Timer1_Stop();
		}
		set_state(temperature);//set the state and its actions 
		uart_send(temperature);//send temp to mcu2
	}
}
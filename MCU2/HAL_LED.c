/*
 * HAL_LED.c
 *
 * Created: 8/12/2024 12:50:52 PM
 *  Author: ma273
 */ 
#include "stdTypes.h"
#include "MCAL_DIO.h"

void TURN_ON_LED(u8 copy_u8portname,u8 copy_u8pinnumber){
	DIO_vSetPinDirection(copy_u8portname,copy_u8pinnumber,1);
	DIO_vSetPinValue(copy_u8portname,copy_u8pinnumber,1);
}

void TURN_Off_LED(u8 copy_u8portname,u8 copy_u8pinnumber){
	DIO_vSetPinDirection(copy_u8portname,copy_u8pinnumber,1);
	DIO_vSetPinValue(copy_u8portname,copy_u8pinnumber,0);
}
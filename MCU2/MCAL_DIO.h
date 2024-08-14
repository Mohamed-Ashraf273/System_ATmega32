/*
 * DIO.h
 *
 * Created: 8/12/2024 11:45:42 AM
 *  Author: ma273
 */ 


#ifndef DIO_H_
#define DIO_H_
//input 0
//output 1
//pullup as the button pressed --> 0 else 1, pulldown viceversa
#include "stdTypes.h"
#include "regs.h"
#define GetBit(reg,pin_number) (reg & (1<<pin_number)) ? 1:0
#define Write_Bit(reg,pin_no,pin_value) if(pin_value)reg|=(1<<pin_no);else reg&=~(1<<pin_no);

void DIO_vSetPortDirection(u8 copy_u8portname,u8 copy_u8portdirection);
void DIO_vSetPortvalue (u8 copy_u8portname,u8 copy_u8portvalue);
void DIO_vSetPinDirection(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pindirection);
void DIO_vSetPinValue(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pinvalue);
u8 DIO_vGetPinValue(u8 copy_u8portname,u8 copy_u8pinnumber);






#endif /* DIO_H_ */
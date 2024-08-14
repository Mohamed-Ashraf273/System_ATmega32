/*
 * DIO.c
 *
 * Created: 8/12/2024 11:50:08 AM
 *  Author: ma273
 */ 

#include "stdTypes.h"
#include "MCAL_DIO.h"


u8 DIO_vGetPinValue(u8 copy_u8portname,u8 copy_u8pinnumber){
	switch (copy_u8portname){
		case 'A' :
		case 'a' :
		return GetBit(PINA,copy_u8pinnumber);
		break;
		case 'B' :
		case 'b' :
		return GetBit(PINB,copy_u8pinnumber);
		break;
		case 'C' :
		case 'c' :
		return GetBit(PINC,copy_u8pinnumber);
		break;
		case 'D' :
		case 'd' :
		return GetBit(PIND,copy_u8pinnumber);
		break;
	}
}
void DIO_vSetPortDirection(u8 copy_u8portname,u8 copy_u8portdirection){
	switch (copy_u8portname){
		case 'A' :
		case 'a' :
		DDRA=copy_u8portdirection;
		break;
		case 'B' :
		case 'b' :
		DDRB=copy_u8portdirection;
		break;
		case 'C' :
		case 'c' :
		DDRC=copy_u8portdirection;
		break;
		case 'D' :
		case 'd' :
		DDRD=copy_u8portdirection;
		break;
	}
}
void DIO_vSetPortvalue (u8 copy_u8portname,u8 copy_u8portvalue){
	switch (copy_u8portname){
		case 'A' :
		case 'a' :
		PORTA=copy_u8portvalue;
		break;
		case 'B' :
		case 'b' :
		PORTB=copy_u8portvalue;
		break;
		case 'C' :
		case 'c' :
		PORTC=copy_u8portvalue;
		break;
		case 'D' :
		case 'd' :
		PORTD=copy_u8portvalue;
		break;
	}
	
}
void DIO_vSetPinDirection(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pindirection){
	switch (copy_u8portname){
		case 'A' :
		case 'a' :
		Write_Bit(DDRA,copy_u8pinnumber,copy_u8pindirection) ;
		break;
		case 'B' :
		case 'b' :
		Write_Bit(DDRB,copy_u8pinnumber,copy_u8pindirection);
		break;
		case 'C' :
		case 'c' :
		Write_Bit(DDRC,copy_u8pinnumber,copy_u8pindirection) ;
		break;
		case 'D' :
		case 'd' :
		Write_Bit(DDRD,copy_u8pinnumber,copy_u8pindirection) ;
		break;
	}
}
void DIO_vSetPinValue(u8 copy_u8portname,u8 copy_u8pinnumber,u8 copy_u8pinvalue){
	switch (copy_u8portname){
		case 'A' :
		case 'a' :
		Write_Bit(PORTA,copy_u8pinnumber,copy_u8pinvalue) ;
		break;
		case 'B' :
		case 'b' :
		Write_Bit(PORTB,copy_u8pinnumber,copy_u8pinvalue);
		break;
		case 'C' :
		case 'c' :
		Write_Bit(PORTC,copy_u8pinnumber,copy_u8pinvalue) ;
		break;
		case 'D' :
		case 'd' :
		Write_Bit(PORTD,copy_u8pinnumber,copy_u8pinvalue) ;
		break;
	}
}


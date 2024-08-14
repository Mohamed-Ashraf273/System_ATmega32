/*
 * MCAL_UART.c
 *
 * Created: 8/12/2024 12:28:20 PM
 *  Author: ma273
 */ 
#include "MCAL_DIO.h"
#include "MCAL_UART.h"
#include <avr/io.h>

void uart_init(unsigned int baud){
	UCSRB = (1 << RXEN) | (1 << TXEN);//enable receiving and transmitting
	UCSRC = (1 << UCSZ1) | (1 << UCSZ0) | (1 << URSEL);//set size to 8 bits and enable writing to UCSRC
	UBRRL = 0x33;
}

void uart_send(u8 data) {
	while (!(UCSRA & (1 << UDRE)));// Wait for the transmit buffer to be empty
	UDR = data;
}
u8 uart_receive(){
	while (!(UCSRA & (1 << RXC)));//Wait for data to be received
	return UDR;
}


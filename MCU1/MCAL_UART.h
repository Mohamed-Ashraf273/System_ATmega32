/*
 * MCAL_UART.h
 *
 * Created: 8/12/2024 12:28:39 PM
 *  Author: ma273
 */ 


#ifndef MCAL_UART_H_
#define MCAL_UART_H_

void uart_init();
void uart_send(u8 data);
u8 uart_receive();


#endif /* MCAL_UART_H_ */
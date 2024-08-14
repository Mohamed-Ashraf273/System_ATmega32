/*
 * regs.h
 *
 * Created: 8/12/2024 11:47:40 AM
 *  Author: ma273
 */ 


#ifndef REGS_H_
#define REGS_H_

#define DDRA (*(volatile char*)0x3A)
#define PORTA (*(volatile char*)0x3B)
#define PINA (*(volatile char*)0x39)
#define DDRB (*(volatile char*)0x37)
#define PORTB (*(volatile char*)0x38)
#define PINB (*(volatile char*)0x36)
#define DDRC (*(volatile char*)0x34)
#define PORTC (*(volatile char*)0x35)
#define PINC (*(volatile char*)0x33)
#define DDRD (*(volatile char*)0x31)
#define PORTD (*(volatile char*)0x32)
#define PIND (*(volatile char*)0x30)
#define MCUCR (*(volatile char*)0x55)
#define MCUCSR (*(volatile char*)0x54)
#define GICR (*(volatile char*)0x5B)
#define GIFR (*(volatile char*)0x5A)
#define SREG (*(volatile char*)0x5F)
#define UCSRB (*(volatile char*)0x2A)
#define UCSRC (*(volatile char*)0x40)
#define UBRRL (*(volatile char*)0x29)
#define ADMUX (*(volatile char*)0x27)
#define ADCSRA (*(volatile char*)0x26)
#define ADCL (*(volatile char*)0x24)
#define TCCR0 (*(volatile char*)0x53)
#define TIMSK (*(volatile char*)0x59)
#define WDTCR (*(volatile char*)0x41)
#define TCCR1A (*(volatile char*)0x4F)
#define TCCR1B (*(volatile char*)0x4E)














#endif /* REGS_H_ */
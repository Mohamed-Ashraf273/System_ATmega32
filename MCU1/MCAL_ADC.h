/*
 * MCAL_ADC.h
 *
 * Created: 8/12/2024 6:55:02 PM
 *  Author: ma273
 */ 


#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_
#include "stdTypes.h"
#include <avr/io.h>
void ADC_init();
uint16_t ADC_read(u8 channel);



#endif /* MCAL_ADC_H_ */
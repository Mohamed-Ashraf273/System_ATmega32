/*
 * MCAL_E2PROM.h
 *
 * Created: 8/12/2024 6:28:56 PM
 *  Author: ma273
 */ 


#ifndef MCAL_E2PROM_H_
#define MCAL_E2PROM_H_
#include "stdTypes.h"

void EEPROM_write(unsigned int address, u8 data);
u8 EEPROM_read(unsigned int address);


#endif /* MCAL_E2PROM_H_ */
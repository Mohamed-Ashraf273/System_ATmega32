/*
 * MCAL_E2PROM.c
 *
 * Created: 8/12/2024 6:28:35 PM
 *  Author: ma273
 */ 
#include <avr/eeprom.h>
#include "MCAL_DIO.h"
#include "stdTypes.h"

void EEPROM_write(unsigned int address, u8 data) {
	eeprom_write_byte((u8*)address, data);
}

u8 EEPROM_read(unsigned int address) {
	return eeprom_read_byte((const u8*)address);
}
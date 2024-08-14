/*
 * HAL_TEMP_SENSOR.c
 *
 * Created: 8/12/2024 6:54:14 PM
 *  Author: ma273
 */ 
#include "stdTypes.h"
#include "HAL_TEMP_SENSEOR.h"
#include "MCAL_ADC.h"
#include <avr/io.h>
uint16_t Get_Tempreature(u8 channel){
	return ADC_read(channel);
}

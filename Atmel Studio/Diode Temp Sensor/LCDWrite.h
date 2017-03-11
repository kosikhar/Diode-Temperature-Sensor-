/*
 * LCD_Write.h
 *
 * Created: 2017-03-04 10:13:08 AM
 *  Author: Koltin Kosik-Harvey
 */ 


#ifndef LCDWRITE_H_
#define LCDWRITE_H_

#define F_CPU 8000000UL
#include <stdio.h>
#include <avr/io.h>
#include "lcd.h"


void extern lcd_Write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint8_t temperture_lm35, uint8_t temperture_diode );



#endif /* LCD_WRITE_H_ */
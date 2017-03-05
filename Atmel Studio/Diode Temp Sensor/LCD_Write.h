/*
 * LCD_Write.h
 *
 * Created: 2017-03-04 10:13:08 AM
 *  Author: Koltin Kosik-Harvey
 */ 


#ifndef LCD_WRITE_H_
#define LCD_WRITE_H_

#include <avr/io.h>
#include <lcd.h>
#include <stdlib.h>

void lcd_write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint8_t temperture_lm35, uint8_t temperture_diode );



#endif /* LCD_WRITE_H_ */
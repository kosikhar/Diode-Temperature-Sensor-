#ifndef LCDWRITE_H_
#define LCDWRITE_H_

#define F_CPU 8000000UL
#include <stdio.h>
#include <avr/io.h>
#include "lcd.h"
#include "TempModel.h"

// This function prints the values of the LM35 and the Diode. Values being; its ADC value and its temperture. 
// Function blocks temperatures larger than 99C to keep interface looking clean. 
void extern lcd_Write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint16_t temperture_lm35, uint16_t temperture_diode);

#endif /* LCD_WRITE_H_ */
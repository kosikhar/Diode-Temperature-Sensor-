#include <avr/io.h>
#include "LCD_Write.h"


int main(void)
{
	uint16_t adc_reading_lm35 = 0x0;
	uint16_t adc_reading_diode = 0x0;
	uint8_t temperture_lm35 = 0x0;
	uint8_t temperture_diode = 0x0;

	lcd_write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);
}


#define  F_CPU 8000000

#include <avr/io.h>
#include "LCD_Write.h"
#include "ADC_Read.h"


int main(void)
{
	
	uint16_t adc_reading_lm35 = 0x0;
	uint16_t adc_reading_diode = 0x0;
	uint8_t temperture_lm35 = 0x0;
	uint8_t temperture_diode = 0x0;

	adc_reading_lm35 = ADCRead(0x0);  //Reads ADC, the input is the number number of the ADC
	adc_reading_diode = ADCRead(0x1);

	lcd_write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);
	
	
	while(1){};
}


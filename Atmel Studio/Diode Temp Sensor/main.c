#define F_CPU 8000000UL

#include <avr/io.h>
#include "LCDWrite.h"
#include "ADCRead.h"



int main(void)
{
	CLKPR = 0b10000000; //Enable clock prescaler change
	CLKPR |= 0x0; // Div 1 prescaller == 8MHz


	uint16_t adc_reading_lm35 = 0x0;
	uint16_t adc_reading_diode = 0x0;
	uint8_t temperture_lm35 = 0x0;
	uint8_t temperture_diode = 0x0;

	//adc_reading_lm35 = ADCRead(0x0);  //Reads ADC, the input is the pin number of the ADC
	//adc_reading_diode = ADCRead(0x1);

	lcd_Write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);
	
	
	while(1){};

	return 0;
}


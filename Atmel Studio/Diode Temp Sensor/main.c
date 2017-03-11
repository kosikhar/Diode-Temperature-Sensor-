#define F_CPU 8000000UL

#include <avr/io.h>
#include "LCDWrite.h"
#include "ADCRead.h"

#define LM35_pin 0
#define Diode_pin 1



int main(void)
{
	CLKPR = 0b10000000; //Enable clock prescaler change
	CLKPR |= 0x0; // Div 1 prescaller == 8MHz

	while(1){

	uint16_t adc_reading_lm35 = 0x0;
	uint16_t adc_reading_diode = 0x0;
	uint8_t temperture_lm35 = 69;
	uint8_t temperture_diode = 0x0;

	adc_reading_lm35 = ADCRead(LM35_pin);  //Reads ADC, the input is the pin number of the ADC
	adc_reading_diode = ADCRead(Diode_pin);

	lcd_Write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);

	_delay_ms(10);

	}


	return 0;
}


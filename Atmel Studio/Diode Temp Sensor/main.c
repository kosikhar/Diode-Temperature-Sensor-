#define F_CPU 8000000UL


#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include "LCDWrite.h"
#include "ADCRead.h"
#include "TempModel.h"

#define LM35_pin 0
#define Diode_pin 1



int main(void)
{
	clock_prescale_set(clock_div_1);
	
	uint16_t adc_reading_lm35 = 0;
	uint16_t adc_reading_diode = 0;
	uint16_t temperture_lm35 = 0;
	uint16_t temperture_diode = 0;

	while(1){

		clock_prescale_set(clock_div_1); //Set freq to 8MHZ

		adc_reading_lm35 = ADCRead(LM35_pin);  //Reads ADC, the input is the pin number of the ADC
		adc_reading_diode = ADCRead(Diode_pin);
		
		temperture_lm35 = temperture_model_lm35(adc_reading_lm35);
		temperture_diode = temperture_model_diode(adc_reading_diode);
		
		clock_prescale_set(clock_div_8);  //For some reason the display doesnt like 8MHz, but works fine with 1MHZ
		lcd_Write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);
	}


	return 0;
}


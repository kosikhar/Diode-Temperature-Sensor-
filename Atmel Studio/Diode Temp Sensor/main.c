//Tell delay.h we're running at 8MHz
#define F_CPU 8000000UL

//Includes
#include <avr/io.h>
#include <util/delay.h>
#include <avr/power.h>
#include "LCDWrite.h"
#include "ADCRead.h"
#include "TempModel.h"

//Define the ADC input pins
#define LM35_pin 0
#define Diode_pin 1


/* Main Function

Utilize a diode as a temperature sensor!

First we use a LM35 as our linear reference. We'll get its ADC value and find out, based on the ADC reference, what
the ambient temperature is. 

We can then read the ADC value of the voltage across a current biased diode, and find a linear map to temperature
based on the LM35's temperature. 

*/
int main(void)
{
	
	// Set CPU Clock Pre-Scaler to div 1 
	clock_prescale_set(clock_div_1); 
	
	// Initialize Required Variables
	uint16_t adc_reading_lm35 = 0;
	uint16_t adc_reading_diode = 0;
	uint16_t temperture_lm35 = 0;
	uint16_t temperture_diode = 0;
	
	//Main Loop
	while(1){
		
		//Reads ADC. ADC function has filter built in
		adc_reading_lm35 = ADCRead(LM35_pin);  
		adc_reading_diode = ADCRead(Diode_pin);
		
		// Applies Map from 16bit ADC value to temperature
		temperture_lm35 = temperture_model_lm35(adc_reading_lm35);  
		temperture_diode = temperture_model_diode(adc_reading_diode); 
		
		//Print results to LCD
		lcd_Write(adc_reading_lm35, adc_reading_diode, temperture_lm35, temperture_diode);
	}

	//Make complier happy c: 
	return 0;
}


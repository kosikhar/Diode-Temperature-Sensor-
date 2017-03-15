#include "TempModel.h"


uint16_t temperture_model_diode( uint16_t adc_value ){     //Assuming the ADC output is less than 1024
	
	uint16_t temperture;
	
	temperture = 28755;
	temperture = temperture - ( 60.481 * adc_value );
	
	temperture = temperture / 100;

	return temperture;
	
} 

uint16_t temperture_model_lm35( uint16_t adc_value ){
	
	uint16_t temperture;

	temperture = adc_value * 10.75;

	return (temperture / 100 - 2);


}
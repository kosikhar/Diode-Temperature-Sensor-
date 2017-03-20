#include "TempModel.h"


uint16_t temperture_model_diode( uint16_t adc_value ){     //Assuming the ADC output is less than 1024
	
	uint16_t temperture;
	
	temperture = 31909;
	temperture = temperture - ( 68.019 * adc_value );

	return (temperture / 100);
	
} 

uint16_t temperture_model_lm35( uint16_t adc_value ){
	
	uint16_t temperture;

	temperture = adc_value * 10.75;

	return (temperture / 100);


}
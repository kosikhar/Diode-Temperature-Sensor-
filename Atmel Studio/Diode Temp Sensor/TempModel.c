#include "TempModel.h"


uint16_t temperture_model( uint16_t adc_value ){     //Assuming the ADC output is less than 1024
	
	uint32_t buffer = 0;
	uint16_t temperture = 0;
	uint32_t buf_adc;
	
	buf_adc = adc_value * (60.481);
	buffer = 28755;
	buffer = buffer - buf_adc;

	temperture = (uint16_t) round(buffer / 100);
	
	return temperture;
	
} 
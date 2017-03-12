#include "TempModel.h"


struct double_as_2ints temperture_model( uint16_t adc_value ){     //Assuming the ADC output is less than 1024
	
	struct double_as_2ints temperture;
	uint32_t buffer = 0;
	uint32_t buf_adc;
	
	buf_adc = adc_value * (60.481);
	buffer = 28755;
	buffer = buffer - buf_adc;

	temperture.whole = (uint16_t) (buffer / 100);
	temperture.decimal = (uint8_t) buffer - temperture.whole;
	
	return temperture;
	
} 
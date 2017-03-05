#ifndef ADC_READ_H_
#define ADC_READ_H_

#include <avr/io.h>

struct ADCOut{    //ADC output is in 2 bytes, so we're going to use a structure of 2, 8bit numbers to store
	uint8_t leftbyte;    //This is going to hold the information in ADCL
	uint8_t rightbyte;	 //This "                                 " ADCH 
	                     // (ADCL and ADCH are registers that hold ADC data)
};

uint16_t byteCombine(struct ADCOut input);

uint16_t ADCRead(uint8_t pin);

#endif 
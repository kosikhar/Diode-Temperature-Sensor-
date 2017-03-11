#ifndef ADCREAD_H_
#define ADCREAD_H_

#ifndef F_CPU 
#define F_CPU 8000000UL
#endif 

#include <avr/io.h>
#include <util/delay.h>

struct ADCOut{    //ADC output is in 2 bytes, so we're going to use a structure of 2, 8bit numbers to store
	uint8_t lowbyte;    //This is going to hold the information in ADCL
	uint8_t highbyte;	 //This "                                 " ADCH  (ADCL and ADCH are registers that hold ADC data)
};

uint16_t extern ADCRead(uint8_t pin);

uint32_t extern byteCombine(struct ADCOut input);  //Combines 2, 8-bit numbers into a 10-bit (For ADC Out)


#endif 
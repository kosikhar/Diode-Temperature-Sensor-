#ifndef ADCREAD_H_
#define ADCREAD_H_

#include <avr/io.h>

//Function reads and samples the ADC, returning a 10bit value (stored as uint16)
//The input is the pin number of the ADC to be read.
uint16_t extern ADCRead(uint8_t pin);


#endif 
#ifndef ADCREAD_H_
#define ADCREAD_H_

#include <avr/io.h>

/*struct ADCOut{    //ADC output is in 2 bytes, so we're going to use a structure of 2, 8bit numbers to store
	uint8_t lowbyte;    //This is going to hold the information in ADCL
	uint16_t highbyte;	 //This "                                 " ADCH  (ADCL and ADCH are registers that hold ADC data)
};
*/

uint16_t extern ADCRead(uint8_t pin);

//uint16_t extern byteCombine(struct ADCOut input);  //Combines 2, 8-bit numbers into a 10-bit (For ADC Out)


#endif 
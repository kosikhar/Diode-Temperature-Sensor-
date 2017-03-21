#ifndef TEMPMODEL_H_
#define TEMPMODEL_H_

#include <avr/io.h>
#include <stdint.h>
#include <math.h>

//This function converts the ADC value to temperature. This model is 
//Based off of experiment by comparing it with the linear LM35
uint16_t temperture_model_diode( uint16_t adc_value );

//The linear model of the LM35 as provided by it's specification sheet
//This model well allows us to find a conversion for the diode's 
//ADC to the temperature
uint16_t temperture_model_lm35( uint16_t adc_value );

#endif /* TEMPMODEL_H_ */
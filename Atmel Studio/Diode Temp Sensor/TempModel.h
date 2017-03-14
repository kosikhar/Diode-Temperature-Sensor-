/*
 * TempModel.h
 *
 * Created: 3/12/2017 1:20:17 PM
 *  Author: Koltin
 */ 


#ifndef TEMPMODEL_H_
#define TEMPMODEL_H_

#include <avr/io.h>
#include <stdint.h>
#include <math.h>


uint16_t temperture_model_diode( uint16_t adc_value );

uint16_t temperture_model_lm35( uint16_t adc_value );

#endif /* TEMPMODEL_H_ */
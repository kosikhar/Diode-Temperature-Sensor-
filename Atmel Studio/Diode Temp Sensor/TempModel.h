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

struct double_as_2ints{       //To avoid using doubles, we're going to split to the temp decimal into 2 parts the whole and the decimal component.
	
	uint16_t whole;
	uint8_t decimal;
	
};


struct double_as_2ints temperture_model( uint16_t adc_value );

#endif /* TEMPMODEL_H_ */
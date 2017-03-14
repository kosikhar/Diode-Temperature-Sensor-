#define F_CPU 8000000UL
#include "ADCRead.h"
#include <util/delay.h>

//Adds a basic low pass filter to the ADC input
#define number_samples 1024
#define sample_time_us 100

uint16_t ADCRead(uint8_t pin){

	uint16_t input = 0; //We're going to sample and average from 16 readings. 
	uint32_t sum = 0; //The sum of all samples.
	uint16_t average = 0; // the average of all the sample
	
	ADCSRB &= 0x00; //Auto Trigger = Free Running mode
	ADCSRA |= (1 << ADEN);                // ADC Enable; Interupt Disable; Freq/1 
	//ADMUX |= (1 << REFS0); //Set reference, AVcc
	ADMUX |= ((1 << REFS0) | (1 << REFS1)) ; //Set Internal 1.1v reference		  
	
	ADMUX &= 0b11110000;
	    
	ADMUX |= pin;  //Set input pin
	
	uint16_t i;
	for(i = 0; i < number_samples; i++) {
	
		ADCSRA |= (1 << ADSC); //Start Conversation

		while( (ADCSRA & (1 << ADSC)) ); //Wait till conversation complete ( ADSC == 0 )

		ADCSRA |= (1 << ADIF);   // Clear ADC Interrupt Flag
		
		input = ADC; 
		sum = sum + input;
		
	}
	
	average = (uint16_t) (sum / number_samples);
		
	return average;
}


#include "ADC_Read.h"

uint16_t ADCRead(uint8_t pin){

	uint16_t input[16]; //We're going to sample and average from 16 readings. 

	PRR &= 0b11111110; //Enable ADC Power
	ADCSRB &= 0x00; //Auto Trigger = Free Running mode
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE) | ( 1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADC Enable; Auto Trigger;
	ADMUX |= (1 << REFS0); //Set reference, AVcc												      // Interupt Enable; Freq/128 
	ADMUX |= pin; //Set ADC pin

	uint8_t i;
	for (i = 0x0; i < 16 ; i++){
	
		ADCSRA |= (1 << ADSC); //Start Conversation, 

		while( ~(ADCSRA & (1 << ADIF)) ); //Wait till conversation complete

		input[i] = ADC;  //Read output

	}

	uint32_t sum = 0x0;
	for (i = 0x0; i < 15; i++)
	{
		sum = ( (uint32_t) input[i] ) + ( (uint32_t) input[i+1] );  // add up all the readings
	}

	uint16_t average_reading = (uint16_t) (sum / 16);  //Find the average of the readings and return the value
	return average_reading;
}
#include "ADCRead.h"

uint16_t ADCRead(uint8_t pin){

	struct ADCOut input[16]; //We're going to sample and average from 16 readings. 

	PRR &= 0b11111110; //Enable ADC Power
	ADCSRB &= 0x00; //Auto Trigger = Free Running mode
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | ( 1 << ADPS2); // ADC Enable; Auto Trigger;
	ADMUX |= (1 << REFS0); //Set reference, AVcc	      // Interupt Enable; Freq/16 
	ADMUX |= pin; //Set ADC pin

	uint8_t i;
	for (i = 0x0; i < 16 ; i++){
	
		ADCSRA |= (1 << ADSC); //Start Conversation, 

		while( (ADCSRA & (1 << ADSC)) ); //Wait till conversation complete ( ADSC == 0 )

		ADCSRA |= (1 << ADIF);   // Clear ADC Interrupt Flag

		
		input[i].lowbyte = 0;
		input[i].highbyte = 0;
		input[i].lowbyte = ADCL;  //Read output
		input[i].highbyte = ADCH; 
		_delay_ms(1);
	}

	uint32_t sum = 0x0;
	for (i = 0x0; i < 15; i++)
	{
		sum = byteCombine(input[i]) + byteCombine(input[i+1]);  // add up all the readings
	}

	uint16_t average_reading = (uint16_t) (sum / 16);  //Find the average of the readings and return the value
	return average_reading;
}

uint32_t byteCombine(struct ADCOut input){ //The ADCOut struct holds these 2 8bit numbers
	
	uint32_t output = 0x0;
	
	output = (input.highbyte << 8) | input.lowbyte;

	return output;
}


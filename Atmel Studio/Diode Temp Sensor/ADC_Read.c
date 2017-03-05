#include "ADC_Read.h"

uint16_t ADCRead(uint8_t pin){

	struct ADCOut input[16]; //We're going to sample and average from 16 readings. 

	PRR &= 0b11111110; //Enable ADC Power
	ADCSRB &= 0x00; //Auto Trigger = Free Running mode
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE) | ( 1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // ADC Enable; Auto Trigger;
	ADMUX |= (1 << REFS0); //Set reference, AVcc														  // Interupt Enable; Freq/128 
	ADMUX |= pin; //Set ADC pin

	uint8_t i;
	for (i = 0x0; i < 16 ; i++){
	
		ADCSRA |= (1 << ADSC); //Start Conversation, 

		while( ~(ADCSRA & (1 << ADIF)) ); //Wait till conversation complete

		input[i].leftbyte = ADCL;  //Read output
		input[i].rightbyte = ADCH; //Once we read the output ADCL/ADCH
						    	//Resets
	}

	uint32_t sum = 0x0;
	for (i = 0x0; i < 15; i++)
	{
		sum = ((uint32_t) byteCombine(input[i])) + ( (uint32_t) byteCombine(input[i+1]) );  // add up all the readings
	}

	uint16_t average_reading = (uint16_t) (sum / 16);  //Find the average of the readings and return the value
	return average_reading;
}


uint16_t byteCombine(struct ADCOut input){ //The ADCOut struct holds these 2 8bit numbers
	
	uint8_t a = 0x00;    //Move struct values into variables we can easily work with
	uint8_t b = 0x00;

	a = input.leftbyte;
	b = input.rightbyte;

	uint16_t output = 0x00;  //initialize the output
	output = output + b; // Add the high byte
	a &= 0b00000011; //only need the last 2 bits, wipe bits7-2
	
	output = output + (256 * (a & 0b00000001)); //if bit0 = 1, add 256
	output = output + (256 * (a & 0b00000010)); //if bit1 = 1, add 512

	return output;
}
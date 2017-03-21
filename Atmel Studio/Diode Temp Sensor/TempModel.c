#include "TempModel.h"


uint16_t temperture_model_diode( uint16_t adc_value ){     //Assuming the ADC output is less than 1024
	
	//Initialize temperture variable
	uint16_t temperture;
	
	/*
		Apply linear model. To avoid relying on decimals, we multiplied temperture 
		output by 100. Then built a linear model on that. So on return we divide by 100
		As a reminder a linear model is in the form y = mx + b.
	*/
	temperture = 31909; //This is the y-intercept (m = 0)
	temperture = temperture - ( 68.019 * adc_value ); //This is applying the slope of -68.019
	
	// Divide output by 100 since the linear model was built from 
	// multiplying the temperture by 100
	return (temperture / 100);
	
} 

uint16_t temperture_model_lm35( uint16_t adc_value ){
	
	//Initialize temperture variable
	uint16_t temperture;
	
	/*
		The LM35 raises its temperture by 0.01V per degree Celsius.
		It also has a 0V output at 0C.
		Since we're using a 1.1V reference, we can directly model this.
		This is what we're going to base the diode model on.
	*/
	temperture = adc_value * 0.1075; //0.1075 is in degrees Celsius per 'ADC unit'.
	
	//Return the output temperture.
	return temperture;


}
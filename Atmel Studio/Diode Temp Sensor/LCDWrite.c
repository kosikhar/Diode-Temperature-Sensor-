#define F_CPU 8000000UL

#include "LCDWrite.h"
#include <util/delay.h>

// Defines the maximum temperature that the LCD will display
#define MAX_TEMP 99

 /*
 ***********************************************************
  
  lcd_write takes in 4 values, as described in the function
  outputs both its ADC reading and the temperature. 

  The Temperature output is limited for visual purposes
  
 ***********************************************************
 */

 void lcd_Write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint16_t temperture_lm35, uint16_t temperture_diode ){  //Not Tested

	lcd_init( LCD_DISP_ON );   //Turn the LCD on, without cursor.
	
	//Initialize character arrays
	char display_line1[17];   //Pre-allocate memory for each line. char = 1B and theres a max of 16 char.
	char display_line2[17];   //1B added for the NULL character produced by sprintf. 

	/* 
	   The if statement is to prevent overloading the output since the linear model 
	   outputs extremely large values for impractical (but possible) inputs.
	   This is mostly for keeping visual fidelity 
	   If the output temperature is larger than 'MAX_TEMP', we'll replace the extreme value
	   with a ':C'. ( A sad face )
	*/
	if ( (temperture_lm35 < MAX_TEMP) && (temperture_diode < MAX_TEMP) ){
	
		sprintf(display_line1, "LM35 :%4.0d - %dC", adc_reading_lm35, temperture_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d - %dC", adc_reading_diode, temperture_diode);   //Second line on the LCD
		
	} else if ( (temperture_lm35 > MAX_TEMP) && (temperture_diode < MAX_TEMP) ) {
		
		sprintf(display_line1, "LM35 :%4.0d -  :(", adc_reading_lm35);						//First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d - %dC", adc_reading_diode, temperture_diode);   //Second line on the LCD			
		
	} else if ( (temperture_lm35 < MAX_TEMP) && (temperture_diode > MAX_TEMP) ) {
		
		sprintf(display_line1, "LM35 :%4.0d - %dC", adc_reading_lm35, temperture_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d -  :C", adc_reading_diode);					    //Second line on the LCD
		
	} else {
		
		sprintf(display_line1, "LM35 :%4.0d -  :C", adc_reading_lm35);						//First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d -  :C", adc_reading_diode);					    //Second line on the LCD		
		
	}
	
	//Begin printing information to display
	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x0);    //Move cursor to the first line
	lcd_puts( display_line1 );                   //display line 1
	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x1);    //Move cursor to the second line
	lcd_puts( display_line2 );                   //display line 2
	
 }

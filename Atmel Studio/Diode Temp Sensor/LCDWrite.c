/*
 * LCD_Write.c
 *
 * Created: 2017-03-04 10:13:34 AM
 *  Author: Koltin Kosik-Harvey
 */
#define F_CPU 8000000UL

#include "LCDWrite.h"
#include <util/delay.h>

#define MAX_TEMP 110
 
 /*
 **************************************
  
  lcd_write takes in 4 values.  As discribed in the function
  outputs both its ADC reading and the temperture. 

  The Temperture output is limited for visual purposes

  
 ***************************************
 */

 void lcd_Write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint16_t temperture_lm35, uint16_t temperture_diode ){  //Not Tested

	lcd_init( LCD_DISP_ON );   //Turn the LCD on, without cursor.

	char display_line1[17];   //Allocate memory for each line. char = 1B and theres a max of 16 char.
	char display_line2[17];   // 1B for the NULL character produced by sprintf.



	// The if statement is to prevent overloading the output since the model allows for 
	// such occurances. 
	if ( (temperture_lm35 < MAX_TEMP) && (temperture_diode < MAX_TEMP) ){
	
		sprintf(display_line1, "LM35 :%4.0d - %dC", adc_reading_lm35, temperture_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d - %dC", adc_reading_diode, temperture_diode);   //Second line on the LCD
		
	} else if ( (temperture_lm35 > MAX_TEMP) && (temperture_diode < MAX_TEMP) ) {
		
		sprintf(display_line1, "LM35 :%4.0d -  :(", adc_reading_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d - %dC", adc_reading_diode, temperture_diode);   //Second line on the LCD			
		
	} else if ( (temperture_lm35 < MAX_TEMP) && (temperture_diode > MAX_TEMP) ) {
		
		sprintf(display_line1, "LM35 :%4.0d - %dC", adc_reading_lm35, temperture_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d -  :C", adc_reading_diode);   //Second line on the LCD
		
	} else {
		
		sprintf(display_line1, "LM35 :%4.0d -  :C", adc_reading_lm35);     //First line on the LCD
		sprintf(display_line2, "DIODE:%4.0d -  :C", adc_reading_diode);   //Second line on the LCD		
		
	}

	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x0);    //Move cursor to the first line
	lcd_puts( display_line1 );               //display line 1
	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x1);    //Move cursor to the second line
	lcd_puts( display_line2 );                //display line 2
	
 }

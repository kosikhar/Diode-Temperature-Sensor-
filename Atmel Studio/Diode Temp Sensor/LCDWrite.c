/*
 * LCD_Write.c
 *
 * Created: 2017-03-04 10:13:34 AM
 *  Author: Koltin Kosik-Harvey
 */
 #include "LCDWrite.h"
 
 /*
 **************************************
  
  lcd_write takes in 4 values.  
  
 ***************************************
 */

 void lcd_Write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint8_t temperture_lm35, uint8_t temperture_diode ){  //Not Tested

	lcd_init( LCD_DISP_ON );   //Turn the LCD on, with cursor.

	char display_line1[17];   //Allocate memory for each line. char = 1B and theres a max of 16 char.
	char display_line2[17];   // 1B for the NULL character produced by sprintf.
	
	if ( (display_line1 == NULL) || (display_line2 == NULL) ){
		char * error = "error"; 
		lcd_puts(error);
	}
	
	sprintf(display_line1, "LM35 :%4.0d -%3.0dC", (int) adc_reading_lm35, (int) temperture_lm35);     //First line on the LCD
	sprintf(display_line2, "DIODE:%4.0d -%3.0dC", (int) adc_reading_diode, (int) temperture_diode);   //Second line on the LCD

	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x0);    //Move cursor to the first line
	lcd_puts( display_line1 );               //display line 1
	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x1);    //Move cursor to the second line
	lcd_puts( display_line2 );                //display line 2
	
 }
/*
 * LCD_Write.c
 *
 * Created: 2017-03-04 10:13:34 AM
 *  Author: Koltin Kosik-Harvey
 */
 #include "LCD_Write.h"
 
 /*
 **************************************
  
  lcd_write takes in 4 values.  
  
 ***************************************
 */

 void lcd_write( uint16_t adc_reading_lm35, uint16_t adc_reading_diode, uint8_t temperture_lm35, uint8_t temperture_diode ){  //Not Tested

	lcd_init( LCD_DISP_ON_CURSOR );   //Turn the LCD on, with cursor.
	
	lcd_clrscr(); //Clear screen then send cursor to "home" (0,0)

	char * display_line1[16];   //Allocate memory for each line. char = 1B and theres a max of 16 char
	char * display_line2[16];
	
	if ( (display_line1 == NULL) || (display_line2 == NULL) ){
		char * error = "error"; 
		lcd_puts(error);
	}
	
	*display_line1 = sprintf("LM35 :%4.0d - %2.0dC", adc_reading_lm35, temperture_lm35);     //First line on the LCD
	*display_line2 = sprintf("DIODE:%4.0d - %2.0dC", adc_reading_diode, temperture_diode);   //Second line on the LCD

	lcd_puts( display_line1 );               //display line 1
	lcd_gotoxy((uint8_t) 0x0, (uint8_t) 0x1);    //Move cursor to the second line
	lcd_puts( display_line2 );                //display line 2
	
	lcd_init( LCD_DISP_ON );        //LCD already is on, but this gets rid of the cursor (*I think). 

 }

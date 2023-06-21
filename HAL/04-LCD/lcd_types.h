/*
 * lcd_types.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Khaled
 */

#ifndef LCD_TYPES_H_
#define LCD_TYPES_H_


typedef enum
{

	    LCD_CLEAR=0x01,
		LCD_CURSOR_OFF=0x0C,
		LCD_CURSOR_ON=0x0F,
		LCD_4BIT_MODE=0x28,
		LCD_8BIT_MODE=0x38,
		LCD_ON=0x0F,
		LCD_CURSOR_UNDERLINE=0x0E,
		LCD_CURSOR_SHIFT_LEFT=0x10,
		LCD_CURSOR_SHIFT_RIGHT=0x14,
		LCD_CURSOR_INCREMENT=0x06,
		LCD_CGRAM_START_ADDRESS=0x40,
		LCD_first_column_start=0x80,
		LCD_second_column_start=0xc0



}lcd_Cmd;


typedef enum
{
	row1,
	row2
} lcd_rows;

typedef enum
{
	column1=0,
	column2=1,
	column3=2,
	column4=3,
	column5=4,
	column6=5,
	column7=6,
	column8=7,
	column9=8,
	column10=9,
	column11=10,
	column12=11,
	column13=12,
	column14=13,
	column15=14,
	column16=15
} lcd_column;





#endif /* LCD_TYPES_H_ */

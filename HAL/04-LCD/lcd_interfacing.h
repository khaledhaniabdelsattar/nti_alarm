/*
 * lcd_interfacing.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Khaled
 */

#ifndef LCD_INTERFACING_H_
#define LCD_INTERFACING_H_
#include "DIO_Rgister.h"
#include "dio_types.h"
#include "dio_interfacing.h"
#include "lcd_types.h"
#include <util/delay.h>
#include <stdio.h>
#include "lcd_cfg.h"

void lcd_intilization();

void send_command(lcd_Cmd comands);
void go_to_xy(lcd_rows row,lcd_column column);
void lcd_display(u8 data);
void lcd_display_string(u8 str[]);
void lcd_display_number_onebyte(u8 number);



#endif /* LCD_INTERFACING_H_ */

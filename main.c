/*
 * main.c
 *
 *  Created on: Jun 28, 2022
 *      Author: Khaled
 */


#include <util/delay.h>
#include "std_types.h"
#include "lcd_interfacing.h"
#include "Button_interfacing.h"
#include "led_interface.h"
#include "Buzzer_interface.h"

void main()
{
Buzzer_configuratio();
lcd_intilization();
push_button_configuration();
leds_configuration();
send_command(LCD_CLEAR);
 //button0 -> start
 //button1 ->  set time
//button2 -> start count down

while (1)

{
	u8 seconds=0;
	s8 minutes=0;
	u8 minutes_increase_indicator=0;
	s8 i=0;
	s8 j=0;
	send_command(LCD_CLEAR);
	go_to_xy(row1, column1);
	lcd_display('0');
	lcd_display('0');
	lcd_display(':');
	lcd_display('0');
	lcd_display('0');
	send_command(LCD_CURSOR_OFF);
	while(is_push_button_pressed(push_button0)==FALSE);
	send_command(LCD_CURSOR_ON);
    while(is_push_button_pressed(push_button2)==FALSE)
	{

	      if(is_push_button_pressed(push_button1)==TRUE)
		   {
          _delay_ms(10);
          while(is_push_button_pressed(push_button1)==TRUE);
           if(seconds<50)
           {

        	   seconds=seconds+10;

           }
           else
           {
        	   seconds=0;
        	   minutes_increase_indicator=1;

           }


		 if(minutes_increase_indicator==1)

		 {


			 minutes_increase_indicator=0;
			 minutes++;
         }


		if(minutes<10)
		{
			go_to_xy(row1, column1);
				lcd_display('0');

			go_to_xy(row1, column2);
			lcd_display_number_onebyte(minutes);

		}
		else
	     {


			go_to_xy(row1, column1);
			lcd_display_number_onebyte(minutes);

		 }

		go_to_xy(row1, column3);
		lcd_display(':');
		go_to_xy(row1,column4);
		lcd_display_number_onebyte(seconds);
		go_to_xy(row1,column6);

		   }

	} //end of setting time

    //if(minutes==0) // skip minutes loop as there is no minutes
    //{
    //minutes=-1 ;

    //}


    //displaying seconds

    for(i=seconds;i>-1;i--)
    {

if(i<10)
    	 		{

    		    go_to_xy(row1,column4);
    	 		lcd_display('0');
    	 		go_to_xy(row1,column5);
    	        lcd_display_number_onebyte(i);

    	 		}
    	 		else
    	 		{
    	 			go_to_xy(row1,column4);
    	 			lcd_display_number_onebyte(i);

    	 		}

    	 		go_to_xy(row1,column6);
    	 		_delay_ms(1);

    }

//displaying minutes
for (i=minutes;i>0;i--)
{

	if(i<10)
	 		{
		   go_to_xy(row1, column1);
		 	lcd_display('0');
	 			go_to_xy(row1, column2);

	        lcd_display_number_onebyte(i-1);

	 		}
	 		else
	 	     {

	 			go_to_xy(row1, column1);
	 			lcd_display_number_onebyte((i-1));

	 		 }


	for(j=60;j>-1;j--)
	{



 		go_to_xy(row1, column3);
 		lcd_display(':');

 		if(j<10)
 		{
 		go_to_xy(row1,column4);
 		lcd_display('0');
 		go_to_xy(row1,column5);
        lcd_display_number_onebyte(j);

 		}
 		else
 		{
 			go_to_xy(row1,column4);
 			lcd_display_number_onebyte(j);

 		}

 		go_to_xy(row1,column6);
 		_delay_ms(1);
	}

}



_delay_ms(1); //last second

   led_on(led1);
   Buzzer_on();
    _delay_ms(1000);
   led_off(led1);
Buzzer_off();
}


}



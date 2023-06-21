/*
 * ssd_interfacing.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Khaled
 */

#include "ssd_interfacing.h"
void ssd_init()

{
	    DIO_cofigure_channel(PORTA, PIN4, output);
		DIO_cofigure_channel(PORTA, PIN5, output);
		DIO_cofigure_channel(PORTA, PIN6, output);
		DIO_cofigure_channel(PORTA, PIN7, output);
		DIO_cofigure_channel(PORTB, PIN1, output); //en1
		DIO_cofigure_channel(PORTB, PIN2, output); //en2
		DIO_cofigure_channel(PORTB, PIN3, output); //dip

        DIO_write_output_channel(PORTA, PIN4, low);
		DIO_write_output_channel(PORTA, PIN5, low);
		DIO_write_output_channel(PORTA, PIN6, low);
		DIO_write_output_channel(PORTA, PIN7, low);

		DIO_write_output_channel(PORTB, PIN1, low); //en2
		DIO_write_output_channel(PORTB, PIN2, low); //en1
		DIO_write_output_channel(PORTB, PIN3, low);
}

void ssd_display(u8 num)
{

   if(num<100)
   {
	  u8 first_digit=(num%10)<<4;
	  u8 second_digit=(num/10)<<4;


      //enable ssd1 and disable ssd2
	  DIO_write_output_channel(PORTB, PIN1, high); //en1
	  DIO_write_output_channel(PORTB, PIN2,low); //en2


	  DIO_write_output_group_of_port(PORTA, 0xf0, first_digit);
	  _delay_ms(1);


	  //enable ssd2 and disable ssd1
	      DIO_write_output_channel(PORTB, PIN1, low); //en1
	  	  DIO_write_output_channel(PORTB, PIN2,high); //en2
          DIO_write_output_group_of_port(PORTA, 0xf0, second_digit);
	  	  _delay_ms(1);

	  }


}



void ssd_display_with_delay (u8 num,u32 delay)

{

	u32 i=0;

	for(i=0;i<delay;i+=3)
	{

		ssd_display(num);
		_delay_ms(1);

    }

}

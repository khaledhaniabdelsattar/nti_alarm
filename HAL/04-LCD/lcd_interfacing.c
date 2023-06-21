/*
 * lcd_interfaving.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Khaled
 */

#include "lcd_interfacing.h"


extern u8 custom_charcters_array [number_of_custom_charachter][size_of_custom_charachter_inbytes];

static void pulse ()
{

	DIO_write_output_channel(PORTB, PIN3, high);
	_delay_ms(100);
	DIO_write_output_channel(PORTB, PIN3, low);

}




static void send_data(u8 data)
{

	DIO_write_output_channel(PORTB, PIN1, high); //RS=1

u8 high_sending=data;
u8 low_sending=data<<4;

DIO_write_output_group_of_port(PORTA,lcd_masking_vlaue, high_sending);
pulse();

DIO_write_output_group_of_port(PORTA,lcd_masking_vlaue, low_sending);
pulse();

}


void static lcd_write_custom_characters()
{

	u8 charcter_number=0;
	u8 charcter_size=0;
	send_command(LCD_CGRAM_START_ADDRESS);
  for(charcter_number=0;charcter_number<number_of_custom_charachter;charcter_number++)
	{


		for (charcter_size=0;charcter_size<size_of_custom_charachter_inbytes;charcter_size++)

		     {
			send_data(custom_charcters_array[charcter_number][charcter_size]);

		       }

	}



}


void static lcd_write_custom_onecharacter()
{


u8 custom_charhchter[8]={0x0A,0x1F,0x1F,0x1F,0x1F,0x0E,0x04,0x00};  /* Heart symbol*/
 u8 i=0;

 send_command(LCD_CGRAM_START_ADDRESS);
 for(i=0;i<8;i++)
 {


	 send_data(custom_charhchter[i]);


 }

 }

void lcd_intilization()

{


	//D4->pA4
	//D5->pA5
	//D6->pA6
	//D7->pA7
	//rs->pB1
	//rw->pB2
	//E->pB3

	DIO_cofigure_channel(PORTA, PIN4, output);
	DIO_cofigure_channel(PORTA, PIN5, output);
	DIO_cofigure_channel(PORTA, PIN6, output);
	DIO_cofigure_channel(PORTA, PIN7, output);
	DIO_cofigure_channel(PORTB, PIN1, output);
	DIO_cofigure_channel(PORTB, PIN2, output);
	DIO_write_output_channel(PORTB, PIN2,low); //Rw alawys zero
	DIO_cofigure_channel(PORTB, PIN3, output);

	_delay_ms(15);

		send_command(0x03);
		_delay_ms(5);

		send_command(0x03);
		_delay_us(100);

		send_command(0x03);
		send_command(0x02);
		send_command(0x02);

	lcd_write_custom_characters();

}



void send_command(lcd_Cmd comands)

{

	DIO_write_output_channel(PORTB, PIN1, low); //RS=0

    u8 high_sending=comands;
	u8 low_sending=comands<<4;

	DIO_write_output_group_of_port(PORTA, lcd_masking_vlaue, high_sending);
	pulse();

	DIO_write_output_group_of_port(PORTA, lcd_masking_vlaue, low_sending);
	pulse();

}

void go_to_xy(lcd_rows row ,lcd_column column)
{

	switch (row)

	{

	case row1:

		send_command(LCD_first_column_start+column);

		break;

	case row2:

			send_command(LCD_second_column_start+column);

			break;



	}


}

void lcd_display(u8 data)
{

	send_data(data);

}

void lcd_display_string(u8 str[])

{


while((*str)!='\0')
{

	lcd_display(*str);

	str++;

}

}

void lcd_display_number_onebyte(u8 number)
{
    u8 str [3];
    u8 *ptr=str; //ptr to loop
    u8 *ptr1=str; // to check first element only;

    sprintf(str,"%d",number);


    if ((*ptr1)==0)  //skip first element
    {
    	ptr++;
    }

    while((*ptr)!='\0')
	{

		lcd_display(*ptr);
          ptr++;

	}

}


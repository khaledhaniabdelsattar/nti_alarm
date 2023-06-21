/*
 * Buzzer.c
 *
 *  Created on: Jun 19, 2022
 *      Author: Khaled
 */


#include "Buzzer_interface.h"

void Buzzer_configuratio()
{

	DIO_cofigure_channel(PORTA, PIN3, output);

	DIO_write_output_channel(PORTA, PIN3, low);

}


void Buzzer_on()

{

	DIO_write_output_channel(PORTA, PIN3,high);


}


void Buzzer_off()

{

	DIO_write_output_channel(PORTA, PIN3,low);


}

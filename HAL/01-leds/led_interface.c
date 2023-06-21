/*
 * led_interface.c
 *
 *  Created on: Jun 12, 2022
 *      Author: Khaled
 */

#include "DIO_Rgister.h"
#include "dio_types.h"
#include "dio_interfacing.h"
#include "led_names.h"
#include "bitmath.h"
#include "led_cfg.h"

void leds_configuration ()
{
    DIO_cofigure_channel(led0_port,led0_pin,output);//led0
    DIO_cofigure_channel(led1_port,led1_pin,output); //led1
    DIO_cofigure_channel(led2_port,led2_pin,output); //led2

#if( led0_cnnection==source)

    DIO_write_output_channel (led0_port,led0_pin,low);

#else if ( led0_cnnection==sink)

    DIO_write_output_channel (led0_port,led0_pin,high);


#endif


#if( led1_cnnection==source)
    DIO_write_output_channel (led1_port,led1_pin,low);

#else if ( led1_cnnection==sink)

    DIO_write_output_channel (led1_port,led1_pin,high);


#endif

#if( led2_cnnection==source)

    DIO_write_output_channel (led2_port,led2_pin,low);

#else if ( led2_cnnection==sink)

    DIO_write_output_channel (led2_port,led2_pin,high);

#endif

}


void led_on(leds led)
{

	switch(led)
	{

	case led0:

#if( led0_cnnection==source)

		DIO_write_output_channel (led0_port,led0_pin,high); //led0

#else if ( led0_cnnection==sink)

    DIO_write_output_channel (led0_port,led0_pin,low);


#endif

		break;

case led1:

#if( led1_cnnection==source)
		DIO_write_output_channel (led1_port,led1_pin,high); //led1

#else if ( led1_cnnection==sink)

    DIO_write_output_channel (led1_port,led1_pin,low);


#endif

		break;


case led2:

#if( led2_cnnection==source)
		DIO_write_output_channel (led2_port,led2_pin,high);


#else if ( led2_cnnection==sink)

    DIO_write_output_channel (led2_port,led2_pin,low);


#endif
				 break;
	}

}


void led_off(leds led)

{

	switch(led)
		{

case led0:

#if( led0_cnnection==source)
			 DIO_write_output_channel (led0_port,led0_pin,low); //led0


#else if ( led0_cnnection==sink)

    DIO_write_output_channel (led0_port,led0_pin,high);


#endif
			 break;

case led1:

#if( led1_cnnection==source)
			 DIO_write_output_channel (led1_port,led1_pin,low); //led1


#else if ( led1_cnnection==sink)

    DIO_write_output_channel (led1_port,led1_pin,high);


#endif
			break;

case led2:

#if( led2_cnnection==source)
			 DIO_write_output_channel (led2_port,led2_pin,low); //led2
#else if ( led2_cnnection==sink)

    DIO_write_output_channel (led2_port,led2_pin,high);


#endif
					 break;
		}


}


void toggle_led (leds led)

{


	switch(led)
			{

			case led0:
				 DIO_flip_pin(led0_port,led0_pin); //led0
				 break;

			case led1:
				DIO_flip_pin(led1_port,led1_pin); //led1
				break;

			case led2:
				DIO_flip_pin(led2_port,led2_pin); //led2
						 break;
			}


}

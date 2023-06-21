/*
 * buttons.c
 *
 *  Created on: Jun 17, 2022
 *      Author: Khaled
 */

#include "Button_interfacing.h"
#include "push_buttons_cfg.h"

void push_button_configuration()
{
    DIO_cofigure_channel(push_button0_port, push_button0_PIN,input);
	DIO_cofigure_channel(push_button1_port, push_button1_PIN,input);
	DIO_cofigure_channel(push_button2_port, push_button2_PIN,input);
}


boolean is_push_button_pressed (push_button button)
{
   boolean is_push_button_pressed_return;
    switch (button)
    {
    case push_button0:

    	#if (push_button0_connection==pull_down)
    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==high)
    	{
    		is_push_button_pressed_return=TRUE;
    	}
    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==low)
    	 {
    		is_push_button_pressed_return=FALSE;
    	 }

       #else if (push_button0_connection==pull_up)
    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==high)
    	    	{
    	    		is_push_button_pressed_return=FALSE;
    	    	}
    	    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==low)
    	    	 {
    	    		is_push_button_pressed_return=TRUE;
    	    	 }

      #endif

    	break;

    //

    case push_button1:

   #if (push_button1_connection==pull_down)
        	if(DIO_recive_input_channel(push_button1_port, push_button1_PIN)==high)
        	{
        		is_push_button_pressed_return=TRUE;
        	}
        	if(DIO_recive_input_channel(push_button1_port, push_button1_PIN)==low)
        	 {
        		is_push_button_pressed_return=FALSE;
        	 }


  #else if(push_button1_connection==pull_up)
    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==high)
    	    	{
    	    		is_push_button_pressed_return=FALSE;
    	    	}
    	    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==low)
    	    	 {
    	    		is_push_button_pressed_return=TRUE;
    	    	 }

      #endif
        	break;


    case push_button2:

#if (push_button2_connection==pull_down)
        	if(DIO_recive_input_channel(push_button2_port, push_button2_PIN)==high)
        	{
        		is_push_button_pressed_return=TRUE;
        	}
        	if(DIO_recive_input_channel(push_button2_port, push_button2_PIN)==low)
        	 {
        		is_push_button_pressed_return=FALSE;
        	 }
#else if(push_button2_connection==pull_up)
    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==high)
    	    	{
    	    		is_push_button_pressed_return=FALSE;
    	    	}
    	    	if(DIO_recive_input_channel(push_button0_port, push_button0_PIN)==low)
    	    	 {
    	    		is_push_button_pressed_return=TRUE;
    	    	 }

      #endif

    	    	break;
}

return is_push_button_pressed_return;

}

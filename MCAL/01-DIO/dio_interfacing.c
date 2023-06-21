/*
 * dio_interfacing.c
 *
 *  Created on: Jun 11, 2022
 *      Author: Khaled
 */

#include "DIO_Rgister.h"
#include "dio_types.h"
#include "bitmath.h"



void DIO_cofigure_channel ( DIO_port port,PIN_NUMBER pin,Pin_dirction dirction)

{
	switch (port)
	{
	case PORTA:

  if(dirction ==input)
  {
	  CLEAR_BIT(DIO_DDRA_REG,pin);

  }
 if (dirction == output)
  {
	 SET_BIT(DIO_DDRA_REG,pin);

  }
  break;


  // portB

	case PORTB:
if(dirction ==input)
  {
	  CLEAR_BIT(DIO_DDRB_REG,pin);

  }
 if (dirction == output)
  {
	 SET_BIT(DIO_DDRB_REG,pin);

  }
break;



  // portC
	case PORTC:


    if(dirction ==input)
    {
  	  CLEAR_BIT(DIO_DDRC_REG,pin);

    }
   if (dirction == output)
    {
  	 SET_BIT(DIO_DDRC_REG,pin);

    }
  break;




    // portD
	case PORTD:

      if(dirction ==input)
      {
    	  CLEAR_BIT(DIO_DDRD_REG,pin);

      }
     if (dirction == output)
      {
    	 SET_BIT(DIO_DDRD_REG,pin);

      }
    break;
	}
}

void DIO_write_output_channel ( DIO_port port ,PIN_NUMBER pin,pin_level level)

{

	switch(port)
	{
	case PORTA:

	  if (level== low)
	  {
		CLEAR_BIT(DIO_PORTA_REG,pin);
	  }

	  if (level== high)
	  	  {
	  		SET_BIT(DIO_PORTA_REG,pin);
	  	  }
	break;


	  //portB
	case PORTB:

	  	  if (level== low)
	  	  {
	  		CLEAR_BIT(DIO_PORTB_REG,pin);
	  	  }

	  	  if (level== high)
	  	  	  {
	  	  		SET_BIT(DIO_PORTB_REG,pin);
	  	  	  }

    break;
	  	//portc
	case PORTC:

	  		  	  if (level== low)
	  		  	  {
	  		  		CLEAR_BIT(DIO_PORTC_REG,pin);
	  		  	  }

	  		  	  if (level== high)
	  		  	  	  {
	  		  	  		SET_BIT(DIO_PORTC_REG,pin);
	  		  	  	  }


            break;
	  		 	//portD
	       case PORTD:

	  		  		  	  if (level== low)
	  		  		  	  {
	  		  		  		CLEAR_BIT(DIO_PORTD_REG,pin);
	  		  		  	  }

	  		  		  	  if (level== high)
	  		  		  	  	  {
	  		  		  	  		SET_BIT(DIO_PORTD_REG,pin);
	  		  		  	  	  }
	  		  		  break;
          }



}





void DIO_write_output_group_of_port (DIO_port port,u8 mask,u8 data)
{

	switch (port)
	{
	case PORTA:

		DIO_PORTA_REG=(DIO_PORTA_REG&(~mask))|(data&mask);

		  break;
	case PORTB:
		DIO_PORTB_REG=(DIO_PORTB_REG&(~mask))|(data&mask);
	             break;
	case PORTC:
		DIO_PORTC_REG=(DIO_PORTC_REG&(~mask))|(data&mask);
	             break;
	case PORTD:
		DIO_PORTD_REG=(DIO_PORTD_REG&(~mask))|(data&mask);
	             break;
	}
}
pin_level DIO_recive_input_channel(DIO_port port,PIN_NUMBER pin)
{
	switch(port)
	{

	case PORTA:

		return CHECK_BIT(DIO_PINA_REG,pin);
		break;

	case PORTB:

		    return CHECK_BIT(DIO_PINB_REG,pin);
			break;

	case PORTC:

			return CHECK_BIT(DIO_PINC_REG,pin);
			break;

	case PORTD:

			return CHECK_BIT(DIO_PIND_REG,pin);
			break;

}
}

void DIO_flip_pin ( DIO_port port,PIN_NUMBER pin)
{


	switch(port)
		{
		case PORTA:
 TOGGLE_BIT(DIO_PORTA_REG,pin);
		break;
 //portB
		case PORTB:

			 TOGGLE_BIT(DIO_PORTB_REG,pin);
	    break;
		  	//portc
		case PORTC:

			 TOGGLE_BIT(DIO_PORTC_REG,pin);
	            break;
		  		 	//portD
		       case PORTD:
               TOGGLE_BIT(DIO_PORTD_REG,pin);
		  		  		  break;
	         }

}








/*
 * dio_types.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Khaled
 */

#ifndef DIO_TYPES_H_
#define DIO_TYPES_H_

  typedef enum
{
   PORTA,
   PORTB,
   PORTC,
   PORTD

} DIO_port ;


typedef enum
{

  PIN0,
  PIN1,
  PIN2,
  PIN3,
  PIN4,
  PIN5,
  PIN6,
  PIN7
} PIN_NUMBER;

typedef enum
{
	input,
    output

} Pin_dirction;


typedef enum

{
	low,
	high

} pin_level;




#endif /* DIO_TYPES_H_ */

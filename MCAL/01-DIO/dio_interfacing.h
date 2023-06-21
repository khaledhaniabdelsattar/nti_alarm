/*
 * dio_interfacing.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Khaled
 */

#ifndef DIO_INTERFACING_H_
#define DIO_INTERFACING_H_
#include "dio_types.h"
#include "DIO_Rgister.h"
void DIO_cofigure_channel ( DIO_port port,PIN_NUMBER pin ,Pin_dirction dirction);
void DIO_write_output_channel ( DIO_port port ,PIN_NUMBER pin,pin_level level);
void DIO_write_output_group_of_port (DIO_port port,u8 mask,u8 data);
void DIO_flip_pin ( DIO_port port,PIN_NUMBER pin);
pin_level DIO_recive_input_channel(DIO_port port,PIN_NUMBER pin);

#endif /* DIO_INTERFACING_H_ */

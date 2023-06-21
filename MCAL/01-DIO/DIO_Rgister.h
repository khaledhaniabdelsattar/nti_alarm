/*
 * DIO_Rgister.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Khaled
 */



#include "std_types.h"

#ifndef DIO_RGISTER_H_
#define DIO_RGISTER_H_

/* hw DIO registers */

#define DIO_PORTA_REG    (*(volatile u8*)(0x3B))
#define DIO_DDRA_REG     (*(volatile u8*)(0x3A))      //A PINS
#define DIO_PINA_REG     (*(volatile u8*)(0x39))


#define DIO_PORTB_REG   (*(volatile u8*)(0x38))
#define DIO_DDRB_REG    (*(volatile u8*)(0x37))      //B PINS
#define DIO_PINB_REG    (*(volatile u8*)(0x36))

#define DIO_PORTC_REG   (*(volatile u8*)(0x35)) //  C PINS
#define DIO_DDRC_REG    (*(volatile u8*)(0x34))
#define DIO_PINC_REG    (*(volatile u8*)(0x33))

#define DIO_PORTD_REG   (*(volatile u8*)(0x32)) //  D PINS
#define DIO_DDRD_REG    (*(volatile u8*)(0x31))
#define DIO_PIND_REG    (*(volatile u8*)(0x30))

#endif /* DIO_RGISTER_H_ */

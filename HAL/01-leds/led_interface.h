/*
 * led_interface.h
 *
 *  Created on: Jun 12, 2022
 *      Author: Khaled
 */

#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_
#include "led_names.h"

void leds_configuration();
void led_on(leds led);
void led_off(leds led);
void toggle_led (leds led);

#endif /* LED_INTERFACE_H_ */

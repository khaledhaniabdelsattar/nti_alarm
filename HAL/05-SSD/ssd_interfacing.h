/*
 * ssd_interfacing.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Khaled
 */

#ifndef SSD_INTERFACING_H_
#define SSD_INTERFACING_H_

#include"dio_interfacing.h"
#include <util/delay.h>
void ssd_init();

void ssd_display(u8 num);

void ssd_display_with_delay (u8 num,u32 delay);


#endif /* SSD_INTERFACING_H_ */

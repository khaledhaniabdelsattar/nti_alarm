/*
 * bitmath.h
 *
 *  Created on: Jun 11, 2022
 *      Author: Khaled
 */

#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(REG,BIT_NUMBER)              REG|=(1<<BIT_NUMBER)
#define CLEAR_BIT(REG,BIT_NUMBER)            REG&=(~(1<<BIT_NUMBER))
#define CHECK_BIT(REG,BIT_NUMBER)            ((REG>>BIT_NUMBER)&1)
#define TOGGLE_BIT(REG,BIT_NUMBER)            REG^=(1<<BIT_NUMBER)


#endif /* BITMATH_H_ */

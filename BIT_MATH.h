/*
 * BIT_MATH.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ali Seleem
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BITNO) (VAR |= (0x01<<BITNO))
#define CLR_BIT(VAR,BITNO) (VAR &= ~(0x01<<BITNO))
#define TOG_BIT(VAR,BITNO) (VAR ^= (0x01<<BITNO))
#define GET_BIT(VAR,BITNO) (((VAR) >> (BITNO)) & 0x01)

#endif /* BIT_MATH_H_ */

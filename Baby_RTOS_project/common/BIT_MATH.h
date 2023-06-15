/*
 * BIT_MATH.h
 *
 *  Created on: Mar 22, 2023
 *      Author: Adel
 */

#ifndef COMMON_BIT_MATH_H_
#define COMMON_BIT_MATH_H_

#define SET_BIT(REG,BIT)   ( REG |=   (1<<BIT))
#define CLR_BIT(REG,BIT)   ( REG &=  ~(1<<BIT))
#define TOG_BIT(REG,BIT)   ( REG ^=   (1<<BIT))
#define GET_BIT(REG,BIT)   ((REG>>BIT)  & 0x01)

#define NULL (void*)0
#endif /* COMMON_BIT_MATH_H_ */

/*
 * Timer0.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Ghefo
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "DIO_register.h"
#include "DIO_interface.h"
#include "TIMER_REG_DEF.h"
#include "EXTI_REG_DEF.h"


void timer0_init_overFlowMode(void);
void timer0_init_CtcMode(void);
void timer0_init_CtcMode(void);

#endif /* TIMER0_H_ */

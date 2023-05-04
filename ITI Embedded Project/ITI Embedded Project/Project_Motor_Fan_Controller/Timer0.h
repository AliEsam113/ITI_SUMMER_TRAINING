/*
 * Timer0.h
 *
 *  Created on: Aug 21, 2022
 *      Author: Ghefo
 */

#ifndef TIMER0_H_
#define TIMER0_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REG_DEF.h"
#include "TIMER_REG_DEF.h"
#include "EXTI_REG_DEF.h"


void timer0_init_overFlowMode(void);
void timer0_init_CtcMode(void);
void timer0_init_PWM(void);
void timer0_set_dutyCycle(u8 duty);

#endif /* TIMER0_H_ */

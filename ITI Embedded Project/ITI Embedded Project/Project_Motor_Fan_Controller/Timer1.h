/*
 * Timer1.h
 *
 *  Created on: Aug 22, 2022
 *      Author: Ghefo
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "REG_DEF.h"
#include "TIMER_REG_DEF.h"
#include "EXTI_REG_DEF.h"

void timer1_init_CtcMode(void);
void Timer1_init_PWM(void);
void Timer1_writDuty(u16 duty);


#endif /* TIMER1_H_ */

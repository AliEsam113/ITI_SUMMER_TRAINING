#ifndef TIMER1_H_
#define TIMER1_H_

#include "TIMER_REG_DEF.h"
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "EXTI_CFG.h"
#include "EXTI_REG_DEF.h"
#include "DIO_interface.h"
void Timer1_init_PWM(void);
void Timer1_writeDuty(u16 duty);



#endif /* TIMER1_H_ */

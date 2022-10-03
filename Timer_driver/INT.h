/*
 * INT.h
 *
 *  Created on: Aug 17, 2022
 *      Author: user
 */

#ifndef INT_H_
#define INT_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_register.h"
#include "avr/interrupt.h"
#include "EXTI_REG_DEF.h"
#include "EXTI_CFG.h"
#include "DIO_interface.h"
void INT0_init(void);
void INT1_init(void);
void INT2_init(void);
void EXTI_init(void);

#endif /* INT_H_ */

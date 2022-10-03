/*
 * EXTI_CFG.h
 *
 *  Created on: Aug 17, 2022
 *      Author: user
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

#define LOGIC_CHANGE 1
#define FALLING_INT0_INT1 2
#define RISING_INT0_INT1 3

#define FALLING_INT2 0
#define RISING_INT2 1
#define INT0_TRIGGER FALLING_INT0_INT1
#define INT1_TRIGGER FALLING_INT0_INT1
#define INT2_TRIGGER FALLING_INT2

#define ENABLE 1
#define DISABLE 0

#define INT0_MODE  ENABLE
#define INT1_MODE  ENABLE
#define INT2_MODE  ENABLE

#endif /* EXTI_CFG_H_ */

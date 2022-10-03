/*
 * DIO_INTERFACE.h
 *
 *  Created on: Aug 13, 2022
 *      Author: user
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "DIO_CONFIG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
enum PORT
{
	PORTA_SEL=1,
	PORTB_SEL=2,
	PORTC_SEL=3,
	PORTD_SEL=4
};
enum DIRECTION
{
	INPUT=0,
	OUTPUT=1
};
enum PIN
{
	PIN0_SEL=0,
	PIN1_SEL=1,
	PIN2_SEL=2,
	PIN3_SEL=3,
	PIN4_SEL=4,
	PIN5_SEL=5,
	PIN6_SEL=6,
	PIN7_SEL=7,
};
enum VALUE
{
	HIGH=1,
	LOW=0
};

void DIO_SetPinDirection(u8 Port,u8 Pin,u8 Direction);
void DIO_SetPinValue(u8 Port,u8 Pin,u8 Value);
u8 DIO_GetPinValue(u8 Port,u8 Pin);

#endif /* DIO_INTERFACE_H_ */

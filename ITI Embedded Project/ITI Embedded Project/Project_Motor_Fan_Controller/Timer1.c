/*
 * Timer1.c
 *
 *  Created on: Aug 22, 2022
 *      Author: Ghefo
 */

#include "Timer1.h"

#define TIMSK         *((volatile u8*)0X59)

void timer1_init_CtcMode(void)
{
	CLR_BIT(SREG,I_BIT); /* Disable global interrupts*/
	// set up timer with prescaler = 64 and CTC mode
	TCCR1B |= (1 << WGM12)|(1 << CS11)|(1 << CS10);
	// initialize counter
	TCNT1 = 0;
	// initialize compare value    /*We will adjust the prescaler and compare value to have interupt every 2 sec*/
	OCR1A = 31249;

	// enable compare interrupt
	TIMSK |= (1 << OCIE1A);

	SET_BIT(SREG,I_BIT);               /*ENABLE GLOBAL INTERRUPT*/
	/*// enable global interrupts
		    sei();
	 */
}
void Timer1_init_PWM(void)
{
	CLR_BIT(SREG,I_BIT); /* Disable global interrupts*/
	SET_BIT(DDRD,PD5);
	TCNT1 = 0;		     /* Count from 0*/

	ICR1  = 2499;        /* Achive 50 HZ frequency for the servo signal*/
	/*
	 * PWM Mode FOC1A = 0
	 * Clear OC1A when reaching compare mode COM1A1 = 1
	 * Mode 14, WGM11 = WGM13 = WGM12 = 1, WGM10 = 0
	 * prescalar FCPU/8 >> CS11 = 1
	 */

	TCCR1A = 0;
	TCCR1A = (1<<WGM11) | (1<<COM1A1);
	TCCR1B = 0;
	TCCR1B = (1<< WGM12) | (1<< WGM13) | (1<<CS11);
	SET_BIT(SREG,I_BIT);
}
void Timer1_writDuty(u16 duty)
{
	OCR1A = duty;    /* Where duty at max = 2499*/
}


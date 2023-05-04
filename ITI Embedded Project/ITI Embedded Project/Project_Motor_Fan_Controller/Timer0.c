/*
 * Timer0.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Ghefo
 */
#include "Timer0.h"
void timer0_init_overFlowMode(void)
{
	CLR_BIT(SREG,I_BIT);
	/* Identity TCNT0 to be 12 (makes one overflow = 0.25 sec)*/
	TCNT0 = 12;   //Timer initial value

	/* Timer0 OV Enable Interrupt*/
	SET_BIT(TIMISK,TOIE0);
	CLR_BIT(TIMISK,OCIE0);

	/* 1 - Non PWM Mode FOC0 = 1
	 * 2 - Normal Mode WGM01 = WGM00 = 0
	 * 3 - Normal Mode COM00 = COM01 = 0
	 * 4 - Clock prescaler 1024, CS00 = CS02 = 1, CS01 = 0
	 */
	TCCR0 = 0;
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<CS02);
	SET_BIT(SREG,I_BIT);

}

void timer0_init_CtcMode(void)
{
	TCNT0 = 0;   //Timer initial value

	/*OCR0 = */
	OCR0 = 250; /* Needed to be written one time only */

#if 0
	/* Timer0 OV Enable Interrupt*/
	SET_BIT(TIMISK,OCIE0);
	CLR_BIT(TIMISK,TOIE0);
#endif

	SET_BIT(DDRB,PB3);
	/* 1 - Non PWM Mode FOC0 = 1
	 * 2 - Compare WGM01 = 1, WGM00 = 0
	 * 3 - Normal Mode COM00 =1, COM01 = 0
	 * 4 - Clock prescaler 1024, CS00 = CS02 = 1, CS01 = 0
	 */
	TCCR0 = 0;
	TCCR0 = (1<<FOC0) | (1<<WGM01) | (1<<COM00) | (1<<CS00);
}

void timer0_init_PWM(void)
{
	CLR_BIT(SREG,I_BIT);
	TCNT0 = 0;   //Timer initial value

	/*OCR0 = */
	OCR0 = 0; /* Needed to be written one time only */

	SET_BIT(DDRB,PB3);   /* Make OC0 Pin output*/
	/* 1 - PWM Mode FOC0 = 0
	 * 2 - Fast PWM Mode  WGM01 = 1, WGM00 = 1
	 * 3 - Normal Mode COM00 =0, COM01 = 1
	 * 4 - Clock prescaler 8, CS00 = CS02 = , CS01 =
	 */
	TCCR0 = 0;
	TCCR0 = (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS01);
	SET_BIT(SREG,I_BIT);
}

void timer0_set_dutyCycle(u8 duty)
{
	OCR0 = duty;
}




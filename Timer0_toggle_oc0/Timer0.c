/*
 * Timer0.c
 *
 *  Created on: Aug 21, 2022
 *      Author: Ghefo
 */
#include "Timer0.h"
#include "DIO_interface.h"
void timer0_init_overFlowMode(void)
{
	CLR_BIT(SREG_R,I_BIT);
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
	SET_BIT(SREG_R,I_BIT);

}

void timer0_init_CtcMode(void)
{
	//CLR_BIT(SREG_R,I_BIT);
	TCNT0 = 0;   //Timer initial value

	/*OCR0 = 244 to achieve 0.25 sec for each interrupt */
	OCR0 = 244; /* Needed to be written one time only */

#if 0
	/* Timer0 OV Enable Interrupt*/
	SET_BIT(TIMISK,OCIE0);
	CLR_BIT(TIMISK,TOIE0);
#endif
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
	/* 1 - Non PWM Mode FOC0 = 1
	 * 2 - Normal Mode WGM01 = 1, WGM00 = 0
	 * 3 - Normal Mode COM00 = COM01 = 0
	 * 4 - Clock prescaler 1024, CS00 = CS02 = 1, CS01 = 0
	 */
	TCCR0 = 0;
	TCCR0 = (1<<FOC0) | (1<<CS00) | (1<<COM00) | (1<<WGM01);
//	SET_BIT(SREG_R,I_BIT);
}
void timer0_PWM(void)
{
		TCNT0 = 0;

		OCR0 = 0;
		DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN3,DIO_u8PIN_OUTPUT);
		/* 1 - Non PWM Mode FOC0 = 1
		 * 2 - Normal Mode WGM01 = 1, WGM00 = 0
		 * 3 - Normal Mode COM00 = COM01 = 0
		 * 4 - Clock prescaler 1024, CS00 = CS02 = 1, CS01 = 0
		 */
		TCCR0 = 0;
		TCCR0 = (1<<COM01) | (1<<WGM00) | (1<<WGM01);
}
void Timer0_writeDuty(u16 duty)
{
	OCR0=duty;
}






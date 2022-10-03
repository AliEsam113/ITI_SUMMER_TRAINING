#include "Timer1.h"

void Timer1_init_PWM(void)
{
	CLR_BIT(SREG_R,I_BIT);
	TCNT1_R=0;
	ICR1_R=2499;
	TCCR1A_R=0;
	TCCR1B_R=0;
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN5,DIO_u8PIN_OUTPUT);
	TCCR1A_R=(1<<WGM11) | (1<<COM1A1);
	TCCR1B_R=(1<<WGM12) | (1<<CS11)| (1<<WGM13);
	SET_BIT(SREG_R,I_BIT);
}
void Timer1_writeDuty(u16 duty)
{
	OCR1A_R=duty;
}



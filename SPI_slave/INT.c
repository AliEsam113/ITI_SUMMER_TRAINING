#include "INT.h"

void INT0_init(void)
{
	CLR_BIT(SREG_R,I_BIT);
	CLR_BIT(DDRD,PD2);
	SET_BIT(PORTD,PD2);
	SET_BIT(GICR_R,INT0_BIT);
	MCUCR |=(INT0_TRIGGER<<0);
	SET_BIT(SREG_R,I_BIT);
}
void INT1_init(void)
{
	CLR_BIT(SREG_R,I_BIT);
	CLR_BIT(DDRD,PD3);
	SET_BIT(PORTD,PD3);
	SET_BIT(GICR_R,INT1_BIT);
	MCUCR |=(INT1_TRIGGER<<2);
	SET_BIT(SREG_R,I_BIT);
}
void INT2_init(void)
{
	DIO_u8SetPinDirection(SREG_R,I_BIT,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DDRB,PB2,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(PORTB,PB2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(GICR_R,INT2_BIT,DIO_u8PIN_OUTPUT);
	MCUCR |=(INT2_TRIGGER<<3);
	DIO_u8SetPinDirection(SREG_R,I_BIT,DIO_u8PIN_OUTPUT);
}
void EXTI_init(void)
{
#if INT0_MODE == ENABLE
	INT0_init();
#endif
#if INT1_MODE == ENABLE
	INT1_init();
#endif
#if INT2_MODE == ENABLE
	INT2_init();
#endif
}

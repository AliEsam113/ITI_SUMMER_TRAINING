#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "avr/io.h"
#include <string.h>
#include "INT.h"
#include "TIMER1_interface.h"
#define f_cpu 8000000
u16 glopal_timer=0;
void Wd_ON(void);
void Wd_Off(void);
void delay(void);

int main()
{
	MTIMER1_voidInit();
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);

	while(1)
	{
		Wd_ON();
		_delay_ms(1000);
		Wd_Off();
	}
	return 1;
}
void Wd_ON(void)
{
	WDTCR=(1<<WDE)|(1<<WDP2)|(1<<WDP1)|(1<<WDP0);
}
void Wd_Off(void)
{
	WDTCR=(1<<WDE)|(1<<WDTOE);
	_delay_ms(4);
	WDTCR=0X00;
}
void delay(void)
{
	glopal_timer++;
	if(glopal_timer==1000)
		glopal_timer=0;
}

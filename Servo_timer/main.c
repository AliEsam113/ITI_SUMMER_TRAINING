#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include <string.h>
#include "INT.h"
#include "adc.h"
#include "Timer1.h"
#define f_cpu 16000000
int main()
{
	Timer1_init_PWM();
	ADC_init();
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PORT_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PORT_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PORT_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PORT_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN3,DIO_u8PIN_HIGH);
	u8 b0,b1,b2,b3;
	u8 c0=DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN0,&b0);
	u8 c1=DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN1,&b1);
	u8 c2=DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN2,&b2);
	u8 c3=DIO_u8GetPinValue(DIO_u8PORTA,DIO_u8PIN3,&b3);
	while(1)
	{
		Timer1_writeDuty(0);
		if(b0)
			Timer1_writeDuty(500);
		else if(b1)
			Timer1_writeDuty(1000);
		else if(b2)
			Timer1_writeDuty(1500);
		else if(b3)
			Timer1_writeDuty(2000);
		else
			Timer1_writeDuty(0);

	}
	return 1;
}




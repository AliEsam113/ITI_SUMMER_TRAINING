#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include <string.h>
#include "uart.h"
#include "TIMER1_interface.h"
int main()
{
	UART_init();
	LCD_vidinit();
	MTIMER1_voidInit();
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
	u8 entered,saved;
	u16 duty=200;
	while(1)
	{
		UART_recieveString(entered);
		if(!strcmp(entered,"increase."))
		{
			duty+=50;
			MTIMER1_voidSetDuty(duty);
			UART_sendString(entered);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
		else if(!strcmp(entered,"decrease."))
		{
			duty-=50;
			MTIMER1_voidSetDuty(duty);
			UART_sendString(entered);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		else if(!strcmp(entered,"cw."))
		{
			MTIMER1_voidSetDuty(duty);
			UART_sendString(entered);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		else if(!strcmp(entered,"ccw."))
		{
			MTIMER1_voidSetDuty(duty);
			UART_sendString(entered);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PIN_HIGH);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PIN_LOW);
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		else if(!strcmp(entered,"rock."))
		{
			UART_sendString(entered);
			LCD_vidwritestring(0,0,"rock");
			LCD_vidwritedata('V');
			LCD_vidwritestring(0,9,"rock");
			if(!strcmp(saved,"siccors"))
			{
				LCD_vidwritestring(1,3,"WIN");
				_delay_ms(1500);
			}
			else if (!strcmp(saved,"paper"))
			{
				LCD_vidwritestring(1,3,"LOSE");
				_delay_ms(1500);
			}
			else
			{
				LCD_vidwritestring(1,3,"STALEMATE");
				_delay_ms(500);
			}
		}
		else if(!strcmp(entered,"paper."))
		{
			UART_sendString(entered);
			LCD_vidwritestring(0,0,"paper");
			LCD_vidwritedata('V');
			LCD_vidwritestring(0,9,"rock");
			if(!strcmp(saved,"rock"))
			{
				LCD_vidwritestring(1,3,"WIN");
				_delay_ms(1500);
			}
			else if (!strcmp(saved,"siccors"))
			{
				LCD_vidwritestring(1,3,"LOSE");
				_delay_ms(1500);
			}
			else
			{
				LCD_vidwritestring(1,3,"STALEMATE");
				_delay_ms(1500);
			}
		}
		else if(!strcmp(entered,"siccors."))
		{
			UART_sendString(entered);
			LCD_vidwritestring(0,0,"siccors");
			LCD_vidwritedata('V');
			LCD_vidwritestring(0,9,"rock");
			if(!strcmp(saved,"paper"))
			{
				LCD_vidwritestring(1,3,"WIN");
				_delay_ms(1500);
			}
			else if (!strcmp(saved,"rock"))
			{
				LCD_vidwritestring(1,3,"LOSE");
				_delay_ms(1500);
			}
			else
			{
				LCD_vidwritestring(1,3,"STALEMATE");
				_delay_ms(1500);
			}
		}
	}
	return 1;
}

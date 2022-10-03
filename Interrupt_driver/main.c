#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "KPD_interface.h"
#include <string.h>
#include "INT.h"
#include "adc.h"
void Reset();
u8 i=0;
#define NUMBER_OF_OVERFLOWS_HALF_SEC 2
u8 globalFlag = 0;
void Success();
void Failed();
int main()
{
	KPD_voidInit();
	LCD_vidinit();
	EXTI_init();
	ADC_init();
	u8 Pressed_Key;
	u32 Temp;
	u32 Intensity;
	u32 Sensor_Reading=0;
	u32 Van;
	char entered_password[10]="";
	char * saved_password="123";
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);

	while(1)
	{
		while(1)
		{
			//Sensor_Reading=ADC_ReadChannel(ADC_CHANNEL_0);
		//	Van=Sensor_Reading*4.88;
			Temp=Van/10.0;
			_delay_ms(100);
			Intensity=ADC_ReadChannel(ADC_CHANNEL_3);
			Pressed_Key=KPD_u8GetPressedKey();
			if(Pressed_Key!=NOT_PRESSED)
			{
				if(Pressed_Key=='c')
				{
					i=0;

					LCD_vidwritecommand(lcd_clr);
					continue;
				}
				if(Pressed_Key=='=')
				{
					LCD_vidwritecommand(lcd_clr);
					break;
				}
				entered_password[i]=Pressed_Key;
				LCD_vidwritedata(Pressed_Key);
				i++;
			}

		}
		if(!strcmp(entered_password,saved_password))
		{
			Success();
			LCD_vidwritecommand(lcd_clr);
			LCD_vidwritestring(0,0,"Temp=");
			LCD_voidDisplayIntegar(Temp);
			LCD_vidwritedata('C');
			LCD_vidwritestring(1,0,"Inten=");
			LCD_voidDisplayIntegar(Intensity);
		}
		else
		{
			Failed();

		}


	}
}
void Success()
{
	LCD_vidwritestring(0,5,"Success");
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_LOW);
}
void Failed()
{
	LCD_vidwritestring(0,5,"Failed");
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);
}
void Reset()
{
	LCD_vidwritecommand(lcd_clr);
	LCD_vidwritestring(0,0,"Enter password : ");
	i=0;
	LCD_setposition(1,0);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);
}
ISR (INT0_vect)
{
	Reset();
}
#if 0
ISR(TIMER0_OVF_vect)
{
	globalFlag++;
	TCNT0 = 12;  /* Identity TCNT0 to be 12 (makes one overflow = 0.25 sec)*/
	if(globalFlag == NUMBER_OF_OVERFLOWS_HALF_SEC)
	{
		TOG_BIT(PORTA,PA0);
		globalFlag = 0;
	}
}
#endif

ISR(TIMER0_COMP_vect)
{
	globalFlag++;
}


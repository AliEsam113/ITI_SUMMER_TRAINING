/*
 * main.c
 *
 *  Created on: Aug 14, 2022
 *      Author: sama
 */

#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "KPD_interface.h"
#include <string.h>
u8 index=0;
int main()
{
	KPD_voidInit();
	LCD_vidinit();
	DIO_u8SetPortDirection(DIO_u8PORTA,0b00001111);
	u8 Pressed_Key;
	char entered_password[10]="";
	char * saved_password="123";

	LCD_vidwritecommand(lcd_clr);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);

	while(1)
	{


		while(1)
		{
			Pressed_Key=KPD_u8GetPressedKey();
			if(Pressed_Key!=NOT_PRESSED)
			{
				if(Pressed_Key=='c')
				{
					index=0;
					LCD_vidwritecommand(lcd_clr);
					continue;
				}
				if(Pressed_Key=='=')
				{
					break;
				}
				entered_password[index]=Pressed_Key;
				LCD_vidwritedata(Pressed_Key);
				index++;
			}

		}
		LCD_vidwritecommand(lcd_clr);
		if(!strcmp(entered_password,saved_password))
		{
			LCD_vidwritestring(0,5,"Success");
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
		}
		else
		{
			LCD_vidwritestring(0,5,"Failed");
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
	}
}

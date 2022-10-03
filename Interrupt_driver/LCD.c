#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "lcd_config.h"
#include "LCD.h"
#include <avr/delay.h>
#include <stdio.h>
#include <stdlib.h>
#define f_cpu 8000000

extern void LCD_vidwritecommand (u8 command)
{
	//RW=0
	DIO_u8SetPinValue (control_port,RW,DIO_u8PIN_LOW);
	//RS=0
	DIO_u8SetPinValue (control_port,RS,DIO_u8PIN_LOW);
	//Data
	DIO_u8SetPortValue (data_port,command);
	//start execution E=1
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_LOW);
}
extern void LCD_vidwritedata (u8 data)
{
	//RW=0
	DIO_u8SetPinValue (control_port,RW,DIO_u8PIN_LOW);
	//RS=0
	DIO_u8SetPinValue (control_port,RS,DIO_u8PIN_HIGH);
	//Data
	DIO_u8SetPortValue (data_port,data);
	//start execution E=1
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(control_port,E,DIO_u8PIN_LOW);
}
extern void LCD_vidinit (void)
{
	DIO_u8SetPinDirection(control_port,RS,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(control_port,RW ,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(control_port,E,DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(data_port,0b11111111);
	_delay_ms (50);
	LCD_vidwritecommand(0b00111100);
	_delay_ms (2);
	LCD_vidwritecommand(0b00001110);
	_delay_ms (2);
	LCD_vidwritecommand(0b00000001);
}
void LCD_setposition(u8 row , u8 column)
{
	if(row==0){
		LCD_vidwritecommand(128+column);
	}
	else if (row==1){
		LCD_vidwritecommand(128+64+column);
	}
}
extern void LCD_vidwritestring (u8 line,u8 column,u8 string[])
{
	u8 i=0;
	LCD_setposition(line,column);
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}
extern void LCD_vidwritestringoncursor (u8 string[])
{
	u8 i=0;
	_delay_ms(2);
	while (string[i]!= 0)
	{
		LCD_vidwritedata(string[i]);
		_delay_ms(2);
				i++;
	}
}


void LCD_voidDisplayIntegar(u32 COPY_u32Number)
{
	u8 LOCAL_u8Num[10]={0};
	s16 i=0;
	u32 LOCAL_u32Remainder;
	if(COPY_u32Number==0)
	{
		LCD_vidwritedata('0');
	}

	if(COPY_u32Number>0)
	{
		while(COPY_u32Number!=0)
		{
			LOCAL_u32Remainder=COPY_u32Number%10;
			LOCAL_u8Num[i]=LOCAL_u32Remainder;
			COPY_u32Number=COPY_u32Number/10;
			i++;
		}
		i--;
		while(i>=0)
		{
			LCD_vidwritedata(LOCAL_u8Num[i]+48);
			i--;
		}
	}
}

void LCD_voidDisplaySpecialChar(u8* Ptr_u8PtrChar,u8 CGRam_index,u8 Copy_u8RowNum,u8 Copy_u8ColNum)
{
	LCD_setposition( Copy_u8RowNum, Copy_u8ColNum);
	LCD_vidwritedata(CGRam_index);
	u8 Local_u8address;
	u8 Local_u8Index;
	if (CGRam_index < 8)
	{
		Local_u8address= CGRam_index * 8;
		Local_u8address=SET_BIT(Local_u8address,6);
		LCD_vidwritecommand(Local_u8address);
		for(Local_u8Index = 0;Local_u8Index < 8;Local_u8Index++)
		{
			LCD_vidwritedata(Ptr_u8PtrChar[Local_u8Index]);
		}
	}
	LCD_vidwritecommand(0x02);

}

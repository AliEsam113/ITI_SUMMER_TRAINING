/*
  * DIO_INTERFACE.c
 *
 *  Created on: Aug 13, 2022
 *      Author: user
 */
#include "DIO_INTERFACE.h"



void DIO_SetPinDirection(u8 Port,u8 Pin,u8 Direction)
{
	switch(Port)
	{
		case PORTA_SEL:
			if(Direction==INPUT)
			{
				CLR_BIT(DDRA_R,Pin);
			}
			else if(Direction==OUTPUT)
			{
				SET_BIT(DDRA_R,Pin);
			}
			break;
		case PORTB_SEL:
			if(Direction==INPUT)
			{
				CLR_BIT(DDRB_R,Pin);
			}
			else if(Direction==OUTPUT)
			{
				SET_BIT(DDRB_R,Pin);
			}
			break;
		case PORTC_SEL:
			if(Direction==INPUT)
			{
				CLR_BIT(DDRC_R,Pin);
			}
			else if(Direction==OUTPUT)
			{
				SET_BIT(DDRC_R,Pin);
			}
			break;
		case PORTD_SEL:
			if(Direction==INPUT)
			{
				CLR_BIT(DDRD_R,Pin);
			}
			else if(Direction==OUTPUT)
			{
				SET_BIT(DDRD_R,Pin);
			}
			break;
        default:
            break;
	}
}
void DIO_SetPinValue(u8 Port,u8 Pin,u8 Value)
{
	switch(Port)
		{
			case PORTA_SEL:
				if(Value==HIGH)
				{
					SET_BIT(PORTA_R,Pin);
				}
				else if(Value==LOW)
				{
					CLR_BIT(PORTA_R,Pin);
				}
				break;
			case PORTB_SEL:
				if(Value==HIGH)
				{
					SET_BIT(PORTB_R,Pin);
				}
				else if(Value==LOW)
				{
					CLR_BIT(PORTB_R,Pin);
				}
				break;
			case PORTC_SEL:
				if(Value==HIGH)
				{
					SET_BIT(PORTC_R, Pin);
				}
				else if(Value==LOW)
				{
					CLR_BIT(PORTC_R, Pin);
				}
				break;
			case PORTD_SEL:
				if(Value==HIGH)
				{
					SET_BIT(PORTD_R, Pin);
				}
				else if(Value==LOW)
				{
					CLR_BIT(PORTD_R, Pin);
				}
				break;
            default:
                break;

		}
}
u8 DIO_GetPinValue(u8 Port,u8 Pin)
{
	switch(Port)
	{
	case PORTA_SEL:
		return GET_BIT(PORTA_R,Pin);
	case PORTB_SEL:
		return GET_BIT(PORTB_R,Pin);
	case PORTC_SEL:
		return GET_BIT(PORTC_R, Pin);
	case PORTD_SEL:
		return GET_BIT(PORTD_R, Pin);
	default:
		return 0;
	}
}

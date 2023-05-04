/*
 * motor_fan.c
 *
 *  Created on: Sep 5, 2022
 *      Author: moham
 */

#include "REG_DEF.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "adc.h"
#include "Timer0.h"
#include "Timer1.h"
#include "util/delay.h"
#include "uart.h"
#include "lcd.h"
#include "avr/interrupt.h"

#define Reading_Channel 0
u8 x = 0, y = 0, z = 0;
u8 flag = 0;
u8 fan = 0;

int main(void)
{
	CLR_BIT(DDRD,PD7);
	SET_BIT(PIND,PD7);
	/*Fan PIn*/
	SET_BIT(DDRB,PB0);
	CLR_BIT(PORTB,PB0);

	/*Failure Pin*/
	SET_BIT(DDRD,PD5);
	SET_BIT(PORTD,PD5);
	/*Overheating Pin*/
	SET_BIT(DDRA,PA4);
	SET_BIT(PORTA,PA4);
	//////////////////////////////////
	ADC_init();
	LCD_init();
	timer0_init_PWM();
	timer1_init_CtcMode();
	UART_init();

	CLR_BIT(DDRD,PD3);

	u16 Temp_Reading = 0;
	u8 speed;

	while(1)
	{
		/*Read the temprature using ADC*/
		Temp_Reading = ADC_ReadChannel(Reading_Channel);
		Temp_Reading = ((float)Temp_Reading * 500)/ 1023;
		LCD_goToRowColumn(0,0);
		LCD_displayString("Temp ");
		LCD_intgerToString(Temp_Reading);

		if(fan == 1)
		{
			timer0_set_dutyCycle(0);
		}
		/*Check the temperature to control the fan*/
		if(Temp_Reading > 70 && fan == 0)
		{
			SET_BIT(PORTB,PB0);
			CLR_BIT(PORTA,PA4);
			flag = 1;
		}
		else
		{
			CLR_BIT(PORTB,PB0);
			SET_BIT(PORTA,PA4);
			flag = 0;
		}
		if(GET_BIT(PIND,PD3) == 1)
		{
			speed = UART_recieveByte();
			_delay_ms(200);
		}

		/*Control the motor using timer0*/
		if(GET_BIT(PIND,PD7))
		{
			timer0_set_dutyCycle((u8)((float)speed*255/100));
		}
		else
		{
			timer0_set_dutyCycle(0);
		}
		LCD_goToRowColumn(1,0);
		LCD_displayString("Speed ");
		LCD_intgerToString(speed);
		LCD_displayString(" %");

		/*

		 */
	}
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	if(flag == 1)
	{
		x++;
		if(x == 5)  //Should be 5
		{
			CLR_BIT(PORTB,PB0);
			x = 0;
			z++;
			if(z == 2)
			{
				fan = 1;
				CLR_BIT(PORTB,PB3);
				CLR_BIT(PORTD,PD5);
			}
		}
	}
	else if(fan == 1)
	{
		y++;
		if(y == 5)  // Should be 5
		{
			SET_BIT(PORTD,PD5);
			y = 0;
		}
	}
	else
	{
		x = 0;
		y = 0;
	}
}



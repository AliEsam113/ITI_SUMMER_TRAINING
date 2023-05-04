/*
 * light_controller.c
 *
 *  Created on: Sep 5, 2022
 *      Author: moham
 */
#include "REG_DEF.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "lcd.h"
#include "I2C_Slave.h"
#include "avr/interrupt.h"

#define I_BIT       7

int main(void)
{
	/***************************interrupts****************************/
	/*INT0 input  */
	GICR = 1<<INT0;		/* Enable INT0*/
	MCUCR = 1<<ISC01;  /* Trigger INT0 on falling edge */
	SET_BIT(SREG,I_BIT);     /* Enable Global Interrupt */

	CLR_BIT(DDRD,PD2);
	SET_BIT(PIND,PD2);

	/******************************************************************/
	LCD_init();
	TWI_init_slave(); // Function to initilaize slave
	/*SET PINs PD0 : PD3 output*/
	SET_BIT(DDRD,PD4);
	SET_BIT(DDRD,PD5);
	SET_BIT(DDRD,PD6);
	SET_BIT(DDRD,PD7);

	u16 led;
	while(1)
	{
		/*************************The driver of I2C is from Google*************************************/
		TWI_match_read_slave(); //Function to match the slave address and slave dirction bit(read)
		led = TWI_read_slave(); // Function to read data
		LCD_clearScreen();
		LCD_displayString("option ");
		LCD_intgerToString(led);
		if (led == 11)
		{
			SET_BIT(PORTD,PD4);
			CLR_BIT(PORTD,PD5);
			CLR_BIT(PORTD,PD6);
			CLR_BIT(PORTD,PD7);
		}
		else if (led == 12)
		{
			CLR_BIT(PORTD,PD4);
			SET_BIT(PORTD,PD5);
			CLR_BIT(PORTD,PD6);
			CLR_BIT(PORTD,PD7);
		}
		else if (led == 13)
		{
			CLR_BIT(PORTD,PD4);
			CLR_BIT(PORTD,PD5);
			SET_BIT(PORTD,PD6);
			CLR_BIT(PORTD,PD7);
		}
		else if (led == 14)
		{
			CLR_BIT(PORTD,PD4);
			CLR_BIT(PORTD,PD5);
			CLR_BIT(PORTD,PD6);
			SET_BIT(PORTD,PD7);
		}
		else if (led == 15)
		{
			SET_BIT(PORTD,PD4);
			SET_BIT(PORTD,PD5);
			CLR_BIT(PORTD,PD6);
			CLR_BIT(PORTD,PD7);
		}
		else if (led == 16)
		{
			CLR_BIT(PORTD,PD4);
			CLR_BIT(PORTD,PD5);
			SET_BIT(PORTD,PD6);
			SET_BIT(PORTD,PD7);
		}
	}
	return 0;
}
ISR(INT0_vect)
{
	/*For reseting after Failure*/
	CLR_BIT(PORTD,PD4);
	CLR_BIT(PORTD,PD5);
	CLR_BIT(PORTD,PD6);
	CLR_BIT(PORTD,PD7);
	LCD_clearScreen();

}

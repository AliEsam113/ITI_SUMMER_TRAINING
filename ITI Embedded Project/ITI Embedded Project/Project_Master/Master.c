/*
 * Master.c
 *
 *  Created on: Sep 5, 2022
 *      Author: moham
 */

#include "REG_DEF.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "lcd.h"
#include "keypad.h"
#include "uart.h"
#include "avr/interrupt.h"
#include "I2C_Master.h"

#define I_BIT       7
#define MCUCR_ISC01  1
#define MCUCR_ISC00  0
#define GICR_INT0  6

s32 LCD_ReadInput();

u8 current_screen = 1;
u8 interrupt = 0;
int main(void)
{
	/*The reset button using interrupt*/

	/***************************interrupts****************************/
	/*INT0 input  */
	GICR = 1<<INT0 | 1<<INT1;		/* Enable INT0 and INT1*/
	MCUCR = 1<<ISC01 | 1<<ISC00;  /* Trigger INT0 on rising edge */
	//SET_BIT(SREG,I_BIT);     // Doesn't work as one of the interrupts will work and not the two of them so we use sei
	sei();			/* Enable Global Interrupt ********From Google */

	CLR_BIT(DDRD,PD2);
	SET_BIT(PIND,PD2);

	CLR_BIT(DDRD,PD3);
	SET_BIT(PIND,PD3);
	/******************************************************************/



	/**/
	LCD_init();
	UART_init();
	TWI_init_master();

	SET_BIT(PORTC,PC2);
	SET_BIT(DDRC,PC2);


	SET_BIT(DDRC,PC7);
	CLR_BIT(PORTC,PC7);


	s8 key;
	s16 speed = 0;
	s16 led = 0;
	_delay_ms(200); //if system failure happen more than one time to avoid displaying control lighting
	if(interrupt == 0 && GET_BIT(PIND,PD2) == 1)
	{
		LCD_goToRowColumn(0,0);
		LCD_displayString("1 Control motor");
		LCD_goToRowColumn(1,0);
		LCD_displayString("2 Control Lighting");
	}
	while(1)
	{
		if (current_screen == 1 && interrupt == 1 && GET_BIT(PIND,PD2) == 1)
		{
			LCD_clearScreen();
			LCD_goToRowColumn(0,0);
			LCD_displayString("1 Control motor");
			LCD_goToRowColumn(1,0);
			LCD_displayString("2 Control Lighting");
			interrupt = 0;
		}
		if(GET_BIT(PIND,PD2) == 0)
		{
			LCD_goToRowColumn20(0,0);
			LCD_displayString("System Failure");
			UART_sendByte(0);
			SET_BIT(PORTC,PC7);
			_delay_ms(250);
			CLR_BIT(PORTC,PC7);
		}
		if(interrupt == 0)
		{
			key = KeyPad_getPressedKey();
		}
		if(key == 1 || ((key == -1 && current_screen == 2) && GET_BIT(PIND,PD2) == 1))
		{
			LCD_clearScreen();
			LCD_goToRowColumn(0,0);
			LCD_displayString("Speed :");
			current_screen = 2;
			interrupt = 0;
			speed = LCD_ReadInput();
			if(speed != -1)
			{
				if (speed >100)
				{
					LCD_clearScreen();
					LCD_displayString("Invalid speed ");
					LCD_goToRowColumn20(1,0);
					LCD_displayString("to go back enter ");
					LCD_goToRowColumn20(2,0);
					LCD_displayString("1 to control motor");
					LCD_goToRowColumn20(3,0);
					LCD_displayString("2 to control light");
				}
				else
				{
					LCD_displayString(" %");
					LCD_goToRowColumn20(1,0);
					LCD_displayString("to go back enter ");
					LCD_goToRowColumn20(2,0);
					LCD_displayString("1 to control motor");
					LCD_goToRowColumn20(3,0);
					LCD_displayString("2 to control light");
					/*Control the speed using UART*/
					UART_sendByte(speed);
					SET_BIT(PORTC,PC7);
					_delay_ms(250);
					CLR_BIT(PORTC,PC7);
				}

			}

		}
		else if(key == 2 || ((interrupt == 1 && current_screen == 3) && GET_BIT(PIND,PD2) == 1))
		{
			LCD_clearScreen();
			LCD_goToRowColumn(0,0);
			LCD_displayString("FL:11, FR:12, F:15");
			LCD_goToRowColumn(1,0);
			LCD_displayString("RL:13, RR:14, R:16");
			current_screen = 3;
			interrupt = 0;
			LCD_goToRowColumn20(2,0);
			led = LCD_ReadInput();
			if(led != -1)
			{
				if(led < 11 || led > 16)
				{
					LCD_clearScreen();
					LCD_displayString("Invalid option ");
					LCD_goToRowColumn20(1,0);
					LCD_displayString("to go back enter ");
					LCD_goToRowColumn20(2,0);
					LCD_displayString("1 to control motor");
					LCD_goToRowColumn20(3,0);
					LCD_displayString("2 to control light");
				}
				else
				{
					LCD_clearScreen();
					LCD_displayString("option ");
					LCD_intgerToString(led);
					LCD_goToRowColumn20(1,0);
					LCD_displayString("to go back enter ");
					LCD_goToRowColumn20(2,0);
					LCD_displayString("1 to control motor");
					LCD_goToRowColumn20(3,0);
					LCD_displayString("2 to control light");

					// Function to initialize TWI
					TWI_start(); // Function to send start condition
					TWI_write_address(address+write); // Function to write address and data direction bit(write) on SDA
					TWI_write_data(led);      // Function to write data in slave
					TWI_stop(); // Function to send stop condition
					_delay_ms(10); // Delay of 10 mili second
				}

			}

		}
	}
	return 0;
}

s32 LCD_ReadInput(){
	s8 Local_u8PressedKey = 0xFF;
	s32 Local_input = 0;
	u8 counter = 0;
	while(1){
		Local_u8PressedKey = KeyPad_getPressedKey();
		if(Local_u8PressedKey != 0xFF){
			if(Local_u8PressedKey == 'k' && counter != 0)
			{
				break;
			}
			else if(Local_u8PressedKey == -1)
			{
				return -1;
			}
			else if(Local_u8PressedKey != 'k' && Local_u8PressedKey != 'd')
			{
				if(counter != 0)
				{
					Local_input *= 10;
					Local_input += Local_u8PressedKey;
				}
				else
				{
					Local_input = Local_u8PressedKey;
				}
				counter++;
				LCD_intgerToString(Local_u8PressedKey);
			}
			else if(counter != 0 && Local_u8PressedKey == 'd')
			{
				LCD_sendCommand(0x10);
				LCD_displayCharacter(' ');
				LCD_sendCommand(0x10);
				Local_input /= 10;
				counter--;
			}
		}
	}
	return Local_input;
}

ISR(INT0_vect)
{
	UART_sendByte(0);
	SET_BIT(PORTC,PC7);
	_delay_ms(250);
	CLR_BIT(PORTC,PC7);
	CLR_BIT(PORTC,PC2);
}

ISR(INT1_vect)
{
	LCD_clearScreen();
	while(GET_BIT(PIND,PD3) == 0)
	{
		LCD_goToRowColumn20(0,0);
		LCD_displayString("Overheating, ");
		LCD_goToRowColumn20(1,0);
		LCD_displayString("Cooling on");
		interrupt = 1;
	}
	LCD_clearScreen();

}

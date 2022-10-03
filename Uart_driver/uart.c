/*
 * uart.c
 *
 *  Created on: Aug 24, 2022
 *      Author: Ghefo
 */
#include "uart.h"

#define UBRR_VALUE ((Frequancy/(8*USART_BAUDRATE))-1)

void UART_init(void)
{
	SET_BIT(UCSRA,U2X);    /* Configure UART double speed rate*/

	/******************** UCSRB Config ************************/
	/* RXCIE = TXCIE = UDRIE = 0  (No interrupt Mode)
	 * RXEN = TXEN = 1 (Enable receive and transmit)
	 * UCSZ2 = 0 (8-bit data size)
	 * RXB8 & TXB8 not used
	 */
	UCSRB = 0;
	UCSRB = (1<<RXEN) | (1<<TXEN);

	/******************** UCSRC Config ************************/
	/* URSEL  = 1 to enable writing on UCSRC
	 * UMSEL  = 0 (Asynchronous mode)
	 * UPM1:0 = 0 (Disable parity)
	 * USBS   = 0 (One bit stop bit)
	 * UCSZ1  = UCSZ0 = 1 (8-bit data size)
	 * UCPOL  = 0  (0 for Asynch. mode)
	 */
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1 <<UCSZ0);

	/* Write data in UBRR*/
	UBRRH = 0;
	UBRRL = 12;
}



void UART_sendByte(const u8 data)
{
	/*UDRE is 1 once UDR register is empty*/
	while(!GET_BIT(UCSRA,UDRE));
	/*Once polling finished (UDR is empty) load ur new data in the UDR register*/
	UDR = data;
}
u8   UART_recieveByte(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}
void UART_sendString(const char* str)
{
	while(*str != '0x00')
	{
		UART_sendByte(*str);
		str++;
	}
}

void UART_recieveString(char* str)
{
	u8 i = 0;
	str[i] = UART_recieveByte();
	while(str[i-1] != '0x00')
	{
		i++;
		str[i] = UART_recieveByte();
	}
	str[i]= '0x00';
}

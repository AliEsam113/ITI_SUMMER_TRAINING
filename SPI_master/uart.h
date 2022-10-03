/*
 * uart.h
 *
 *  Created on: Aug 24, 2022
 *      Author: Ghefo
 */

#ifndef UART_H_
#define UART_H_

#include"avr/io.h"
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

/**********************************************************************************
 	 	 	 	 	 	 	 	 	 MACROS, typedefs
 *********************************************************************************/
#define USART_BAUDRATE     9600
#define Frequancy          1000000

#define UBRR *((volatile u16*)0x29)
/**********************************************************************************
 	 	 	 	 	 	 	 	 	 Function Prototypes
 *********************************************************************************/
void UART_init(void);
void UART_sendByte(const u8 data);
u8   UART_recieveByte(void);
void UART_sendString(const char* str);
void UART_recieveString(char* str);

#endif /* UART_H_ */

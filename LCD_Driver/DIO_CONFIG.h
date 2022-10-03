/*
 * DIO_CONFIG.h
 *
 *  Created on: Aug 13, 2022
 *      Author: user
 */

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_

#define PORTA_R *((u8 *)0x3B)
#define DDRA_R *((u8 *)0x3A)
#define PINA_R *((u8 *)0x39)

#define PORTB_R *((u8 *)0x38)
#define DDRB_R *((u8 *)0x37)
#define PINB_R *((u8 *)0x36)

#define PORTC_R *((u8 *)0x35)
#define DDRC_R *((u8 *)0x34)
#define PINC_R *((u8 *)0x33)

#define PORTD_R *((u8 *)0x32)
#define DDRD_R *((u8 *)0x31)
#define PIND_R *((u8 *)0x30)



#endif /* DIO_CONFIG_H_ */

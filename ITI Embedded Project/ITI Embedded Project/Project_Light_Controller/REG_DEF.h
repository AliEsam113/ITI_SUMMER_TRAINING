#ifndef REG_DEF_H
#define REG_DEF_H

#define PA0 0
#define PA1 1
#define PA2 2
#define PA3 3
#define PA4 4
#define PA5 5
#define PA6 6
#define PA7 7

#define PB0 0
#define PB1 1
#define PB2 2
#define PB3 3
#define PB4 4
#define PB5 5
#define PB6 6
#define PB7 7

#define PC0 0
#define PC1 1
#define PC2 2
#define PC3 3
#define PC4 4
#define PC5 5
#define PC6 6
#define PC7 7

#define PD0 0
#define PD1 1
#define PD2 2
#define PD3 3
#define PD4 4
#define PD5 5
#define PD6 6
#define PD7 7

#define DDRA *((volatile u8 *)0x3A)
#define DDRB *((volatile u8 *)0x37)
#define DDRC *((volatile u8 *)0x34)
#define DDRD *((volatile u8 *)0x31)

#define PORTA *((volatile u8 *)0x3B)
#define PORTB *((volatile u8 *)0x38)
#define PORTC *((volatile u8 *)0x35)
#define PORTD *((volatile u8 *)0x32)

#define PINA *((volatile u8 *)0x39)
#define PINB *((volatile u8 *)0x36)
#define PINC *((volatile u8 *)0x33)
#define PIND *((volatile u8 *)0x30)

#endif

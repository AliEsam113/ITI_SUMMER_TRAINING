#ifndef TIMER_REG_DEF_H
#define TIMER_REG_DEF_H

#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define OCIE0   1
#define TOIE0   0

#define I_BIT       7

#define TCCR0  *((volatile u8*)0x53)
#define TCNT0  *((volatile u8*)0x52)
#define OCR0   *((volatile u8*)0x5C)
#define TIMISK *((volatile u8*)0x59)
#define TIFR   *((volatile u8*)0x58)

#endif

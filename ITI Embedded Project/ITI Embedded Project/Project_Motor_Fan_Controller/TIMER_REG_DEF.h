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

#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

#define ICNC1   7
#define ICES1   6
/* bit 5 reserved */
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#define I_BIT       7

#define TCCR0    *((volatile u8*)0x53)
#define TCNT0    *((volatile u8*)0x52)
#define OCR0     *((volatile u8*)0x5C)

#define TIMISK   *((volatile u8*)0x59)
#define TIFR     *((volatile u8*)0x58)

#define TCCR1A   *((volatile u8*) 0x4F)
#define TCCR1B   *((volatile u8*) 0x4E)
#define TCNT1    *((volatile u16*)0x4C)
#define OCR1A    *((volatile u16*)0x4A)
#define OCR1B    *((volatile u16*)0x48)
#define ICR1     *((volatile u16*)0x46)



#endif

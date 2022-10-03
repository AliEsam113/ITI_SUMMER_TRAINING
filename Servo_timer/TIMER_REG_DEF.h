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

#define WGM10   0
#define WGM11   1
#define FOC1B   2
#define FOC1A   3
#define COM1B0  4
#define COM1B1  5
#define COM1A0  6
#define COM1A1  7

#define CS10    0
#define CS11    1
#define CS12    2
#define WGM12   3
#define WGM13   4
#define ICES1   6
#define ICNC1   7

#define ICR1_R   *((volatile u16*)0x46)
#define TCCR0_R  *((volatile u8*)0x53)
#define TCNT0_R  *((volatile u8*)0x52)
#define OCR0_R   *((volatile u8*)0x5C)
#define TIMISK_R *((volatile u8*)0x59)
#define TIFR_R   *((volatile u8*)0x58)

#define TCCR1A_R   *((volatile u8*)0x4F)
#define TCCR1B_R   *((volatile u8*)0x4E)
#define TCNT1_R   *((volatile u16*)0x4C)
#define OCR1A_R  *((volatile u16*)0x4A)
#define OCR1B_R   *((volatile u16*)0x48)



#endif

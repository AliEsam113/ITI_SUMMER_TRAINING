#ifndef EXTI_REG_DEF_H
#define EXTI_REG_DEF_H

#define I_BIT       7
#define INT0_BIT    6
#define INT1_BIT    7
#define INT2_BIT    5
#define ISC11_BIT   3
#define ISC10_BIT   2
#define ISC01_BIT   1
#define ISC00_BIT   0

#define SREG   *((volatile u8*)0x5F)
#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)

#endif

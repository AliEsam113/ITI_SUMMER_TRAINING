#define I_BIT 7
#define INT0_BIT 6
#define INT1_BIT 7
#define INT2_BIT 5

#define ISC11_BIT 3
#define ISC10_BIT 2
#define ISC01_BIT 1
#define ISC00_BIT 0


#define SREG_R	 	*((volatile u8*)0x5F)
#define MCUCR_R	 	*((volatile u8*)0x55)
#define MCUCSR_R	*((volatile u8*)0x54)
#define GICR_R	 	*((volatile u8*)0x5B)
#define GIFR_R	 	*((volatile u8*)0x5A)

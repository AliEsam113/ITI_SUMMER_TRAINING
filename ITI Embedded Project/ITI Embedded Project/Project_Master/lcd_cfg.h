#ifndef LCD_CFG_H_
#define LCD_CFG_H_

/* LCD HW Pins */
#define RS PD4
#define RW PD5
#define E  PD6

#define LCD_CTRL_PORT       PORTD
#define LCD_CTRL_PORT_DIR   DDRD

#define LCD_DATA_PORT       PORTB
#define LCD_DATA_PORT_DIR   DDRB

/* LCD Commands */
#define CLEAR_COMMAND                0x01
#define TWO_LINE_LCD_Eight_BIT_MODE  0x38
#define TWO_LINE_LCD_FOUR_BIT_MODE   0x28
#define CURSOR_OFF                   0x0C
#define CURSOR_ON                    0x0E
#define SET_CURSOR_LOCATION          0x80 

#define LCD_MODE  TWO_LINE_LCD_Eight_BIT_MODE



#endif

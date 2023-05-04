#ifndef LCD_H_
#define LCD_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG_DEF.h"
#include "avr/delay.h"


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
void LCD_init(void);
void LCD_sendCommand(u8 command);
void LCD_displayCharacter(u8 data);
void LCD_displayString(const char *Str);
void LCD_clearScreen(void);
void LCD_goToRowColumn(u8 row,u8 col);
void LCD_displayStringRowColumn(u8 row,u8 col,const char *Str);
void LCD_intgerToString(u16 data);

#endif /* LCD_H_ */

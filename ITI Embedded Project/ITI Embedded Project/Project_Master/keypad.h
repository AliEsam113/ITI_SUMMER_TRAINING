#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "REG_DEF.h"
#include "avr/delay.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

/* Keypad configurations for number of rows and columns */
#define N_col 3
#define N_row 4

/* Keypad Port Configurations */
#define KEYPAD_PORT_OUT PORTA
#define KEYPAD_PORT_IN  PINA
#define KEYPAD_PORT_DIR DDRA 

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Function responsible for getting the pressed keypad key
 */
s8 KeyPad_getPressedKey(void);

#endif /* KEYPAD_H_ */

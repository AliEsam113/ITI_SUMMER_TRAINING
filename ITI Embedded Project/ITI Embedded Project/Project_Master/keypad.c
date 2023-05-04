#include "keypad.h"
#include "REG_DEF.h"
/*******************************************************************************
 *                      Functions Prototypes(Private)                          *
 *******************************************************************************/

extern u8 interrupt;

#if (N_col == 3)
/*Function responsible for mapping the switch number for 4*3 keypad*/
static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number);
#elif (N_col == 4)
/*Function responsible for mapping the switch number for 4*4 keypad*/
static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number);
#endif

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
s8 KeyPad_getPressedKey(void)
{
	u8 output_col,input_row;
	u8 pressed_key_order = 0;
	while(1)
	{
		if(interrupt == 1)
		{
			return -1;
		}
		for(output_col=0;output_col<N_col;output_col++) /* loop for columns */
		{
			/* 
			 * each time only one of the column pins will be output and 
			 * the rest will be input pins include the input_row pins
			 */ 
			KEYPAD_PORT_DIR = (0b00010000<<output_col);
			
			/* 
			 * clear the output pin column in this trace and enable the internal 
			 * pull up resistors for the rows pins
			 */ 
			KEYPAD_PORT_OUT = (~(0b00010000<<output_col));

			for(input_row=0;input_row<N_row;input_row++) /* loop for rows */
			{
				if(!GET_BIT(KEYPAD_PORT_IN,input_row)) /* if the switch is press in this input_row */
				{
					pressed_key_order = (input_row*N_col)+output_col+1;
					while(GET_BIT(KEYPAD_PORT_IN,input_row)==0);
					#if (N_col == 3)
						return KeyPad_4x3_adjustKeyNumber(pressed_key_order);
					#elif (N_col == 4)
						return KeyPad_4x4_adjustKeyNumber(pressed_key_order);
					#endif
				}
			}
		}
	}	
}

#if (N_col == 3) 

static u8 KeyPad_4x3_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
		case 1: return 1; break;
		case 2: return 2; break;
		case 3: return 3; break;
		case 4: return 4; break;
		case 5: return 5; break;
		case 6: return 6; break;
		case 7: return 7; break;
		case 8: return 8; break;
		case 9: return 9; break;
		case 10: return 'd'; // ASCII Code of *
				 break;
		case 11: return 0;
				 break;		
		case 12: return 'k'; // ASCII Code of #
				 break;
		default: return button_number;								 						
	}
} 

#elif (N_col == 4)
 
static u8 KeyPad_4x4_adjustKeyNumber(u8 button_number)
{
	switch(button_number)
	{
		case 1: return 7; 
				break;
		case 2: return 8; 
				break;
		case 3: return 9; 
				break;
		case 4: return '%'; // ASCII Code of %
				break;
		case 5: return 4; 
				break;
		case 6: return 5;
				break;
		case 7: return 6; 
				break;
		case 8: return '*'; /* ASCII Code of '*' */
				break;		
		case 9: return 1; 
				break;
		case 10: return 2; 
				break;
		case 11: return 3; 
				break;
		case 12: return '-'; /* ASCII Code of '-' */
				break;
		case 13: return 13;  /* ASCII of Enter */
				break;			
		case 14: return 0; 
				break;
		case 15: return '='; /* ASCII Code of '=' */
				break;
		case 16: return '+'; /* ASCII Code of '+' */
				break;
		default: return button_number;								 						
	}
} 

#endif

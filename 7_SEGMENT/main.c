#include "avr/io.h"
#include "avr/delay.h"
#include "DIO_INTERFACE.h"
void Display(u8 counter);

int main(void)
{
	//PORTC display tens
	//PORTD display ones
	DIO_SetPinDirection(PORTA_SEL,PIN0_SEL,OUTPUT);
	DIO_SetPinDirection(PORTA_SEL,PIN1_SEL,OUTPUT);

	DIO_SetPinDirection(PORTC_SEL,PIN0_SEL,OUTPUT);
	DIO_SetPinDirection(PORTC_SEL,PIN1_SEL,OUTPUT);
	DIO_SetPinDirection(PORTC_SEL,PIN2_SEL,OUTPUT);
	DIO_SetPinDirection(PORTC_SEL,PIN3_SEL,OUTPUT);

	DIO_SetPinDirection(PORTD_SEL,PIN0_SEL,OUTPUT);
	DIO_SetPinDirection(PORTD_SEL,PIN1_SEL,OUTPUT);
	DIO_SetPinDirection(PORTD_SEL,PIN2_SEL,OUTPUT);
	DIO_SetPinDirection(PORTD_SEL,PIN3_SEL,OUTPUT);
	u8 counter=0;
	DIO_SetPinValue(PORTA_R,PIN0_SEL,LOW);
	DIO_SetPinValue(PORTA_R,PIN0_SEL,HIGH);
	while(1)
	{
		_delay_ms(500);
		Display(counter);
		if(counter==30)
		{
			DIO_SetPinValue(PORTA_R,PIN0_SEL,!DIO_GetPinValue(PORTA_R,PIN0_SEL));
			DIO_SetPinValue(PORTA_R,PIN1_SEL,!DIO_GetPinValue(PORTA_R,PIN1_SEL));
			counter=0;
			_delay_ms(5000);

		}
		counter++;
	}
	return 0;

}

void Display(u8 counter)
{
	switch(counter)
			{
				case 0 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 1 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 2 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 3 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 4 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 5 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 6 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 7 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 8 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 9 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 10 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;

				case 11 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 12 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 13 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 14 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 15 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 16 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 17 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 18 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 19 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 20 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 21 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 22 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 23 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 24 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 25 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 26 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 27 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 28 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 29 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,HIGH);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,HIGH);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;
				case 30 :
					DIO_SetPinValue(PORTD_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN1_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTD_R,PIN3_SEL,LOW);


					DIO_SetPinValue(PORTC_R,PIN0_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN1_SEL,HIGH);
					DIO_SetPinValue(PORTC_R,PIN2_SEL,LOW);
					DIO_SetPinValue(PORTC_R,PIN3_SEL,LOW);
					break;


				}
}


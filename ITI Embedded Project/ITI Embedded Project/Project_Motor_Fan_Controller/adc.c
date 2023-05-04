#include "adc.h"


void ADC_init(void)
{
	/*What we need to identify*/
	/* 1 - REF Volt
	 * 2 - ADC Result RIGHT or LEFT
	 * 3 - INIT default channel number
	 * 4 - PRESCALER Select */


	/* Choose AREF as Vref */
	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);

	/* Right adjusted ADC result buffer*/
	CLR_BIT(ADMUX,ADLAR);

	/* Default channel number is CH0 single ended*/
	ADMUX &= 0xE0;

	/* ADC Enable */
	SET_BIT(ADCSRA,ADEN);

	/* Prescaler selected to be 8*/
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
}


u16 ADC_ReadChannel(u8 channelNumber)
{
	/* Select channel number*/
	channelNumber &= 0x07;
	ADMUX &= 0xE0;
	ADMUX |= channelNumber;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADSC);

	/* Polling on ADIF flag */
	while(!GET_BIT(ADCSRA,ADIF));

	/* Clear the ADIF flag by writing a logical one to it */
	SET_BIT(ADCSRA,ADIF);

	/*Return ADC data buffer (10 bits) */
	return ADC;
}


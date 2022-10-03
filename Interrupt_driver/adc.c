#include "adc.h"

void ADC_init()
{
	SET_BIT(ADMUX_R,REFS0);
	CLR_BIT(ADMUX_R,REFS1);
	ADCSRA_R &= 0b11111000;
	ADCSRA_R |= 7;
	SET_BIT(ADCSRA_R,ADEN);
}
u32 ADC_ReadChannel(u8 channelNumber)
{
	ADMUX_R &= 0b11100000;
	ADMUX_R |=channelNumber;
	SET_BIT(ADCSRA_R,ADSC);
	while(!GET_BIT(ADCSRA_R,ADIF));
	SET_BIT(ADCSRA_R,ADIF);
	return ADC_R;
}

#include <util/delay.h>
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD.h"
#include <string.h>
#include "INT.h"
#include "adc.h"

u32 Intensity=0,Sensor_Reading=0,Van=0,Temp=0;
void Take_readings();
int main()
{
	timer0_init_CtcMode();

}
void Take_readings()
{
 u32 counter1=0;
 u32 counter2=0;
	counter1++;
	counter2++;
	if(counter1==4000)
	{
		Intensity=ADC_ReadChannel(ADC_CHANNEL_3);
		counter1=0;
	}
	if(counter2==4000)
	{
		Sensor_Reading=ADC_ReadChannel(ADC_CHANNEL_0);
		Van=Sensor_Reading*4.88;
		Temp=Van/10.0;

		counter2=0;
	}
}

ISR(TIMER1_COMPB_vect)
{
	Take_readings();
}



#include <util/delay.h>
#include "DIO_interface.h"
#include "LCD.h"
#include "ADC.h"
#include "INT.h"

int main()
{
	LCD_vidinit();
	ADC_init();
	u32 Sensor_Reading=0;
	u32 Van;
	u32 Temperature=0;

	while(1)
	{
		Sensor_Reading=ADC_ReadChannel(ADC_CHANNEL_0);
		LCD_vidwritestring(0,0,"Temp is :");
		Van=Sensor_Reading*4.88;
		Temperature=Van/10.0;
		LCD_voidDisplayIntegar(Temperature);

	}
}



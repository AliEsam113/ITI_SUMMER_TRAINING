/*
 * adc.h
 *
 *  Created on: Aug 18, 2022
 *      Author: user
 */

#ifndef ADC_H_
#define ADC_H_

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "DIO_register.h"
#include "ADC_REG_DEF.h"

#define ADC_CHANNEL_0 0
#define ADC_CHANNEL_1 1
#define ADC_CHANNEL_2 2
#define ADC_CHANNEL_3 3
#define ADC_CHANNEL_4 4
#define ADC_CHANNEL_5 5
#define ADC_CHANNEL_6 6
#define ADC_CHANNEL_7 7

void ADC_init();
u32 ADC_ReadChannel(u8 channelNumber);

#endif /* ADC_H_ */

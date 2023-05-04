/*
 * ADC_RED_DEF.h
 *
 *  Created on: Aug 18, 2022
 *      Author: Ghefo
 */

#ifndef ADC_REG_DEF_H_
#define ADC_REG_DEF_H_

#ifndef ADC_REG_DEF_H
#define ADC_REG_DEF_H

#define MUX0    0
#define MUX1    1
#define MUX2    2
#define MUX3    3
#define MUX4    4
#define ADLAR   5
#define REFS0   6
#define REFS1   7

#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADMUX  *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define ADCL   *((volatile u8*) 0x24)
#define ADCH   *((volatile u8*) 0x25)
#define ADC    *((volatile u16*)0x24)



#endif



#endif /* ADC_REG_DEF_H_ */


#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ADC_REG_DEF.h"

/*Function prototypes*/
void ADC_init(void);
u16  ADC_ReadChannel(u8 channelNumber);

#endif /* ADC_H_ */

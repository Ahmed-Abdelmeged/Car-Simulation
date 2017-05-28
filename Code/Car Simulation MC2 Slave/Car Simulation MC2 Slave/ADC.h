/*
 * ADC.h
 *
 * Created: 4/30/2016 06:12:09 م
 *  Author: Ahmed
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "INIT_PIN.h"
#include "TYPE_DATE.h"
#include "micro_config.h"

void ADC_init(void);
uint16 ADC_Read(uint8 CH_num);



#endif /* ADC_H_ */
/*
 * ADC.c
 *
 * Created: 4/30/2016 06:12:22 م
 *  Author: Ahmed
 */ 
 #include "ADC.h"
  void ADC_init(void)
  {
  ADMUX=0;
  ADCSRA|=(1<<ADEN)|(1<<ADPS1)|(1<<ADPS0);
  }
  uint16 ADC_Read(uint8 CH_num)
  {
  
  CH_num &= 0x07;
  ADMUX &= 0xE0;
  ADMUX |= CH_num;
  SET_BIT(ADCSRA,ADSC);
  while(BIT_IS_CLEAR(ADCSRA,ADIF));
  SET_BIT(ADCSRA,ADIF);
  return ADC;
  }
/*
 * PWM.c
 *
 * Created: 5/25/2016 05:20:06 ?
 *  Author: Ahmed
 */ 
 #include "PWM.h"


 void PWM1_init(uint8 speed1)
 {
 TCNT0=0;
 OCR0A=speed1;
 TCCR0A=(1<<WGM00)|(1<<WGM01)|(1<<COM0A1);
 TCCR0B=(1<<CS01)|(1<<CS00);
DDRG|=(1<<PG5);
 }

 
 void PWM2_init(uint8 speed2)
 {
 
 TCNT0=0;
 OCR0B=speed2;
 TCCR0A=(1<<WGM00)|(1<<WGM01)|(1<<COM0B1);
 TCCR0B=(1<<CS01)|(1<<CS00);
 DDRB|=(1<<PB7);

 }

 
 void PWM3_init(uint8 speed3)
 {
  TCNT0=0;
  OCR2A=speed3;
  TCCR2A=(1<<WGM20)|(1<<WGM21)|(1<<COM2A1);
  TCCR2B=(1<<CS21)|(1<<CS20);
 DDRH|=(1<<PH6);

 }

 
 void PWM4_init(uint8 speed4)
 {
   TCNT0=0;
   OCR2B=speed4;
   TCCR2A=(1<<WGM20)|(1<<WGM21)|(1<<COM2B1);
   TCCR2B=(1<<CS21)|(1<<CS20);
   DDRB|=(1<<PB4);

 }
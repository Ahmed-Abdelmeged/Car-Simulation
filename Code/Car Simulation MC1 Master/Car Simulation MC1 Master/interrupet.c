/*
 * interrupet.c
 *
 * Created: 5/29/2016 6:08:28 PM
 *  Author: ismail
 */ 

#include "interrupet.h"

extern uint16 x;


void INT0_init(void)
{
	SREG &= ~(1<<7);
	 EIMSK|=(1<<INT0);
	DDRD &= ~(1<<PD0);
 EICRA|=(1<<ISC00)|(1<<ISC01);
	SREG |= (1<<7);
}


void INT1_init(void)
{
	SREG &= ~(1<<7);
	EIMSK|=(1<<INT1);
	DDRD &= ~(1<<PD1);
	EICRA|=(1<<ISC10)|(1<<ISC11);
	SREG |= (1<<7);
}



void INT2_init(void)
{
	SREG &= ~(1<<7);
	EIMSK|=(1<<INT2);
	DDRD &= ~(1<<PD2);
	EICRA|=(1<<ISC20)|(1<<ISC21);
	SREG |= (1<<7);
}


void INT3_init(void)
{
	SREG &= ~(1<<7);
	EIMSK|=(1<<INT3);
	DDRD &= ~(1<<PD3);
	EICRA|=(1<<ISC30)|(1<<ISC31);
	SREG |= (1<<7);
}



void INT6_init(void)
{
	SREG &= ~(1<<7);
	EIMSK|=(1<<INT6);
	DDRE &= ~(1<<PE6);
	EICRB|=(1<<ISC60)|(1<<ISC61);
	SREG |= (1<<7);
}


void INT5_init(void)
{
	SREG &= ~(1<<7);
	EIMSK|=(1<<INT5);
	DDRE &= ~(1<<PE5);
	EICRB|=(1<<ISC50)|(1<<ISC51);
	SREG |= (1<<7);
}


ISR(INT0_vect)
{
	PWM1_init(0);
	PWM2_init(x);
	PWM4_init(0);
	PWM3_init(x);
	LCD_DisplayStringRowCol(1,0,"Forward         ");
			LCD_DisplayStringRowCol(3,0,"                ");

}
ISR(INT1_vect)
{
	
	PWM2_init(0);
	PWM1_init(x);
	PWM3_init(0);
	PWM4_init(x);
		LCD_DisplayStringRowCol(1,0,"Back            ");
		LCD_DisplayStringRowCol(3,0,"                ");

}
ISR(INT2_vect)
{
	
	PWM1_init(0);
	PWM2_init(x);
	PWM3_init(0);
	PWM4_init(x);
		LCD_DisplayStringRowCol(1,0,"Right           ");
				LCD_DisplayStringRowCol(3,0,"                ");


}
ISR(INT3_vect)
{
	
	PWM2_init(0);
	PWM1_init(x);
	PWM4_init(0);
	PWM3_init(x);
		LCD_DisplayStringRowCol(1,0,"Left            ");
				LCD_DisplayStringRowCol(3,0,"                ");


}

ISR(INT6_vect)
{
	
	PWM1_init(0);
	PWM2_init(0);
	PWM3_init(0);
	PWM4_init(0);
			LCD_DisplayStringRowCol(1,0,"Hand Break         ");
				LCD_DisplayStringRowCol(3,0,"                ");

}

ISR(INT5_vect)
{
	
	PORTJ=0b00001111;
	_delay_ms(25);
	PORTJ=0;
	_delay_ms(25);

}
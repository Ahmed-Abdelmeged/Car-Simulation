/*
 * Car Simulation MC1 Master.c
 *
 * Created: 5/25/2016 04:56:42 م
 * Author : Ahmed
 */ 

 #include "LCD.h"
 #include "ADC.h"
#include "PWM.h"
#include "interrupet.h"
#include "SPI.h"

uint16 speed;
uint8 x;

int main(void)
{
LCD_Init();
ADC_init();
SPI_Master_init();
LCD_DisplayStringRowCol(0,0,"Speed :   ");
LCD_DisplayStringRowCol(1,0,"Stop           ");

LCD_DisplayStringRowCol(2,0,"Lights OFF    ");
PORTD=0b00001111;
PORTE=0b01000000;
DDRC=0xff;
DDRK=0;
DDRD=0xff;
DDRL=0xff;
DDRJ=0xff;
while(1)
{
	PORTK=0xFF;

	INT0_init();
	INT1_init();
	INT2_init();
	INT3_init();
	INT6_init();

speed=ADC_Read(0);
x=speed/4;


LCD_GoToRowCol(0,8);
LCD_IntToString(x);
LCD_DisplayStringRowCol(0,12,"km/h");




if(BIT_IS_CLEAR(PINK,PK0))
{
	PORTC=0b01111000;
	LCD_DisplayStringRowCol(2,0,"Lights On      ");
}

if(BIT_IS_CLEAR(PINK,PK1))
{
		PORTJ=0b00001111;
		_delay_ms(10);
		PORTJ=0;
				_delay_ms(10);

}


if(BIT_IS_CLEAR(PINK,PK2))
{
	PORTD=0b11000000;
		LCD_DisplayStringRowCol(3,0,"Mist Lampes ON     ");

}


if(BIT_IS_CLEAR(PINK,PK3))
{
	PORTD=0;
	PORTC=0;
		LCD_DisplayStringRowCol(2,0,"Lights OFF         ");
		LCD_DisplayStringRowCol(3,0,"Mist Lampes OFF    ");

}


}

}





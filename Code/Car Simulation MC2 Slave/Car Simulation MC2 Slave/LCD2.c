/*
 * LCD2.c
 *
 * Created: 5/30/2016 12:36:23 AM
 *  Author: ismail
 */ 

#include "LCD2.h"

void LCD2_Init(void){
	LCD2_CTRL_PORT_DIR |= (1<<E2) | (1<<RS2) | (1<<RW2);
	#if (DATA_BITS_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD2_DATA_PORT |= 0xF0;
	#else
	LCD2_DATA_PORT |= 0x0F;
	#endif
	LCD2_SendCommand(FOUR_BITS_DATA_MODE);
	LCD2_SendCommand(Two_Lines_Four_Bits);
	#elif (DATA_BITS_MODE == 8)
	LCD2_DATA_PORT_DIR |= 0xFF;
	LCD2_SendCommand(Two_Lines_Eight_Bits);
	#endif
	LCD2_SendCommand(Cursor_Off);
	LCD2_SendCommand(Clear_LCD);
}

void LCD2_SendCommand(uint8 command)
{
	CLEAR_BIT(LCD2_CTRL_PORT,RS2);
	CLEAR_BIT(LCD2_CTRL_PORT,RW2);
	_delay_ms(1);
	SET_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD2_DATA_PORT = ( command & 0xF0 );
	#else
	LCD2_DATA_PORT = ( (command>>4) & 0x0F);
	#endif
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	SET_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);

	#ifdef UPPER_PORT_PINS
	LCD2_DATA_PORT = ( (command<<4) & 0xF0 );
	#else
	LCD2_DATA_PORT = ( command & 0x0F);
	#endif
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	#elif (DATA_BITS_MODE == 8)
	LCD2_DATA_PORT = command;
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	#endif
}

void LCD2_DisplayCharacter(uint8 data)
{
	SET_BIT(LCD2_CTRL_PORT,RS2);
	CLEAR_BIT(LCD2_CTRL_PORT,RW2);
	_delay_ms(1);
	SET_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	#if (DATA_BITS_MODE == 4)
	#ifdef UPPER_PORT_PINS
	LCD2_DATA_PORT = ( data & 0xF0 );
	#else
	LCD2_DATA_PORT = ( (data>>4) & 0x0F);
	#endif
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	SET_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);

	#ifdef UPPER_PORT_PINS
	LCD2_DATA_PORT = ( (data<<4) & 0xF0 );
	#else
	LCD2_DATA_PORT = ( data & 0x0F);
	#endif
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	SET_BIT(LCD_CTRL_PORT,E2);
	_delay_ms(1);
	#elif (DATA_BITS_MODE == 8)
	LCD2_DATA_PORT = data;
	_delay_ms(1);
	CLEAR_BIT(LCD2_CTRL_PORT,E2);
	_delay_ms(1);
	#endif
}

void LCD2_DisplayString( const char *str)
{
	while ( (*str) != '\0')
	{
		LCD2_DisplayCharacter(*str);
		++str;
	}
}

void LCD2_GoToRowCol(uint8 row , uint8 col)
{ uint8 address;
	switch (row)
	{
		case 0 : address = col;
		break;
		case 1 : address = col + 0x40;
		break;
		case 2 : address = col + 0x10;
		break;
		case 3 : address = col + 0x50;
		break;
	}
	LCD2_SendCommand(address|Set_Cursor_Location);
}

void LCD2_DisplayStringRowCol(uint8 row , uint8 col, const char *str)
{
	LCD2_GoToRowCol(row ,col);
	LCD2_DisplayString( str);
}

void LCD2_IntToString(int data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD2_DisplayString(buff);

}

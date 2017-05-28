/*
 * LCD.c
 *
 * Created: 4/27/2016 05:50:35 م
 *  Author: Ahmed
 */ 
 #include "LCD.h"
 
 void LCD_Init(void){
	 LCD_CTRL_PORT_DIR |= ((1<<E) | (1<<RS) | (1<<RW));
	 #if (DATA_BITS_MODE == 4)
	 #ifdef UPPER_PORT_PINS
	 LCD_DATA_PORT |= 0xF0;
	 #else
	 LCD_DATA_PORT |= 0x0F;
	 #endif
	 LCD_SendCommand(FOUR_BITS_DATA_MODE);
	 LCD_SendCommand(Two_Lines_Four_Bits);
	 #elif (DATA_BITS_MODE == 8)
	 LCD_DATA_PORT_DIR |= 0xFF;
	 LCD_SendCommand(Two_Lines_Eight_Bits);
	 #endif
	 LCD_SendCommand(Cursor_Off);
	 LCD_SendCommand(Clear_LCD);
 }

 void LCD_SendCommand(uint8 command)
 {
	 CLEAR_BIT(LCD_CTRL_PORT,RS);
	 CLEAR_BIT(LCD_CTRL_PORT,RW);
	 _delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #if (DATA_BITS_MODE == 4)
	 #ifdef UPPER_PORT_PINS
	 LCD_DATA_PORT = ( command & 0xF0 );
	 #else
	 LCD_DATA_PORT = ( (command>>4) & 0x0F);
	 #endif
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);

	 #ifdef UPPER_PORT_PINS
	 LCD_DATA_PORT = ( (command<<4) & 0xF0 );
	 #else
	 LCD_DATA_PORT = ( command & 0x0F);
	 #endif
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #elif (DATA_BITS_MODE == 8)
	 LCD_DATA_PORT = command;
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #endif
 }

 void LCD_DisplayCharacter(uint8 data)
 {
	 SET_BIT(LCD_CTRL_PORT,RS);
	 CLEAR_BIT(LCD_CTRL_PORT,RW);
	 _delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #if (DATA_BITS_MODE == 4)
	 #ifdef UPPER_PORT_PINS
	 LCD_DATA_PORT = ( data & 0xF0 );
	 #else
	 LCD_DATA_PORT = ( (data>>4) & 0x0F);
	 #endif
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);

	 #ifdef UPPER_PORT_PINS
	 LCD_DATA_PORT = ( (data<<4) & 0xF0 );
	 #else
	 LCD_DATA_PORT = ( data & 0x0F);
	 #endif
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 SET_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #elif (DATA_BITS_MODE == 8)
	 LCD_DATA_PORT = data;
	 _delay_ms(1);
	 CLEAR_BIT(LCD_CTRL_PORT,E);
	 _delay_ms(1);
	 #endif
 }

 void LCD_DisplayString( const char *str)
 {
	 while ( (*str) != '\0')
	 {
		 LCD_DisplayCharacter(*str);
		 ++str;
	 }
 }

 void LCD_GoToRowCol(uint8 row , uint8 col)
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
	 LCD_SendCommand(address|Set_Cursor_Location);
 }

 void LCD_DisplayStringRowCol(uint8 row , uint8 col, const char *str)
 {
	 LCD_GoToRowCol(row ,col);
	 LCD_DisplayString( str);
 }

 void LCD_IntToString(int data)
 {
	 char buff[16];
	 itoa(data,buff,10);
	 LCD_DisplayString(buff);

 }

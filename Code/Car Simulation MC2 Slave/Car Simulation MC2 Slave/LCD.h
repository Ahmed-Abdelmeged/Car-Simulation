/*
 * LCD.h
 *
 * Created: 4/27/2016 05:50:02 م
 *  Author: Ahmed
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "INIT_PIN.h"
#include "TYPE_DATE.h"
#include "micro_config.h"

#define DATA_BITS_MODE 8
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif


#define RS PC0
#define RW PC1
#define E  PC2
#define LCD_CTRL_PORT PORTC
#define LCD_CTRL_PORT_DIR DDRC
#define LCD_DATA_PORT PORTA
#define LCD_DATA_PORT_DIR DDRA


#define Clear_LCD 0x01
#define FOUR_BITS_DATA_MODE 0x02
#define Two_Lines_Eight_Bits 0x38
#define Two_Lines_Four_Bits 0x28
#define Cursor_Off 0x0c
#define Cursor_On 0x0E
#define Shift_Display_Right 0x1c
#define Shift_Display_Left 0x18
#define Shift_Cursor_Left 0x10
#define Shift_Cursor_Right 0x14
#define Set_Cursor_Location 0x80


void LCD_SendCommand(uint8 command);
void LCD_Init(void);
void LCD_DisplayCharacter(uint8 data);
void LCD_DisplayString( const char *str);
void LCD_GoToRowCol(uint8 row , uint8 col);
void LCD_DisplayStringRowCol(uint8 row , uint8 col, const char *str);
void LCD_IntToString(int data);





#endif /* LCD_H_ */
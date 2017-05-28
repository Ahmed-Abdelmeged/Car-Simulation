/*
 * LCD2.h
 *
 * Created: 5/30/2016 12:35:56 AM
 *  Author: ismail
 */ 


#ifndef LCD2_H_
#define LCD2_H_


#include "INIT_PIN.h"
#include "TYPE_DATE.h"
#include "micro_config.h"

#define DATA_BITS_MODE 8
#if (DATA_BITS_MODE == 4)
#define UPPER_PORT_PINS
#endif


#define RS2 PL0
#define RW2 PL1
#define E2  PL2
#define LCD2_CTRL_PORT PORTL
#define LCD2_CTRL_PORT_DIR DDRL
#define LCD2_DATA_PORT PORTJ
#define LCD2_DATA_PORT_DIR DDRJ


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


void LCD2_SendCommand(uint8 command);
void LCD2_Init(void);
void LCD2_DisplayCharacter(uint8 data);
void LCD2_DisplayString( const char *str);
void LCD2_GoToRowCol(uint8 row , uint8 col);
void LCD2_DisplayStringRowCol(uint8 row , uint8 col, const char *str);
void LCD2_IntToString(int data);



#endif /* LCD2_H_ */
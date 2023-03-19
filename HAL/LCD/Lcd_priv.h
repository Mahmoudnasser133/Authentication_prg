/*
 * Lcd_priv.h
 *
 *  Created on: Feb 19, 2023
 *      Author: NTI
 */

#ifndef LCD_LCD_PRIV_H_
#define LCD_LCD_PRIV_H_

#define LCD_CLEAR 				0x01
#define LCD_RETURN_H 			0x02
#define ENTRY_MODE				0X06
#define CURSOR_ON_DISPLAY_ON	0X0e

#define ADDRESS_ROW_1			0X80
#define ADDRESS_ROW_2			0XC0
#define ADDRESS_ROW_3			0X94
#define ADDRESS_ROW_4			0XD4

#define ADDRESS_CGRAM			0X40
static void H_LCD_void_latchByte(u8 copy_u8Byte);

#endif /* LCD_LCD_PRIV_H_ */

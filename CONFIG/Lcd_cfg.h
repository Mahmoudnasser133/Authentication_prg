/*
 * Lcd_cfg.h
 *
 *  Created on: Feb 19, 2023
 *      Author: NTI
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

 #define LCD_RS_PIN 	DIO_PA3
#define LCD_EN_PIN		DIO_PA2

//if 8 bit mode
#define LCD_D0_PIN		DIO_PB3
#define LCD_D1_PIN		DIO_PB5
#define LCD_D2_PIN		DIO_PB6
#define LCD_D3_PIN		DIO_PB7
/*************************************/
#define LCD_D4_PIN		DIO_PB0
#define LCD_D5_PIN		DIO_PB1
#define LCD_D6_PIN		DIO_PB2
#define LCD_D7_PIN		DIO_PB4

#define _4_BIT_MODE		4
#define FNC_SET_FOUR_BIT_MODE   0x28

#define _8_BIT_MODE		 8
#define FNC_SET_EIGHT_BIT_MODE   0x38

#define LCD_MODE	 _4_BIT_MODE
//#define LCD_MODE	 _8_BIT_MODE

/*
typedef struct{
	s8 Custum_Arr_char[8];
	u8 Custum_Arr_ID;
}Custum_struct_char;
*/
#endif /* LCD_CFG_H_ */

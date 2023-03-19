/*
 * Keypad_cfg.h
 *
 *  Created on: Feb 23, 2023
 *      Author: nasser
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define KEYPAD_R1_PIN     DIO_PC5
#define KEYPAD_R2_PIN     DIO_PC4
#define KEYPAD_R3_PIN     DIO_PC3
#define KEYPAD_R4_PIN     DIO_PC2

#define KEYPAD_C1_PIN     DIO_PD7
#define KEYPAD_C2_PIN     DIO_PD6
#define KEYPAD_C3_PIN     DIO_PD5
#define KEYPAD_C4_PIN     DIO_PD3

u8 keypad[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'o','0','=','+'}};

u8 keypad_col[4]={KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN,KEYPAD_C4_PIN};

#endif /* KEYPAD_CFG_H_ */

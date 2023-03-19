/*
 * Keypad_int.h
 *
 *  Created on: Feb 23, 2023
 *      Author: nasser
 */

#ifndef KEYPAD_KEYPAD_INT_H_
#define KEYPAD_KEYPAD_INT_H_
/*
#define PB1_ID	1
#define PB2_ID	2
#define PB3_ID	3
#define PB4_ID	4
*/
#define ACTIVE_LOW		0
#define ACTIVE_HIGH		1

#define PREESED_KEY			1
#define NO_PRESSED_KEY		0

u8 H_KEYPAD_u8_getPressedKey(void);

#endif /* KEYPAD_KEYPAD_INT_H_ */

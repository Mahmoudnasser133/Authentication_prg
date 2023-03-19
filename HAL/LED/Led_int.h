/*
 * Led_int.h
 *
 *  Created on: Feb 18, 2023
 *      Author: NTI
 */

#ifndef LED_LED_INT_H_
#define LED_LED_INT_H_

#define LED_RED     0
#define LED_BLUE    1
#define LED_GRN     2
#define LED_YELLOW   3

void H_LED_void_turnON(u8 ledID);
void H_LED_void_turnOFF(u8 ledID);
void H_LED_void_toggle(u8 ledID);

#endif /* LED_LED_INT_H_ */

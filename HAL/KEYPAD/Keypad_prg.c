/*
 * Keypad_prg.c
 *
 *  Created on: Feb 23, 2023
 *      Author: nasser
 */

#include "avr/delay.h"
#include "STD_TYPES.h"
#include "Dio_int.h"
#include "Keypad_cfg.h"
#include "Keypad_int.h"

u8 H_KEYPAD_u8_getPressedKey(void)
{
	u8 row,col,val=NO_PRESSED_KEY,read;

	for(row=0;row<4;row++)
	{
		M_Dio_void_setPinValue(KEYPAD_R1_PIN,DIO_HIGH);
		M_Dio_void_setPinValue(KEYPAD_R2_PIN,DIO_HIGH);
		M_Dio_void_setPinValue(KEYPAD_R3_PIN,DIO_HIGH);
		M_Dio_void_setPinValue(KEYPAD_R4_PIN,DIO_HIGH);

		M_Dio_void_setPinValue((KEYPAD_R1_PIN-row),DIO_LOW);

		for(col=0;col<4;col++)
		{
			read=M_Dio_en_getPinValue(keypad_col[col]);
			if(read == ACTIVE_LOW)
			{
				val=keypad[row][col];
				break;
			}
		}
		if(read== ACTIVE_LOW)
		{
			break;
		}

	}

	return val;
}

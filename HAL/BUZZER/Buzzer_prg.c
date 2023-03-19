/*
 * Buzzer_prg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "Dio_int.h"
#include "Buzzer_int.h"

void H_BUZZER_void_turnON(void)
{
	M_Dio_void_setPinValue(BUZZER_PIN, DIO_HIGH);
}

void H_BUZZER_void_turnOFF(void)
{
	M_Dio_void_setPinValue(BUZZER_PIN, DIO_LOW);
}

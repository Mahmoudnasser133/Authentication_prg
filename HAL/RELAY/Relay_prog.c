/*
 * relay_prog.c
 *
 *  Created on: ??�/??�/????
 *      Author: ahmed
 */

#include "Dio_int.h"
#include "Relay_init.h"

void H_relay_void_ON(relayID_t relayID) {
	if (relayID == relayID_1)
		M_Dio_void_setPinValue(RELAY1_PIN, DIO_HIGH);
	else if (relayID == relayID_2)
		M_Dio_void_setPinValue(RELAY2_PIN, DIO_HIGH);
}

void H_relay_void_OFF(relayID_t relayID) {
	if (relayID == relayID_1)
		M_Dio_void_setPinValue(RELAY1_PIN, DIO_LOW);
	else if (relayID == relayID_2)
		M_Dio_void_setPinValue(RELAY2_PIN, DIO_LOW);
}

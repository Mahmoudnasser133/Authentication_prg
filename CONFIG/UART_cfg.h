/*
 * UART_cfg.h
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */

#ifndef UART_CFG_H_
#define UART_CFG_H_
#include "STD_TYPES.h"
typedef struct
{
	Baud_rate		Baud_rate_value;
	Word_Length		Word_leght;
	Parity_mode		parity_Mode;
	Stop_Bits		NO_stopBits;

}UART_config;

#endif /* UART_CFG_H_ */

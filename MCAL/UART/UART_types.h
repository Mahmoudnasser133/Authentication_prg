/*
 * UART_types.h
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */

#ifndef UART_UART_TYPES_H_
#define UART_UART_TYPES_H_

#include "STD_TYPES.h"

typedef enum
{
	Disable,
	Even=2,
	Odd
}Parity_mode;

typedef enum
{
	One_bit,
	Two_bits
}Stop_Bits;

typedef enum
{
	five,
	six,
	seven,
	eight,
	nine=7
}Word_Length;


typedef enum
{
	Baud_rate_9600 = 103,
	Baud_rate_115200 =8,
	Baud_rate_57600 = 16
}Baud_rate;

#endif /* UART_UART_TYPES_H_ */

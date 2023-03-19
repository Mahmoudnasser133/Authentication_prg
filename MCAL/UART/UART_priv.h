/*
 * UART_priv.h
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */

#ifndef UART_UART_PRIV_H_
#define UART_UART_PRIV_H_

#define FCPU_UART	16000000UL

#define PARITY_MASK			0XCF
#define STOP_BIT_MASK		0XF7
#define WORD_LENGTH_MASK	0XF9
#define MAXCOUNTER 			50000
#endif /* UART_UART_PRIV_H_ */

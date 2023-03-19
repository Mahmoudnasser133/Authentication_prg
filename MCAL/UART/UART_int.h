/*
 * UART_int.h
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */

#ifndef UART_UART_INT_H_
#define UART_UART_INT_H_

#include "STD_TYPES.h"
#include "UART_types.h"
#include "UART_priv.h"
#include "UART_cfg.h"
/*
void UART_vInit(unsigned long baud);
void UART_vSendData(char data);
char UART_u8ReceiveData(void);
void UART_vSendstring( char *ptr);
*/

void M_UART_void_int(UART_config *UART_cofig_ptr);

void M_UART_v_SendData(u8 data);

u8 M_UART_u8_ReceiveData(void);

void M_UART_vSendstring( u8 *ptr);

void M_UART_void_receiveByteAsynchCallBack(void (*copy_call_back_ptr_UART)(void));

#endif /* UART_UART_INT_H_ */

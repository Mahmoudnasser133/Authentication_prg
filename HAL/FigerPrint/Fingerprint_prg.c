/*
 * Fingerprint_prg.c
 *
 *  Created on: Mar 17, 2023
 *      Author: NTI
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Lcd_int.h"
#include "UART_int.h"
#include "FingerPrint_int.h"
#include <util/delay.h>



void H_fingerPrint_void_init(UART_config *finger_ptr)
{
	M_UART_void_int(finger_ptr);

}

void H_fingerPrint_void_sendcomnd(const char * command,u8 size )
{
	u8 i;


	for(i=0;i<size;i++)
	{
		M_UART_v_SendData(command[i]);
	}

}

void H_fingerPrint_void_Recivecommand(void )
{
	u8 i;
	u8 command[12];
	for(i=0;i<12;i++)
	{
		command[i] = M_UART_u8_ReceiveData();

		H_LCD_void_sendIntNum(i);

	}



			if(command[9] == 0x00)
			{
				H_LCD_void_sendString("OK");
				H_LCD_void_sendIntNum(command[i]);
			}
			//H_LCD_void_sendIntNum(command[i]);
			//	H_LCD_void_sendData(' ');


	}


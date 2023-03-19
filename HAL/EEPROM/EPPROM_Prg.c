/*
 * EPPROM_Prg.C
 *
 *  Created on: Mar 11, 2023
 *      Author: NTI
 */

#include <avr/delay.h>
#include "STD_TYPES.h"
#include "I2c_priv.h"
#include "I2c_int.h"
#include "EEPROM_int.h"
void H_EEPROM_void_init(IIC_CONFIG *IIC_Config_ptr)
{

	M_I2C_void_Init(IIC_Config_ptr);

}


u8 H_EEPROM_void_writeByte(u16 address,u8 data)
{
	u8 status;
	_delay_ms(300);
//1- step 1 send start
		M_I2c_void_send_start();
//2- check status
		M_I2c_void_getStatus(&status);
		if(status != START_SEND)
		{
			// error return 0;
		}
//3- send SLA + W
	M_I2C_void_write_address( 0XA0 | ( (EEPROM_address_mask & address)>>7 ) );
//4-Check status
	M_I2c_void_getStatus(&status);
			if(status != SLA_W_TRANSMIT_ACK)
			{
				// error return 0;
			}
//5- send reset of byte address
	M_I2C_void_write_data((u8)address);
//6-Check status
  M_I2c_void_getStatus(&status);
		if(status != DATA_TRANSMITTED_ACK)
		{
			// error return 0;
		}
//7 send data
M_I2C_void_write_data(data);

//8-Check status
	M_I2c_void_getStatus(&status);
	if(status != DATA_TRANSMITTED_ACK)
	{
		// error return 0;
	}

//9 - send stop
   M_I2c_void_send_stop();

  return 1;

}



u8 H_EEPROM_void_readByte(u16 address,u8* data)
{
u8 status;
	_delay_ms(300);
//1- step 1 send start
	M_I2c_void_send_start();
//2- check status
	M_I2c_void_getStatus(&status);
		if(status != START_SEND)
		{
			// error return 0;
		}

//3- send SLA + W
	M_I2C_void_write_address( 0XA0 | (EEPROM_address_mask & address)>>7);

//4-Check status
	M_I2c_void_getStatus(&status);
			if(status != SLA_W_TRANSMIT_ACK)
			{
				// error return 0;
			}
//5- send reset of byte address
	M_I2C_void_write_data((u8)address);
//6-Check status
	M_I2c_void_getStatus(&status);
				if(status != DATA_TRANSMITTED_ACK)
				{
					// error return 0;
				}
//7-Repeated start
	M_I2c_void_send_start();
//8- check status
	M_I2c_void_getStatus(&status);
			if(status != REPET_START)
			{
				// error return 0;
			}
// 9- send SLA+R
   M_I2C_void_write_data(0xA0 | 1);

//10 - check status
   M_I2c_void_getStatus(&status);
		if(status != DATA_TRANSMITTED_ACK)
		{
			// error return 0;
		}
//11 - read data
	M_I2c_receiveByte_NoACK(data);
//12 - check status
   M_I2c_void_getStatus(&status);
		 if(status != DATA_RECIVE_ACK)
		 {
			 // error return 0;
		 }
 //13 - send stop
    M_I2c_void_send_stop();

return 1;
}


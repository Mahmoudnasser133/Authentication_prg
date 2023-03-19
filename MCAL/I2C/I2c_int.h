/*
 * I2c_int.h
 *
 *  Created on: Mar 9, 2023
 *      Author: nasser
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_

#include "I2c_priv.h"
#include "I2c_cfg.h"

void M_I2C_void_Init(IIC_CONFIG *IIC_CONFIG_ptr);

void M_I2c_void_send_start(void);

void M_I2c_void_send_stop(void);

void M_I2c_void_receiveByte_ACK(u8 * ptr);

void M_I2c_receiveByte_NoACK(u8 * ptr);

void M_I2C_void_write_address(u8 address);

void M_I2C_void_set_address(u8 address);

void M_I2C_void_write_data(u8 data);

void M_I2c_void_getStatus(u8* status );

u8 M_I2C_void_slave_read(void);

#endif /* MCAL_I2C_I2C_INT_H_ */

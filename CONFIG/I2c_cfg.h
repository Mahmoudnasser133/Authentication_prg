/*
 * I2c_cfg.h
 *
 *  Created on: Mar 9, 2023
 *      Author: nasser
 */

#ifndef CONFIG_I2C_CFG_H_
#define CONFIG_I2C_CFG_H_


#include "STD_TYPES.h"
#include "I2c_types.h"

#define FCPU_I2C	16000000UL

typedef struct
{
	I2C_prescaler			IIC_prescaler;
	I2C_prescaler_value		IIC_prescaler_value;
	Speed_Mode				speed_SCL_Clock;
}IIC_CONFIG;

#endif /* CONFIG_I2C_CFG_H_ */

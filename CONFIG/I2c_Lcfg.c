/*
 * I2c_Lcfg.c
 *
 *  Created on: Mar 15, 2023
 *      Author: nasser
 */

#include "I2c_cfg.h"

IIC_CONFIG I2c_cfg_struct ={I2c_prescaler_1,prescaler_1_value,Fast_speed_400Kbs};

IIC_CONFIG I2c_cfg_struct_RTC ={I2c_prescaler_1,prescaler_1_value,Normal_speed_100Kbs};

/*
 * I2v_types.h
 *
 *  Created on: Mar 9, 2023
 *      Author: nasser
 */

#ifndef MCAL_I2C_I2C_TYPES_H_
#define MCAL_I2C_I2C_TYPES_H_

typedef enum
{
	I2c_prescaler_1,
	I2c_Prescaler_4,
	I2c_Prescaler_16,
	I2c_Prescaler_64
}I2C_prescaler;

typedef enum
{
	prescaler_1_value=1,
	Prescaler_4_value=4,
	Prescaler_16_value=16,
	Prescaler_64_value=64
}I2C_prescaler_value;

typedef enum
{
	Normal_speed_100Kbs = 72,
	Fast_speed_400Kbs = 12,
}Speed_Mode;



#endif /* MCAL_I2C_I2C_TYPES_H_ */

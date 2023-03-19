/*
 * I2c_priv.h
 *
 *  Created on: Mar 9, 2023
 *      Author: nasser
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_

#define TWSR_status_mask		0XF8
#define SLA_W_TRANSMIT_ACK		0X18
#define DATA_TRANSMITTED_ACK	0X28
#define SLA_W_RECIVE_ACK		0X60
#define START_SEND				0X08
#define REPET_START				0X10
#define DATA_RECIVE_NACK		0X58
#define DATA_RECIVE_ACK			0X50

#endif /* MCAL_I2C_I2C_PRIV_H_ */

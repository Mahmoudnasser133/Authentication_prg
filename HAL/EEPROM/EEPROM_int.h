/*
 * EEPROM_int.h
 *
 *  Created on: Mar 11, 2023
 *      Author: NTI
 */

#ifndef HAL_EEPROM_EEPROM_INT_H_
#define HAL_EEPROM_EEPROM_INT_H_

#define EEPROM_address_mask		0x0300

void H_EEPROM_void_init(IIC_CONFIG *IIC_Config_ptr);

u8 H_EEPROM_void_writeByte(u16 address,u8 data);

u8 H_EEPROM_void_readByte(u16 address,u8* data);

#endif /* HAL_EEPROM_EEPROM_INT_H_ */

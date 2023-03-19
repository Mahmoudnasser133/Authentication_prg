/*
 * Authentication_config.h
 *
 *  Created on: Mar 15, 2023
 *      Author: nasser
 */

#ifndef AUTHENTICATION_CONFIG_H_
#define AUTHENTICATION_CONFIG_H_

#define EEPROM_STATUS_ADDRESS		0x10

#define EEPROM_hour_ADDRESS			0x11
#define EEPROM_min_ADDRESS 			0x12
#define EEPROM_second_ADDRESS 		0x13
#define EEPROM_format_ADDRESS 		0x14

#define EEPROM_day_ADDRESS			0x15
#define EEPROM_date_ADDRESS 		0x16
#define EEPROM_mon_ADDRESS	 		0x17
#define EEPROM_year_ADDRESS 		0x18

#define EEPROM_RTC_STATUS_ADDRESS	0x20

#define EEPROM_EMPTY				0XFF

#define WRONG_PASSWORD				0x00
#define CORRECT_PASSWORD			0x01
#define MAX_TRY						3
#endif /* AUTHENTICATION_CONFIG_H_ */

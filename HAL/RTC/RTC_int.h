/*
 * RTC_int.h
 *
 *  Created on: Mar 12, 2023
 *      Author: nasser
 */

#ifndef HAL_RTC_RTC_INT_H_
#define HAL_RTC_RTC_INT_H_

#define hour_12_AM				0x40
#define hour_12_PM				0x60
#define hour_24					0x00

#define Device_Write_address	0xD0			/* Define RTC DS1307 slave address for write operation */
#define Device_Read_address		0xD1			/* Make LSB bit high of slave address for read operation */
#define TimeFormat12			0x40				/* Define 12 hour format */
#define AMPM					0x20



void H_Rtc_void_init(IIC_CONFIG* rtc_ptr);

void H_Rtc_void_set_time(u8 h,u8 m, u8 s,u8 format);

void H_Rtc_void_get_time(u8* h,u8* m, u8* s);

void H_Rtc_void_get_time_str(u8* h,u8* m, u8* s);

void H_RTC_Calendar_Write(u8 _day, u8 _date, u8 _month, u8 _year);	/* function for calendar */

void H_RTC_Read_Calendar(u8* day,u8* date,u8* month, u8* year );

u8 BCD_B(u8 data);

#endif /* HAL_RTC_RTC_INT_H_ */

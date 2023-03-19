/*
 * RTC_prg.c
 *
 *  Created on: Mar 12, 2023
 *      Author: nasser
 */
#include <stdio.h>
#include <string.h>
#include <avr/delay.h>

#include "STD_TYPES.h"
#include "I2c_priv.h"
#include "I2c_int.h"
#include "RTC_priv.h"
#include "RTC_int.h"
#include "Lcd_int.h"

void H_Rtc_void_init(IIC_CONFIG* rtc_ptr)
{
	M_I2C_void_Init(rtc_ptr);
_delay_ms(300);
}


void H_Rtc_void_set_time(u8 h,u8 m, u8 s,u8 format)
{
	h|= format;

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD0);//110100+W
	M_I2C_void_write_data(0x00);
	M_I2C_void_write_data(s);
	M_I2C_void_write_data(m);
	M_I2C_void_write_data(h);
	M_I2c_void_send_stop();
	_delay_ms(300);
}
// void char *
void H_Rtc_void_get_time(u8* h,u8* m, u8* s)
{
	//char buffer[20];

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD0);//110100+W
	M_I2C_void_write_data(0x00);//address second

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD1);//read
	M_I2c_void_receiveByte_ACK(s);
	M_I2c_void_receiveByte_ACK(m);
	M_I2c_receiveByte_NoACK(h);

	*h = *h & 0x1F;
	*h= BCD_B(*h);
	*m= BCD_B(*m);
	*s = BCD_B(*s);

	M_I2c_void_send_stop();


}

void H_Rtc_void_get_time_str(u8* h,u8* m, u8* s)
{
	char buffer[20];

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD0);//110100+W
	M_I2C_void_write_data(0x00);//address second

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD1);//read
	M_I2c_void_receiveByte_ACK(s);
	M_I2c_void_receiveByte_ACK(m);
	M_I2c_receiveByte_NoACK(h);
	M_I2c_void_send_stop();

	if(*h & TimeFormat12)
	{
		sprintf(buffer, "%02x:%02x:%02x ", (*h & 0b00011111), *m, *s);

		if(*h & AMPM )
		{
			strcat(buffer, "PM");
		}
		else
		{
			strcat(buffer, "AM");
		}

	}
	else
	{
		sprintf(buffer, "%02x:%02x:%02x ", (*h & 0b00011111), *m, *s);

	}


	H_LCD_void_sendString(buffer);


}

void H_RTC_Calendar_Write(u8 _day, u8 _date, u8 _month, u8 _year)	/* function for calendar */
{
	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD0);//110100+W
	M_I2C_void_write_data(0x03);//day address

	M_I2C_void_write_data(_day);
	M_I2C_void_write_data(_date);
	M_I2C_void_write_data(_month);
	M_I2C_void_write_data(_year);

	M_I2c_void_send_stop();
	_delay_ms(300);
}

void H_RTC_Read_Calendar(u8* day,u8* date,u8* month, u8* year )
{
	char buffer_2[20];
	char* days[7]= {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD0);//110100+W
	M_I2C_void_write_data(0x03);//day address

	M_I2c_void_send_start();
	M_I2C_void_write_data(0xD1);//110100+R
	M_I2c_void_receiveByte_ACK(day);

	M_I2c_void_receiveByte_ACK(date);
	M_I2c_void_receiveByte_ACK(month);
	M_I2c_receiveByte_NoACK(year);
	M_I2c_void_send_stop();

	sprintf(buffer_2,"%02x/%02x/%02x  %s",*date,*month,*year,days[*day - 1]);
	H_LCD_void_sendString(buffer_2);
}

u8 BCD_B(u8 data)
{
	u8 m,n;
	u8 bin;
	m = (u8) (data>>4) *10;
	n = data & (u8)0x0f;
	bin = m + n;
	return bin;
}

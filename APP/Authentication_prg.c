/*
 * Authentication_prg.c
 *
 *  Created on: Mar 15, 2023
 *      Author: nasser
 */


/******************************************
  INCLUDES
*******************************************/

#include <util/delay.h>
#include <stdio.h>
#include <string.h>
#include "Dio_int.h"
#include "Port_int.h"
#include "Lcd_int.h"
#include "Keypad_int.h"
#include "Led_int.h"
#include "Buzzer_int.h"
#include "I2c_int.h"
#include "EEPROM_int.h"
#include "RTC_int.h"
#include "Buzzer_int.h"
#include "Relay_init.h"
#include "Glint.h"
#include "Exti_int.h"

#include "Authentication_config.h"



/******************************************
   ( global variables)
*******************************************/
u8 EEPROM_Password_address[4]={0X01,0X02,0X03,0X04};
u8 EEPROM_read_data,i,Password_flag=CORRECT_PASSWORD,no_try=0;
u8 h,min,sec;
//char last_login[20];
u8 KEYPAD_read_data;
char * mass;
char  format1;
u8 RTC_hours,RTC_minute,RTC_second,RTC_date,RTC_month,RTC_years,RTC_day,format;
/******************************************
  Global Data (non static global)
*******************************************/
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
extern	IIC_CONFIG I2c_cfg_struct;
extern	IIC_CONFIG I2c_cfg_struct_RTC;
extern const EXTI_cfg Exti_Config_Arr[EXTI_CONFIG_ARR_SIZE];


/******************************************
  Local Functions prototypes
*******************************************/
void Login_First_Time(void);
void User_sign_in(void);
u8 scan_password(void);
void Last_Login_Time_And_Save_NewTime(void);
void trigger_to_ECU2(void);
void Log_out(void);
int main ()
{
/*************************************************
 	 local variables
 *************************************************/


/*************************************************
	 Initializations
 *************************************************/
	Port_Init(PORT_Config_Arr);
	H_LCD_void_Init();
	H_EEPROM_void_init(&I2c_cfg_struct);
	_delay_ms(300);
	H_Rtc_void_init(&I2c_cfg_struct_RTC);
	Enable_Global_INT();

	//external int
	enableInt(Exti_Config_Arr+1);
	setCallBack(Log_out,INT1_id);
while(1)
{
/*****************       login first time   *************************
 *****************							***************************/
	Login_First_Time();
/////////////////	End login first time 	///////////////////////////

/****************	 User Sign in 	**************************************
 ****************					**************************************/
	User_sign_in();
/****************	 last login time	**************************************
****************					**************************************/
	Last_Login_Time_And_Save_NewTime();
/*******************************************************************************/
//send trigger to ECU2//
trigger_to_ECU2();

// open the door//
H_relay_void_ON(relayID_1);
_delay_ms(1000);
H_relay_void_OFF(relayID_1);


/**********************************************************************************/
/****************	 start session Time 	**************************************
****************					        ****************************************/

H_LCD_void_clearScreen();
H_LCD_void_sendString("Time AND Date");
u32 counter = 0;
/******************************************************************/
while(1)
	{

		H_LCD_void_gotoXY(2, 1);
		H_Rtc_void_get_time_str(&RTC_hours, &RTC_minute, &RTC_second);;
		H_LCD_void_gotoXY(3, 1);
		H_RTC_Read_Calendar(&RTC_day, &RTC_date, &RTC_month, &RTC_years);
	counter++;
			if(counter == 10 )
			{
				counter = 0;
				H_LCD_void_clearScreen();
				H_LCD_void_sendString("End Time");

				break;
			}
	}


}
	return 0;
}


u8 scan_password(void)
{
	u8 flag=CORRECT_PASSWORD,i;
	u8 EEPROM_Password_data[4]={EEPROM_EMPTY,EEPROM_EMPTY,EEPROM_EMPTY,EEPROM_EMPTY};

	for(i=0;i<4;i++)
			{
				do
				{
					KEYPAD_read_data = H_KEYPAD_u8_getPressedKey();

				}while(KEYPAD_read_data == NO_PRESSED_KEY);
				_delay_ms(100);
				H_LCD_void_sendData(KEYPAD_read_data);
				_delay_ms(250);
				H_LCD_void_gotoXY(2,1+i);
				H_LCD_void_sendData('*');

				H_EEPROM_void_readByte(EEPROM_Password_address[i], &EEPROM_Password_data[i]);

				if(KEYPAD_read_data != EEPROM_Password_data[i])
				{
					flag = WRONG_PASSWORD;
				}

			}

return flag;
}

void trigger_to_ECU2(void)
{
	M_Dio_void_setPortValue(DIO_PA5, DIO_HIGH);
	_delay_ms(50);
	M_Dio_void_setPortValue(DIO_PA5, DIO_LOW);
}


void Log_out(void)
{
	H_LCD_void_clearScreen();
	H_LCD_void_sendString("End Time");
	H_LED_void_turnON(LED_GRN);

}

void Login_First_Time(void)
{
	//H_EEPROM_void_writeByte(EEPROM_STATUS_ADDRESS,EEPROM_EMPTY);//

	H_EEPROM_void_readByte(EEPROM_STATUS_ADDRESS,&EEPROM_read_data);

	if(EEPROM_read_data == EEPROM_EMPTY)
	{
		H_LCD_void_clearScreen();
		H_LCD_void_sendString("Login First Time");
		H_LCD_void_gotoXY(2, 1);
		H_LCD_void_sendString("Please Set Password");
		H_LCD_void_gotoXY(3, 1);

		for(i=0;i<4;i++)
		{

			do
			{
				KEYPAD_read_data = H_KEYPAD_u8_getPressedKey();

			}while(KEYPAD_read_data == NO_PRESSED_KEY);
			_delay_ms(100);

			H_EEPROM_void_writeByte(EEPROM_Password_address[i] , KEYPAD_read_data );
			H_LCD_void_sendData(KEYPAD_read_data);
			_delay_ms(150);
			H_LCD_void_gotoXY(3,1+i);
			H_LCD_void_sendData('*');

		}
		H_LCD_void_clearScreen();
		H_LCD_void_sendString("Password Saved");
		_delay_ms(400);
	H_EEPROM_void_writeByte(EEPROM_STATUS_ADDRESS,'B');//B for Busy

	}
}

void User_sign_in(void)
{
	H_EEPROM_void_readByte(EEPROM_STATUS_ADDRESS,&EEPROM_read_data);
	 if(EEPROM_read_data == 'B')
	{
		H_LCD_void_clearScreen();
		H_LCD_void_sendString("Enter Password");
		H_LCD_void_gotoXY(2, 1);

		Password_flag = scan_password();

	}


		switch(Password_flag)
		{
			case WRONG_PASSWORD:
					while( Password_flag == WRONG_PASSWORD )
					 {
						no_try++;
						H_LCD_void_clearScreen();
						H_LCD_void_sendString("Wrong Password");
						H_LCD_void_gotoXY(2, 1);
						H_LCD_void_sendString("Please Try Again");
						_delay_ms(400);
						H_LCD_void_clearScreen();
						H_LCD_void_sendString("Enter Password");
						H_LCD_void_gotoXY(2, 1);
						Password_flag = scan_password();

						if(no_try <= MAX_TRY && Password_flag == CORRECT_PASSWORD)
						{
							H_LCD_void_clearScreen();
							H_BUZZER_void_turnOFF();
							H_LCD_void_sendString("Correct Password");
							_delay_ms(400);
							H_LCD_void_clearScreen();
							H_LCD_void_sendString("Welcome Home");
							break;
						}

						else if(no_try == MAX_TRY)
							{
								H_LCD_void_clearScreen();
								H_BUZZER_void_turnON();
								H_LCD_void_sendString("Wait 5 second");
								_delay_ms(5000);
								no_try=0;
							}

					 }
						break;

			case CORRECT_PASSWORD:
					H_LCD_void_clearScreen();
					H_LCD_void_sendString("Correct Password");
					_delay_ms(400);
					H_LCD_void_clearScreen();
					H_LCD_void_sendString("Welcome Home");

					break;
			}

}

void Last_Login_Time_And_Save_NewTime(void)
{
	H_EEPROM_void_readByte(EEPROM_hour_ADDRESS,		&h);
	H_EEPROM_void_readByte(EEPROM_min_ADDRESS,		&min);
	H_EEPROM_void_readByte(EEPROM_second_ADDRESS, 	&sec);
	H_LCD_void_gotoXY(2, 1);
	H_LCD_void_sendString("your last Login");
	H_LCD_void_gotoXY(3, 1);
	H_LCD_void_sendIntNum(h);
	H_LCD_void_sendData(':');
	H_LCD_void_sendIntNum(min);
	H_LCD_void_sendData(':');
	H_LCD_void_sendIntNum(sec);
	//_delay_ms(700);
/************************save new login in EEPROM *******************************/
	H_Rtc_void_get_time(&RTC_hours, &RTC_minute, &RTC_second);

	H_EEPROM_void_writeByte(EEPROM_hour_ADDRESS,	RTC_hours);
	H_EEPROM_void_writeByte(EEPROM_min_ADDRESS,		RTC_minute);
	H_EEPROM_void_writeByte(EEPROM_second_ADDRESS, 	RTC_second);
}




#if 0


	H_EEPROM_void_writeByte(EEPROM_hour_ADDRESS,	RTC_hours);
	H_EEPROM_void_writeByte(EEPROM_min_ADDRESS,		RTC_minute);
	H_EEPROM_void_writeByte(EEPROM_second_ADDRESS, 	RTC_second);

	/*
	H_EEPROM_void_readByte(EEPROM_hour_ADDRESS,		&RTC_hours);
	H_EEPROM_void_readByte(EEPROM_min_ADDRESS,		&RTC_minute);
	H_EEPROM_void_readByte(EEPROM_second_ADDRESS, 	&RTC_second);
	H_EEPROM_void_readByte(EEPROM_date_ADDRESS, 	&RTC_date);
	H_EEPROM_void_readByte(EEPROM_day_ADDRESS, 		&RTC_day);
	H_EEPROM_void_readByte(EEPROM_mon_ADDRESS, 		&RTC_month);
	H_EEPROM_void_readByte(EEPROM_year_ADDRESS, 	&RTC_years);
	H_EEPROM_void_readByte(EEPROM_format_ADDRESS, 	&format);
	*/
H_EEPROM_void_writeByte(EEPROM_hour_ADDRESS,	0x06);
H_EEPROM_void_writeByte(EEPROM_min_ADDRESS,		0x50);
H_EEPROM_void_writeByte(EEPROM_second_ADDRESS, 	0x00);
H_EEPROM_void_writeByte(EEPROM_date_ADDRESS, 	0x18);
H_EEPROM_void_writeByte(EEPROM_day_ADDRESS, 	0x06);
H_EEPROM_void_writeByte(EEPROM_mon_ADDRESS, 	0x03);
H_EEPROM_void_writeByte(EEPROM_year_ADDRESS, 	0x23);

u8 h,min,sec,date,day,mon,year;
H_EEPROM_void_readByte(EEPROM_hour_ADDRESS,		&h);
H_EEPROM_void_readByte(EEPROM_min_ADDRESS,		&min);
H_EEPROM_void_readByte(EEPROM_second_ADDRESS, 	&sec);
H_EEPROM_void_readByte(EEPROM_date_ADDRESS, 	&date);
H_EEPROM_void_readByte(EEPROM_day_ADDRESS, 		&day);
H_EEPROM_void_readByte(EEPROM_mon_ADDRESS, 		&mon);
H_EEPROM_void_readByte(EEPROM_year_ADDRESS, 	&year);

/*
H_EEPROM_void_readByte(EEPROM_RTC_STATUS_ADDRESS,&EEPROM_read_data);

if(EEPROM_read_data == EEPROM_EMPTY)
{
	RTC_hours  = 0x02;
	RTC_minute = 0x00;
	RTC_second = 0x00;
	RTC_date   = 0x16;
	RTC_month  = 0x03;
	RTC_years  = 0x23;
	RTC_day    = 0x05;
	format	   = hour_12_PM;

	H_EEPROM_void_writeByte(EEPROM_hour_ADDRESS,	RTC_hours);
	H_EEPROM_void_writeByte(EEPROM_min_ADDRESS,		RTC_minute);
	H_EEPROM_void_writeByte(EEPROM_second_ADDRESS, 	RTC_second);
	H_EEPROM_void_writeByte(EEPROM_date_ADDRESS, 	RTC_date);
	H_EEPROM_void_writeByte(EEPROM_day_ADDRESS, 	RTC_day);
	H_EEPROM_void_writeByte(EEPROM_mon_ADDRESS, 	RTC_month);
	H_EEPROM_void_writeByte(EEPROM_year_ADDRESS, 	RTC_years);
	H_EEPROM_void_writeByte(EEPROM_format_ADDRESS, 	format);

//H_Rtc_void_set_time(0x02, 0x50, 0x50, hour_12_PM);

//H_RTC_Calendar_Write(0x05, 0x16, 0x03, 0x23);
	H_EEPROM_void_writeByte(EEPROM_RTC_STATUS_ADDRESS,'B');//B for Busy
}

*/

#endif


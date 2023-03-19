/*
 * Lcd_prg.c
 *
 *  Created on: Feb 19, 2023
 *      Author: NTI
 */

#ifndef LCD_LCD_PRG_C_
#define LCD_LCD_PRG_C_

#include "avr/delay.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Lcd_priv.h"
#include "Lcd_cfg.h"

#include "Lcd_int.h"

static void H_LCD_void_latchByte(u8 copy_u8Byte)
{
#if(LCD_MODE== _4_BIT_MODE)
	{
		//enable =0
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
		//_delay_ms(1);

		M_Dio_void_setPinValue(LCD_D7_PIN,GET_BIT(copy_u8Byte,7) );
		M_Dio_void_setPinValue(LCD_D6_PIN,GET_BIT(copy_u8Byte,6) );
		M_Dio_void_setPinValue(LCD_D5_PIN,GET_BIT(copy_u8Byte,5) );
		M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,4) );
		//send enable pulse enable =1
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);
		_delay_ms(2);
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
		_delay_ms(2);
		M_Dio_void_setPinValue(LCD_D7_PIN,GET_BIT(copy_u8Byte,3) );
		M_Dio_void_setPinValue(LCD_D6_PIN,GET_BIT(copy_u8Byte,2) );
		M_Dio_void_setPinValue(LCD_D5_PIN,GET_BIT(copy_u8Byte,1) );
		M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,0) );
		//send enable pulse enable =1
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);
		_delay_ms(2);
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
		_delay_ms(50);
	}
#elif(LCD_MODE== _8_BIT_MODE)
	{
		//enable =0
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
		_delay_ms(1);

		M_Dio_void_setPinValue(LCD_D0_PIN,GET_BIT(copy_u8Byte,0) );
		M_Dio_void_setPinValue(LCD_D1_PIN,GET_BIT(copy_u8Byte,1) );
		M_Dio_void_setPinValue(LCD_D2_PIN,GET_BIT(copy_u8Byte,2) );
		M_Dio_void_setPinValue(LCD_D3_PIN,GET_BIT(copy_u8Byte,3) );
		M_Dio_void_setPinValue(LCD_D4_PIN,GET_BIT(copy_u8Byte,4) );
		M_Dio_void_setPinValue(LCD_D5_PIN,GET_BIT(copy_u8Byte,5) );
		M_Dio_void_setPinValue(LCD_D6_PIN,GET_BIT(copy_u8Byte,6) );
		M_Dio_void_setPinValue(LCD_D7_PIN,GET_BIT(copy_u8Byte,7) );
		//send enable pulse enable =1
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_HIGH);
		_delay_ms(2);
		M_Dio_void_setPinValue(LCD_EN_PIN,DIO_LOW);
		_delay_ms(50);
	}
#endif
}

void H_LCD_void_Init(void)
{
#if(LCD_MODE== _4_BIT_MODE)
	{
		_delay_ms(100);
		 H_LCD_void_sendCommand(LCD_RETURN_H);
		_delay_ms(10);
		 H_LCD_void_sendCommand(FNC_SET_FOUR_BIT_MODE);
		 _delay_ms(1);
		 H_LCD_void_sendCommand(CURSOR_ON_DISPLAY_ON);
		 _delay_ms(1);
		 H_LCD_void_sendCommand(LCD_CLEAR);
		 _delay_ms(10);
		 H_LCD_void_sendCommand(ENTRY_MODE);
		 _delay_ms(1);

	}
#elif(LCD_MODE== _8_BIT_MODE)
	{
		_delay_ms(100);
		 H_LCD_void_sendCommand(FNC_SET_EIGHT_BIT_MODE);
		 _delay_ms(1);
		 H_LCD_void_sendCommand(CURSOR_ON_DISPLAY_ON);
		 _delay_ms(1);
		 H_LCD_void_sendCommand(LCD_CLEAR);
		 _delay_ms(10);
		 H_LCD_void_sendCommand(ENTRY_MODE);
		 _delay_ms(1);
	}
#endif
}

void H_LCD_void_sendData(u8 copy_u8data )
{
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_HIGH);
	H_LCD_void_latchByte(copy_u8data);
}

void H_LCD_void_sendCommand(u8 copy_u8command)
{
	M_Dio_void_setPinValue(LCD_RS_PIN,DIO_LOW);
	H_LCD_void_latchByte(copy_u8command);
}

void H_LCD_void_sendString(const char * pstr)
{
	while(*pstr!='\0')
	{
		H_LCD_void_sendData(*pstr);
		pstr++;
	}
}

void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
	s8 arr[10],i=0;

	if(copy_s32Num == 0)
	{
		arr[i]=0;
		i++;
	}
	else if(copy_s32Num<0)
	{
		H_LCD_void_sendData('-');
		copy_s32Num*=-1;
	}


	while(copy_s32Num!=0)
	{
		arr[i]=copy_s32Num%10;
		copy_s32Num/=10;
		i++;
	}

	int j;
	for (j=i-1;j>=0;j--)
	{
		H_LCD_void_sendData(arr[j]+48);
	}


}

void H_LCD_void_clearScreen(void)
{
	 H_LCD_void_sendCommand(LCD_CLEAR);
		 _delay_ms(10);
}
void H_LCD_void_gotoXY(u8 copy_u8Row,u8 copy_u8Col)
{
	u8 copy_u8command;

	if(copy_u8Row>4||copy_u8Row<1||copy_u8Col>20||copy_u8Col<1)
			{
				copy_u8command=0x80;
			}
		else if(copy_u8Row==1)
			{
				copy_u8command=ADDRESS_ROW_1+copy_u8Col-1 ;
			}
		else if (copy_u8Row==2)
			{
				copy_u8command=ADDRESS_ROW_2+copy_u8Col-1;
			}
		else if (copy_u8Row==3)
			{
				copy_u8command=ADDRESS_ROW_3+copy_u8Col-1;
			}
		else if (copy_u8Row==4)
			{
				copy_u8command=ADDRESS_ROW_4+copy_u8Col-1;
			}
		H_LCD_void_sendCommand(copy_u8command);
		_delay_ms(1);
}


void H_LCD_void_creatCustomChar(const u8 * ArrPattern,u8 copy_u8charCode)
{
	H_LCD_void_sendCommand(ADDRESS_CGRAM+copy_u8charCode*8);
	u8 i;
	for(i=0;i<8;i++)
	{
		H_LCD_void_sendData(ArrPattern[i]);
	}
}

void H_LCD_void_displayCustomChar(u8 copy_u8charCode)
{
	H_LCD_void_sendData(copy_u8charCode);
}


#endif /* LCD_LCD_PRG_C_ */

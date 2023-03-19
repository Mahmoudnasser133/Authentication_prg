/*
 * finger.c
 *
 *  Created on: Mar 17, 2023
 *      Author: NTI
 */


#include <util/delay.h>
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
#include "UART_int.h"
#include "FingerPrint_int.h"
#include "Mcu_HW.h"
extern const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE];
UART_config fp = {Baud_rate_57600,eight,Disable,One_bit};
extern const char hand_shake[12];
extern const char Gen_Img[12];
extern const char Reg_Model[12];
extern u8 recive[20];
extern u8 i;
u8 mass[100];
volatile u8 val;
void toggel(void);
int main()
{

	Port_Init(PORT_Config_Arr);
		H_LCD_void_Init();
H_fingerPrint_void_init(&fp);

//M_UART_void_int(&fp);

u8 size = 12 ;

Enable_Global_INT();

H_fingerPrint_void_sendcomnd(hand_shake,size);
M_UART_void_receiveByteAsynchCallBack(toggel);
//size = sizeof(Gen_Img);
////H_fingerPrint_void_sendcomnd(Gen_Img,size);
//size = sizeof(Reg_Model);
////H_fingerPrint_void_sendcomnd(Reg_Model,size);
//H_fingerPrint_void_Recivecommand();
//H_fingerPrint_void_sendcomnd(hand_shake,size);
//H_fingerPrint_void_Recivecommand();
//H_LCD_void_sendData('m');
u8 j=0;
while(1)
{
	H_LCD_void_sendIntNum(i);

 if(i>9)
 {

 }
}



return 0;
}

void toggel(void)

{
//	H_LED_void_toggle(LED_GRN);
//
//	val = UDR_REG;
//	i++;


}


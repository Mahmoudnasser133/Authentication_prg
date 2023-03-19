/*
 * Port_Lcfg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Port_Lcfg.c
*  Module   : PORT
*  breif    : Config file for PORT Driver
*
*****************************************************************
*/
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Port_types.h"
#include "Port_cfg.h"


/******************************************
  Local Macros / Functions
*******************************************/


/******************************************
  Local Data
*******************************************/

/******************************************
  Global Data
*******************************************/

const Port_ConfigType PORT_Config_Arr[PORT_PINS_CONFIG_ARR_SIZE]= {

/*************************************************************************
 *                     LCD_pins = 6
 ***************************************************************************/
											  {PORT_PB0,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

											   {PORT_PB1,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

											   {PORT_PB2,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

											   {PORT_PB4,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

											   {PORT_PA2,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

											   {PORT_PA3,
											   PORT_PIN_LEVEL_LOW,
											   PORT_PINDIR_OUTPUT,
											   PORT_PIN_IN_ATTATCH_FLOATING},

/*********************************************************************************
*                     KEYPAD_pins = 8
*********************************************************************************/
											   {PORT_PC5,
											   PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_OUTPUT,//
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PC4,
											   PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_OUTPUT,//
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PC3,
											   PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_OUTPUT,//
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PC2,
											   PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_OUTPUT,//
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PD7,
											   PORT_PIN_LEVEL_HIGH,//high
											   PORT_PINDIR_INPUT,//input
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PD6,
												PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_INPUT,//input
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PD5,
											   PORT_PIN_LEVEL_HIGH,//high
											   PORT_PINDIR_INPUT,//input
											   PORT_PIN_IN_ATTATCH_PULLUP},

											   {PORT_PD3,
											   PORT_PIN_LEVEL_HIGH,//
											   PORT_PINDIR_INPUT,//input
											   PORT_PIN_IN_ATTATCH_PULLUP},

/*********************************************************************************
*                     LED_pins = 4
*********************************************************************************/

											   	   	   {PORT_PB7,
													   PORT_PIN_LEVEL_LOW,
													   PORT_PINDIR_OUTPUT,
													   PORT_PIN_IN_ATTATCH_FLOATING},

													   {PORT_PA4,
													   PORT_PIN_LEVEL_LOW,
													   PORT_PINDIR_OUTPUT,
													   PORT_PIN_IN_ATTATCH_FLOATING},

													   {PORT_PA5,
													   PORT_PIN_LEVEL_LOW,
													   PORT_PINDIR_OUTPUT,
													   PORT_PIN_IN_ATTATCH_FLOATING},

													   {PORT_PA6,
													   PORT_PIN_LEVEL_LOW,
													   PORT_PINDIR_OUTPUT,
													   PORT_PIN_IN_ATTATCH_FLOATING},

/*********************************************************************************
*                     BUZZER_pin = 1
*********************************************************************************/
												   {PORT_PC6,
												   PORT_PIN_LEVEL_LOW,
												   PORT_PINDIR_OUTPUT,
												   PORT_PIN_IN_ATTATCH_FLOATING},

/*********************************************************************************
*                     relay_pin = 1
*********************************************************************************/
												   {PORT_PC7,
												   PORT_PIN_LEVEL_LOW,
												   PORT_PINDIR_OUTPUT,
												   PORT_PIN_IN_ATTATCH_FLOATING},
};

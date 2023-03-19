/*
 * Port_cfg.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

#ifndef PORT_CFG_H_
#define PORT_CFG_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"

/******************************************
  GLOBAL CONSTANT MACROS
******************************************/
#define PORT_PINS_CONFIG_ARR_SIZE 20

/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/

/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/
typedef struct {
	Port_PinType             Port_PinNumber; //PA0 or PA1...etc
	Port_LevelType           Port_PinLevelValue;// initial value of pin
    Port_PinDirectionType    Port_PinDirection; // input or output
	Port_InternalAttachType  Port_PinInternalAttach;//pull up or floating

}Port_ConfigType;

#endif /* PORT_CFG_H_ */

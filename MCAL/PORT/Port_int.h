/*
 * Port_int.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

#ifndef PORT_PORT_INT_H_
#define PORT_PORT_INT_H_

/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Port_types.h"
#include "Port_cfg.h"

/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/


/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/


/******************************************
  GLOBAL DATA TYPES AND STRUCTURES
*******************************************/



/******************************************
   GLOBAL FUNCTIONS PROTOTYPES
*******************************************/

/******************************************
  syntax : void Port_Init(const Port_ConfigType * ConfigPtr);

  Description :

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :
  parameters (out) : none
  Return Value     : void
******************************************/
void Port_Init(const Port_ConfigType * ConfigPtr);

#endif /* PORT_PORT_INT_H_ */

/*
 * Dio_int.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */

#ifndef DIO_DIO_INT_H_
#define DIO_DIO_INT_H_


/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "Dio_types.h"
#include "Dio_cfg.h"
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
  syntax : Dio_LevelType M_Dio_en_getPinValue(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
Dio_LevelType M_Dio_en_getPinValue(Dio_ChannelType ChannelId);
/******************************************
  syntax : void M_Dio_void_setPinValue(Dio_ChannelType ChannelId,Dio_LevelType Level);

  Description : write the pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_setPinValue(Dio_ChannelType ChannelId,Dio_LevelType Level);

/******************************************
  syntax : Dio_PortLevelType M_Dio_en_getPortValue(Dio_PortType PortId);

  Description : Read the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType
******************************************/
Dio_PortLevelType M_Dio_en_getPortValue(Dio_PortType PortId);

/******************************************
  syntax : void M_Dio_void_setPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

  Description : write the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_setPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

/******************************************
  syntax : Dio_LevelType M_Dio_void_togglePinValue(Dio_ChannelType channelId);

  Description : toggle the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_togglePinValue(Dio_ChannelType channelId);
#endif /* DIO_DIO_INT_H_ */

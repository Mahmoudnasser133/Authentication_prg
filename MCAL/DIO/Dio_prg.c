/*
 * Dio_prg.c
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Dio_int.h"
#include "Mcu_HW.h"




/******************************************
  Local Data (static global )
*******************************************/



/******************************************
  Global Data (non static global)
*******************************************/





/******************************************
  Local Functions body
*******************************************/


/******************************************
  Global Functions body
*******************************************/

/******************************************
  syntax : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

  Description : read the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin)
  parameters (out) :  Non
  Return Value     : Dio_HIGH or DIO_LOW
******************************************/
Dio_LevelType  M_Dio_en_getPinValue(Dio_ChannelType ChannelId)
{
	u8 pin = ChannelId % 10;
	u8 port = ChannelId / 10;

	Dio_LevelType Local_levelType;
	switch(port)
	{
	case DIO_PORTA :Local_levelType = GET_BIT( PINA_REG,pin);break;
	case DIO_PORTB :Local_levelType = GET_BIT( PINB_REG,pin);break;
	case DIO_PORTC :Local_levelType = GET_BIT( PINC_REG,pin);break;
	case DIO_PORTD :Local_levelType = GET_BIT( PIND_REG,pin);break;
	}
    return Local_levelType ;
}
/******************************************
  syntax : void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);

  Description : write the pin

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  channelId (pin) ,Level (Dio_HIGH or Dio_LOW)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_setPinValue(Dio_ChannelType ChannelId,Dio_LevelType Level)
{
	u8 pin = ChannelId % 10;
	u8 port = ChannelId / 10;

	if(Level == DIO_HIGH)
	{
		switch(port)
		{
		case DIO_PORTA : SET_BIT( PORTA_REG,pin);break;
		case DIO_PORTB : SET_BIT( PORTB_REG,pin);break;
		case DIO_PORTC : SET_BIT( PORTC_REG,pin);break;
		case DIO_PORTD : SET_BIT( PORTD_REG,pin);break;
		}

	}
	else if (Level == DIO_LOW)
	{
		switch(port)
		{
		case DIO_PORTA : CLR_BIT( PORTA_REG,pin);break;
		case DIO_PORTB : CLR_BIT( PORTB_REG,pin);break;
		case DIO_PORTC : CLR_BIT( PORTC_REG,pin);break;
		case DIO_PORTD : CLR_BIT( PORTD_REG,pin);break;
		}

	}

}

/******************************************
  syntax : Dio_PortLevelType M_Dio_en_getPortValue(Dio_PortType PortId);

  Description : Read the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId
  parameters (out) :  Non
  Return Value     : Dio_PortLevelType
******************************************/
Dio_PortLevelType M_Dio_en_getPortValue(Dio_PortType PortId)
{
	Dio_PortLevelType Local_Reading;

	switch( PortId)
	{
	case DIO_PORTA :Local_Reading =  PORTA_REG;break;
	case DIO_PORTB :Local_Reading =  PORTB_REG;break;
	case DIO_PORTC :Local_Reading =  PORTC_REG;break;
	case DIO_PORTD :Local_Reading =  PORTD_REG;break;
	}

	return Local_Reading;
}

/******************************************
  syntax : void M_Dio_void_setPortValue(Dio_PortType PortId,Dio_PortLevelType Level);

  Description : write the whole port

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_setPortValue(Dio_PortType PortId,Dio_PortLevelType Level)
{
	switch(PortId)
	{
    	case DIO_PORTA : PORTA_REG = Level;break;
    	case DIO_PORTB : PORTB_REG = Level;break;
    	case DIO_PORTC : PORTC_REG = Level;break;
    	case DIO_PORTD : PORTD_REG = Level;break;
	}
}

/******************************************
  syntax : Dio_LevelType M_Dio_void_togglePinValue(Dio_ChannelType channelId);

  Description : toggle the pin state

  Synch/Asynch     : Synchronouse
  Reentrance       : Reentrant
  parameters (in)  :  PortId, Level (0-255)
  parameters (out) :  Non
  Return Value     : void
******************************************/
void M_Dio_void_togglePinValue(Dio_ChannelType channelId)
{
	u8 pin = channelId % 10;
	u8 port = channelId/ 10;

	switch(port)
	{
	case DIO_PORTA :TOG_BIT( PORTA_REG,pin);break;
	case DIO_PORTB :TOG_BIT( PORTB_REG,pin);break;
	case DIO_PORTC :TOG_BIT( PORTC_REG,pin);break;
	case DIO_PORTD :TOG_BIT( PORTD_REG,pin);break;
	}

}



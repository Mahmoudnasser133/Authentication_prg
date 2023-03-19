/*
 * I2c_prg.c
 *
 *  Created on: Mar 9, 2023
 *      Author: nasser
 */


#include "STD_TYPES.h"
#include "Mcu_HW.h"
#include "BIT_MATH.h"

#include "I2c_priv.h"
#include "I2c_int.h"

void M_I2C_void_Init(IIC_CONFIG *IIC_CONFIG_ptr)
{
	//TWBR_REG = (unsigned char) ( ( (FCPU_I2C/( IIC_CONFIG_ptr->speed_SCL_Clock)*1000 ) - 16) / (2*IIC_CONFIG_ptr->IIC_prescaler_value) );
TWBR_REG = IIC_CONFIG_ptr->speed_SCL_Clock;
//apply mask
	TWSR_REG &= TWSR_status_mask;
// insert mask
	TWSR_REG |= IIC_CONFIG_ptr->IIC_prescaler;
//Enable IIC
	SET_BIT(TWCR_REG,TWEN_BIT);
}

void M_I2c_void_send_start(void)
{
	//u16 counter=0;
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWSTA_BIT) | (1<<TWEN_BIT);
//Wait for TWINT Flag set. This indicates that the START condition has been transmitted
	while((GET_BIT(TWCR_REG,TWINT_BIT)) == 0 );
	/*
	while((GET_BIT(TWCR_REG,TWINT_BIT)) == 0 && (counter < 50000 ))
	{
		counter++;
	}
	*/
}

void M_I2c_void_send_stop(void)
{
	TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWSTO_BIT);
}


void M_I2c_void_receiveByte_ACK(u8 * ptr)
{
	TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT) | (1<<TWEA_BIT);
	while( (GET_BIT(TWCR_REG,TWINT_BIT) ) == 0 );
	//while ((TWSR_REG & TWSR_status_mask) != DATA_RECIVE_ACK); // data byte has been received and  ACK has been returned
	*ptr = TWDR_REG;
}

//this fn should receive 1 byte and respond with NO ACK
void M_I2c_receiveByte_NoACK(u8 * ptr)
{
	TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT);//clear flag
	while( (GET_BIT(TWCR_REG,TWINT_BIT) ) == 0 );
	//while ((TWSR_REG & TWSR_status_mask) != DATA_RECIVE_NACK); // data byte has been received and Not ACK has been returned
	*ptr = TWDR_REG;
}
void M_I2C_void_write_address(u8 address)
	{
		TWDR_REG = address;
		TWCR_REG = (1<<TWINT_BIT)|(1<<TWEN_BIT);//clear flag
		while( (GET_BIT(TWCR_REG,TWINT_BIT) ) == 0); //wait to finish
		//while ((TWSR_REG & TWSR_status_mask) != SLA_W_TRANSMIT_ACK); // SLA+write has been transmitted and ACK has been received
	}

void M_I2C_void_write_data(u8 data)
	{
		TWDR_REG = data;
		TWCR_REG =(1<<TWINT_BIT)|(1<<TWEN_BIT);//clear flag
		while( (GET_BIT(TWCR_REG,TWINT_BIT)) == 0); //wait to finish
		//while ((TWSR_REG & TWSR_status_mask) != DATA_TRANSMITTED_ACK); // data has been transmitted and ACK has been received
	}


void M_I2C_void_set_address(u8 address)
	{
		TWAR_REG = address;
	}

void M_I2c_void_getStatus(u8* status )
	{
		*status = ( TWSR_REG & TWSR_status_mask );
	}












/*
u8 M_I2C_void_slave_read(void)
	{
		TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWEA_BIT);
		while( (GET_BIT(TWCR_REG,TWINT_BIT) ) ==0);
		while ((TWSR_REG & TWSR_status_mask) != SLA_W_RECIVE_ACK); // own SLA+W has been received and ACK has been returned
		TWCR_REG=(1<<TWINT_BIT)|(1<<TWEN_BIT)|(1<<TWEA_BIT);
		while( (GET_BIT(TWCR_REG,TWINT_BIT) ) ==0);
		while ((TWSR_REG & TWSR_status_mask) != 0x80); // previously addressed with own SLA+W : data has been received : ACK has been returned
		return TWDR_REG ;
	}
*/

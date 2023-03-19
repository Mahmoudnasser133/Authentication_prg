/*
 * Mcu_HW.h
 *
 *  Created on: Feb 17, 2023
 *      Author: aya_enan
 */
/*****************************************************************/
/* FILE DESCRIPTION:
----------------------------------------------------------------
*  file     : Mcu_HW.h
*
*  breif    : this file contains all registers addresses
*
*****************************************************************
*/
#ifndef MCU_HW_H_
#define MCU_HW_H_
/******************************************
  INCLUDES
*******************************************/
#include "STD_TYPES.h"
/******************************************
  Global Data TYPES AND STRUCTURES
*******************************************/


/******************************************
  GLOBAL CONSTANT MACROS
*******************************************/
//-------------------DIO-------------------
//------------------ END of DIO------------


#define PORTA_REG  (*((volatile u8*)0x3B))
#define DDRA_REG  (*((volatile u8*)0x3A))
#define PINA_REG  (*((volatile u8*)0x39))

#define PORTB_REG  (*((volatile u8*)0x38))
#define DDRB_REG  (*((volatile u8*)0x37))
#define PINB_REG  (*((volatile u8*)0x36))

#define PORTC_REG  (*((volatile u8*)0x35))
#define DDRC_REG  (*((volatile u8*)0x34))
#define PINC_REG  (*((volatile u8*)0x33))

#define PORTD_REG  (*((volatile u8*)0x32))
#define DDRD_REG  (*((volatile u8*)0x31))
#define PIND_REG  (*((volatile u8*)0x30))
//external interrupt
#define GICR_REG  (*((volatile u8*)0x5B))
#define GIFR_REG  (*((volatile u8*)0x5A))
#define MCUCR_REG  (*((volatile u8*)0x55))
#define MCUCSR_REG  (*((volatile u8*)0x54))
#define ISC2_BIT    6

#define SREG_REG  (*((volatile u8*)0x5F))


// Timer0
#define TCCR0_REG  (*((volatile u8*)0x53))
#define TCNT0_REG	(*((volatile u8*)0x52))
#define OCR0_REG	(*((volatile u8*)0x5C))
#define TIMSK_REG	(*((volatile u8*)0x59))

#define WGM00_BIT		6
#define WGM01_BIT		3
#define CS00_BIT		0
#define CS01_BIT		1
#define CS02_BIT		2
#define COM00_BIT		4
#define COM01_BIT		5
#define TOIE0_BIT		0
#define OCIE0_BIT		1

// Timer 1
#define  TCNT1H_REG  (*((volatile u8*)0x4D))
#define  TCNT1L_REG  (*((volatile u8*)0x4C))
#define  TCNT1_REG  (*((volatile u16*)0x4C))

#define  TCCR1A_REG  (*((volatile u8*)0x4F))
#define  TCCR1B_REG  (*((volatile u8*)0x4E))

#define  OCR1AH_REG  (*((volatile u8*)0x4B))
#define  OCR1AL_REG  (*((volatile u8*)0x4A))
#define  OCR1A_REG  (*((volatile u16*)0x4A))

#define  OCR1BH_REG  (*((volatile u8*)0x49))
#define  OCR1BL_REG  (*((volatile u8*)0x48))
#define  OCR1B_REG  (*((volatile u16*)0x48))

#define  ICR1_REG  (*((volatile u16*)0x46))

#define  TIFR_REG  (*((volatile u16*)0x58))
#define ICF1_BIT		5
#define ICES1_BIT		6
#define ICNC1_BIT		7

#define WGM10_BIT		0
#define WGM11_BIT		1
#define WGM12_BIT		3
#define WGM13_BIT		4

#define CS10_BIT		0
#define CS11_BIT		1
#define CS12_BIT		2


// ADC
#define  ADMUX_REG   (*((volatile u8*)0x27))
#define  ADCSRA_REG  (*((volatile u8*)0x26))
#define ADCH_REG	 (*((volatile u8*)0x25))
#define ADCL_REG	(*((volatile u8*)0x24))
#define ADC_REG		(*((volatile u16*)0x24))
#define SFIOR_REG	(*((volatile u8*)0x50))

 //REFS1 REFS0 ADLAR MUX4 MUX3 MUX2 MUX1 MUX0
#define REFS1_BIT		7
#define REFS0_BIT		6
#define ADLAR_BIT		5
#define MUX4_BIT		4
#define MUX3_BIT		3
#define MUX2_BIT		2
#define MUX1_BIT		1
#define MUX0_BIT		0
//ADEN ADSC ADATE ADIF ADIE ADPS2 ADPS1 ADPS0
#define ADEN_BIT	7
#define ADSC_BIT	6
#define ADIF_BIT	4
#define ADIE_BIT	3

// UART
#define  UBRRL_REG   (*((volatile u8*)0x29))
#define  UBRRH_REG  (*((volatile u8*)0x40))
#define  UCSRC_REG  (*((volatile u8*)0x40))
#define  UCSRB_REG  (*((volatile u8*)0x2A))
#define  UCSRA_REG  (*((volatile u8*)0x2B))
#define  UDR_REG  (*((volatile u8*)0x2C))

#define TXEN_BIT	3
#define RXEN_BIT	4
#define UDRE_BIT	5
#define RXC_BIT		7
#define URSEL_BIT	7
#define UCSZ0_BIT	1
#define UCSZ1_BIT	2
#define TXC_BIT		6
#define RXCIE_BIT	7


//SPI
#define  SPCR_REG   (*((volatile u8*)0X2D))
#define  SPSR_REG	(*((volatile u8*)0X2E))
#define  SPDR_REG	(*((volatile u8*)0X2F))

#define SPE_BIT		6
#define SPIF_BIT	7
#define SPIE_BIT	7


//IIC
#define  TWDR_REG   (*((volatile u8*)0X23))
#define  TWAR_REG   (*((volatile u8*)0X22))
#define  TWSR_REG   (*((volatile u8*)0X21))
#define  TWBR_REG   (*((volatile u8*)0X20))
#define  TWCR_REG	(*((volatile u8*)0X56))

#define TWEN_BIT	2
#define TWINT_BIT	7
#define TWEA_BIT	6
#define TWSTA_BIT	5
#define TWSTO_BIT	4
/******************************************
  GLOBAL FUNCTIONS MACROS
*******************************************/
#endif /* MCU_HW_H_ */

/*
 * UART_prg.c
 *
 *  Created on: Mar 4, 2023
 *      Author: nasser
 */
#include <avr/delay.h>

#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "UART_int.h"
#include <avr/interrupt.h>
static void (*call_back_UART_ptr)(void) = NULL;
u8 recive[20],i;
#if 1

	void M_UART_void_int(UART_config *UART_cofig_ptr)
		{

			//calculate UBRR_reg

			u16 UBRR = UART_cofig_ptr->Baud_rate_value;

			UBRRH_REG=(u8)(UBRR>>8);
			UBRRL_REG=(u8)UBRR;
			//	UBRR = (FCPU_UART/( 16 * ( UART_cofig_ptr->Baud_rate) )) - 1 ;

	/*************************************************************/
				CLR_BIT(UCSRA_REG,1);

			/* Enable USART Sender & Receiver*/
				SET_BIT(UCSRB_REG,TXEN_BIT);
				SET_BIT(UCSRB_REG,RXEN_BIT);

				if(UART_cofig_ptr->Word_leght == nine)
					{
						SET_BIT(UCSRB_REG,2);
					}
				//UCSRC_REG=(1<<URSEL_BIT)|(1<<UCSZ0_BIT)|(1<<UCSZ1_BIT);

				//APPLY MASK
				UCSRC_REG &= 0x81;

				UCSRC_REG|=(1<<URSEL_BIT)| ((UART_cofig_ptr->parity_Mode)<<4) | ((UART_cofig_ptr->NO_stopBits)<<3)| ((UART_cofig_ptr->Word_leght)<<1) ;


		#if 0
			//select parity mode

			//APPLY MASK
			UCSRC_REG &= PARITY_MASK;
			//insert mask
			UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->parity_Mode)<<4);
		/*************************************************************/
		// select NO of stop bits

			//APPLY MASK
			UCSRC_REG &= STOP_BIT_MASK;
			//insert mask
			UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->NO_stopBits)<<3);
		/*************************************************************/
			//select Word Length

			//APPLY MASK
			UCSRC_REG &= WORD_LENGTH_MASK;
			//insert mask
			UCSRC_REG |= (1<<URSEL_BIT) | ((UART_cofig_ptr->Word_leght)<<1);

			if(UART_cofig_ptr->Word_leght == nine)
			{
				SET_BIT(UCSRB_REG,2);
			}
			/* Enable USART Sender & Receiver*/
				SET_BIT(UCSRB_REG,TXEN_BIT);
				SET_BIT(UCSRB_REG,RXEN_BIT);
		#endif

		}


void M_UART_v_SendData(u8 data)
		{
			u16 counter=0;

			/*Wait for UDR transmit buffer to be empty*/

			while(  ( GET_BIT(UCSRA_REG,UDRE_BIT) ) == 0  &&  counter < MAXCOUNTER )
			{
				counter++;
			}


			/*Put data to UDR transmit buffer transmit*/
			UDR_REG = data ;
		}

u8 M_UART_u8_ReceiveData(void)
		{
			u16 counter=0;
				/*Wait for UDR receive buffer to be filled with data*/

//			while( ( GET_BIT(UCSRA_REG,RXC_BIT) ) == 0  && counter < MAXCOUNTER)
//			{
//				counter++;
//			}
			while( ( GET_BIT(UCSRA_REG,RXC_BIT) ) == 0);

			/*Receive data from UDR receive buffer*/
				return UDR_REG ;
		}

void M_UART_void_receiveByteAsynchCallBack(void (*copy_call_back_ptr_UART)(void))
{

	call_back_UART_ptr = copy_call_back_ptr_UART;
/*************************** Enable interrupt**********************************/
	SET_BIT(UCSRB_REG,RXCIE_BIT);


}
void M_UART_vSendstring( u8 *ptr)
		{
			while(*ptr!= '\0' )
			{
				M_UART_v_SendData(*ptr);
				ptr++;
				//_delay_ms(50);
			}
		}




ISR( USART_RXC_vect)
{

	recive[i] = UDR_REG;
	i++;
	//call_back_UART_ptr();
}






#endif






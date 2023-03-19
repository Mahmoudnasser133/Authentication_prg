/*
 * Exti_prg.c
 *
 *  Created on: Feb 24, 2023
 *      Author: NTI
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "avr/interrupt.h"
#include "Exti_priv.h"
#include "Exti_cfg.h"
#include "Exti_int.h"

 static void (*callBack_Arr[3])(void)={NULL,NULL,NULL};

void enableInt(const EXTI_cfg * EXTI_ConfigPtr)
{

		// step1 : set General Interrupt Control Register
// step 2 apply Mask
		switch(EXTI_ConfigPtr->IntID )
			{
				case INT0_id:
							SET_BIT(GICR_REG,INT0_BIT);
							MCUCR_REG &= EXTI_INT0_TRIGGER;//apply Mask
							MCUCR_REG |= EXTI_ConfigPtr->IntTrigger;
							break;

				case INT1_id:
								SET_BIT(GICR_REG,INT1_BIT);
								MCUCR_REG &= EXTI_INT1_TRIGGER;//apply Mask
								MCUCR_REG |= EXTI_ConfigPtr->IntTrigger<<2 ;
								break;
				case INT2_id:
								CLR_BIT(MCUCSR_REG,ISC2_BIT );//clr bit
								SET_BIT(MCUCSR_REG,GET_BIT(EXTI_ConfigPtr->IntTrigger,0));
								break;
			}

	}



void disableInt(const EXTI_cfg * EXTI_ConfigPtr)
{
	switch(EXTI_ConfigPtr->IntID )
				{
					case INT0_id:
								CLR_BIT(GICR_REG,INT0_BIT);
								MCUCR_REG &= EXTI_INT0_TRIGGER;//apply Mask
								MCUCR_REG |= EXTI_ConfigPtr->IntTrigger;
								break;

					case INT1_id:
									CLR_BIT(GICR_REG,INT1_BIT);
									MCUCR_REG &= EXTI_INT1_TRIGGER;//apply Mask
									MCUCR_REG |= EXTI_ConfigPtr->IntTrigger<<2 ;
									break;
					case INT2_id:
						CLR_BIT(GICR_REG,INT2_BIT);
							CLR_BIT(MCUCSR_REG,ISC2_BIT );//clr bit
									SET_BIT(MCUCSR_REG,GET_BIT(EXTI_ConfigPtr->IntTrigger,0));
									break;
				}
}




void setCallBack(void (*copy_callBack)(void),u8 IntID)
{
	callBack_Arr[IntID]=copy_callBack;
}

ISR(INT1_vect)
{

	callBack_Arr[1]();

}



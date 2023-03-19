/*
 * Glint_prg.c
 *
 *  Created on: Feb 25, 2023
 *      Author: nasser
 */

#include "BIT_MATH.h"
#include "Mcu_HW.h"
#include "Glint.h"


void Enable_Global_INT(void)
{
	SET_BIT(SREG_REG,I_bit);
}

void Disable_Global_INT(void)
{
	CLR_BIT(SREG_REG,I_bit);
}

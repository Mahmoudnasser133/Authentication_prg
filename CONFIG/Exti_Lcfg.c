/*
 * Exti_Lcfg.c
 *
 *  Created on: Feb 25, 2023
 *      Author: nasser
 */

#include "STD_TYPES.h"
#include "Exti_types.h"
#include "Exti_cfg.h"



const EXTI_cfg Exti_Config_Arr[EXTI_CONFIG_ARR_SIZE]= {{INT0_id,FALLING_EDGE},
													   {INT1_id,FALLING_EDGE}};

/*
 * Exti_cfg.h
 *
 *  Created on: Feb 24, 2023
 *      Author: NTI
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_

#include "STD_TYPES.h"
#include "Exti_types.h"

#define EXTI_CONFIG_ARR_SIZE 2

typedef struct {
	EXTI_INT_ID 			IntID;
	EXTI_INT_triggers		IntTrigger;
}EXTI_cfg;

#endif /* EXTI_CFG_H_ */

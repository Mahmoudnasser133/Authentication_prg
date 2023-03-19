/*
 * Exti_int.h
 *
 *  Created on: Feb 24, 2023
 *      Author: NTI
 */

#ifndef EXTI_EXTI_INT_H_
#define EXTI_EXTI_INT_H_

#include "STD_TYPES.h"
#include "Exti_types.h"
#include "Exti_cfg.h"


#define NULL_0	 0

void enableInt(const EXTI_cfg * ConfigPtr);
void disableInt(const EXTI_cfg * ConfigPtr);

void setCallBack(void (*copy_callBack)(void),u8 IntID);
#endif /* EXTI_EXTI_INT_H_ */

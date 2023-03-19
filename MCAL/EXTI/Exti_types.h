/*
 * Exti_types.h
 *
 *  Created on: Feb 24, 2023
 *      Author: NTI
 */

#ifndef EXTI_EXTI_TYPES_H_
#define EXTI_EXTI_TYPES_H_

#include "STD_TYPES.h"

typedef enum{
	INT0_id,
	INT1_id,
	INT2_id

}EXTI_INT_ID;

typedef enum{
LOW_LEVEL,
ANY_CHANGE,
FALLING_EDGE,
RISING_EDGE
}EXTI_INT_triggers;

#endif /* EXTI_EXTI_TYPES_H_ */

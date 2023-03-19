/*
 * Led_prg.c
 *
 *  Created on: Feb 18, 2023
 *      Author: NTI
 */

#include "STD_TYPES.h"
#include "Dio_int.h"
#include "Led_priv.h"
#include "Led_cfg.h"
#include "Led_int.h"

void H_LED_void_turnON(u8 ledID)
{
	switch(ledID)
	{
	case LED_RED:
#if(LED_RED_DIR == LED_FORWARD_DIR)

		M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);

#elif(LED_RED_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_RED_PIN,DIO_LOW);
#else
#error ("Wrong LED Direction");
#endif
		break;


	case LED_BLUE:
#if(LED_BLUE_DIR == LED_FORWARD_DIR)

		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);

#elif(LED_BLUE_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_LOW);
#else
#error ("Wrong LED Direction");
#endif
			break;
		/**********************/
	case LED_YELLOW:
#if(LED_YELLO_DIR == LED_FORWARD_DIR)

		M_Dio_void_setPinValue(LED_YELLO_PIN,DIO_HIGH);

#elif(LED_YELLO_DIR == LED_REVERSE_DIR)
		M_Dio_void_setPinValue(LED_YELLO_PIN,DIO_LOW);
#else
#error ("Wrong LED Direction");
#endif
			break;
	/**********************/
		case LED_GRN:
	#if(LED_GRN_DIR == LED_FORWARD_DIR)

			M_Dio_void_setPinValue(LED_GRN_PIN,DIO_HIGH);

	#elif(LED_GRN_DIR == LED_REVERSE_DIR)
			M_Dio_void_setPinValue(LED_GRN_PIN,DIO_LOW);
	#else
	#error ("Wrong LED Direction");
	#endif
				break;

	}
}
void H_LED_void_turnOFF(u8 ledID)
{
	switch(ledID)
		{
		case LED_RED:
	#if(LED_RED_DIR == LED_FORWARD_DIR)

			M_Dio_void_setPinValue(LED_RED_PIN,DIO_LOW);

	#elif(LED_RED_DIR == LED_REVERSE_DIR)
			M_Dio_void_setPinValue(LED_RED_PIN,DIO_HIGH);
	#else
	#error ("Wrong LED Direction");
	#endif
			break;
			/******/
		case LED_YELLOW:
			#if(LED_YELLO_DIR == LED_FORWARD_DIR)

					M_Dio_void_setPinValue(LED_YELLO_PIN,DIO_LOW);

			#elif(LED_YELLO_DIR == LED_REVERSE_DIR)
					M_Dio_void_setPinValue(LED_YELLO_PIN,DIO_HIGH);
			#else
			#error ("Wrong LED Direction");
			#endif
					break;
			/******/
			case LED_BLUE:
				#if(LED_BLUE_DIR == LED_FORWARD_DIR)

						M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_LOW);

				#elif(LED_BLUE_DIR == LED_REVERSE_DIR)
						M_Dio_void_setPinValue(LED_BLUE_PIN,DIO_HIGH);
				#else
				#error ("Wrong LED Direction");
				#endif
						break;
			/******/
				case LED_GRN:
					#if(LED_GRN_DIR == LED_FORWARD_DIR)

							M_Dio_void_setPinValue(LED_GRN_PIN,DIO_LOW);

					#elif(LED_GRN_DIR == LED_REVERSE_DIR)
							M_Dio_void_setPinValue(LED_GRN_PIN,DIO_HIGH);
					#else
					#error ("Wrong LED Direction");
					#endif
							break;

		}

}
void H_LED_void_toggle(u8 ledID)
{
	switch(ledID)
			{
			case LED_RED:
		#if(LED_RED_DIR == LED_FORWARD_DIR)

				M_Dio_void_togglePinValue(LED_RED_PIN);

		#elif(LED_RED_DIR == LED_REVERSE_DIR)
				M_Dio_void_togglePinValue(LED_RED_PIN);
		#else
		#error ("Wrong LED Direction");
		#endif
				break;
				/******/
			case LED_YELLOW:
				#if(LED_YELLO_DIR == LED_FORWARD_DIR)

				M_Dio_void_togglePinValue(LED_YELLO_PIN);

				#elif(LED_YELLO_DIR == LED_REVERSE_DIR)
				M_Dio_void_togglePinValue(LED_YELLO_PIN);
				#else
				#error ("Wrong LED Direction");
				#endif
						break;
				/******/
				case LED_BLUE:
					#if(LED_BLUE_DIR == LED_FORWARD_DIR)

					M_Dio_void_togglePinValue(LED_BLUE_PIN);

					#elif(LED_BLUE_DIR == LED_REVERSE_DIR)
					M_Dio_void_togglePinValue(LED_BLUE_PIN);
					#else
					#error ("Wrong LED Direction");
					#endif
							break;
				/******/
					case LED_GRN:
						#if(LED_GRN_DIR == LED_FORWARD_DIR)

						M_Dio_void_togglePinValue(LED_GRN_PIN);

						#elif(LED_GRN_DIR == LED_REVERSE_DIR)
						M_Dio_void_togglePinValue(LED_GRN_PIN);
						#else
						#error ("Wrong LED Direction");
						#endif
								break;

			}

}

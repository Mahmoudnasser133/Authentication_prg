/*
 * FingerPrint_int.h
 *
 *  Created on: Mar 17, 2023
 *      Author: NTI
 */

#ifndef FIGERPRINT_FINGERPRINT_INT_H_
#define FIGERPRINT_FINGERPRINT_INT_H_

#include "FingerPrint_types.h"
#include "FingerPrint_cfg.h"


//First three Packages
//const char Header[]			= {0xEF, 0x01};
//const char Address[]		= {0xFF, 0xFF, 0xFF, 0xFF};
//const char Command[]		= {0x01, 0x00};

//commands Packages
//const char PassVfy[]		= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x7, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1B};
//const char f_detect[]		= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x3, 0x1, 0x0, 0x5};
//const char f_imz2ch1[]		= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x4, 0x2, 0x1, 0x0, 0x8};
//const char f_imz2ch2[]		= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x4, 0x2, 0x2, 0x0, 0x9};
//const char f_createModel[]	= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x3, 0x5, 0x0, 0x9};
//char f_storeModel[]			= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x6, 0x6, 0x1, 0x0, 0x1, 0x0, 0xE};
//const char f_search[]		= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x8, 0x4, 0x1, 0x0, 0x0, 0x0, 0xA3, 0x0, 0xb1};
//char f_delete[]				= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x7, 0xC, 0x0, 0x0, 0x0, 0x1, 0x0, 0x15};
//char fp_empty[]				= {0xEF, 0x01,0xFF, 0xFF, 0xFF, 0xFF,0x01,0x3,0xd,0x0,0x11};




void H_fingerPrint_void_init(UART_config *finger_ptr);

void H_fingerPrint_void_sendcomnd(const char * command,u8 size );

void H_fingerPrint_void_Recivecommand(void );





#endif /* FIGERPRINT_FINGERPRINT_INT_H_ */
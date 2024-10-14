/*
 * 7_Segment.h
 *
 *  Created on: Oct 2, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_7_SEGMENT_ECU_7_SEGMENT_H_
#define ECUAL_7_SEGMENT_ECU_7_SEGMENT_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_7_Segment_CFG.h"

/* Section 2 : Macros Declarations */

#define SEGMENT_DECODER_LIMIT       4
#define SEGMENT_DIGIT_LIMIT         9

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
	SEGMENT_COMMON_ANODE = 0,
	SEGMENT_COMMON_CATHODE
}SEGMENT_KEY_T;

typedef struct {
	PIN_CFG_T SEGMENT_PINS[4];
	SEGMENT_KEY_T SEGMENT_CON;
}SEGMENT_T;

/* Section 5 : Functions Declarations */

Std_ReturnType SEGMENT_INITIALIZE(const SEGMENT_T *seg);
Std_ReturnType SEGMENT_WRITE_VALUE(const SEGMENT_T *seg , uint8 number);

#endif /* ECUAL_7_SEGMENT_ECU_7_SEGMENT_H_ */

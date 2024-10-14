/*
 * ECU_RELAY.h
 *
 *  Created on: Sep 26, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_RELAY_ECU_RELAY_H_
#define ECUAL_RELAY_ECU_RELAY_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_RELAY_CFG.h"


/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
	RELAY_OFF = 0,
	RELAY_ON
}RELAY_STATE;

typedef struct {
	PIN_CFG_T RELAY_PIN;
}RELAY_T;

/* Section 5 : Functions Declarations */

Std_ReturnType RELAY_INITIALIZE (const RELAY_T *relay);
Std_ReturnType RELAY_TURN_ON (const RELAY_T *relay);
Std_ReturnType RELAY_TURN_OFF (const RELAY_T *relay);
Std_ReturnType RELAY_TOGGLE (const RELAY_T *relay);
Std_ReturnType RELAY_GET_STATUS (const RELAY_T *relay , LOGIC_T *relay_st);

#endif /* ECUAL_RELAY_ECU_RELAY_H_ */

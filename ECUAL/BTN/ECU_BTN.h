/*
 * ECU_BTN.h
 *
 *  Created on: Sep 21, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_BTN_ECU_BTN_H_
#define ECUAL_BTN_ECU_BTN_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_BTN_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
	BTN_ACTIVE_HIGH = 0,    //PULL DOWN RESISTOR
	BTN_ACTIVE_LOW 			//PULL UP RESISTOR
}BTN_CONNECTION;

typedef enum {
	BTN_PRESSED = 0,
	BTN_RELEASED
}BTN_STATUS;

typedef struct {
	PIN_CFG_T PIN;
	BTN_CONNECTION BTN_CON;
	BTN_STATUS BTN_STATE;
}BTN_T;

/* Section 5 : Functions Declarations */

Std_ReturnType BTN_INITIALIZE(const BTN_T *btn);
Std_ReturnType BTN_GET_STATUS(const BTN_T *btn,BTN_STATUS *btn_st);

#endif /* ECUAL_BTN_ECU_BTN_H_ */

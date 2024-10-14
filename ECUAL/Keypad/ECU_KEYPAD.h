/*
 * ECU_KEYPAD.h
 *
 *  Created on: Oct 8, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_KEYPAD_ECU_KEYPAD_H_
#define ECUAL_KEYPAD_ECU_KEYPAD_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_KEYPAD_CFG.h"

/* Section 2 : Macros Declarations */

#define KEYPAD_ROWS                 0x04
#define KEYPAD_COLUMNS              0x04

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum{
	KEYPAD_ACTIVE_HIGH = 0, // Resistor Pull Down
	KEYPAD_ACTIVE_LOW		// Resistor Pull Up
}KEYPAD_ACTIVE_STATE_T;

typedef struct{
	PIN_CFG_T KEYPAD_ROWS_PINS[KEYPAD_ROWS];
	PIN_CFG_T KEYPAD_COLUMNS_PINS[KEYPAD_COLUMNS];
	KEYPAD_ACTIVE_STATE_T KEYPAD_CON;
}KEYPAD_T;

/* Section 5 : Functions Declarations */

Std_ReturnType KEYPAD_INITIALIZE(const KEYPAD_T *keypad);
Std_ReturnType KEYPAD_GET_DATA(const KEYPAD_T *keypad , uint8 *data);

#endif /* ECUAL_KEYPAD_ECU_KEYPAD_H_ */

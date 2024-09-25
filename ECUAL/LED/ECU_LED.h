/*
 * ECU_LED.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_LED_ECU_LED_H_
#define ECUAL_LED_ECU_LED_H_

/* Section 1 : Includes */

#include "ECU_LED_CFG.h"
#include "../../MCAL/GPIO/HAL_GPIO.h"

/* Section 2 : Macros Declarations */

#define LED_DIRECT          (DIRECTION_T)GPIO_OUTPUT

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum{
	LED_OFF = 0,
	LED_ON
}LED_LOGIC;

typedef struct{
	PIN_CFG_T LED_Pin;
}LED_T;

/* Section 5 : Functions Declarations */
Std_ReturnType LED_INITIALIZE(const LED_T *led);
Std_ReturnType LED_TURN_ON(const LED_T *led);
Std_ReturnType LED_TURN_OFF(const LED_T *led);
Std_ReturnType LED_TOGGLE(const LED_T *led);
Std_ReturnType LED_GET_LOGIC(const LED_T *led,LOGIC_T *LOG);


#endif /* ECUAL_LED_ECU_LED_H_ */

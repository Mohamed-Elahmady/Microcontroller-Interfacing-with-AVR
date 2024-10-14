/*
 * ECU_DC_MOTOR.h
 *
 *  Created on: Sep 29, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_DC_MOTOR_ECU_DC_MOTOR_H_
#define ECUAL_DC_MOTOR_ECU_DC_MOTOR_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "ECU_DC_MOTOR_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
	DC_MOTOR_OFF = 0,
	DC_MOTOR_ON
}DC_MOTOR_STATE;

typedef enum {
	DC_MOTOR_STOPED = 0,
	DC_MOTOR_CW,
	DC_MOTOR_CCW
}DC_MOTOR_ROTATE;

typedef struct {
	PIN_CFG_T DC_MOTOR_PIN[2];
}DC_MOTOR_T;

/* Section 5 : Functions Declarations */

Std_ReturnType DC_MOTOR_INITIALIZE(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_ROTATE_CW(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_ROTATE_CCW(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_STOP(const DC_MOTOR_T *motor);
Std_ReturnType DC_MOTOR_GET_ROTATION_DIRECTION(const DC_MOTOR_T *motor ,DC_MOTOR_ROTATE *rot);

#endif /* ECUAL_DC_MOTOR_ECU_DC_MOTOR_H_ */


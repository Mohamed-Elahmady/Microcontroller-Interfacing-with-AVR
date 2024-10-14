/*
 * ECU_DC_MOTOR.c
 *
 *  Created on: Sep 29, 2024
 *      Author: Mohamed Elahmady
 */


#include "ECU_DC_MOTOR.h"

#if DC_MOTOR_CFG == (DC_MOTOR_CFG_ENABLE)

Std_ReturnType DC_MOTOR_INITIALIZE(const DC_MOTOR_T *motor){
	Std_ReturnType Retval = E_OK;
	if(NULL == motor){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_INITIALIZE(&(motor->DC_MOTOR_PIN[0]));
		Retval = GPIO_PIN_INITIALIZE(&(motor->DC_MOTOR_PIN[1]));
	}
	return Retval;
}

#endif

#if DC_MOTOR_CFG == (DC_MOTOR_CFG_ENABLE)

Std_ReturnType DC_MOTOR_ROTATE_CW(const DC_MOTOR_T *motor){
	Std_ReturnType Retval = E_OK;
	if(NULL == motor){
			Retval = E_NOT_OK;
		}
		else{
			LOGIC_T IN1 = (LOGIC_T)DC_MOTOR_ON;
			LOGIC_T IN2 = (LOGIC_T)DC_MOTOR_OFF;
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[0]) , IN1);
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[1]) , IN2);
		}
		return Retval;
}

#endif

#if DC_MOTOR_CFG == (DC_MOTOR_CFG_ENABLE)

Std_ReturnType DC_MOTOR_ROTATE_CCW(const DC_MOTOR_T *motor){
	Std_ReturnType Retval = E_OK;
	if(NULL == motor){
			Retval = E_NOT_OK;
		}
		else{
			LOGIC_T IN1 = (LOGIC_T)DC_MOTOR_OFF;
			LOGIC_T IN2 = (LOGIC_T)DC_MOTOR_ON;
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[0]) , IN1);
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[1]) , IN2);
		}
		return Retval;
}

#endif

#if DC_MOTOR_CFG == (DC_MOTOR_CFG_ENABLE)

Std_ReturnType DC_MOTOR_STOP(const DC_MOTOR_T *motor){
	Std_ReturnType Retval = E_OK;
	if(NULL == motor){
			Retval = E_NOT_OK;
		}
		else{
			LOGIC_T IN1 = (LOGIC_T)DC_MOTOR_OFF;
			LOGIC_T IN2 = (LOGIC_T)DC_MOTOR_OFF;
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[0]) , IN1);
			Retval = GPIO_PIN_WRITE_LOGIC(&(motor->DC_MOTOR_PIN[1]) , IN2);
		}
		return Retval;
}

#endif

#if DC_MOTOR_CFG == (DC_MOTOR_CFG_ENABLE)

Std_ReturnType DC_MOTOR_GET_ROTATION_DIRECTION(const DC_MOTOR_T *motor ,DC_MOTOR_ROTATE *rot){
	Std_ReturnType Retval = E_OK;
	if(NULL == motor || NULL == rot){
			Retval = E_NOT_OK;
		}
		else{
			LOGIC_T IN1 = (LOGIC_T)DC_MOTOR_OFF;
			LOGIC_T IN2 = (LOGIC_T)DC_MOTOR_OFF;
			Retval = GPIO_PIN_READ_LOGIC(&(motor->DC_MOTOR_PIN[0]) , &(IN1));
			Retval = GPIO_PIN_READ_LOGIC(&(motor->DC_MOTOR_PIN[1]) , &(IN2));
			if(IN1 == (LOGIC_T)DC_MOTOR_ON && IN2 == (LOGIC_T)DC_MOTOR_OFF){
				*rot = DC_MOTOR_CW;
			}
			else if (IN1 == (LOGIC_T)DC_MOTOR_OFF && IN2 == (LOGIC_T)DC_MOTOR_ON){
				*rot = DC_MOTOR_CCW;
			}
			else{
				*rot = DC_MOTOR_STOPED;
			}

		}
		return Retval;
}

#endif

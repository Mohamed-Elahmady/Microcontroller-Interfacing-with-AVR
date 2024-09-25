/*
 * ECU_LED.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */


#include "ECU_LED.h"


Std_ReturnType LED_INITIALIZE(const LED_T *led){
	Std_ReturnType Retval = E_OK;
	if(NULL == led){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_INITIALIZE(&(led->LED_Pin));
	}
	return Retval;
}
Std_ReturnType LED_TURN_ON(const LED_T *led){
	Std_ReturnType Retval = E_OK;
	if(NULL == led){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(led->LED_Pin),(LOGIC_T)LED_ON);
	}
	return Retval;
}
Std_ReturnType LED_TURN_OFF(const LED_T *led){
	Std_ReturnType Retval = E_OK;
	if(NULL == led){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(led->LED_Pin),(LOGIC_T)LED_OFF);
	}
	return Retval;
}
Std_ReturnType LED_TOGGLE(const LED_T *led){
	Std_ReturnType Retval = E_OK;
	if(NULL == led){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_TOGGLE_LOGIC(&(led->LED_Pin));
	}
	return Retval;
}
Std_ReturnType LED_GET_LOGIC(const LED_T *led,LOGIC_T *LOG){
	Std_ReturnType Retval = E_OK;
	if(NULL == led || NULL == LOG){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_READ_LOGIC(&(led->LED_Pin),LOG);
	}
	return Retval;
}

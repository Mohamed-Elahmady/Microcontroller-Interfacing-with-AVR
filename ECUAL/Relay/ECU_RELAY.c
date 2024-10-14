/*
 * ECU_RELAY.c
 *
 *  Created on: Sep 26, 2024
 *      Author: Mohamed Elahmady
 */


#include "ECU_RELAY.h"

Std_ReturnType RELAY_INITIALIZE (const RELAY_T *relay){
	Std_ReturnType Retval = E_OK;
	if(NULL == relay){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_INITIALIZE(&(relay->RELAY_PIN));
	}
	return Retval;
}
Std_ReturnType RELAY_TURN_ON (const RELAY_T *relay){
	Std_ReturnType Retval = E_OK;
	if(NULL == relay){
		Retval = E_NOT_OK;
	}
	else{
		LOGIC_T log = (LOGIC_T)RELAY_ON;
		Retval = GPIO_PIN_WRITE_LOGIC(&(relay->RELAY_PIN),log);
	}
	return Retval;
}
Std_ReturnType RELAY_TURN_OFF (const RELAY_T *relay){
	Std_ReturnType Retval = E_OK;
	if(NULL == relay){
		Retval = E_NOT_OK;
	}
	else{
		LOGIC_T log = (LOGIC_T)RELAY_OFF;
		Retval = GPIO_PIN_WRITE_LOGIC(&(relay->RELAY_PIN),log);
	}
	return Retval;
}
Std_ReturnType RELAY_TOGGLE (const RELAY_T *relay){
	Std_ReturnType Retval = E_OK;
	if(NULL == relay){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_TOGGLE_LOGIC(&(relay->RELAY_PIN));
	}
	return Retval;
}
Std_ReturnType RELAY_GET_STATUS (const RELAY_T *relay , LOGIC_T *relay_st){
	Std_ReturnType Retval = E_OK;
	if(NULL == relay || NULL == relay_st){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_READ_LOGIC(&(relay->RELAY_PIN) , relay_st);
	}
	return Retval;
}

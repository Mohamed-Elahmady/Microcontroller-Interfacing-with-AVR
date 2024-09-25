/*
 * ECU_BTN.c
 *
 *  Created on: Sep 21, 2024
 *      Author: Mohamed Elahmady
 */

#include "ECU_BTN.h"

Std_ReturnType BTN_INITIALIZE(const BTN_T *btn){
	Std_ReturnType Retval = E_OK;
	if(NULL == btn){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(btn->PIN));
	}
	return Retval;
}
Std_ReturnType BTN_GET_STATUS(const BTN_T *btn,BTN_STATUS *btn_st){
	Std_ReturnType Retval = E_OK;
	if(NULL == btn || NULL == btn_st){
		Retval = E_NOT_OK;
	}
	else{
		LOGIC_T log = GPIO_LOW;
		Retval = GPIO_PIN_READ_LOGIC(&(btn->PIN),&log);
		if(BTN_ACTIVE_HIGH == btn->BTN_CON){
			if(GPIO_HIGH == log){
				*btn_st = BTN_PRESSED;
			}
			else{
				*btn_st = BTN_RELEASED;
			}
		}
		else if(BTN_ACTIVE_LOW == btn->BTN_CON){
			if(GPIO_HIGH == log){
				*btn_st = BTN_RELEASED;
			}
			else{
				*btn_st = BTN_PRESSED;
			}
		}
		else{
			Retval = E_NOT_OK;
		}
	}
	return Retval;
}

/*
 * ECU_KEYPAD.c
 *
 *  Created on: Oct 8, 2024
 *      Author: Mohamed Elahmady
 */

#include "ECU_KEYPAD.h"

uint8 keypad_semi_calc[KEYPAD_ROWS][KEYPAD_COLUMNS] = {{'7' , '8' , '9' , '/'} ,
													   {'4' , '5' , '6' , '*'} ,
													   {'1' , '2' , '3' , '-'} ,
													   {'C' , '0' , '=' , '+'}};

#if KEYPAD_CFG_ENABLE == KEYPAD_CFG

Std_ReturnType KEYPAD_INITIALIZE(const KEYPAD_T *keypad){
	Std_ReturnType Retval = E_OK;
	if(NULL == keypad){
		Retval = E_NOT_OK;
	}
	else{
		for(uint8 r = 0 ; r < (KEYPAD_ROWS) ; r++){
			Retval = GPIO_PIN_INITIALIZE(&(keypad->KEYPAD_ROWS_PINS[r]));
		}
		for(uint8 c = 0 ; c < (KEYPAD_COLUMNS) ; c++){
			Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(keypad->KEYPAD_COLUMNS_PINS[c]));
		}
	}
	return Retval;
}

#endif

#if KEYPAD_CFG_ENABLE == KEYPAD_CFG

Std_ReturnType KEYPAD_GET_DATA(const KEYPAD_T *keypad , uint8 *data){
	Std_ReturnType Retval = E_OK;
	if(NULL == keypad || NULL == data){
		Retval = E_NOT_OK;
	}
	else{
		LOGIC_T log = GPIO_LOW;
		for(uint8 r = 0 ; r < (KEYPAD_ROWS) ; r++){
			for(uint8 i = 0 ; i < (KEYPAD_ROWS) ; i++){
				Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->KEYPAD_ROWS_PINS[i]) , GPIO_LOW);
			}
			Retval = GPIO_PIN_WRITE_LOGIC(&(keypad->KEYPAD_ROWS_PINS[r]) , GPIO_HIGH);
			for(uint8 c = 0 ; c < (KEYPAD_COLUMNS) ; c++){
				Retval = GPIO_PIN_READ_LOGIC(&(keypad->KEYPAD_COLUMNS_PINS[c]) , &log);
				if(KEYPAD_ACTIVE_HIGH == keypad->KEYPAD_CON){
					if(GPIO_HIGH == log){
						*data = keypad_semi_calc[r][c];
					}
					else{}
				}
				else if(KEYPAD_ACTIVE_LOW == keypad->KEYPAD_CON){
					if(GPIO_LOW == log){
						*data = keypad_semi_calc[r][c];
					}
					else{}
				}
				else{}
			}
		}
	}
	return Retval;
}

#endif

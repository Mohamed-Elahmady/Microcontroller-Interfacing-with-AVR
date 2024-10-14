/*
 * 7_Segment.c
 *
 *  Created on: Oct 2, 2024
 *      Author: Mohamed Elahmady
 */

#include "ECU_7_Segment.h"

Std_ReturnType SEGMENT_INITIALIZE(const SEGMENT_T *seg){
	Std_ReturnType Retval = E_OK;
	if(NULL== seg){
		Retval = E_NOT_OK;
	}
	else{
		for(int i = 0 ; i < SEGMENT_DECODER_LIMIT ; i++){
			Retval = GPIO_PIN_INITIALIZE(&(seg->SEGMENT_PINS[i]));
		}
	}
	return Retval;
}
Std_ReturnType SEGMENT_WRITE_VALUE(const SEGMENT_T *seg , uint8 number){
	Std_ReturnType Retval = E_OK;
		if(NULL== seg || number > SEGMENT_DIGIT_LIMIT){
			Retval = E_NOT_OK;
		}
		else{
			for(int i = 0 ; i < SEGMENT_DECODER_LIMIT ; i++){
				Retval = GPIO_PIN_WRITE_LOGIC(&(seg->SEGMENT_PINS[i]) , ((number >> i) & 0x01));
			}
		}
		return Retval;
}

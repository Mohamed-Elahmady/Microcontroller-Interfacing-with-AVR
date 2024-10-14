/*
 * APP.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

#include <util/delay.h>
#include "APP.h"

Std_ReturnType Ret = E_NOT_OK;
uint8 var = 0;

int main() {
	Application_intialize();
	while(1){
		Ret = KEYPAD_GET_DATA(&keypad1 , &var);
		if('3' == var){
			Ret = LED_TURN_ON(&led1);
		}
		else{
			Ret = LED_TURN_OFF(&led1);
		}
	}
	return 0;
}
void Application_intialize(void) {
	ECU_INITIALIZE();
}

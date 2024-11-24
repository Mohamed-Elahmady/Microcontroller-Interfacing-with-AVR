/*
 * APP.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

#include <util/delay.h>
#include "APP.h"

Std_ReturnType Ret = E_NOT_OK;



int main() {
	Application_intialize();

	while(1){

	}
	return 0;
}
void Application_intialize(void) {
	ECU_INITIALIZE();
}

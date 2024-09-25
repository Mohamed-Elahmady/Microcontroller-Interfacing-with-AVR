/*
 * APP.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

#include <util/delay.h>
#include "APP.h"

LED_T led1 = {
	.LED_Pin.PORT = PORTC_IND,
	.LED_Pin.PIN  = GPIO_PIN0,
	.LED_Pin.DIRECTION = GPIO_OUTPUT,
	.LED_Pin.LOGIC = GPIO_LOW
};

LED_T led2 = {
	.LED_Pin.PORT = PORTC_IND,
	.LED_Pin.PIN  = GPIO_PIN1,
	.LED_Pin.DIRECTION = GPIO_OUTPUT,
	.LED_Pin.LOGIC = GPIO_LOW
};
LED_T led3 = {
	.LED_Pin.PORT = PORTC_IND,
	.LED_Pin.PIN  = GPIO_PIN2,
	.LED_Pin.DIRECTION = GPIO_OUTPUT,
	.LED_Pin.LOGIC = GPIO_LOW
};
LED_T led4 = {
	.LED_Pin.PORT = PORTC_IND,
	.LED_Pin.PIN  = GPIO_PIN3,
	.LED_Pin.DIRECTION = GPIO_OUTPUT,
	.LED_Pin.LOGIC = GPIO_LOW
};

Std_ReturnType Ret = E_NOT_OK;

int main() {
	Application_intialize();
	    while(1){
	        LED_TURN_ON(&led1);
	        _delay_ms(500);
	        LED_TURN_OFF(&led1);
	        LED_TURN_ON(&led2);
	        _delay_ms(500);
	        LED_TURN_OFF(&led2);
	        LED_TURN_ON(&led3);
	        _delay_ms(500);
	        LED_TURN_OFF(&led3);
	        LED_TURN_ON(&led4);
	        _delay_ms(500);
	        LED_TURN_OFF(&led4);
	        LED_TURN_ON(&led3);
	        _delay_ms(500);
	        LED_TURN_OFF(&led3);
	        LED_TURN_ON(&led2);
	        _delay_ms(500);
	        LED_TURN_OFF(&led2);
	    }
}
void Application_intialize(void)
{
	Ret = LED_INITIALIZE(&(led1));
	Ret = LED_INITIALIZE(&(led2));
	Ret = LED_INITIALIZE(&(led3));
	Ret = LED_INITIALIZE(&(led4));
}

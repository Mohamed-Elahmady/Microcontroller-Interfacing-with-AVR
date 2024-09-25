/*
 * HAL_GPIO.c
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */


#include "HAL_GPIO.h"

volatile uint8 *DDR_REG[] = {&DDRA,&DDRB,&DDRC,&DDRD};
volatile uint8 *PIN_REG[] = {&PINA,&PINB,&PINC,&PIND};
volatile uint8 *PORT_REG[] = {&PORTA,&PORTB,&PORTC,&PORTD};

						/*Pin Functions*/

#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_DIRECTION_INITIALIZE (const PIN_CFG_T *Pin){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX)){
		Retval = E_NOT_OK;
	}
	else{
			switch(Pin->DIRECTION){
			case GPIO_INPUT:
				CLEAR_BIT(*(DDR_REG[Pin->PORT]),Pin->PIN);
				break;
			case GPIO_OUTPUT:
				SET_BIT(*(DDR_REG[Pin->PORT]),Pin->PIN);
				break;
			default:
				Retval = E_NOT_OK;
				break;
			}
	}
	return Retval;
}
#endif
#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_GET_DIRECTION (const PIN_CFG_T *Pin,DIRECTION_T *DIR){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX) || NULL == DIR){
		Retval = E_NOT_OK;
	}
	else{
		*DIR = READ_BIT(*(DDR_REG[Pin->PORT]),Pin->PIN);
	}
	return Retval;
}
#endif
#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_WRITE_LOGIC (const PIN_CFG_T *Pin,LOGIC_T LOG){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		switch(LOG){
		case GPIO_LOW:
			CLEAR_BIT(*(PORT_REG[Pin->PORT]),Pin->PIN);
			break;
		case GPIO_HIGH:
			SET_BIT(*(PORT_REG[Pin->PORT]),Pin->PIN);
			break;
		default:
			Retval = E_NOT_OK;
			break;
		}
	}
	return Retval;
}
#endif
#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_READ_LOGIC (const PIN_CFG_T *Pin,LOGIC_T *LOG){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX) || NULL == LOG){
		Retval = E_NOT_OK;
	}
	else{
		*LOG  = READ_BIT(*(PIN_REG[Pin->PORT]),Pin->PIN);
	}
	return Retval;
}
#endif
#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_TOGGLE_LOGIC (const PIN_CFG_T *Pin){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		TOGGLE_BIT(*(PORT_REG[Pin->PORT]),Pin->PIN);
	}
	return Retval;
}
#endif
#if GPIO_PIN_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PIN_INITIALIZE (const PIN_CFG_T *Pin){
	Std_ReturnType Retval = E_OK;
	if(NULL == Pin || (Pin->PIN) >= (PORT_PIN_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_DIRECTION_INITIALIZE(Pin);
		Retval = GPIO_PIN_WRITE_LOGIC(Pin,Pin->LOGIC);
	}
	return Retval;
}
#endif

						/*PORT Functions*/
#if GPIO_PORT_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PORT_DIRECTION_INITIALIZE (PORT_T PORT,uint8 DIR){
	Std_ReturnType Retval = E_OK;
	if(PORT >= (PORT_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		*(DDR_REG[PORT]) = DIR;
	}
	return Retval;
}
#endif
#if GPIO_PORT_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PORT_GET_DIRECTION (PORT_T PORT ,uint8 *DIR){
	Std_ReturnType Retval = E_OK;
	if(PORT >= (PORT_MAX) || NULL == DIR){
		Retval = E_NOT_OK;
	}
	else{
		*DIR = *(DDR_REG[PORT]);
	}
	return Retval;
}
#endif
#if GPIO_PORT_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PORT_WRITE_LOGIC (PORT_T PORT,uint8 LOG){
	Std_ReturnType Retval = E_OK;
	if(PORT >= (PORT_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		*(PORT_REG[PORT]) = LOG;
	}
	return Retval;
}
#endif
#if GPIO_PORT_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PORT_READ_LOGIC (PORT_T PORT,uint8 *LOG){
	Std_ReturnType Retval = E_OK;
	if(PORT >= (PORT_MAX) || NULL == LOG){
		Retval = E_NOT_OK;
	}
	else{
		*LOG = *(PORT_REG[PORT]);
	}
	return Retval;
}
#endif
#if GPIO_PORT_CFG == GPIO_CFG_ENABLE
Std_ReturnType GPIO_PORT_TOGGLE_LOGIC (PORT_T PORT){
	Std_ReturnType Retval = E_OK;
	if(PORT >= (PORT_MAX)){
		Retval = E_NOT_OK;
	}
	else{
		*(PORT_REG[PORT]) ^= PORT_MASK;
	}
	return Retval;
}
#endif

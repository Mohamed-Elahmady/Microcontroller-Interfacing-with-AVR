/*
 * EXT_INTERRUPT.c
 *
 *  Created on: Nov 23, 2024
 *      Author: Mohamed Elahmady
 */

#include "HAL_EXT_INTERRUPT.h"


/*************** Helper Functions  *****************/

void(*int0_isr_func)(void);
void(*int1_isr_func)(void);
void(*int2_isr_func)(void);

static Std_ReturnType EXT_INTX_DISABLE(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INTX_ENABLE(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INTX_CLEAR_FLAG(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INTX_PIN_INITIALIZE(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INTX_SET_EDGE(const EXT_INTX_T *intx);

static Std_ReturnType EXT_INTX_SET_HANDLER(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INT2_SET_ISR(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INT1_SET_ISR(const EXT_INTX_T *intx);
static Std_ReturnType EXT_INT0_SET_ISR(const EXT_INTX_T *intx);


/*************** Main Functions  *****************/

Std_ReturnType EXT_INTX_INITIALIZE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		Retval = EXT_INTX_DISABLE(intx);
		Retval = EXT_INTX_CLEAR_FLAG(intx);
		Retval = EXT_INTX_PIN_INITIALIZE(intx);
		Retval = EXT_INTX_SET_EDGE(intx);
		Retval = EXT_INTX_SET_HANDLER(intx);
		Retval = EXT_INTX_ENABLE(intx);
	}
	return Retval;
}

Std_ReturnType EXT_INTX_DE_INITIALIZE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		Retval = EXT_INTX_DISABLE(intx);
		Retval = EXT_INTX_CLEAR_FLAG(intx);
	}
	return Retval;
}

void ISR_INT0_TEMP(void){
	EXT_INT0_CLEAR_FLAG();

	if(int0_isr_func){
		int0_isr_func();
	}
	else{/*Nothing*/}
}

void ISR_INT1_TEMP(void){
	EXT_INT1_CLEAR_FLAG();

	if(int1_isr_func){
		int1_isr_func();
	}
	else{/*Nothing*/}
}

void ISR_INT2_TEMP(void){
	EXT_INT2_CLEAR_FLAG();

	if(int2_isr_func){
		int2_isr_func();
	}
	else{/*Nothing*/}
}

/*************** Helper Functions  *****************/

static Std_ReturnType EXT_INTX_DISABLE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		switch(intx->src){
			case INT0_N:
				EXT_INT0_SET_DISABLE();
				break;
			case INT1_N:
				EXT_INT1_SET_DISABLE();
				break;
			case INT2_N:
				EXT_INT2_SET_DISABLE();
				break;
			default:
				Retval = E_NOT_OK;
				break;
		}
	}
	return Retval;
}

static Std_ReturnType EXT_INTX_ENABLE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		switch(intx->src){
			case INT0_N:
				GLOBAL_INTERRUPT_ENABLE_SIGNAL();
				EXT_INT0_SET_ENABLE();
				break;
			case INT1_N:
				GLOBAL_INTERRUPT_ENABLE_SIGNAL();
				EXT_INT1_SET_ENABLE();
				break;
			case INT2_N:
				GLOBAL_INTERRUPT_ENABLE_SIGNAL();
				EXT_INT2_SET_ENABLE();
				break;
			default:
				Retval = E_NOT_OK;
				break;
		}
	}
	return Retval;
}

static Std_ReturnType EXT_INTX_CLEAR_FLAG(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		switch(intx->src){
			case INT0_N:
				EXT_INT0_CLEAR_FLAG();
				break;
			case INT1_N:
				EXT_INT1_CLEAR_FLAG();
				break;
			case INT2_N:
				EXT_INT2_CLEAR_FLAG();
				break;
			default:
				Retval = E_NOT_OK;
				break;
		}
	}
	return Retval;
}

static Std_ReturnType EXT_INTX_SET_EDGE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
		if(NULL == intx){
			Retval = E_NOT_OK;
		}
		else{
			switch(intx->src){
				case INT0_N:
					if(LOW_LEVEL == intx->action){
						EXT_INT0_LOW_LEVEL_ISC00();
						EXT_INT0_LOW_LEVEL_ISC01();
					}
					else if(ANY_CHANGE == intx->action){
						EXT_INT0_LOGICAL_CHANGE_ISC00();
						EXT_INT0_LOGICAL_CHANGE_ISC01();
					}
					else if(FALLING_EDGE == intx->action){
						EXT_INT0_FALLING_EDGE_ISC00();
						EXT_INT0_FALLING_EDGE_ISC01();
					}
					else if(RISING_EDGE == intx->action){
						EXT_INT0_RISING_EDGE_ISC00();
						EXT_INT0_RISING_EDGE_ISC01();
					}
					else{
						Retval = E_NOT_OK;
					}
					break;
				case INT1_N:
					if(LOW_LEVEL == intx->action){
						EXT_INT1_LOW_LEVEL_ISC10();
						EXT_INT1_LOW_LEVEL_ISC11();
					}
					else if(ANY_CHANGE == intx->action){
						EXT_INT1_LOGICAL_CHANGE_ISC10();
						EXT_INT1_LOGICAL_CHANGE_ISC11();
					}
					else if(FALLING_EDGE == intx->action){
						EXT_INT1_FALLING_EDGE_ISC10();
						EXT_INT1_FALLING_EDGE_ISC11();
					}
					else if(RISING_EDGE == intx->action){
						EXT_INT1_RISING_EDGE_ISC10();
						EXT_INT1_RISING_EDGE_ISC11();
					}
					else{
						Retval = E_NOT_OK;
					}
					break;
				case INT2_N:
					if(FALLING_EDGE == intx->action){
						EXT_INT2_FALLING_EDGE_ISC2();
					}
					else if(RISING_EDGE == intx->action){
						EXT_INT2_RISING_EDGE_ISC2();
					}
					else{
						Retval = E_NOT_OK;
					}
					break;
				default:
					Retval = E_NOT_OK;
					break;
			}
		}
		return Retval;
}

static Std_ReturnType EXT_INTX_SET_HANDLER(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		switch(intx->src){
			case INT0_N:
				EXT_INT0_SET_ISR(intx);
				break;
			case INT1_N:
				EXT_INT1_SET_ISR(intx);
				break;
			case INT2_N:
				EXT_INT2_SET_ISR(intx);
				break;
			default:
				Retval = E_NOT_OK;
				break;
		}
	}
	return Retval;
}

static Std_ReturnType EXT_INTX_PIN_INITIALIZE(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_DIRECTION_INITIALIZE(&(intx->pin));
	}
	return Retval;
}

static Std_ReturnType EXT_INT0_SET_ISR(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		int0_isr_func = intx->INTX_HANDLE;
	}
	return Retval;
}

static Std_ReturnType EXT_INT1_SET_ISR(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		int1_isr_func = intx->INTX_HANDLE;
	}
	return Retval;
}

static Std_ReturnType EXT_INT2_SET_ISR(const EXT_INTX_T *intx){
	Std_ReturnType Retval = E_OK;
	if(NULL == intx){
		Retval = E_NOT_OK;
	}
	else{
		int2_isr_func = intx->INTX_HANDLE;
	}
	return Retval;
}



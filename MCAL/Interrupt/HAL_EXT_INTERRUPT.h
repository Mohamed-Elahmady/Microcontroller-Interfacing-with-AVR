/*
 * EXT_INTERRUPT.h
 *
 *  Created on: Nov 23, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef MCAL_INTERRUPT_HAL_EXT_INTERRUPT_H_
#define MCAL_INTERRUPT_HAL_EXT_INTERRUPT_H_

/* Section 1 : Includes */

#include "HAL_INTERRUPT_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */

// 			INT0

#define EXT_INT0_CLEAR_FLAG()				  (GIFR |= (1 << INTF0))

#define EXT_INT0_SET_DISABLE()				  (GICR &= ~(1 << INT0))
#define EXT_INT0_SET_ENABLE()				  (GICR |= (1 << INT0))

// ACTION

#define EXT_INT0_LOW_LEVEL_ISC00()			  (MCUCR &= ~(1 << ISC00))
#define EXT_INT0_LOW_LEVEL_ISC01()			  (MCUCR &= ~(1 << ISC01))

#define EXT_INT0_LOGICAL_CHANGE_ISC00()		  (MCUCR |= (1 << ISC00))
#define EXT_INT0_LOGICAL_CHANGE_ISC01()		  (MCUCR &= ~(1 << ISC01))

#define EXT_INT0_FALLING_EDGE_ISC00()		  (MCUCR &= ~(1 << ISC00))
#define EXT_INT0_FALLING_EDGE_ISC01()		  (MCUCR |= (1 << ISC01))

#define EXT_INT0_RISING_EDGE_ISC00()		  (MCUCR |= (1 << ISC00))
#define EXT_INT0_RISING_EDGE_ISC01()		  (MCUCR |= (1 << ISC01))


// 			INT1

#define EXT_INT1_CLEAR_FLAG()				  (GIFR |= (1 << INTF1))

#define EXT_INT1_SET_DISABLE()				  (GICR &= ~(1 << INT1))
#define EXT_INT1_SET_ENABLE()				  (GICR |= (1 << INT1))

// ACTION

#define EXT_INT1_LOW_LEVEL_ISC10()			  (MCUCR &= ~(1 << ISC10))
#define EXT_INT1_LOW_LEVEL_ISC11()			  (MCUCR &= ~(1 << ISC11))

#define EXT_INT1_LOGICAL_CHANGE_ISC10()		  (MCUCR |= (1 << ISC10))
#define EXT_INT1_LOGICAL_CHANGE_ISC11()		  (MCUCR &= ~(1 << ISC11))

#define EXT_INT1_FALLING_EDGE_ISC10()		  (MCUCR &= ~(1 << ISC10))
#define EXT_INT1_FALLING_EDGE_ISC11()		  (MCUCR |= (1 << ISC11))

#define EXT_INT1_RISING_EDGE_ISC10()		  (MCUCR |= (1 << ISC10))
#define EXT_INT1_RISING_EDGE_ISC11()		  (MCUCR |= (1 << ISC11))

// 			INT2

#define EXT_INT2_CLEAR_FLAG()				  (GIFR |= (1 << INTF2))

#define EXT_INT2_SET_DISABLE()				  (GICR &= ~(1 << INT2))
#define EXT_INT2_SET_ENABLE()				  (GICR |= (1 << INT2))

// ACTION

#define EXT_INT2_FALLING_EDGE_ISC2()		  (MCUCSR &= ~(1 << ISC2))
#define EXT_INT2_RISING_EDGE_ISC2()			  (MCUCSR |= (1 << ISC2))


/* Section 4 : User Defined Data Types Declarations */

typedef void (*EXT_INTERRUPT_HND)(void);

typedef enum {
	LOW_LEVEL = 0,
	ANY_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
}INTX_ACT_T;

typedef enum {
	INT0_N = 0,
	INT1_N,
	INT2_N
}INTX_SRC_T;

typedef struct{
	void(*INTX_HANDLE)(void);
	INTX_ACT_T action;
	INTX_SRC_T src;
	PIN_CFG_T pin;
}EXT_INTX_T;
/* Section 5 : Functions Declarations */

Std_ReturnType EXT_INTX_INITIALIZE(const EXT_INTX_T *intx);
Std_ReturnType EXT_INTX_DE_INITIALIZE(const EXT_INTX_T *intx);



#endif /* MCAL_INTERRUPT_HAL_EXT_INTERRUPT_H_ */

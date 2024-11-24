/*
 * HAL_INTERRUPT_CFG.h
 *
 *  Created on: Nov 23, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef MCAL_INTERRUPT_HAL_INTERRUPT_CFG_H_
#define MCAL_INTERRUPT_HAL_INTERRUPT_CFG_H_

/* Section 1 : Includes */

#include "HAL_INTERRUPT_CFG_GEN.h"
#include "../GPIO/HAL_GPIO.h"
#include "../MCAL_Std_Types.h"
#include "../Device_CFG.h"

/* Section 2 : Macros Declarations */

#define INTERRUPT_NOT_OCCUR		    0x00
#define INTERRUPT_OCCUR				0x01

#define INTERRUPT_DISABLE			0x00
#define INTERRUPT_ENABLE			0x01

/* Section 3 : Macros Functions Declarations */

#define READ_BIT(REG,BIT_POS)           (((REG) >> (BIT_POS)) & (BIT_MASK))

#define GLOBAL_INTERRUPT_DISABLE_SIGNAL()		(SREG &= ~(1 << SREG_I))
#define GLOBAL_INTERRUPT_ENABLE_SIGNAL()		(SREG |= 1 << SREG_I)

/* Section 4 : User Defined Data Types Declarations */



/* Section 5 : Functions Declarations */






#endif /* MCAL_INTERRUPT_HAL_INTERRUPT_CFG_H_ */

/*
 * ECU_INIT.h
 *
 *  Created on: Oct 2, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_ECU_INIT_H_
#define ECUAL_ECU_INIT_H_

/* Section 1 : Includes */

#include "LED/ECU_LED.h"
#include "BTN/ECU_BTN.h"
#include "RELAY/ECU_RELAY.h"
#include "DC_MOTOR/ECU_DC_MOTOR.h"
#include "7 Segment/ECU_7_Segment.h"
#include "Keypad/ECU_KEYPAD.h"
#include "CHAR LCD/CHR_LCD.h"
#include "../MCAL/Interrupt/HAL_INT_INTERRUPT.h"
#include "../MCAL/Interrupt/HAL_EXT_INTERRUPT.h"
#include "../MCAL/EEPROM/HAL_EEPROM.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */



/* Section 5 : Functions Declarations */

void ECU_INITIALIZE(void);


#endif /* ECUAL_ECU_INIT_H_ */

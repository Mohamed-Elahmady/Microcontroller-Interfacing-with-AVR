/*
 * HAL_EEPROM.h
 *
 *  Created on: Nov 24, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef MCAL_EEPROM_HAL_EEPROM_H_
#define MCAL_EEPROM_HAL_EEPROM_H_

/* Section 1 : Includes */

#include "HAL_EEPROM_CFG.h"
#include "../Interrupt/HAL_INTERRUPT_CFG.h"
#include "../MCAL_Std_Types.h"
#include "../Device_CFG.h"

/* Section 2 : Macros Declarations */



/* Section 3 : Macros Functions Declarations */

#define EEPROM_READ_1BYTE()							  (EECR |= (1 << EERE))
#define EEPROM_WRITE_1BYTE()					      (EECR |= (1 << EEWE))

#define EEPROM_MASTER_WRITE_ENABLE()			      (EECR |= (1 << EEMWE))

#define EEPROM_READY_INTERRUPT_DISABLE()			  (EECR &= ~(1 << EERIE))
#define EEPROM_READY_INTERRUPT_ENABLE()			      (EECR |= (1 << EERIE))

/* Section 4 : User Defined Data Types Declarations */



/* Section 5 : Functions Declarations */

Std_ReturnType DATA_EEPROM_WRITE_1BYTE(uint16 *ADD , uint8 data);
Std_ReturnType DATA_EEPROM_READ_1BYTE(uint16 *ADD , uint8 *data);



#endif /* MCAL_EEPROM_HAL_EEPROM_H_ */

/*
 * HAL_EEPROM.c
 *
 *  Created on: Nov 24, 2024
 *      Author: Mohamed Elahmady
 */

#include "HAL_EEPROM.h"


Std_ReturnType DATA_EEPROM_WRITE_1BYTE(uint16 *ADD , uint8 data){
	Std_ReturnType Retval = E_OK;
	if(NULL == ADD || *ADD > 0x3FF){
		Retval = E_NOT_OK;
	}
	else{
		uint8 GIE_STATUS = ((SREG>>SREG_I)&0x01);

		EEARH = (uint8)((*ADD >> 8)&0x03);
		EEARL = (uint8)((*ADD)&0xFF);

		EEDR = data;

		GLOBAL_INTERRUPT_DISABLE_SIGNAL();
		EEPROM_READY_INTERRUPT_DISABLE();

		EEPROM_MASTER_WRITE_ENABLE();
		EEPROM_WRITE_1BYTE();

		while(1 == ((EECR>>1)&0x01));

		if(1 == GIE_STATUS){
			GLOBAL_INTERRUPT_ENABLE_SIGNAL();
			EEPROM_READY_INTERRUPT_ENABLE();
		}
		else if(0 == GIE_STATUS){
			GLOBAL_INTERRUPT_DISABLE_SIGNAL();
			EEPROM_READY_INTERRUPT_DISABLE();
		}
		else{/*Nothing*/}

	}
	return Retval;
}
Std_ReturnType DATA_EEPROM_READ_1BYTE(uint16 *ADD , uint8 *data){
	Std_ReturnType Retval = E_OK;
	if(NULL == ADD || NULL == data || *ADD > 0x3FF){
		Retval = E_NOT_OK;
	}
	else{
		EEARH = (uint8)((*ADD >> 8)&0x03);
		EEARL = (uint8)((*ADD)&0xFF);

		EEPROM_READ_1BYTE();

		*data = EEDR;
	}
	return Retval;
}

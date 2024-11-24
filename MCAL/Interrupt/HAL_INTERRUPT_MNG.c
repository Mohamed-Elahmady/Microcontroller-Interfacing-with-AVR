/*
 * HAL_INTERRUPT_MNG.c
 *
 *  Created on: Nov 23, 2024
 *      Author: Mohamed Elahmady
 */


#include "HAL_INTERRUPT_MNG.h"

ISR(INT0_vect){
	if ((INTERRUPT_OCCUR == READ_BIT(GIFR, INTF0)) &&
	        (INTERRUPT_ENABLE == READ_BIT(GICR, INT0))) {
			ISR_INT0_TEMP();
	    }
}

ISR(INT1_vect){
	if ((INTERRUPT_OCCUR == READ_BIT(GIFR, INTF1)) &&
	        (INTERRUPT_ENABLE == READ_BIT(GICR, INT1))) {
			ISR_INT1_TEMP();
	    }
}

ISR(INT2_vect){
	if ((INTERRUPT_OCCUR == READ_BIT(GIFR, INTF2)) &&
	        (INTERRUPT_ENABLE == READ_BIT(GICR, INT2))) {
			ISR_INT2_TEMP();
	    }
}

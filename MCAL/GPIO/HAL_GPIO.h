/*
 * HAL_GPIO.h
 *
 *  Created on: Sep 20, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef MCAL_GPIO_HAL_GPIO_H_
#define MCAL_GPIO_HAL_GPIO_H_

/* Section 1 : Includes */

//#include <avr/iom32.h>
#include "../MCAL_Std_Types.h"
#include "HAL_GPIO_CFG.h"
#include "../Device_CFG.h"

/* Section 2 : Macros Declarations */

#define BIT_MASK               (uint8)0x01
#define PORT_MASK              (uint8)0xFF

#define PORT_PIN_MAX           8
#define PORT_MAX               4

/* Section 3 : Macros Functions Declarations */
#define SET_BIT(REG,BIT_POS)            (REG |= ((BIT_MASK) << (BIT_POS)))
#define CLEAR_BIT(REG,BIT_POS)          (REG &= ~((BIT_MASK) << (BIT_POS)))
#define TOGGLE_BIT(REG,BIT_POS)         (REG ^= ((BIT_MASK) << (BIT_POS)))
#define READ_BIT(REG,BIT_POS)           (((REG) >> (BIT_POS)) & (BIT_MASK))


/* Section 4 : User Defined Data Types Declarations */

typedef enum{
	PORTA_IND = 0,
	PORTB_IND,
	PORTC_IND,
	PORTD_IND,
}PORT_T;

typedef enum{
	GPIO_PIN0 = 0,
	GPIO_PIN1,
	GPIO_PIN2,
	GPIO_PIN3,
	GPIO_PIN4,
	GPIO_PIN5,
	GPIO_PIN6,
	GPIO_PIN7
}PIN_T;

typedef enum{
	GPIO_INPUT = 0,
	GPIO_OUTPUT
}DIRECTION_T;

typedef enum{
	GPIO_LOW = 0,
	GPIO_HIGH
}LOGIC_T;

typedef struct{
	uint8 PORT               :3;
	uint8 PIN                :3;
	uint8 DIRECTION          :1;
	uint8 LOGIC              :1;
}PIN_CFG_T;

/* Section 5 : Functions Declarations */

						/*Pin Functions*/
Std_ReturnType GPIO_PIN_DIRECTION_INITIALIZE (const PIN_CFG_T *Pin);
Std_ReturnType GPIO_PIN_GET_DIRECTION (const PIN_CFG_T *Pin,DIRECTION_T *DIR);
Std_ReturnType GPIO_PIN_WRITE_LOGIC (const PIN_CFG_T *Pin,LOGIC_T LOG);
Std_ReturnType GPIO_PIN_READ_LOGIC (const PIN_CFG_T *Pin,LOGIC_T *LOG);
Std_ReturnType GPIO_PIN_TOGGLE_LOGIC (const PIN_CFG_T *Pin);
Std_ReturnType GPIO_PIN_INITIALIZE (const PIN_CFG_T *Pin);


						/*PORT Functions*/
Std_ReturnType GPIO_PORT_DIRECTION_INITIALIZE (PORT_T PORT,uint8 DIR);
Std_ReturnType GPIO_PORT_GET_DIRECTION (PORT_T PORT ,uint8 *DIR);
Std_ReturnType GPIO_PORT_WRITE_LOGIC (PORT_T PORT,uint8 LOG);
Std_ReturnType GPIO_PORT_READ_LOGIC (PORT_T PORT,uint8 *LOG);
Std_ReturnType GPIO_PORT_TOGGLE_LOGIC (PORT_T PORT);


#endif /* MCAL_GPIO_HAL_GPIO_H_ */

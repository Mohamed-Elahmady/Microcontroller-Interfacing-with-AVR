/*
 * CHR_LCD.h
 *
 *  Created on: Nov 6, 2024
 *      Author: Mohamed Elahmady
 */

/* Section 0 : File Guard */

#ifndef ECUAL_CHAR_LCD_CHR_LCD_H_
#define ECUAL_CHAR_LCD_CHR_LCD_H_

/* Section 1 : Includes */

#include "../../MCAL/GPIO/HAL_GPIO.h"
#include "CHR_LCD_CFG.h"

/* Section 2 : Macros Declarations */

#define CHR_LCD_CLEAR_DISPLAY				0x01

#define CHR_LCD_CURSOR_HOME					0x02

#define CHR_LCD_ENS_DEC_SFT_OFF				0x04
#define CHR_LCD_ENS_DEC_SFT_ON				0x05
#define CHR_LCD_ENS_INC_SFT_OFF				0x06
#define CHR_LCD_ENS_INC_SFT_ON				0x07

#define CHR_LCD_DSP_OFF_ULC_OFF_BLC_OFF		0x08
#define CHR_LCD_DSP_ON_ULC_OFF_BLC_OFF		0x0C
#define CHR_LCD_DSP_ON_ULC_OFF_BLC_ON		0x0D
#define CHR_LCD_DSP_ON_ULC_ON_BLC_OFF		0x0E
#define CHR_LCD_DSP_ON_ULC_ON_BLC_ON		0x0F

#define CHR_LCD_CMV_LFT						0x10
#define CHR_LCD_CMV_RGT						0x11
#define CHR_LCD_DPS_LFT						0x18
#define CHR_LCD_DPS_RGT						0x1C

#define CHR_LCD_FNS_4BIT_1DL_F58			0x20
#define CHR_LCD_FNS_4BIT_1DL_F511			0x24
#define CHR_LCD_FNS_4BIT_2DL_F58			0x28
#define CHR_LCD_FNS_4BIT_2DL_F511			0x2C
#define CHR_LCD_FNS_8BIT_1DL_F58			0x30
#define CHR_LCD_FNS_8BIT_1DL_F511			0x34
#define CHR_LCD_FNS_8BIT_2DL_F58			0x38
#define CHR_LCD_FNS_8BIT_2DL_F511			0x3C

#define CHR_LCD_DDRAM_STA					0x80
#define CHR_LCD_CGRAM_STA					0x40

/* Section 3 : Macros Functions Declarations */



/* Section 4 : User Defined Data Types Declarations */

typedef enum {
	ROW1 = 1,
	ROW2,
	ROW3,
	ROW4
}CHR_LCD_ROW;

typedef struct{
	PIN_CFG_T RS_PIN;
	PIN_CFG_T EN_PIN;
	PIN_CFG_T LCD_DATA_PINS[4];
}CHR_LCD_4BIT_T;

typedef struct{
	PIN_CFG_T RS_PIN;
	PIN_CFG_T EN_PIN;
	PIN_CFG_T LCD_DATA_PINS[8];
}CHR_LCD_8BIT_T;

/* Section 5 : Functions Declarations */

Std_ReturnType CHR_LCD_4BIT_INITIALIZE(const CHR_LCD_4BIT_T *lcd);
Std_ReturnType CHR_LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT_T *lcd , uint8 command);
Std_ReturnType CHR_LCD_4BIT_SEND_CHAR_DATA(const CHR_LCD_4BIT_T *lcd , uint8 data);
Std_ReturnType CHR_LCD_4BIT_SEND_CHAR_POS(const CHR_LCD_4BIT_T *lcd , uint8 data , uint8 row , uint8 column);
Std_ReturnType CHR_LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT_T *lcd , uint8 *str);
Std_ReturnType CHR_LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT_T *lcd , uint8 *str , uint8 row , uint8 column);
Std_ReturnType CHR_LCD_4BIT_SEND_CUSTOM_CHAR(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos);

Std_ReturnType CHR_LCD_8BIT_INITIALIZE(const CHR_LCD_8BIT_T *lcd);
Std_ReturnType CHR_LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT_T *lcd , uint8 command);
Std_ReturnType CHR_LCD_8BIT_SEND_CHAR_DATA(const CHR_LCD_8BIT_T *lcd , uint8 data);
Std_ReturnType CHR_LCD_8BIT_SEND_CHAR_POS(const CHR_LCD_8BIT_T *lcd , uint8 data , uint8 row , uint8 column);
Std_ReturnType CHR_LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT_T *lcd , uint8 *str);
Std_ReturnType CHR_LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT_T *lcd , uint8 *str , uint8 row , uint8 column);
Std_ReturnType CHR_LCD_8BIT_SEND_CUSTOM_CHAR(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos);

Std_ReturnType CONVERT_CHAR_TO_STRING(uint8 data , uint8 *str);
Std_ReturnType CONVERT_SHORT_TO_STRING(uint8 data , uint8 *str);
Std_ReturnType CONVERT_INT_TO_STRING(uint8 data , uint8 *str);

#endif /* ECUAL_CHAR_LCD_CHR_LCD_H_ */

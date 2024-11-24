/*
 * CHR_LCD.c
 *
 *  Created on: Nov 6, 2024
 *      Author: Mohamed Elahmady
 */

#include "CHR_LCD.h"

/********** Helper Functions  ***********/

static Std_ReturnType CHR_LCD_4BIT_SEND_4BIT(const CHR_LCD_4BIT_T *lcd , uint8 data);
static Std_ReturnType CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(const CHR_LCD_4BIT_T *lcd);
static Std_ReturnType CHR_LCD_4BIT_SET_CURSOR(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column);

static Std_ReturnType CHR_LCD_8BIT_SEND_ENABLE_SIGNAL(const CHR_LCD_8BIT_T *lcd);
static Std_ReturnType CHR_LCD_8BIT_SET_CURSOR(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column);

/********** MAIN Functions  ***********/

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_INITIALIZE(const CHR_LCD_4BIT_T *lcd){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_INITIALIZE(&(lcd->RS_PIN));
		Retval = GPIO_PIN_INITIALIZE(&(lcd->EN_PIN));
		for(int i = 0; i < 4 ; i++){
			Retval = GPIO_PIN_INITIALIZE(&(lcd->LCD_DATA_PINS[i]));
		}
		_delay_ms(20);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);
		_delay_ms(5);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);
		_delay_us(150);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);

		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_CLEAR_DISPLAY);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_CURSOR_HOME);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_ENS_INC_SFT_OFF);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_DSP_ON_ULC_OFF_BLC_OFF);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_4BIT_2DL_F58);
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , CHR_LCD_DDRAM_STA);
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_COMMAND(const CHR_LCD_4BIT_T *lcd , uint8 command){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
		Retval = CHR_LCD_4BIT_SEND_4BIT(lcd , (command >> 4));
		Retval = CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(lcd);
		Retval = CHR_LCD_4BIT_SEND_4BIT(lcd , (command));
		Retval = CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(lcd);
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_CHAR_DATA(const CHR_LCD_4BIT_T *lcd , uint8 data){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_HIGH);
		Retval = CHR_LCD_4BIT_SEND_4BIT(lcd , (data >> 4));
		Retval = CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(lcd);
		Retval = CHR_LCD_4BIT_SEND_4BIT(lcd , (data));
		Retval = CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(lcd);
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_CHAR_POS(const CHR_LCD_4BIT_T *lcd , uint8 data , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = CHR_LCD_4BIT_SET_CURSOR(lcd , row , column);
		Retval = CHR_LCD_4BIT_SEND_CHAR_DATA(lcd , data);
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_STRING(const CHR_LCD_4BIT_T *lcd , uint8 *str){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd || NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		while(*str){
			Retval = CHR_LCD_4BIT_SEND_CHAR_DATA(lcd , *str++);
		}
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_STRING_POS(const CHR_LCD_4BIT_T *lcd , uint8 *str , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd || NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		while(*str){
			Retval = CHR_LCD_4BIT_SEND_CHAR_POS(lcd , *str++ , row ,column++);
		}
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_4BIT_CFG

Std_ReturnType CHR_LCD_4BIT_SEND_CUSTOM_CHAR(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , (CHR_LCD_CGRAM_STA+(mem_pos*8)));
		for(int i = 0 ; i < 8 ; i++){
			Retval = CHR_LCD_4BIT_SEND_CHAR_DATA(lcd ,chr[i]);
		}
		Retval = CHR_LCD_4BIT_SEND_CHAR_POS(lcd , mem_pos , row , column);
	}
	return Retval;
}

#endif







#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_INITIALIZE(const CHR_LCD_8BIT_T *lcd){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_INITIALIZE(&(lcd->RS_PIN));
		Retval = GPIO_PIN_INITIALIZE(&(lcd->EN_PIN));
		for(int i = 0; i < 8 ; i++){
			Retval = GPIO_PIN_INITIALIZE(&(lcd->LCD_DATA_PINS[i]));
		}
		_delay_ms(20);
        Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);
		_delay_ms(5);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);
		_delay_us(150);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);

		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_CLEAR_DISPLAY);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_CURSOR_HOME);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_ENS_INC_SFT_OFF);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_DSP_ON_ULC_OFF_BLC_OFF);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_FNS_8BIT_2DL_F58);
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , CHR_LCD_DDRAM_STA);
	}
	return Retval;
}

#endif
#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_COMMAND(const CHR_LCD_8BIT_T *lcd , uint8 command){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
		for(int i = 0; i < 8 ; i++){
			Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->LCD_DATA_PINS[i]) , ((command >> i) & 0x01));
		}
		Retval = CHR_LCD_8BIT_SEND_ENABLE_SIGNAL(lcd);
	}
	return Retval;
}

#endif
#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_CHAR_DATA(const CHR_LCD_8BIT_T *lcd , uint8 data){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_HIGH);
		for(int i = 0; i < 8 ; i++){
			Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->LCD_DATA_PINS[i]) , ((data >> i) & 0x01));
		}
		Retval = CHR_LCD_8BIT_SEND_ENABLE_SIGNAL(lcd);
	}
	return Retval;
}

#endif
#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_CHAR_POS(const CHR_LCD_8BIT_T *lcd , uint8 data , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = CHR_LCD_8BIT_SET_CURSOR(lcd , row , column);
		Retval = CHR_LCD_8BIT_SEND_CHAR_DATA(lcd , data);
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_STRING(const CHR_LCD_8BIT_T *lcd , uint8 *str){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd || NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		while(*str){
			CHR_LCD_8BIT_SEND_CHAR_DATA(lcd , *str++);
		}
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_STRING_POS(const CHR_LCD_8BIT_T *lcd , uint8 *str , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd || NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		while(*str){
			CHR_LCD_8BIT_SEND_CHAR_POS(lcd , *str++ , row , column++);
		}
	}
	return Retval;
}

#endif

#if CHR_LCD_CFG_ENABLE == CHR_LCD_8BIT_CFG

Std_ReturnType CHR_LCD_8BIT_SEND_CUSTOM_CHAR(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column , uint8 chr[] , uint8 mem_pos){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , (CHR_LCD_CGRAM_STA + mem_pos*8));
		for(int i = 0; i < 8 ; i++){
			Retval = CHR_LCD_8BIT_SEND_CHAR_DATA(lcd , chr[i]);
		}
		Retval = CHR_LCD_8BIT_SEND_CHAR_POS(lcd , mem_pos , row ,column);
	}
	return Retval;
}

#endif

Std_ReturnType CONVERT_CHAR_TO_STRING(uint8 data , uint8 *str){
	Std_ReturnType Retval = E_OK;
	if(NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		memset(str,'\0',4);
		sprintf(str,"%i",data);
	}
	return Retval;
}
Std_ReturnType CONVERT_SHORT_TO_STRING(uint8 data , uint8 *str){
	Std_ReturnType Retval = E_OK;
	if(NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		memset(str,'\0',6);
		sprintf(str,"%i",data);
	}
	return Retval;
}
Std_ReturnType CONVERT_INT_TO_STRING(uint8 data , uint8 *str){
	Std_ReturnType Retval = E_OK;
	if(NULL == str){
		Retval = E_NOT_OK;
	}
	else{
		memset(str,'\0',11);
		sprintf(str,"%i",data);
	}
	return Retval;
}

/********** Helper Functions  ***********/

static Std_ReturnType CHR_LCD_4BIT_SEND_4BIT(const CHR_LCD_4BIT_T *lcd , uint8 data){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		for(int i = 0; i < 4 ; i++){
			Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->LCD_DATA_PINS[i]) , (data >> i)&0x01);
		}
	}
	return Retval;
}

static Std_ReturnType CHR_LCD_4BIT_SEND_ENABLE_SIGNAL(const CHR_LCD_4BIT_T *lcd){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_HIGH);
		_delay_us(5);
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_LOW);
	}
	return Retval;
}

static Std_ReturnType CHR_LCD_4BIT_SET_CURSOR(const CHR_LCD_4BIT_T *lcd , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
		if(NULL == lcd){
			Retval = E_NOT_OK;
		}
		else{
			Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
			column--;
			switch(row){
			case ROW1:
				Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , (0x80+column));
				break;
			case ROW2:
				Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , (0xC0+column));
				break;
			case ROW3:
				Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , (0x94+column));
				break;
			case ROW4:
				Retval = CHR_LCD_4BIT_SEND_COMMAND(lcd , (0xD4+column));
				break;
			default:
				Retval = E_NOT_OK;
				break;
			}
		}
		return Retval;
}

static Std_ReturnType CHR_LCD_8BIT_SEND_ENABLE_SIGNAL(const CHR_LCD_8BIT_T *lcd){
	Std_ReturnType Retval = E_OK;
	if(NULL == lcd){
		Retval = E_NOT_OK;
	}
	else{
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_HIGH);
		_delay_us(5);
		Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->EN_PIN) , GPIO_LOW);
	}
	return Retval;
}

static Std_ReturnType CHR_LCD_8BIT_SET_CURSOR(const CHR_LCD_8BIT_T *lcd , uint8 row , uint8 column){
	Std_ReturnType Retval = E_OK;
		if(NULL == lcd){
			Retval = E_NOT_OK;
		}
		else{
			Retval = GPIO_PIN_WRITE_LOGIC(&(lcd->RS_PIN) , GPIO_LOW);
			column--;
			switch(row){
			case ROW1:
				Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , (0x80+column));
				break;
			case ROW2:
				Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , (0xC0+column));
				break;
			case ROW3:
				Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , (0x94+column));
				break;
			case ROW4:
				Retval = CHR_LCD_8BIT_SEND_COMMAND(lcd , (0xD4+column));
				break;
			default:
				Retval = E_NOT_OK;
				break;
			}
		}
		return Retval;
}

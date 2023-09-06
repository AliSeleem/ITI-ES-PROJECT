/*
 * Keypad.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Ali Seleem
 */

#include <avr/io.h>
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "Dio.h"
#include "Keypad.h"
#include "STD_TYPES.h"

static void Keypad_SetColumnLevel(u8 column , Dio_PinLevelType level);
static Dio_PinLevelType Keypad_GetRowLevel(u8 row);

void Keypad_Init(void){
	DioSetPinMode(KEYPAD_PIN_R1, DIO_PIN_INPUT_PULLUP);
	DioSetPinMode(KEYPAD_PIN_R2, DIO_PIN_INPUT_PULLUP);
	DioSetPinMode(KEYPAD_PIN_R3, DIO_PIN_INPUT_PULLUP);
	DioSetPinMode(KEYPAD_PIN_R4, DIO_PIN_INPUT_PULLUP);


	DioSetPinMode(KEYPAD_PIN_C1, DIO_PIN_OUTPUT);
	DioSetPinMode(KEYPAD_PIN_C2, DIO_PIN_OUTPUT);
	DioSetPinMode(KEYPAD_PIN_C3, DIO_PIN_OUTPUT);

	Dio_SetPinLevel(KEYPAD_PIN_C1 , STD_HIGH);
	Dio_SetPinLevel(KEYPAD_PIN_C2 , STD_HIGH);
	Dio_SetPinLevel(KEYPAD_PIN_C3 , STD_HIGH);
}


Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType Button){
	Keypad_ButtonStateType state = KEYPAD_NOT_PRESSED;

	u8 row = Button / 3;
	u8 column = Button % 3;

	Keypad_SetColumnLevel(column, STD_LOW);

	if(Keypad_GetRowLevel(row) == STD_LOW){
		_delay_ms(5);
		if(Keypad_GetRowLevel(row) == STD_LOW){
			state = KEYPAD_PRESSED;
		}
	}

	Keypad_SetColumnLevel(column, STD_HIGH);

	return state;
}

static void Keypad_SetColumnLevel(u8 column , Dio_PinLevelType level){
	switch(column){
	case 0:
		Dio_SetPinLevel(KEYPAD_PIN_C1, level);
		break;
	case 1:
		Dio_SetPinLevel(KEYPAD_PIN_C2, level);
		break;
	case 2:
		Dio_SetPinLevel(KEYPAD_PIN_C3, level);
		break;
	default:
		break;
	}

}

static Dio_PinLevelType Keypad_GetRowLevel(u8 row){
	Dio_PinLevelType level = STD_HIGH;

	switch(row)
	{
		case 0:
			level = Dio_ReadPinLevel(KEYPAD_PIN_R1);
			break;
		case 1:
			level = Dio_ReadPinLevel(KEYPAD_PIN_R2);
			break;
		case 2:
			level = Dio_ReadPinLevel(KEYPAD_PIN_R3);
			break;
		case 3:
			level = Dio_ReadPinLevel(KEYPAD_PIN_R4);
			break;
		default:
			break;
	}
	return level;
}


Keypad_ButtonType Keypad_GetPressedButton(void){
	u8 i;
	Keypad_ButtonType button = KEYPAD_INVALID;

	for(i = 0 ; i < 12 ; i++){
		if(Keypad_GetButtonState(i) == KEYPAD_PRESSED){
			button = i;
			break;
		}
	}
	return button;
}


u8 Keypad_ToLcd(void){
	Keypad_ButtonType btn = Keypad_GetPressedButton();
	u8 out = 0;
	switch(btn){
	case 0:
		out = '1';
		break;
	case 1:
		out = '2';
		break;
	case 2:
		out = '3';
		break;
	case 3:
		out = '4';
		break;
	case 4:
		out = '5';
		break;
	case 5:
		out = '6';
		break;
	case 6:
		out = '7';
		break;
	case 7:
		out = '8';
		break;
	case 8:
		out = '9';
		break;
	case 9:
		out = '*';
		break;
	case 10:
		out = '0';
		break;
	case 11:
		out = '#';
		break;
	default:
		break;
	}
	return out;
}


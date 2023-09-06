/*
 * main.c
 *
 *  Created on: Sep 5, 2023
 *      Author: Ali Seleem
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Dio.h"
#include "Keypad.h"
#include "Lcd.h"
#include "Protection.h"

u8 correct_pass[4] = {'6', '4', '7', '6'};

void main(){
	Lcd_InitPins();
	Lcd_Init();
	Keypad_Init();
	Lcd_DisplayString("SELEEM PRO. CO.");
	_delay_ms(3000);
	Lcd_ClearDisplay();
	while(1){
		u8 l = Password(correct_pass);
		if(l == 1){
			Lcd_ClearDisplay();
			Lcd_DisplayString("Welcome Sir!");
			break;
		}
		else{
			Lcd_ClearDisplay();
			Lcd_DisplayString("Wrong password");
			GotoXY(2,0);
			Lcd_DisplayString("Try Again...");
			_delay_ms(1000);
			Lcd_ClearDisplay();
		}
	}
}


/*
 * Protection.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Ali Seleem
 */
#include <avr/io.h>
#include <avr/delay.h>
#include "STD_TYPES.h"
#include "Keypad.h"
#include "Lcd.h"
#include "Protection.h"

u8 Password(u8* correct_pass){		//Asks the user for a password and gets the correct as arg and return boolean
	Lcd_DisplayString("Enter Pass: ");
	u8 input, count = 0;
	u8 entered_pass[4];
	while(count != 4){
		input = Keypad_ToLcd();
		if(input != 0){
			Lcd_SendData(input);
			entered_pass[count] = input;
			_delay_ms(500);
			count++;
		}
	}
	return Pass_Check(correct_pass, entered_pass);
}

u8 Pass_Check(u8* correct_pass, u8* entered_pass){		//Checks if the entered password is correct and returns boolean value
	u8 l = 1;
	for(u8 i = 0 ; i < 4 ; i++){
		if(correct_pass[i] != entered_pass[i]){
			l--;
			break;
		}
	}
	return l;
}

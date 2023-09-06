#include "avr/io.h"
#include "avr/delay.h"
#include "BIT_MATH.h"
#include "Dio.h"
#include "Lcd.h"
#include "STD_TYPES.h"

void Lcd_SendCommand (u8 command)
{
	/***LOW FOR COMMAND***/
	Dio_SetPinLevel (LCD_PIN_RS , STD_LOW);

	/***LOW FOR WRITE***/
	Dio_SetPinLevel (LCD_PIN_RW , STD_LOW);


	_delay_ms(1);
	Dio_SetPinLevel (LCD_PIN_EN , STD_HIGH);
	_delay_ms(1);

	Dio_SetPinLevel(LCD_PIN_D0 , GET_BIT(command , 0));
	Dio_SetPinLevel(LCD_PIN_D1 , GET_BIT(command , 1));
	Dio_SetPinLevel(LCD_PIN_D2 , GET_BIT(command , 2));
	Dio_SetPinLevel(LCD_PIN_D3 , GET_BIT(command , 3));
	Dio_SetPinLevel(LCD_PIN_D4 , GET_BIT(command , 4));
	Dio_SetPinLevel(LCD_PIN_D5 , GET_BIT(command , 5));
	Dio_SetPinLevel(LCD_PIN_D6 , GET_BIT(command , 6));
	Dio_SetPinLevel(LCD_PIN_D7 , GET_BIT(command , 7));

	_delay_ms(1);
	Dio_SetPinLevel (LCD_PIN_EN , STD_LOW);
	_delay_ms(1);

}


void Lcd_SendData(u8 command)
{
	/***HIGH FOR DATA***/
	Dio_SetPinLevel (LCD_PIN_RS , STD_HIGH);

	/***LOW FOR WRITE***/

	Dio_SetPinLevel (LCD_PIN_RW , STD_LOW);

	_delay_ms(1);
	Dio_SetPinLevel (LCD_PIN_EN , STD_HIGH);
	_delay_ms(1);

	Dio_SetPinLevel(LCD_PIN_D0 , GET_BIT(command , 0));
	Dio_SetPinLevel(LCD_PIN_D1 , GET_BIT(command , 1));
	Dio_SetPinLevel(LCD_PIN_D2 , GET_BIT(command , 2));
	Dio_SetPinLevel(LCD_PIN_D3 , GET_BIT(command , 3));
	Dio_SetPinLevel(LCD_PIN_D4 , GET_BIT(command , 4));
	Dio_SetPinLevel(LCD_PIN_D5 , GET_BIT(command , 5));
	Dio_SetPinLevel(LCD_PIN_D6 , GET_BIT(command , 6));
	Dio_SetPinLevel(LCD_PIN_D7 , GET_BIT(command , 7));

	_delay_ms(1);
	Dio_SetPinLevel (LCD_PIN_EN , STD_LOW);
	_delay_ms(1);

}

void Lcd_InitPins(void)
{
	DioSetPinMode (LCD_PIN_EN , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_RS , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_RW , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D0 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D1 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D2 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D3 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D4 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D5 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D6 , DIO_PIN_OUTPUT);
	DioSetPinMode (LCD_PIN_D7 , DIO_PIN_OUTPUT);

}


void Lcd_Init (void)
{
	_delay_ms(40);

	/*Function set command : 2 lines , 5*8 font size*/
	Lcd_SendCommand(0b00111000);

	/*Display ON/OFF control : display enable , disable cursior , no blink cursior*/
	Lcd_SendCommand(0b00001100);

	/*Clear Display*/
	Lcd_SendCommand(0b00000001);
}

void Lcd_ClearDisplay(void){
	/*Clear Display*/
	Lcd_SendCommand(0b00000001);
}

void Lcd_DisplayString(const u8 *str)
{
	u8 i= 0;
	while(str[i] != '\0')
	{
		Lcd_SendData(*str);
		str++;
	}
}

void GotoXY(u8 x, u8 y)
{
	u8 Address;
	switch(x){
	case 1:
		Address = y;
		break;
	case 2:
		Address = y + 64;
	}
	Lcd_SendCommand((Address + 128));
}

/*
 * Dio.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Ali Seleem
 */

#ifndef DIO_H_
#define DIO_H_

typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD,
}Dio_PortType;

typedef enum{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7,

}Dio_PinType;

typedef enum{
	DIO_PIN_OUTPUT,
	DIO_PIN_INPUT_FLOATING,
	DIO_PIN_INPUT_PULLUP
}Dio_PinModeType;

typedef enum{
	DIO_PORT_OUTPUT = 0xff,
	DIO_PORT_INPUT = 0
}Dio_PortModeType;

typedef enum{
	DIO_PORT_LOW = 0,
	DIO_PORT_HIGH = 0xff
}Dio_PortLevelType;

typedef enum{
	STD_LOW,
	STD_HIGH
}Dio_PinLevelType;

void Dio_SetPortMode (Dio_PortType port ,Dio_PinModeType mode);
void Dio_SetPortLevel (Dio_PortType port ,Dio_PortLevelType mode);
Dio_PortLevelType Dio_ReadPortLevelType (Dio_PortType port);
void DioSetPinMode (Dio_PortType port, Dio_PinType pin, Dio_PinModeType mode);
void Dio_SetPinLevel (Dio_PortType port, Dio_PinType pin, Dio_PinLevelType level);
Dio_PinLevelType Dio_FlipPinLevel (Dio_PortType port , Dio_PinType pin);
void Dio_ToggelPinLevel (Dio_PortType port , Dio_PinType pin);
Dio_PinLevelType Dio_ReadPinLevel (Dio_PortType port , Dio_PinType pin);

#endif /* DIO_H_ */

/*
 * main.c
 *
 *  Created on: Jun 18, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "GPIO.h"
#include "keypad.h"
#include <util/delay.h>


GPIO_Pin_Configuration LED = {PORTA,Pin_Zero,Output}; //Initialization of LED just for test

int main(void)   //starting point
{

	__GPIO_Set_Pin_Direction__(&LED);   //set the direction of the LED's pin

	__Keypad_Initialization__();   //call this function from HAL layer to initialize the keypad


	for(;;) {  //super loop

		if (__Keypad_Get_Key__() == '*') { __GPIO_Set_Pin__(&LED);} //turn on The LED
	}//the end of the super loop


	return Null;
}

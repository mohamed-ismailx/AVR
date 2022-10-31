/*
 * main.c
 *
 *  Created on: Jun 18, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "GPIO.h"
#include "LCD.h"
#include <util/delay.h>


int main(void)   //starting point
{

	__LCD_Initialization__();  //initialization of the LCD
	__LCD_Send_String_Position__("welcome", Row_One, Column_One);  //display a string on LCD

	for(;;) {  //super loop



	}//the end of the super loop


	return Null;
}

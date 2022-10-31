/*
 * LED.c
 *
 *  Created on: Jul 24, 2022
 *      Author: oliver
 */

#include "Stdlib.h"
#include "GPIO.h"



GPIO_Pin_Configuration LED = {PORTD,Pin_Zero,Output};    //configure the LED parameter


//function to Initialize the LED
void __LED_Initialization__(void) {

	__GPIO_Set_Pin_Direction__(&LED);    //set the pin direction (input - output)


} //the end of the function

//function to turn on the LED
void __LED_On__(void) {

	__GPIO_Set_Pin__(&LED);       //turn on the LED


} //the end of the function


//function to turn off the LED
void __LED_Off__(void) {

	__GPIO_Clear_Pin__(&LED);    //turn off the LED


} //the end of the function

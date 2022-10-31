/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "GPIO.h"
#include "external_interrupt.h"
#include <util/delay.h>



/* this main code just for test the external interrupt */

void test(void);  //the prototype of the function that blinks the LED (just for test)

GPIO_Pin_Configuration LED = {PORTD,Pin_Seven,Output}; //Initialization of LED (just for test)
EXTI_Configuration INT = {Falling_EXTI01,INT0,&test};  //Initialization of the external interrupt 1

int main(void)   //starting point
{

	__GPIO_Set_Pin_Direction__(&LED);   //set the LED's pin direction

	__EINT_Global_INT_Enable__();       //enable the global interrupt
	__EINT_Select_Edge__(&INT);         //set the selected edge
	__EINT_Enable__(&INT);              //enable the external interrupt
	__EINT_Set_Call_Back_Function__(&INT);  //send the function to MCAL layer


	for(;;) {  //super loop



	}//the end of the super loop


	return Null;

} //the end of the main function



/* function to blink the LED */
void test(void) {

	__GPIO_Set_Pin__(&LED);    //turn on the LED
	_delay_ms(1000);           //wait 1 second
	__GPIO_Clear_Pin__(&LED);  //turn off the LED
	_delay_ms(1000);           //wait 1 second

} //the end of the funcion



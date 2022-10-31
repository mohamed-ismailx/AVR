/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "external_interrupt.h"
#include "GPIO.h"
#include "LCD.h"
#include "ADC.h"
#include "Convert.h"
#define F_CPU 8000000UL
#include <util/delay.h>



/*  this main code just for test the ADC  */




void test(u16 Data);  //the prototype of the function that gets the digital value (just for test)


ADC_Configuration ADCx = {AVCC,Right_Adjust_Result,Channel_ADC2,Division_Factor_Per_16,Single_Conversion_Mode,0xFF,Null,Null,&test};

u8 Source[5];

int main(void)   //starting point
{

	__LCD_Initialization__();           //initialization of the LCD

	__EINT_Global_INT_Enable__();       //enable the global interrupt

	__ADC_Initialization__(&ADCx);      //initialization of the ADC

	for(;;) {  //super loop

			__ADC_Set_Call_Back_Function__(&ADCx);      //call the ADC's set call back function to enable the ADC's interrupt

			ADCx.Analog_Value = (ADCx.Digital_Value * 5000UL) / 1024;      //calculate the analog value
			__Int_To_Ascii__(ADCx.Analog_Value,Source);                   //convert the analog value to the ascii code
			__LCD_Send_String_Position__(Source, Row_One, Column_One);    //display the analog value on the LCD


	}//the end of the super loop


	return Null;

} //the end of the main function


/* function to get the digital value of the temperature sensor */
void test(u16 Data) {

	ADCx.Digital_Value = Data;       //update the digital value to the structure's variable

} //the end of the function



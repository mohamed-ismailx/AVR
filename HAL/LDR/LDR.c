/*
 * LDR.c
 *
 *  Created on: Jul 24, 2022
 *      Author: oliver
 */

#include "Stdlib.h"
#include "ADC.h"
#include "external_interrupt.h"
#include "LDR.h"
#include "LED.h"


ADC_Configuration ADCx = {AVCC,Right_Adjust_Result,Channel_ADC2,Division_Factor_Per_16,Single_Conversion_Mode,0xFF,Null,&__Get_The_Digital_Value__};  //configure the ADC parameters



//function to Initialize the LDR
void __LDR_Initialization__(void)
{

	__LED_Initialization__();           //initialize the LED

	__EINT_Global_INT_Enable__();       //enable the global interrupt

	__ADC_Initialization__(&ADCx);      //initialization of the ADC


} //the end of the function


//function to activate the LED based on the light
void __LDR__(void) {

	__ADC_Set_Call_Back_Function__(&ADCx);      //call the ADC's set call back function to enable the ADC's interrupt

	ADCx.Analog_Value = (ADCx.Digital_Value * 5000UL) / 1024;      //calculate the analog value


	if((ADCx.Analog_Value >= 0) && (ADCx.Analog_Value <= 1500))	{       //check if the value of the output voltage

		__LED_Off__();            //if that happens, turn off the LED because there is a light

	}      //the end of the if statement

	else {    //else, there is no light

		__LED_On__();             //turn off the LED
	}    //the end of the else scope


}//the end of the function



//function to get the digital value of the LDR
void __Get_The_Digital_Value__(u16 Data) {

	ADCx.Digital_Value = Data;       //update the digital value to the structure's variable

} //the end of the function



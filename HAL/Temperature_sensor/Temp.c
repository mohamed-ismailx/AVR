/*
 * Temp.c
 *
 *  Created on: Jul 24, 2022
 *      Author: oliver
 */


#include "Stdlib.h"
#include "external_interrupt.h"
#include "GPIO.h"
#include "LCD.h"
#include "ADC.h"
#include "Convert.h"
#include "Temp.h"




ADC_Configuration ADCx = {AVCC,Right_Adjust_Result,Channel_ADC2,Division_Factor_Per_16,Single_Conversion_Mode,0xFF,Null,&__Get_The_Digital_Value__};    //configure the ADC parameters

static u8 Source[5];   //declare an array to hold the temperature value as a string

static u8 Temp;        //declare a variable to hold the temperature value as an integer


/* function to initialize the temperature sensor  */
void __Temp_Initialization__(void)
{

	__LCD_Initialization__();           //initialization of the LCD

	__EINT_Global_INT_Enable__();       //enable the global interrupt

	__ADC_Initialization__(&ADCx);      //initialization of the ADC


} //the end of the function


/* function to display the temperature value */
void __Temp_Display__(void) {


	__ADC_Set_Call_Back_Function__(&ADCx);      //call the ADC's set call back function to enable the ADC's interrupt

	ADCx.Analog_Value = (ADCx.Digital_Value * 5000UL) / 1024;      //calculate the analog value
	Temp =   ADCx.Analog_Value / 10;                              //calculate the temperature value
	__Int_To_Ascii__(Temp,Source);                   //convert the analog value to the ascii code
	__LCD_Send_String_Position__(Source, Row_One, Column_One);    //display the analog value on the LCD
	__LCD_Send_Character_Position__('C', Row_One, Column_Three);    //display the analog value on the LCD


}  //the end of the function



/* function to get the digital value of the temperature sensor */
void __Get_The_Digital_Value__(u16 Data) {

	ADCx.Digital_Value = Data;       //update the digital value to the structure's variable

} //the end of the function

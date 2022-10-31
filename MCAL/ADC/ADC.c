/*
 * ADC.c
 *
 *  Created on: Jul 22, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "ADC.h"


static volatile u8 ADC_Flag = Null;        //define a variable to indicate that the ISR function finished update of digital value from ADCHL register
static void (*ADC_Function)(u16);    //declare a pointer to function to hold the address of the function that comes form the application layer



/* function to initialize the ADC */
Check_Error __ADC_Initialization__(ADC_Configuration *Data) {

	Check_Error Execution_State = Correct_Execution;  //Define a variable to check error in the function


	if(Data != NULL) {   //Check If The Content Of Structure Is Not Empty And It Hold The Address

			ADC->ADMUX.Bit_Access.ADLAR = Data->Adjust_Result;   //set the adjust result
			ADC->ADMUX.Bit_Access.REFS = Data->Voltage_Reference;        //set the ADC's voltage reference
			ADC->ADCSRA.Bit_Access.ADPS = Data->Prescaler;            //set the ADC's prescaler

			if(Data->Mode == Single_Conversion_Mode) {           //check if the mode is single conversion mode
				ADC->ADCSRA.Bit_Access.ADATE = Disable;           //if that happens, disable the trigger bit
			} //the end of the if statement

			else  //else
			{
				ADC->ADCSRA.Bit_Access.ADATE = Enable;               //enable the trigger bit
				ADC_Trigger->SFIOR.Bit_Access.ADTS = Data->Mode;     //set the selected mode
			}//end of the else scope

			ADC->ADCSRA.Bit_Access.ADEN = Enable;  //enable the ADC

			if(Data->Mode == Free_Running_mode) {             //check if the mode is free running mode
				ADC->ADCSRA.Bit_Access.ADSC = Enable;        //if that happens, enable the single conversion mode just once
			} //the end of the if statement

	} //the end of the if statement

	else {  //else the structure is empty address

		Execution_State = Error_Execution;  //Update the error state to the variable
	} //the end of the else

	return Execution_State;  //return the execution state

} //the end of the function



//function to enable the ADC
void __ADC_Enable__(void)
{
	ADC->ADCSRA.Bit_Access.ADEN = Enable;  //enable the ADC
}  //the end of the function



//function to disable the ADC
void __ADC_Disable__(void)
{
	ADC->ADCSRA.Bit_Access.ADEN = Disable;  //disable the ADC
}  //the end of the function


//function to start Single conversion
Check_Error __ADC_Single_Conversion__(ADC_Configuration *Data)
{
	Check_Error Execution_State = Correct_Execution;  //Define a variable to check error in the function

	if(Data != NULL) {   //Check If The Content Of Structure Is Not Empty And It Hold The Address

		ADC->ADMUX.Bit_Access.MUX = Data->Channal;    //Set the selected channel

		ADC->ADCSRA.Bit_Access.ADSC = Enable;         //Start conversion

		while(!ADC->ADCSRA.Bit_Access.ADIF);          //Wait until the conversion is finished

		ADC->ADCSRA.Bit_Access.ADIF = Enable;         //clear the ADC interrupt flag

		Data->Digital_Value = ADC->ADCHL;            //read the digital value

		Data->Analog_Value = (Data->Digital_Value * 5000UL) / 1024;      //calculate the analog value

	} //the end of the if statement


		else {  //else the structure is empty address

			Execution_State = Error_Execution;  //Update the error state to the variable
		} //the end of the else

		return Execution_State;  //return the execution state

} //the end of the function



//function to get the digital value at free running mode
Check_Error __ADC_Free_Running__(ADC_Configuration *Data)
{

	Check_Error Execution_State = Correct_Execution;  //Define a variable to check error in the function

	if(Data != NULL) {   //Check If The Content Of Structure Is Not Empty And It Hold The Address

		ADC->ADMUX.Bit_Access.MUX = Data->Channal;    //Set the selected channel

		while(!ADC->ADCSRA.Bit_Access.ADIF);          //Wait until the conversion is finished

		ADC->ADCSRA.Bit_Access.ADIF = Enable;

		Data->Digital_Value = ADC->ADCHL;            //read the digital value

		Data->Analog_Value = (Data->Digital_Value * 5000UL) / 1024;      //calculate the analog value


	} //the end of the if statement


		else {  //else the structure is empty address

			Execution_State = Error_Execution;  //Update the error state to the variable
		} //the end of the else

		return Execution_State;  //return the execution state

} //the end of the function



//function to get the address of the function from the application layer the used when the ADC is finished his conversion process
Check_Error __ADC_Set_Call_Back_Function__(ADC_Configuration *Data)
{
	Check_Error Execution_State = Correct_Execution;  //Define a variable to check error in the function

	if((Data != NULL) && (ADC_Flag == Null))      //Then check if the content of the structure is not empty and it holds the address and the ADC flag is set to 0, i.e., the ISR function didn't read the digital value yet
	{
		ADC_Flag = True;                              //if that happens, set the ADC flag
		ADC_Function = Data->ADC_Call_Back_Function;   //get the address of the function that comes from the application layer
		ADC->ADCSRA.Bit_Access.ADIE = Enable;           //enable the ADC interrupt
		ADC->ADMUX.Bit_Access.MUX = Data->Channal;      //set the selected channel
		ADC->ADCSRA.Bit_Access.ADSC = Enable;           //start conversion

	}  //the end of the if statement

	else {  //else the structure is empty address

		Execution_State = Error_Execution;  //Update the error state to the variable
	} //the end of the else

	return Execution_State;  //return the execution state

} //the end of the function





/* ISR function that works with ADC Conversion Complete */
void __vector_16(void)
{

	if(ADC_Function != NULL)            //check if the pointer to function (ADC function) is hold the address of the function that comes form the application
	{
		ADC_Flag = Null;                           //clear the ADC flag
		ADC->ADCSRA.Bit_Access.ADIE = Disable;   //disable the ADC interrupt
		ADC_Function(ADC->ADCHL);          //send the digital value to the function that comes form the application layer
	} //the end of the if statement

} //the end ISR function


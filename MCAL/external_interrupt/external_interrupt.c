/*
 * external_interrupt.c
 *
 *  Created on: Jul 21, 2022
 *      Author: mohamed mohahmed taha
 */

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "GPIO.h"
#include "external_interrupt.h"


static void (*EINT_Function[No_EXTI])(void) = {NULL,NULL,NULL};  //define an array of pointers to function to hold the functions that come from the application layer to use them in ISR

/* function to enable the global interrupt */
void __EINT_Global_INT_Enable__(void) {

	EINT_SREG->SREG.Bit_Access.I_Bit = Enable;      //Assign 1 to I_Bit to enable the global interrupt

}  //the end of the function



/* function to disable the global interrupt */
void __EINT_Global_INT_Disable__(void) {

	EINT_SREG->SREG.Bit_Access.I_Bit = Disable;      //Assign 1 to I_Bit to disable the global interrupt

}//the end of the function



/* function to enable the selected external interrupt */
Check_Error __EINT_Enable__(EXTI_Configuration *Data) {


	Check_Error Error_State = Correct_Execution;   //Define a variable To Check Error In The Function

	if(Data != NULL) {  //Check If The Content Of Structure Is Not Empty And It Hold The Address

		switch(Data->EXIT)    //Switching The Value Of EXIT That In Structure
		{

			case INT0:  //INT0 case
				EINT_Interrupt->GICR.Bit_Access.INT0 = Enable;      //to enable the external interrupt 0, assign 1 to GICR's INT0 bit
				break;  //the end of the case

			case INT1:  //INT1 case
				EINT_Interrupt->GICR.Bit_Access.INT1 = Enable;      //to enable the external interrupt 1, assign 1 to GICR's INT1 bit
				break;  //the end of the case

			case INT2:   //INT2 case
				EINT_Interrupt->GICR.Bit_Access.INT2 = Enable;      //to enable the external interrupt 2, assign 1 to GICR's INT2 bit
				break;  //the end of the case

			default:  //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;  //the end of the default case

		}  //the end of the EXIT

	} //the end of the if statement


	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State;    //return error state

} //the end of the function




/* function to disable the selected external interrupt */
Check_Error __EINT_Disable__(EXTI_Configuration *Data) {


	Check_Error Error_State = Correct_Execution;   //Define a variable To Check Error In The Function

	if(Data != NULL) {  //Check If The Content Of Structure Is Not Empty And It Hold The Address

		switch(Data->EXIT)    //Switching The Value Of EXIT That In Structure
		{

			case INT0:  //INT0 case
				EINT_Interrupt->GICR.Bit_Access.INT0 = Disable;      //to disable the external interrupt 0, assign 0 to GICR's INT0 bit
				break;  //the end of the case

			case INT1:  //INT1 case
				EINT_Interrupt->GICR.Bit_Access.INT1 = Disable;      //to disable the external interrupt 1, assign 0 to GICR's INT1 bit
				break;  //the end of the case

			case INT2:   //INT2 case
				EINT_Interrupt->GICR.Bit_Access.INT2 = Disable;      //to disable the external interrupt 2, assign 0 to GICR's INT2 bit
				break;  //the end of the case

			default:  //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;  //the end of the default case

		}  //the end of the EXIT

	} //the end of the if statement


	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State;    //return error state

} //the end of the function


/* function to select the external interrupt edge */
Check_Error __EINT_Select_Edge__(EXTI_Configuration *Data) {

	Check_Error Error_State = Correct_Execution;   //Define a variable To Check Error In The Function


	if(Data != NULL) {    //Check If The Content Of Structure Is Not Empty And It Hold The Address

		switch(Data->EXIT)    //Switching The Value Of EXIT That In Structure
		{

			case INT0:  //INT0 case
				EINT_Edges->MCUCR.Bit_Access.ISC01_00 = Data->Edge;    //assign the selected edge to the MCUCR's ICS01 bit
				GPIOD->DDR.Bit_Access.Bit_Two = Disable;              //To make the INT0 as input, assign 0 to the DDR register.
				GPIOD->PORT.Bit_Access.Bit_Two = Enable;              //To make the INT0 as input pull up, assign 0 to the PORT register
				break;  //the end of the case

			case INT1:  //INT1 case
				EINT_Edges->MCUCR.Bit_Access.ISC11_10 = Data->Edge;    //assign the selected edge to the MCUCR's ICS11 bit
				GPIOD->DDR.Bit_Access.Bit_Three = Disable;            //To make the INT1 as input, assign 0 to the DDR register.
				GPIOD->PORT.Bit_Access.Bit_Three = Enable;            //To make the INT1 as input pull up, assign 0 to the PORT register
				break;  //the end of the case

			case INT2:   //INT2 case
				EINT_Edges->MCUCSR.Bit_Access.ISC2 = Data->Edge;       //assign the selected edge to the MCUCSR's ICS2 bit
				GPIOB->DDR.Bit_Access.Bit_Two = Disable;              //To make the INT2 as input, assign 0 to the DDR register.
				GPIOB->PORT.Bit_Access.Bit_Two = Enable;              //To make the INT2 as input pull up, assign 0 to the PORT register
				break;  //the end of the case

			default:  //default case
				Error_State = Error_Execution;
				break;  //the end of the default case

		}  //the end of the EXIT

	} //the end of the if statement



	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State;    //return error state


} //the end of the function



/* function to read the external interrupt's flag status */
u8 __EINT_Read_Flags__(EXTI_Configuration *Data) {


	u8 Error_State = Correct_Execution;   //Define a variable To Check Error In The Function
	u8 Flag_Value;                        //Declare a variable to hold the flag value

	if(Data != NULL) {  //Check If The Content Of Structure Is Not Empty And It Hold The Address

		switch(Data->EXIT)    //Switching The Value Of EXIT That In Structure
		{

			case INT0:  //INT0 case
				Flag_Value = EINT_Interrupt->GIFR.Bit_Access.INTF0;   //read the INT0 flag
				break;  //the end of the case

			case INT1:  //INT1 case
				Flag_Value = EINT_Interrupt->GIFR.Bit_Access.INTF1;   //read the INT1 flag
				break;  //the end of the case

			case INT2:   //INT2 case
				Flag_Value = EINT_Interrupt->GIFR.Bit_Access.INTF2;   //read the INT0 flag
				break;  //the end of the case

			default:  //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;  //the end of the default case

		}  //the end of the EXIT

	} //the end of the if statement


	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State == Error_Execution? Error_State : Flag_Value;  //if there is no error return the flag value

}  //the end of the function



/* function to clear the selected external interrupt flag */
Check_Error __EINT_Clear_Flag__(EXTI_Configuration *Data)
{

	Check_Error Error_State = Correct_Execution;    //Define a variable To Check Error In The Function


	if(Data != NULL)     //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{
		switch (Data->EXIT)   //Switching The Value Of EXIT That In Structure
		{

			case INT0:   //INT0 case
				EINT_Interrupt->GIFR.Bit_Access.INTF0 = Enable;    //clear the external interrupt 0 flag by assign 1 to the GIFR's INTF0 bit
				break;  //the end of the case

			case INT1:  //INT1 case
				EINT_Interrupt->GIFR.Bit_Access.INTF1 = Enable;   //clear the external interrupt 1 flag by assign 1 to the GIFR's INTF1 bit
				break;  //the end of the case

			case INT2:  //INT2 case
				EINT_Interrupt->GIFR.Bit_Access.INTF2 = Enable;  //clear the external interrupt 2 flag by assign 1 to the GIFR's INTF2 bit
				break; //the end of the case


			default:  //default case
				Error_State = Error_Execution;     //Update The Error State To The Variable
				break;  //the end of the default case
		} //the end of the switch

	} //the end of the if statement

	else      //Else The Structure Is Empty Address
		Error_State = Error_Execution;  //Update The Error State To The Variable


	return Error_State;   //return error state


} //the end of the function



/* function to get the function from the application layer that used in ISR */
void __EINT_Set_Call_Back_Function__(EXTI_Configuration *Data)
{
	 EINT_Function[Data->EXIT] = Data->EINT;     //update the address of the function that comes from the application layer to the EINT_Function to use it in IRS based on the selected external interrupt

}  //the end of the function



/* ISR function of the external interrupt 0 */
void __vector_1(void)
{

	EINT_Function[INT0]();    //call the function that works when the event of the external interrupt 0 occurs

} //the end of the ISR




/* ISR function of the external interrupt 1 */
void __vector_2(void)
{

	EINT_Function[INT1]();  //call the function that works when the event of the external interrupt 1 occurs

} //the end of the ISR


/* ISR function of the external interrupt 2 */
void __vector_3(void)
{

	EINT_Function[INT2]();  //call the function that works when the event of the external interrupt occurs

} //the end of the ISR




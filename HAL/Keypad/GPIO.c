/*
 * gpio.c
 *
 *  Created on: Jun 18, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef GPIO_C_
#define GPIO_C_

#include "Stdlib.h"
#include "AVR_Registers.h"
#include "GPIO.h"



static GPIO_Registers *GPIOx[No_Ports] = {GPIOA,GPIOB,GPIOC,GPIOD}; //Array Of Pointers To Structure To Access GPIO Registers By Base Address Of GPIOA,GPIOB And GPIOC

Check_Error __GPIO_Set_Pin_Direction__(const GPIO_Pin_Configuration *Data)   //Definition Of Function That Configuration The Pin Direction
{

	Check_Error Error_State = Correct_Execution;   //Define a variable to check error in the function

	if(Data != NULL)  //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch (Data->Pin)   //Switching The Value Of Pin That In Structure
		{
			case Pin_Zero:   //case pin is zero
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Zero = Data->Direction;  //Take the port data and update the direction to pin Zero
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Zero = High : Null;  //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break;  //the end of the case

			case Pin_One:    //case pin is one
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_One = Data->Direction;  //Take the port data and update the direction to pin one
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_One = High : Null;  //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Two:    //case pin is two
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Two = Data->Direction;  //Take the port data and update the direction to pin two
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Two = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Three:    //case pin is three
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Three = Data->Direction;   //Take the port data and update the direction to pin three
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Three = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Four:    //case pin is four
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Four = Data->Direction;  //Take the port data and update the direction to pin four
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Four = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Five:   //case pin is Five
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Five = Data->Direction;  //Take the port data and update the direction to pin five
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Five = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Six:   //case pin is Six
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Six = Data->Direction;   //Take the port data and update the direction to pin six
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Six = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			case Pin_Seven:   //case pin is Seven
				GPIOx[Data->Port]->DDR.Bit_Access.Bit_Seven = Data->Direction;     //Take the port data and update the direction to pin seven
				Data->Direction == Input_Pull_Up? GPIOx[Data->Port]->PORT.Bit_Access.Bit_Seven = High : Null; //Check if The mode is input Pullup / PullDown and update the mode to this Pin
				break; //the end of the case

			default:  //Default the pin value is error
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;  //the end of the default case
		} //the end of the switch

	} //the end of the if statement

	else    //else the structure is empty address
		Error_State = Error_Execution;    //Update the error state to the variable



	return Error_State;    //Return the error state
}   //the end of the function


Check_Error __GPIO_Set_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That Configuration The Pin Output (HIGH)
{

	Check_Error Error_State = Correct_Execution;    //Define a variable To Check Error In The Function

	if(Data != NULL)        //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch (Data->Pin)    //Switching The Value Of Pin That In Structure
		{
			case Pin_Zero:   //case pin is zero
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Zero = High;   //set pin zero
				break;  //the end of the case

			case Pin_One:   //case pin is one
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_One = High;    //set pin one
				break; //the end of the case

			case Pin_Two:   //case pin is two
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Two = High;    //set pin two
				break;   //the end of the case

			case Pin_Three:   //case pin is three
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Three = High;  //set pin three
				break;   //the end of the case

			case Pin_Four:    //case pin is four
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Four = High;   //set pin four
				break;    //the end of the case

			case Pin_Five:    //case pin is five
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Five = High;   //set pin five
				break;   //the end of the case

			case Pin_Six:  //case pin is six
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Six = High;    //set pin six
				break;     //the end of the case

			case Pin_Seven:   //case pin is seven
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Seven = High;  //set pin seven
				break;  //the end of the case

			default:     //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;   //the end of the default case
		}   //the end of the switch

	}   //the end of the if statement

	else  //Else The Structure Is Empty Address
		Error_State = Error_Execution;   //Update The Error State To The Variable


	return Error_State;    //return error state
} //the end of the function


Check_Error __GPIO_Clear_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That Configuration The Pin Output (LOW)
{

	Check_Error Error_State = Correct_Execution;   //Define a variable To Check Error In The Function

	if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch (Data->Pin)   //Switching The Value Of Pin That In Structure
		{
			case Pin_Zero:   //case pin is zero
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Zero = Low;    //clear pin zero
				break;   //the end of the case

			case Pin_One:    //case pin is one
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_One = Low;    //clear pin one
				break;   //the end of the case

			case Pin_Two:   //case pin is two
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Two = Low;    //clear pin two
				break;   //the end of the case

			case Pin_Three:   //case pin is three
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Three = Low;   //clear pin three
				break;   //the end of the case

			case Pin_Four:   //case pin is four
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Four = Low;    //clear pin four
				break;   //the end of the case

			case Pin_Five:  //case pin is five
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Five = Low;    //clear pin five
				break;  //the end of the case

			case Pin_Six:   //case pin is six
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Six = Low;     //clear pin six
				break;   //the end of the case

			case Pin_Seven:   //case pin is seven
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Seven = Low;   //clear pin seven
				break;  //the end of the case

			default:    //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break; //the end of the default case
		}  //the end of the switch

	} //the end of the if statement

	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State;    //return error state

}  //the end of the function


u8 __GPIO_Read_Pin__(const GPIO_Pin_Configuration *Data)  //Definition Of Function That read The Pin value
{

	u8 Error_State = Correct_Execution;    //Variable To Check Error In The Function
	u8 Read_Pin;                           //Variable To read the pin value

	if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch (Data->Pin)    //Switching The Value Of Pin That In Structure
		{
			case Pin_Zero:  //case pin zero
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Zero;    //read pin zero
				break;  //the end of the case

			case Pin_One: //case pin one
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_One;     //read pin one
				break; //the end of the case

			case Pin_Two:  //case pin two
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Two;     //read pin two
				break; //the end of the case

			case Pin_Three: //case pin three
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Three;   //read pin three
				break;  //the end of the case

			case Pin_Four:  //case pin four
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Four;    //read pin four
				break;  //the end of the case

			case Pin_Five:  //case pin five
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Five;    //read pin five
				break;  //the end of the case

			case Pin_Six:   //case pin six
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Six;     //read pin six
				break;   //the end of the case

			case Pin_Seven:  //case pin seven
				Read_Pin = GPIOx[Data->Port]->PIN.Bit_Access.Bit_Seven;   //read pin seven
				break;  //the end of the case

			default:   //default case
				Error_State = Error_Execution;
				break;  //the end of the default case
		}  //the end of the switch

	} //the end of the if statement

	else    //Else The Structure Is Empty Address
		Error_State = Error_Execution;  //Update The Error State To The Variable


	return Error_State == Error_Execution? Error_State: Read_Pin;   //return the value of pin if there is no error

}  //the end of the function


Check_Error __GPIO_Toggle_Pin__(const GPIO_Pin_Configuration *Data) //Definition Of Function That toggle The Pin value
{

	Check_Error Error_State = Correct_Execution;     //Define a variable To Check Error In The Function

	if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{

		switch (Data->Pin)     //Switching The Value Of Pin That In Structure
		{
			case Pin_Zero:   //case pin zero
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Zero ^= High;       //toggle pin zero
				break;  //the end of the case

			case Pin_One: //case pin one
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_One ^= High;        //toggle pin one
				break;  //the end of the case

			case Pin_Two:  //case pin two
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Two ^= High;         //toggle pin two
				break;  //the end of the case

			case Pin_Three:  //case pin three
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Three ^= High;      //toggle pin  three
				break;  //the end of the case

			case Pin_Four:  //case pin four
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Four ^= High;      //toggle pin four
				break;   //the end of the case

			case Pin_Five: //case pin five
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Five ^= High;       //toggle pin five
				break; //the end of the case

			case Pin_Six:  //case pin six
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Six ^= High;       //toggle pin six
				break; //the end of the case

			case Pin_Seven:  //case pin seven
				GPIOx[Data->Port]->PORT.Bit_Access.Bit_Seven ^= High;    //toggle pin seven
				break;  //the end of the case

			default:   //default case
				Error_State = Error_Execution;   //Update The Error State To The Variable
				break;  //the end of the default case
		} //the end of the switch

	}  //the end of the if statement

	else    //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State;   //return error state

}  //the end of the function


Check_Error __GPIO_Set_Port_Direction__(GPIO_Port_Configuration *Data) //Definition Of Function That Configuration The Port Direction
{

	Check_Error Error_State = Correct_Execution;    //Define a variable To Check Error In The Function

	if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{
		GPIOx[Data->Port]->DDR.Register_Access = Data->Port_Value;       //set port direction
		//0xf0    -   0x00
		if(Data->Direction == Input_Pull_Up)       //check if the mode is input pull up
			GPIOx[Data->Port]->PORT.Register_Access = ~(Data->Port_Value);    //set PORT register if the mode is pull up
	}  //the end of the if statement

	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;   //Update The Error State To The Variable


	return Error_State;   //return error state
}  //the end of the function

Check_Error __GPIO_Write_Port__(GPIO_Port_Configuration *Data)  //Definition Of Function That write The port value
{

	Check_Error Error_State = Correct_Execution;    //Define a variable To Check Error In The Function
	u8 Value;    //Variable To Check Error In The Function

	if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
	{
		Value = GPIOx[Data->Port]->DDR.Register_Access | GPIOx[Data->Port]->PORT.Register_Access;
		GPIOx[Data->Port]->PORT.Register_Access = Data->Port_Value & Value;   //assign the value to the port.

	//       0x00 | 0x0f    =  0x0f
	//  x = Port | DDR
    //       0xff & 0x0f
	//  port = port value & x

	}  //end if

	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;   //Update The Error State To The Variable


	return Error_State;   //return error state
}


u8 __GPIO_Read_Port__(GPIO_Port_Configuration *Data)   //Definition Of Function That read The port value
{

	u8 Error_State = Correct_Execution;    //Define a variable To Check Error In The Function
	u8 Read_Port;                          //Define a variable To read port

	if(Data != NULL)    //Check If The Content Of Structure Is Not Empty And It Hold The Address
		Read_Port = GPIOx[Data->Port]->PIN.Register_Access;    //read the value of the port


	else     //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable


	return Error_State == Error_Execution? Error_State: Read_Port;   //return read port if there is no error
}  //the end of the function


Check_Error __GPIO_Anding_Port__(GPIO_Port_Configuration *Data,GPIO_Anding_Oring_Configuration_Value *Anding) //Definition Of Function That make and operation for The port value
{

	Check_Error Error_State = Correct_Execution;   //Define a variable To Check Error In The Function

	if(Data != NULL)   //Check If The Content Of Structure Is Not Empty And It Hold The Address
	GPIOx[Data->Port]->PORT.Register_Access &= Anding->Anding_Value;    //anding the port

	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;     //Update The Error State To The Variable

	return Error_State;   //return error state
}  //the end of the function

Check_Error __GPIO_Oring_Port__(GPIO_Port_Configuration *Data,GPIO_Anding_Oring_Configuration_Value *Oring)  //Definition Of Function That make or operation for The port value
{

	Check_Error Error_State = Correct_Execution;    //Define av ariable To Check Error In The Function

	if(Data != NULL)     //Check If The Content Of Structure Is Not Empty And It Hold The Address
	GPIOx[Data->Port]->PORT.Register_Access |= Oring->Oring_Value;  //oring the port

	else   //Else The Structure Is Empty Address
		Error_State = Error_Execution;    //Update The Error State To The Variable

	return Error_State;  //return error state

}  //the end of the function

#endif /* GPIO_C_ */

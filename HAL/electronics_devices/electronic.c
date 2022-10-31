/*
 * electronic.c
 *
 *  Created on: Jul 16, 2022
 *      Author: oliver
 */


#include "Stdlib.h"
#include "GPIO.h"
#include "electronic.h"
#include <util/delay.h>


/* Seven Segment */

static u8 Segment[Seven_Segment] = {0xBF,0x86,0xDB,0xCF,0xE6,0xED,0xFD,0x87,0xFF,0xEF}; //Initialization of the seven segment for display numbers

GPIO_Pin_Configuration Segment_A = {Segment_Port_A,Segment_Pin_A,Output};    //Initialization of the seven segment's pin A
GPIO_Pin_Configuration Segment_B = {Segment_Port_B,Segment_Pin_B,Output};    //Initialization of the seven segment's pin B
GPIO_Pin_Configuration Segment_C = {Segment_Port_C,Segment_Pin_C,Output};    //Initialization of the seven segment's pin C
GPIO_Pin_Configuration Segment_D = {Segment_Port_D,Segment_Pin_D,Output};    //Initialization of the seven segment's pin D
GPIO_Pin_Configuration Segment_E = {Segment_Port_E,Segment_Pin_E,Output};    //Initialization of the seven segment's pin E
GPIO_Pin_Configuration Segment_F = {Segment_Port_F,Segment_Pin_F,Output};    //Initialization of the seven segment's pin F
GPIO_Pin_Configuration Segment_G = {Segment_Port_G,Segment_Pin_G,Output};    //Initialization of the seven segment's pin G
GPIO_Pin_Configuration Segment_Dot = {Segment_Port_Dot,Segment_Pin_Dot,Output};  //Initialization of the seven segment's pin Dot


/* DC Motor */

GPIO_Pin_Configuration DC_Motor = {DC_Motor_Port,DC_Motor_Pin,Output};   //Initialization of the DC Motor pin

/* Opto */

GPIO_Pin_Configuration Opto = {Opto_Port,Opto_Pin,Output};   //Initialization of the Optocoupler pin


/* Relay */

GPIO_Pin_Configuration Relay = {Relay_Port,Relay_Pin,Output};   //Initialization of the relay pin.

/* Stepper Motor */

GPIO_Pin_Configuration Stepper_Motor_Blue = {Stepper_Motor_Blue_Port,Stepper_Motor_Blue_Pin,Output};   //Initialization of the Stepper Motor's blue pin.
GPIO_Pin_Configuration Stepper_Motor_Pink = {Stepper_Motor_Pink_Port,Stepper_Motor_Pink_Pin,Output};   //Initialization of the Stepper Motor's pink pin.
GPIO_Pin_Configuration Stepper_Motor_Yellow = {Stepper_Motor_Yellow_Port,Stepper_Motor_Yellow_Pin,Output};   //Initialization of the Stepper Motor's yellow pin.
GPIO_Pin_Configuration Stepper_Motor_Orange = {Stepper_Motor_Orange_Port,Stepper_Motor_Orange_Pin,Output};   //Initialization of the Stepper Motor's orange pin.



/* Function to set the direction of seven segment pins */
void __Seven_Segment_Initialization__(void){

	__GPIO_Set_Pin_Direction__(&Segment_A);      //Set the direction of the seven segment's pin A
	__GPIO_Set_Pin_Direction__(&Segment_B);      //Set the direction of the seven segment's pin B
	__GPIO_Set_Pin_Direction__(&Segment_C);      //Set the direction of the seven segment's pin C
	__GPIO_Set_Pin_Direction__(&Segment_D);      //Set the direction of the seven segment's pin D
	__GPIO_Set_Pin_Direction__(&Segment_E);      //Set the direction of the seven segment's pin E
	__GPIO_Set_Pin_Direction__(&Segment_F);      //Set the direction of the seven segment's pin F
	__GPIO_Set_Pin_Direction__(&Segment_G);      //Set the direction of the seven segment's pin G
	__GPIO_Set_Pin_Direction__(&Segment_Dot);    //Set the direction of the seven segment's pin Dot

} //the end of the function


/* Function to take data and display it on seven segment */
void __Seven_Segment_Display__(u8 Data) {

	if(Data & 0x01)                            //Check if the 1st bit of data is set.
		__GPIO_Set_Pin__(&Segment_A);          //If that happens, this pin will be set.
	else                                       //else
		__GPIO_Clear_Pin__(&Segment_A);        //else, clear this pin

	if(Data & 0x02)                            //Check if the 2nd bit of data is set.
			__GPIO_Set_Pin__(&Segment_B);      //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_B);    //else, clear this pin.

	if(Data & 0x04)                            //Check if the 3th bit of data is set
			__GPIO_Set_Pin__(&Segment_C);      //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_C);    //else, clear this pin

	if(Data & 0x08)                            //Check if the 4th bit of the data is set
			__GPIO_Set_Pin__(&Segment_D);      //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_D);    //else, clear this pin

	if(Data & 0x10)                            //Check if the 5th bit of data is set
			__GPIO_Set_Pin__(&Segment_E);      //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_E);    //else, clear this pin

	if(Data & 0x20)                            //check if the 6th bit of data is set
			__GPIO_Set_Pin__(&Segment_F);      //If that happens, this pin will be set.
		else							       //else
			__GPIO_Clear_Pin__(&Segment_F);    //else, clear this pin

	if(Data & 0x40)                            //check if the 7th bit of data is set
			__GPIO_Set_Pin__(&Segment_G);      //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_G);    //else, clear this pin

	if(Data & 0x80)                            //check if the 8th bit of data is set.
			__GPIO_Set_Pin__(&Segment_Dot);    //If that happens, this pin will be set.
		else                                   //else
			__GPIO_Clear_Pin__(&Segment_Dot);  //else, clear this pin

}  //the end of the function



/* function to display all numbers on seven segments as a counter. */
void __Seven_Segment_Counter__(void) {

	u8 Loop;    //Declare a variable to use it in for loop.

	for(Loop = Null;Loop < Seven_Segment;Loop++)        //for loop for counter display.
	{
		__Seven_Segment_Display__(Segment[Loop]);       //display the value of the data.
		_delay_ms(1000);                                //delay to display a different number every one second.
	}   //the end of the for loop.



} //the end of the function.


/* Function to set the direction of the DC Motor pin */
void __DC_Motor_Initialization__(void)
{
	__GPIO_Set_Pin_Direction__(&DC_Motor);  //Set the direction for the DC Motor's pin
} //the end of the function



/* Function to set the direction of the Optocoupler pin */

void __Opto_Initialization__(void)
{
	__GPIO_Set_Pin_Direction__(&Opto);  //Set the direction for the optocoupler's pin
} //the end of the function


/* Function to set the direction of the relay pin */

void __Relay_Initialization__(void)
{
	__GPIO_Set_Pin_Direction__(&Relay); //Set the direction for Relay's pin
} //end of function

/* Function for set the DC Motor pin */
void __DC_Motor_On__(void)
{
	__GPIO_Set_Pin__(&DC_Motor);   //set the DC motor's pin
} //end of function


/* Function to set the optocoupler pin */
void __Opto_On__(void)
{
	__GPIO_Set_Pin__(&Opto);       //Set the optocoupler's pin
} //the end of the function


/* Function to set the Relay pin */
void __Relay_On__(void)
{

	__GPIO_Set_Pin__(&Relay);    //Set the Relay's pin

} //the end of the function




/* Function to clear the DC Motor pin */
void __DC_Motor_Off__(void)
{
	__GPIO_Clear_Pin__(&DC_Motor);  //clear the DC motor's pin
}


/* Function to set the Optocoupler pin */
void __Opto_Off__(void)
{
	__GPIO_Clear_Pin__(&Opto);    //clear the optocoupler's pin
} //the end of the function


/* Function to Clear the Relay pin */
void __Relay_Off__(void)
{
	__GPIO_Clear_Pin__(&Relay);    //clear the optocoupler's pin
} //the end of the function


/* Function to set the direction of the seven segment pins */
void __Stepper_Motor_Initialization__(void) {

	__GPIO_Set_Pin_Direction__(&Stepper_Motor_Blue);      //Set the direction for the Stepper motor's blue pin
	__GPIO_Set_Pin_Direction__(&Stepper_Motor_Pink);      //Set the direction for the Stepper motor's pink pin
	__GPIO_Set_Pin_Direction__(&Stepper_Motor_Yellow);    //Set the direction for the Stepper motor's yellow pin
	__GPIO_Set_Pin_Direction__(&Stepper_Motor_Orange);    //Set the direction for the Stepper motor's orange pin

}  //the end of the function


/* function to run the stepper motor with cw for n of rounds */
void __Stepper_Motor_CW__(f32 Rounds) {

	u16 Loop;      //Declare a variable to use it in for loop
    f32 Steps = Rounds * Stepper_Motor_Limit;        //define a variable to store the number of steps

    for(Loop = Null;Loop <= Steps;Loop++)     //for loop for control the stepper motor steps
    {
    	__GPIO_Set_Pin__(&Stepper_Motor_Blue);  	  //set the stepper motor's blue pin
    	_delay_ms(20);                          	  //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Blue);      //clear the stepper motor's blue pin
    	__GPIO_Set_Pin__(&Stepper_Motor_Pink);        //set the stepper motor's pink pin
    	_delay_ms(20);                                //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Pink);      //clear the stepper motor's pink pin
		__GPIO_Set_Pin__(&Stepper_Motor_Yellow);      //set the stepper motor's yellow pin
		_delay_ms(20);                                //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Yellow);    //clear the stepper motor's yellow pin
		__GPIO_Set_Pin__(&Stepper_Motor_Orange);      //set the stepper motor's orange pin
		_delay_ms(20);                                //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Orange);    //clear the stepper motor orange pin

    } //the end the for loop

}  //the end of the function


/* function to run stepper motor with anti cw for n of rounds */
void __Stepper_Motor_Anti_CW__(f32 Rounds) {


	u16 Loop;      //Declare a variable to use it in for loop
    f32 Steps = Rounds * Stepper_Motor_Limit;        //define a variable to store the number of steps

    for(Loop = Null;Loop <= Steps;Loop++)     //for loop to control the stepper motor steps
    {
    	__GPIO_Set_Pin__(&Stepper_Motor_Orange);  	    //set the stepper motor's orange pin
    	_delay_ms(20);                          	    //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Orange);      //clear the stepper motor's orange pin
    	__GPIO_Set_Pin__(&Stepper_Motor_Yellow);        //set the stepper motor's yellow pin
    	_delay_ms(20);                                  //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Yellow);      //clear the stepper motor's yellow pin
		__GPIO_Set_Pin__(&Stepper_Motor_Pink);          //set the stepper motor's pink pin
		_delay_ms(20);                                  //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Pink);        //clear the stepper motor's pink pin
		__GPIO_Set_Pin__(&Stepper_Motor_Blue);          //set the stepper motor's blue pin
		_delay_ms(20);                                  //wait 20 ms
    	__GPIO_Clear_Pin__(&Stepper_Motor_Blue);        //clear the stepper motor blue pin

    } //the end of the for loop

} //the end of the function



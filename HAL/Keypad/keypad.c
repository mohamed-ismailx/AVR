/*
 * keypad.c
 *
 *  Created on: Jul 19, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "GPIO.h"
#include "keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>

static u8 Keypad_Map[Keypad_Row][Keypad_Column] = {{'1','2','3','A'},   //Define a 2D array to hold the values of each key
												   {'4','5','6','B'},
												   {'7','8','9','C'},
												   {'*','0','#','D'}};

/* keypad  row */
GPIO_Pin_Configuration Keypad_Row_Zero = {Keypad_Row_Zero_Port,Keypad_Row_Zero_Pin,Output};        //Initialization of the keypad's row zero
GPIO_Pin_Configuration Keypad_Row_One = {Keypad_Row_One_Port,Keypad_Row_One_Pin,Output};         //Initialization of the keypad's row one
GPIO_Pin_Configuration Keypad_Row_Two = {Keypad_Row_Two_Port,Keypad_Row_Two_Pin,Output};         //Initialization of the keypad's row two
GPIO_Pin_Configuration Keypad_Row_Three = {Keypad_Row_Three_Port,Keypad_Row_Three_Pin,Output};       //Initialization of the keypad's row four

GPIO_Pin_Configuration *Keypad_Rows[Keypad_Row] = {&Keypad_Row_Zero,&Keypad_Row_One,&Keypad_Row_Two,&Keypad_Row_Three}; //An array of pointers to structure to use it in a for loop

/* keypad  column */
GPIO_Pin_Configuration Keypad_Column_Zero = {Keypad_Column_Zero_Port,Keypad_Column_Zero_Pin,Input_Pull_Up};     //Initialization of the keypad's column zero
GPIO_Pin_Configuration Keypad_Column_One = {Keypad_Column_One_Port,Keypad_Column_One_Pin,Input_Pull_Up};      //Initialization of the keypad's column one
GPIO_Pin_Configuration Keypad_Column_Two = {Keypad_Column_Two_Port,Keypad_Column_Two_Pin,Input_Pull_Up};      //Initialization of the keypad's column two
GPIO_Pin_Configuration Keypad_Column_Three = {Keypad_Column_Three_Port,Keypad_Column_Three_Pin,Input_Pull_Up};    //Initialization of the keypad's column four

GPIO_Pin_Configuration *Keypad_Columns[Keypad_Column] = {&Keypad_Column_Zero,&Keypad_Column_One,&Keypad_Column_Two,&Keypad_Column_Three}; //An array of pointers to structure to use it in a for loop


/* Function to set the direction of keypad pins */
void __Keypad_Initialization__(void) {

	/* keypad row */
	__GPIO_Set_Pin_Direction__(&Keypad_Row_Zero);      //Set the direction of the keypad's row zero pin as output pin
	__GPIO_Set_Pin_Direction__(&Keypad_Row_One);       //Set the direction of the keypad's row one pin as output pin
	__GPIO_Set_Pin_Direction__(&Keypad_Row_Two);       //Set the direction of the keypad's row two pin as output pin
	__GPIO_Set_Pin_Direction__(&Keypad_Row_Three);     //Set the direction of the keypad's row three pin as output pin

	/* keypad column */
	__GPIO_Set_Pin_Direction__(&Keypad_Column_Zero);   //Set the direction of the keypad's column zero pin as input pin
	__GPIO_Set_Pin_Direction__(&Keypad_Column_One);    //Set the direction of the keypad's column one pin as input pin
	__GPIO_Set_Pin_Direction__(&Keypad_Column_Two);    //Set the direction of the keypad's column two pin as input pin
	__GPIO_Set_Pin_Direction__(&Keypad_Column_Three);  //Set the direction of the keypad's column three pin as input pin


	__GPIO_Set_Pin__(&Keypad_Row_Zero);                //Set the keypad's row zero
	__GPIO_Set_Pin__(&Keypad_Row_One);                 //Set the keypad's row one
	__GPIO_Set_Pin__(&Keypad_Row_Two);                 //Set the keypad's row two
	__GPIO_Set_Pin__(&Keypad_Row_Three);               //Set the keypad's row three


}  //the end of the function



/* Function to get the value of the pressed key */
u8 __Keypad_Get_Key__(void){

	u8 Loop,Round;          //Declare two variables to use them in loops as row and column
	u8 Pressed_Key = True;    //Define a variable to hold the pressed key value

	for(Loop = Null;Loop < Keypad_Row;Loop++) {     //for loop to clear the keypad's row one by one and set the previous row

		__GPIO_Clear_Pin__(Keypad_Rows[Loop]);   //Clear the current keypad's row pin

		for(Round = Null;Round < Keypad_Column;Round++) {  //for loop to check which key is pressed

				Pressed_Key = __GPIO_Read_Pin__(Keypad_Columns[Round]);   //Read the current keypad's column pin

				if(!Pressed_Key) {     //check if the key is pressed

					_delay_ms(250);   //delay to check if the pressed key is pressed by a human or if it is just a noise.

					if(!Pressed_Key) {  //ensure that the key is still pressed

						_delay_ms(100); //delay for pouncing
						while(!__GPIO_Read_Pin__(Keypad_Columns[Round])); //wait until the user finish pressed the key
						Pressed_Key = Keypad_Map[Loop][Round];    //get the value of the pressed key from the array (keypad_map) by the current loop (row) and the current round (column) then save this value in pressed_key variable
						break;  //exit from this loop (second loop)
					} //the end of the if statement

				} //the end of the if statement

		} //the end of the second for loop

		__GPIO_Set_Pin__(Keypad_Rows[Loop]); //Set the current (ie previous) keypad's row pin


		if(Pressed_Key != True) {   //check if the value is value of key
			break;  //exit from this loop (first loop)
		} //the end of the function

	} //the end of the first for loop


	return Pressed_Key; //return the pressed key

} //the end of the function



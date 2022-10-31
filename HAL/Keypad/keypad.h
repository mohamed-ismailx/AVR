/*
 * keypad.h
 *
 *  Created on: Jul 19, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_


#define Keypad_Row     4    //Define the rows of the keypad
#define Keypad_Column  4    //Define the columns of the keypad


/* Declare an enum to configure the pins of the keypad */

typedef enum {

	/* keypad rows */
	Keypad_Row_Zero_Pin = Pin_Three,        //configure the keypad's row zero pin as the output pin x.
	Keypad_Row_One_Pin = Pin_Two,          //configure the keypad's row one pin as the output pin x.
	Keypad_Row_Two_Pin = Pin_One,          //configure the keypad's row two pin as the output pin x.
	Keypad_Row_Three_Pin = Pin_Zero,      //configure the keypad's row three pin as the output pin x.

	/* keypad rows */
	Keypad_Column_Zero_Pin = Pin_Four,     //configure the keypad's column zero pin as the input pin x.
	Keypad_Column_One_Pin = Pin_Five,      //configure the keypad's column one pin as the input pin x.
	Keypad_Column_Two_Pin = Pin_Six,       //configure the keypad's column two pin as the input pin x.
	Keypad_Column_Three_Pin = Pin_Seven    //configure the keypad's column three pin as the input pin x.

}Keypad_Pins;


/* Declare an enum to configure the port for each pin */

typedef enum {

	/* keypad rows */
	Keypad_Row_Zero_Port = PORTB,     //configure the keypad's port of row zero pin as port x.
	Keypad_Row_One_Port = PORTB,      //configure the keypad's port of row one pin as port x.
	Keypad_Row_Two_Port = PORTB,      //configure the keypad's port of row two pin as port x.
	Keypad_Row_Three_Port = PORTB,    //configure the keypad's port of row three pin as port x.

	/* keypad rows */
	Keypad_Column_Zero_Port = PORTB,  //configure the keypad's port of column zero pin as port x.
	Keypad_Column_One_Port = PORTB,   //configure the keypad's port of column one pin as port x.
	Keypad_Column_Two_Port = PORTB,   //configure the keypad's port of column two pin as port x.
	Keypad_Column_Three_Port = PORTB  //configure the keypad's port of column three pin as port x.

}Keypad_Ports;  //the end of the enum



void __Keypad_Initialization__(void); //The prototype of the function that sets the direction of keypad pins
u8 __Keypad_Get_Key__(void); //the prototype of the function that gets the value of the pressed key then return this value



#endif /* KEYPAD_H_ */

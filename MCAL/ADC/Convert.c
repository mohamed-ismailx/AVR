/*
 * Convert.c
 *
 *  Created on: Jul 22, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "Convert.h"


/* Function to convert from the integer to ascii */
void __Int_To_Ascii__(u8 Integer,u8 *String) {

	u8 Size = Null;     //define a variable to hold the size

	while (Integer) {     //while loop to check if the integer variable is converted

		String[Size] = (Integer % 10) + '0';          //convert the current digit
		Integer /= 10;                                //move to the next digit   (23) / 10  --> 2.3  = 2
		Size++;                                       //increase the size to calculate the size of the converted integer, also to store the next converted digit
	}     //the end of the while loop

	__Reverse_String__(String,Size);      //call the function to reverse the converted string

	String[Size] = '\0';                  //add the last item to the string (Null character)

}  //the end of the function


/* Function to reverse the string */
void __Reverse_String__(u8 *String,u8 Size) {

	u8 Counter = Null;                      //define a variable to use it as a counter to switching the string's items
	u8 Reverse_Conunter = Size - True;      //define a variable to hold the last element in the string
 	u8 Temp;                                //declare a variable to hold the value of the item that will be exchanged


	while(Counter < Reverse_Conunter) {     //while loop to see if all elements have been exchanged

		Temp = String[Counter];             //save the value of the current element
		String[Counter] = String[Reverse_Conunter];    //update the value of the element (reverse counter)
		String[Reverse_Conunter] = Temp;               //update the saved value
		Counter++;                                     //increase the counter value to move to the next element
		Reverse_Conunter--;                            //decrease the reverse counter to move to the next element
	}  //the end of the while loop


}  //the end of the function


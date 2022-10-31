/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "LDR.h"



int main(void)   //starting point
{

	__LDR_Initialization__();    //initialize the LDR

	for(;;) {  //super loop

		__LDR__();  //call the function that activates the LED based on the light

	}//the end of the super loop


	return Null;

} //the end of the main function





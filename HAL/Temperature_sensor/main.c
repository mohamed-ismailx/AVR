/*
 * main.c
 *
 *  Created on: Jun 21, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "Temp.h"


int main(void)   //starting point
{

	__Temp_Initialization__();

	for(;;) {  //super loop

		__Temp_Display__();

	}//the end of the super loop


	return Null;

} //the end of the main function




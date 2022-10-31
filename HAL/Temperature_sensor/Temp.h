/*
 * Temp.h
 *
 *  Created on: Jul 24, 2022
 *      Author: oliver
 */

#ifndef TEMP_H_
#define TEMP_H_


#define Temp_Size    5       //define the size of the array that hold the temperature sensor as a string


void __Temp_Initialization__(void);    //the prototype of the function that initializes the temperature sensor
void __Temp_Display__(void);           //the prototype of the function that displays the temperature value
void __Get_The_Digital_Value__(u16 Data);  //the prototype of the function that gets the digital value (just for test)


#endif /* TEMP_H_ */

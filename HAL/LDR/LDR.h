/*
 * LDR.h
 *
 *  Created on: Jul 24, 2022
 *      Author: oliver
 */

#ifndef LDR_H_
#define LDR_H_



void __Get_The_Digital_Value__(u16 Data);  //the prototype of the function that gets the digital value

//function to Initialize the LDR
void __LDR_Initialization__(void);         //the prototype of the function that initializes the LDR

void __LDR__(void);                        //the prototype of the function that activates the LED based on the light


#endif /* LDR_H_ */

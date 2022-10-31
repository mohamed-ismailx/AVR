/*
 * external_interrupt.h
 *
 *  Created on: Jul 21, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef EXTERNAL_INTERRUPT_H_
#define EXTERNAL_INTERRUPT_H_


#define No_EXTI      3            //Define the number of external interrupts in the atmega32


/* Declare an enum to configure the external interrupt's edges */

typedef enum {

	Low_Level_EXTI01,        //configure the low level edge for external interrupt 0 and 1
	Any_Change_EXTI01,       //configure the any logical change event for external interrupt 0 and 1
	Falling_EXTI01,          //configure the falling edge for external interrupt 0 and 1
	Rising_EXTI01,           //configure the rising edge for external interrupt 0 and 1
	Falling_EXTI2 = Null,    //configure the falling edge for external interrupt 2
	Rising_EXTI2             //configure the rising edge for external interrupt 2

}EXTI_Edges;  //the end of the enum


/* Declare an enum to define the external interrupts */

typedef enum {

	INT0,               //configure the external interrupt 0
	INT1,               //configure the external interrupt 1
	INT2                //configure the external interrupt 2

}EXTIx;  //the end of the enum


/* Declare a structure for EXTI configuration parameters  */

typedef struct
{
	EXTI_Edges Edge;              //Declare a variable from type EXTI_Edges
	EXTIx EXIT;                   //Declare a variable from type EXTIx
	void (*EINT)(void);           //Declare a pointer to function to hold the address of the function that comes form the application layer

}EXTI_Configuration;  //the end of the structure



void __EINT_Global_INT_Enable__(void);       //the prototype of the function that enables the global interrupt
void __EINT_Global_INT_Disable__(void);      //the prototype of the function that disables the global interrupt
Check_Error __EINT_Enable__(EXTI_Configuration *Data);   //the prototype of the function that enables the selected external interrupt
Check_Error __EINT_Disable__(EXTI_Configuration *Data);  //the prototype of the function that disables the selected external interrupt
Check_Error __EINT_Select_Edge__(EXTI_Configuration *Data); //the prototype of the function that selects the edge of the external interrupt
u8 __EINT_Read_Flags__(EXTI_Configuration *Data);          //the prototype of the function that reads the external interrupt's flag status
Check_Error __EINT_Clear_Flag__(EXTI_Configuration *Data); //the prototype of the function that clears the selected external interrupt flag
void __EINT_Set_Call_Back_Function__(EXTI_Configuration *Data); //the prototype of the function that gets the function from the application layer that used in ISR


void __vector_1(void)    __attribute__((signal));   //the prototype of the ISR function that works with external interrupt 0
void __vector_2(void)    __attribute__((signal));   //the prototype of the ISR function that works with external interrupt 1
void __vector_3(void)    __attribute__((signal));   //the prototype of the ISR function that works with external interrupt 2



#endif /* EXTERNAL_INTERRUPT_H_ */

/*
 * AVR_Registers.h
 *
 *  Created on: Jun 18, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef AVR_REGISTERS_H_
#define AVR_REGISTERS_H_


/************************************ GPIO *********************************/


/* Declare a structure to declare the register's bits */
typedef struct
{
	u8 Bit_Zero : 1;             //Declare a variable with 1bit size
	u8 Bit_One : 1;              //Declare a variable with 1bit size
	u8 Bit_Two : 1;              //Declare a variable with 1bit size
	u8 Bit_Three : 1;            //Declare a variable with 1bit size
	u8 Bit_Four : 1;             //Declare a variable with 1bit size
	u8 Bit_Five : 1;             //Declare a variable with 1bit size
	u8 Bit_Six : 1;              //Declare a variable with 1bit size
	u8 Bit_Seven : 1;            //Declare a variable with 1bit size

}GPIO_Bits;  //end of the structure


/* Declare a union to access the register or its bits */
typedef union
{
	u8 Register_Access;         //Declare a variable with the size of the register
	GPIO_Bits Bit_Access;       //Declare a variable from type GPIO bits

}GPIO_Access;  //the end of the union


/* Declare a structure to access GPIO registers */
typedef struct
{
	volatile GPIO_Access PIN;         /* Declare the PIN register */
	volatile GPIO_Access DDR;         /* Declare the DDR register */
	volatile GPIO_Access PORT;        /* Declare the PORT register */

}GPIO_Registers;  //the end of the structure



#define GPIOA ((GPIO_Registers*)0x39)           //Define the PORTA base address
#define GPIOB ((GPIO_Registers*)0x36)           //Define the PORTB base address
#define GPIOC ((GPIO_Registers*)0x33)           //Define the PORTC base address
#define GPIOD ((GPIO_Registers*)0x30)           //Define the PORTD base address


/***************************************************************************/



#endif /* AVR_REGISTERS_H_ */

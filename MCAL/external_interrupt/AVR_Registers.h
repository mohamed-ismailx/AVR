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
	u8 Register_Access;         //Define a variable with the size of the register
	GPIO_Bits Bit_Access;       //Define a variable from type GPIO bits

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


/************************************ EINT *********************************/

/* Declare a structure to declare the register's bits */

typedef struct
{
	u8 Non : 5;      //Declare a variable with 5bit size not used
	u8 INTF2 : 1;    //Declare a variable with 1bit size as an INTF2 bit
	u8 INTF0 : 1;    //Declare a variable with 1bit size as an INTF0 bit
	u8 INTF1 : 1;    //Declare a variable with 1bit size as an INTF1 bit

}GIFR_Bits; //the end of the structure



/* Define a structure to declare the register's bits */

typedef struct
{
	u8 IVCE : 1;      //Declare a variable with 1bit size as a IVCE bit
	u8 IVSEL : 4;     //Declare a variable with 4bit size as a IVSEL bit
	u8 INT2 : 1;      //Declare a variable with 1bit size as a INT2 bit
	u8 INT0 : 1;      //Declare a variable with 1bit size as a INT0 bit
	u8 INT1 : 1;      //Declare a variable with 1bit size as a INT1 bit

}GICR_Bits;  //the end of the structure



/* Declare a union to access the register or its bits */

typedef union
{
	u8 Register_Access;     //Declare a variable with the size of the register
	GIFR_Bits Bit_Access;    //Declare a variable from type GIFR_Bits

}GIFR_Access;  //the end of the union


/* Declare a union to access the register or its bits */

typedef union
{
	u8 Register_Access;    //Declare a variable with the size of the register
	GICR_Bits Bit_Access;   //Declare a variable form type GICR_Bits

}GICR_Access;  //the end of the union


/* Declare a structure to access GIFR and GICR registers */

typedef struct
{
	volatile GIFR_Access GIFR;     /* Declare the GIFR register */
	volatile GICR_Access GICR;     /* Declare the GICR register */

}EINT_Interrupt_Registers;  //the end of the structure
//0x5A


/* Declare a structure to declare the register's bits */

typedef struct
{
	u8 PORF : 1;     //Declare a variable with 1bit size as a PORF bit
	u8 EXTRF : 1;    //Declare a variable with 1bit size as a EXTRF bit
	u8 BORF : 1;     //Declare a variable with 1bit size as a BORF bit
	u8 WDRF : 1;     //Declare a variable with 1bit size as a WDRF bit
	u8 JTRF : 2;     //Declare a variable with 2bit size as a JTRF bit
	u8 ISC2 : 1;     //Declare a variable with 1bit size as a ISC2 bit
	u8 JTD : 1;      //Declare a variable with 1bit size as a JTD bit

}MCUCSR_Bits;  //the end of the structure

/* Declare a structure to declare the register's bits */

typedef struct
{
	u8 ISC01_00 : 2;   //Declare a variable with 2bit size as a ISC01_00 bit
	u8 ISC11_10 : 2;   //Declare a variable with 2bit size as a ISC11_10 bit
	u8 SM0 : 1;        //Declare a variable with 1bit size as a SM0 bit
	u8 SM1 : 1;        //Declare a variable with 1bit size as a SM1 bit
	u8 SM2 : 1;        //Declare a variable with 1bit size as a SM2 bit
	u8 SE: 1;          //Declare a variable with 1bit size as a SE bit

}MCUCR_Bits;  //the end of the structure


/* Declare a union to access the register or its bits */

typedef union
{
	u8 Register_Access;    //Declare a variable with the size of the register
	MCUCR_Bits Bit_Access;  //Declare a variable from type MCUCR_Bits

}MCUCR_Access;  //the end of the union


/* Declare a union to access the register or its bits */

typedef union
{
	u8 Register_Access;      //Declare a variable with the size of the register
	MCUCSR_Bits Bit_Access;   //Declare a variable from type MCUCSR_Bits

}MCUCSR_Access;   //the end of the structure


/* Declare a structure to access MCUCSR and MCUCR registers */

typedef struct
{
	volatile MCUCSR_Access MCUCSR;     /* Declare the MCUCSR register */
	volatile MCUCR_Access MCUCR;       /* Declare the MCUCR register */

}EINT_Edges_Registers;  //the end of the structure //0x54


/* Declare a structure to declare the register's bits */

typedef struct
{
	u8 C_Bit :1;       //Declare a variable with 1bit size as a C_Bit bit
	u8 Z_Bit :1;       //Declare a variable with 1bit size as a Z_Bit bit
	u8 N_Bit :1;       //Declare a variable with 1bit size as a N_Bit bit
	u8 V_Bit :1;       //Declare a variable with 1bit size as a V_Bit bit
	u8 S_Bit :1;       //Declare a variable with 1bit size as a S_Bit bit
	u8 H_Bit :1;       //Declare a variable with 1bit size as a H_Bit bit
	u8 T_Bit :1;       //Declare a variable with 1bit size as a T_Bit bit
	u8 I_Bit :1;       //Declare a variable with 1bit size as a I_Bit bit

}SREG_Bits;  //the end of the structure //0x5F




/* Declare a union to access the register or its bits */

typedef union
{
	u8 Register_Access;          //Declare a variable with the size of the register
	SREG_Bits Bit_Access;         //Declare a variable from type SREG_Bits

}SREG_Access; //the end of the union


/* Declare a structure to access SREG register */

typedef struct
{
	volatile SREG_Access SREG;      /* Declare the SREG register */

}EINT_SREG_Register;  //the end of the structure //0x5F




#define EINT_Edges  ((EINT_Edges_Registers*)0x54)               //Define the base address of EINT Edges registers
#define EINT_Interrupt  ((EINT_Interrupt_Registers*)0x5A)       //Define the base address of EINT Interrupt registers
#define EINT_SREG  ((EINT_SREG_Register*)0x5F)                  //Define the base address of the SREG register



/*****************************************************************************/


#endif /* AVR_REGISTERS_H_ */

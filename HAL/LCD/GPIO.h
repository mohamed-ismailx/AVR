/*
 * GPIO.h
 *
 *  Created on: Jun 18, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef GPIO_H_
#define GPIO_H_


#define No_Ports 4      //define the number of ports



/* Declare an enum to configure the modes of the GPIO */
typedef enum
{
	Input_Pull_Up = 0b0000,      //configuration of input pull up mode
	Output = 0b0001,             //configuration of output mode
	Input_Floating = 0b1000      //configuration of input floating mode


}GPIO_Directions;  //the end of the enum



/* Declare an enum to configure the Pins of the GPIO */
typedef enum
{
	Pin_Zero,      //configuration of pin zero
	Pin_One,       //configuration of pin one
	Pin_Two,       //configuration of pin two
	Pin_Three,     //configuration of pin three
	Pin_Four,      //configuration of pin four
	Pin_Five,      //configuration of pin five
	Pin_Six,       //configuration of pin six
	Pin_Seven      //configuration of pin seven

}GPIO_Pins; //the end of the enum



/* Declare an enum to configure the Ports of the GPIO */

typedef enum
{
	PORTA,      //configuration of port A
	PORTB,      //configuration of port B
	PORTC,      //configuration of port C
	PORTD       //configuration of port D

}GPIO_Ports;   //the end of the enum



/* Declare an enum to configure the levels of the pins */

typedef enum
{
	Low,    //configuration of low  is 0
	High    //configuration of high is 1

}GPIO_Level;  //the end of the enum


/* Declare a structure for pin configuration parameters  */
typedef struct
{
	GPIO_Ports Port;                   //Declare a variable from type GPIO_Ports
	GPIO_Pins Pin;                     //Declare a variable from type GPIO_Pins
	GPIO_Directions Direction;         //Declare a variable from type GPIO_Directions

}GPIO_Pin_Configuration; //the end of the structure


/* Declare a structure for port configuration parameters  */

typedef struct
{
	GPIO_Ports Port;                  //Declare a variable from type GPIO_Ports
	u8 Port_Value;                    //Declare a variable to hold the port value
	GPIO_Directions Direction;        //Declare a variable from type GPIO_Directions

}GPIO_Port_Configuration; //the end of the structure


/* Declare a structure for operation parameters */

typedef struct
{
	u8 Anding_Value;             //Declare a variable to hold the anding value
	u8 Oring_Value;              //Declare a variable to hold the oring value

}GPIO_Anding_Oring_Configuration_Value;  //the end of the structure


Check_Error __GPIO_Set_Pin_Direction__(const GPIO_Pin_Configuration *Data);  //The Prototype Of Function That Configuration The Pin Direction
Check_Error __GPIO_Set_Pin__(const GPIO_Pin_Configuration *Data);           //The Prototype Of Function That Configuration The Pin Output (HIGH)
Check_Error __GPIO_Clear_Pin__(const GPIO_Pin_Configuration *Data);         //The Prototype Of Function That Configuration The Pin Output (LOW)
u8 __GPIO_Read_Pin__(const GPIO_Pin_Configuration *Data);                   //The Prototype Of Function That read The Pin value
Check_Error __GPIO_Toggle_Pin__(const GPIO_Pin_Configuration *Data);        //The Prototype Of Function That toggle The Pin value
Check_Error __GPIO_Set_Port_Direction__(GPIO_Port_Configuration *Data);     //The Prototype Of Function That Configuration The Port Direction
Check_Error __GPIO_Write_Port__(GPIO_Port_Configuration *Data);             //The Prototype Of Function That write The port value
u8 __GPIO_Read_Port__(GPIO_Port_Configuration *Data);                       //The Prototype Of Function That read The port value
Check_Error __GPIO_Anding_Port__(GPIO_Port_Configuration *Data,GPIO_Anding_Oring_Configuration_Value *Anding);  //The Prototype Of Function That make and operation for The port value
Check_Error __GPIO_Oring_Port__(GPIO_Port_Configuration *Data,GPIO_Anding_Oring_Configuration_Value *Oring); //The Prototype Of Function That make or operation for The port value



#endif /* GPIO_H_ */


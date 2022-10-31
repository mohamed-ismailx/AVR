/*
 * electronic.h
 *
 *  Created on: Jul 16, 2022
 *      Author: mohamed mohamed taha
 */




#ifndef ELECTRONIC_H_
#define ELECTRONIC_H_

#define Seven_Segment          10      //Define the number of elements to use as a size for the array.
#define Electronics_on_state   1       //Define the on state
#define Electronics_off_state  0       //Define the off state

#define Stepper_Motor_Limit 520        //Define the Limit of the stepper motor

/* Declare an enum to configure the output pins of the seven segment */

typedef enum {
	Segment_Pin_A = Pin_Zero,     //configure the seven segment's pin A as the output pin x.
	Segment_Pin_B = Pin_One,      //configure the seven segment's pin B as the output pin x.
	Segment_Pin_C = Pin_Two,      //configure the seven segment's pin C as the output pin x.
	Segment_Pin_D = Pin_Three,    //configure the seven segment's pin D as the output pin x.
	Segment_Pin_E = Pin_Four,     //configure the seven segment's pin E as the output pin x.
	Segment_Pin_F = Pin_Five,     //configure the seven segment's pin F as the output pin x.
	Segment_Pin_G = Pin_Six,      //configure the seven segment's pin G as the output pin x.
	Segment_Pin_Dot = Pin_Seven   //configure the seven segment's pin dot as the output pin x.

}Segment_Pin_Configuration;  //end of enum


/* Declare an enum to configure the port for each output pins */

typedef enum {

	Segment_Port_A = PORTA,   //configure the seven segment's port of pin A as port x.
	Segment_Port_B = PORTA,   //configure the seven segment's port of pin B as port x.
	Segment_Port_C = PORTA,   //configure the seven segment's port of pin C as port x.
	Segment_Port_D = PORTA,   //configure the seven segment's port of pin D as port x.
	Segment_Port_E = PORTA,   //configure the seven segment's port of pin E as port x.
	Segment_Port_F = PORTA,   //configure the seven segment's port of pin F as port x.
	Segment_Port_G = PORTA,   //configure the seven segment's port of pin G as port x.
	Segment_Port_Dot = PORTA  //configure the seven segment's port of pin Dot as port x.

}Segment_Port_Configuration;   //the end of the enum




/* Declare an enum to configure the output pins of the DC motor, optocoupler and relay */

typedef enum {

	DC_Motor_Pin = Pin_Zero,          //configure the DC Motor's pin as output pin x.
	Opto_Pin  = Pin_One,              //configure the Opto's pin as output pin x.
	Relay_Pin = Pin_Two,              //configure the Relay's pin as output pin x.

	/* Stepper motor */
	Stepper_Motor_Blue_Pin = Pin_Zero,    //configure the stepper motor's blue pin as output pin x.
	Stepper_Motor_Pink_Pin = Pin_One,     //configure the stepper motor's pink pin as output pin x.
	Stepper_Motor_Yellow_Pin = Pin_Two,   //configure the stepper motor's yellow pin as output pin x.
	Stepper_Motor_Orange_Pin = Pin_Three  //configure the stepper motor's orange pin as output pin x.

}Electronics_Pin_Configuration;  //the end of the enum


/* Declare an enum to configure the port for each output pins  */
typedef enum {

	DC_Motor_Port = PORTB,            //configure the port of the DC Motor's pin as port x.
	Opto_Port  = PORTB,               //configure the port of the Opto's pin as port x.
	Relay_Port = PORTB,               //configure the port of the Relay's pin as port x.

	/* Stepper Motor */
	Stepper_Motor_Blue_Port = PORTC,     //configure the stepper motor's blue pin as output pin x.
	Stepper_Motor_Pink_Port = PORTC,     //configure the stepper motor's pink pin as output pin x.
	Stepper_Motor_Yellow_Port = PORTC,   //configure the stepper motor's yellow pin as output pin x.
	Stepper_Motor_Orange_Port = PORTC    //configure the stepper motor's orange pin as output pin x.


}Electronics_Port_Configuration;  //the end of the enum





void __Seven_Segment_Initialization__(void); //The prototype of the function that sets the direction of seven segment pins
void __Seven_Segment_Display__(u8 Data);     //The prototype of the function that takes data and display it on seven segment
void __DC_Motor_Initialization__(void);      //The prototype of the function that sets the direction of DC Motor pin
void __Opto_Initialization__(void);          //The prototype of the function that sets the direction of optocoupler pin
void __Relay_Initialization__(void);         //The prototype of the function that sets the direction of Relay pin
void __Opto_Off__(void);                     //The prototype of the function that clears the optocoupler pin
void __DC_Motor_Off__(void);                 //The prototype of the function that clears the DC Motor pin
void __Relay_Off__(void);                    //The prototype of the function that clears the relay pin
void __Opto_On__(void);                      //The prototype of the function that sets the optocoupler pin
void __DC_Motor_On__(void);                  //The prototype of the function that set the DC Motor pin
void __Relay_On__(void);                     //The prototype of the function that set the relay pin
void __Stepper_Motor_Initialization__(void); //The prototype of the function that set the direction of stepper motor pins
void __Stepper_Motor_CW__(f32 Rounds);       //The prototype of the function that run stepper motor with cw for n of rounds
void __Stepper_Motor_Anti_CW__(f32 Rounds);  //The prototype of the function that run stepper motor with anti cw for n of rounds




#endif /* ELECTRONIC_H_ */

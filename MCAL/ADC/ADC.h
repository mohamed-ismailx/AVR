/*
 * ADC.h
 *
 *  Created on: Jul 22, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef ADC_H_
#define ADC_H_


/* Declare an enum to configure the adjust result to read the ADCL and ADCH registers */

typedef enum
{
	Right_Adjust_Result,        //configure the right adjust result
	Left_Adjust_Result         //configure the left adjust result

}ADC_Adjust_Result;   //the end of the enum



/* Declare an enum to configure the ADC voltage reference */

typedef enum
{
	AREF,            //configure the AREF voltage
	AVCC,            //configure the AVCC voltage
	Internal = 3     //configure the internal voltage

}ADC_Voltage_Reference_Selections;  //the end of the enum



/* Declare an enum to configure the ADC's channels */

typedef enum
{
	Channel_ADC0,              //configure the ADC's channel 0
	Channel_ADC1,			   //configure the ADC's channel 1
	Channel_ADC2,              //configure the ADC's channel 2
	Channel_ADC3,              //configure the ADC's channel 3
	Channel_ADC4,              //configure the ADC's channel 4
	Channel_ADC5,              //configure the ADC's channel 5
	Channel_ADC6,              //configure the ADC's channel 6
	Channel_ADC7,              //configure the ADC's channel 7

	//+   -    Gain

	Channel_ADC0_ADC0_x10,     //configure the ADC's channel 0 for the positive input and channel 0 for the negative input with gain x10
	Channel_ADC1_ADC0_x10,     //configure the ADC's channel 1 for the positive input and channel 0 for the negative input with gain x10
	Channel_ADC0_ADC0_x200,    //configure the ADC's channel 0 for the positive input and channel 0 for the negative input with gain x200
	Channel_ADC1_ADC0_x200,    //configure the ADC's channel 1 for the positive input and channel 0 for the negative input with gain x200
	Channel_ADC2_ADC2_x10,     //configure the ADC's channel 2 for the positive input and channel 2 for the negative input with gain x10
	Channel_ADC3_ADC2_x10,     //configure the ADC's channel 3 for the positive input and channel 2 for the negative input with gain x10
	Channel_ADC2_ADC2_x200,    //configure the ADC's channel 2 for the positive input and channel 2 for the negative input with gain x200
	Channel_ADC3_ADC2_x200,    //configure the ADC's channel 3 for the positive input and channel 2 for the negative input with gain x200
	Channel_ADC0_ADC1_x1,      //configure the ADC's channel 0 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC1_ADC1_x1,      //configure the ADC's channel 1 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC2_ADC1_x1,      //configure the ADC's channel 2 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC3_ADC1_x1,      //configure the ADC's channel 3 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC4_ADC1_x1,      //configure the ADC's channel 4 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC5_ADC1_x1,      //configure the ADC's channel 5 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC6_ADC1_x1,      //configure the ADC's channel 6 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC7_ADC1_x1,      //configure the ADC's channel 7 for the positive input and channel 1 for the negative input with gain x1
	Channel_ADC0_ADC2_x1,      //configure the ADC's channel 0 for the positive input and channel 2 for the negative input with gain x1
	Channel_ADC1_ADC2_x1,      //configure the ADC's channel 1 for the positive input and channel 2 for the negative input with gain x1
	Channel_ADC2_ADC2_x1,      //configure the ADC's channel 2 for the positive input and channel 2 for the negative input with gain x1
	Channel_ADC3_ADC2_x1,      //configure the ADC's channel 3 for the positive input and channel 2 for the negative input with gain x1
	Channel_ADC4_ADC2_x1,      //configure the ADC's channel 4 for the positive input and channel 2 for the negative input with gain x1
	Channel_ADC5_ADC2_x1       //configure the ADC's channel 5 for the positive input and channel 2 for the negative input with gain x1

}ADC_Channel_MUX_Selections;   //the end of the enum


/* Declare an enum to configure the ADC's channels */

typedef enum
{
	Division_Factor_Per_2,          //configure the prescaler by division factor 2
	Division_Factor_Per_2_,         //configure the prescaler by division factor 2
	Division_Factor_Per_4,          //configure the prescaler by division factor 4
 	Division_Factor_Per_8,          //configure the prescaler by division factor 8
	Division_Factor_Per_16,         //configure the prescaler by division factor 16
	Division_Factor_Per_32,         //configure the prescaler by division factor 32
	Division_Factor_Per_64,         //configure the prescaler by division factor 64
	Division_Factor_Per_128         //configure the prescaler by division factor 128

}ADC_Prescaler;   //the end of the enum


/* Declare an enum to configure the ADC's Modes */
typedef enum
{
	Single_Conversion_Mode = 0b11110,    //configure the single conversion mode
	Free_Running_mode = 0,               //configure the free running mode
	Analog_Comparator,                   //configure the analog comparator mode
	External_Interrupt_Request_0,        //configure the external interrupt request 0 mode
	Timer_Counter0_Compare_Match,        //configure the Timer Counter 0 Compare Match mode
	Timer_Counter0_Overflow,             //configure the Timer Counter 0 Overflow mode
	Timer_Counter1_Compare_Match_B,      //configure the Timer Counter 1 Compare Match B mode
	Timer_Counter1_Overflow,             //configure the Timer Counter 1 Overflow mode
	Timer_Counter1_Capture_Event         //configure the Timer Counter 1 Capture Event mode

}ADC_Trigger_Source;   //the end of the enum


/* Declare a structure for ADC configuration parameters  */

typedef struct
{
	ADC_Voltage_Reference_Selections        Voltage_Reference;          //Declare a variable from type ADC_Voltage_Reference_Selections
	ADC_Adjust_Result                       Adjust_Result;              //Declare a variable from type ADC_Adjust_Result
	ADC_Channel_MUX_Selections              Channal;                    //Declare a variable from type ADC_Channel_MUX_Selections
	ADC_Prescaler                           Prescaler;                  //Declare a variable from type ADC_Prescaler
	ADC_Trigger_Source                      Mode;                       //Declare a variable from type ADC_Trigger_Source
	u16 									Digital_Value;              //Declare a variable to hold the digital value
	u16 									Analog_Value;               //Declare a variable to hold the analog value
	void (*ADC_Call_Back_Function)(u16);                               //Declare a pointer to function to hold the address of the function that used in ISR function

}ADC_Configuration;   //the end of the structure


/* function to initialize the ADC */
Check_Error __ADC_Initialization__(ADC_Configuration *Data);        //the prototype of the function that initializes the ADC
void __ADC_Disable__(void);                                         //the prototype of the function that disables the ADC
void __ADC_Enable__(void);                                          //the prototype of the function that enables the ADC
Check_Error __ADC_Single_Conversion__(ADC_Configuration *Data);     //the prototype of the function that starts single conversion
Check_Error __ADC_Free_Running__(ADC_Configuration *Data);          //the prototype of the function that starts free running mode

//function to get the function from the application layer the used when the ADC is finished his conversion process
Check_Error __ADC_Set_Call_Back_Function__(ADC_Configuration *Data); //the prototype of the function that gets the address of the function from the application layer the used when the ADC is finished his conversion process


void __vector_16(void)    __attribute__((signal));   //the prototype of the ISR function that works with ADC Conversion Complete


#endif /* ADC_H_ */

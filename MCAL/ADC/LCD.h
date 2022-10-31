/*
 * LCD.h
 *
 *  Created on: Jul 20, 2022
 *      Author: mohamed mohamed taha
 */

#ifndef LCD_H_
#define LCD_H_



#define LCD_Full_Mode             Disable         //define the LCD full mode to enable or disable this mode
#define LCD_Half_Mode             Enable         //define the LCD half mode to enable or disable this mode


#define LCD_Lines              2     //define the number of LCD's lines
#define Lcd_CGRAM_Pattern_Bits 8     //define the number of bits of the CGRAM



/* Declare an enum to configure the pins of the LCD */

typedef enum {

		LCD_RS_Pin = Pin_Zero,            //configure the LCD's RS pin as the output pin x.
		LCD_RW_Pin = Pin_One,             //configure the LCD's RW pin as the output pin x.
		LCD_Enb_Pin = Pin_One,            //configure the LCD's ENB pin as the output pin x.
		LCD_Data_Zero_Pin = Pin_Two,     //configure the LCD's data zero pin as the output pin x.
		LCD_Data_One_Pin = Pin_Three,       //configure the LCD's data one pin as the output pin x.
		LCD_Data_Two_Pin = Pin_Four,       //configure the LCD's data two pin as the output pin x.
		LCD_Data_Three_Pin = Pin_Five,   //configure the LCD's data three pin as the output pin x.
		LCD_Data_Four_Pin = Pin_Two,     //configure the LCD's data four pin as the output pin x.
		LCD_Data_Five_Pin = Pin_Three,     //configure the LCD's data five pin as the output pin x.
		LCD_Data_Six_Pin = Pin_Four,       //configure the LCD's data six pin as the output pin x.
		LCD_Data_Seven_Pin = Pin_Five    //configure the LCD's data seven pin as the output pin x.

}LCD_Pins; //the end of the enum



/* Declare an enum to configure the ports for each pin */
typedef enum {

	LCD_RS_Port = PORTA,               //configure the keypad's port of RS pin as port x.
	LCD_RW_Port = PORTA,               //configure the keypad's port of RW zero pin as port x.
	LCD_Enb_Port = PORTA,              //configure the keypad's port of ENB zero pin as port x.
	LCD_Data_Zero_Port = PORTA,        //configure the keypad's port of data zero zero pin as port x.
	LCD_Data_One_Port = PORTA,         //configure the keypad's port of data one pin as port x.
	LCD_Data_Two_Port = PORTA,         //configure the keypad's port of data two pin as port x.
	LCD_Data_Three_Port = PORTA,       //configure the keypad's port of data three pin as port x.
	LCD_Data_Four_Port = PORTA,        //configure the keypad's port of data four pin as port x.
	LCD_Data_Five_Port = PORTA,        //configure the keypad's port of data five pin as port x.
	LCD_Data_Six_Port = PORTA,         //configure the keypad's port of data six pin as port x.
	LCD_Data_Seven_Port = PORTA        //configure the keypad's port of data seven pin as port x.

}LCD_Ports;  //the end of the enum

/* Declare an enum to configure the commands of the LCD */
typedef enum {

	Clear_Display = 0x01,             //define this command to clear display of the LCD
	Return_Home = 0x02,               //define this command to return home
	Entry_Mode = 0x06,                //define this command to entry mode
	Display_On_Cursor_Off = 0x0C,     //define this command to make LCD's display on with no cursor
	Display_On_Cursor_On = 0x0E,      //define this command to make LCD's display on with cursor
	Display_On_Blink_On = 0x0F,       //define this command to make LCD's display on with blinking cursor
	Display_Off = 0x08,               //define this command to make LCD's display off
	Cursor_Shift_Left = 0x10,         //define this command to make the cursor move to left one column
	Cursor_Shift_Right = 0x14,        //define this command to make the cursor move to right one column
	Display_Shift_Left = 0x18,        //define this command to move the letters one column to left
	Display_Shift_Right = 0x1C,       //define this command to move the letters one column to right
	Function_Set_8_Bit_Operating_Mode = 0x38, //define this command to make LCD entered in 8bit mode operation mode
	Function_Set_4_Bit_Operating_Mode_One = 0x32, //define this command to make LCD entered in 4bit operation mode
	Function_Set_4_Bit_Operating_Mode_Two = 0x33, //define this command to make LCD entered in 4bit operation mode
	Function_Set_4_Bit_2_Lines = 0x28,     //define this command to make LCD display the letters in 2 lines
	Set_DDRAM_Address_First_Line = 0x80,   //define this command to make LCD display the written letters in first line
	Set_DDRAM_Address_Second_Line = 0xC0,  //define this command to make LCD display the written letters in second line
	Set_CGRAM = 0x40                       //define this command to write in CGRAM

}LCD_Commands; //the end of the enum

/* Declare an enum to define the rows of the LCD */
typedef enum
{
	Row_One,        //define the first row in the LCD
	Row_Two         //define the second row in the LCD

}LCD_Rows;  //end of the enum


/* Declare an enum to define the LCD's columns */
typedef enum
{
	Column_One,           //define the 1st column in the LCD
	Column_Two,           //define the 2ndst column in the LCD
	Column_Three,         //define the 3th column in the LCD
	Column_Four,          //define the 4th column in the LCD
	Column_Five,          //define the 5th column in the LCD
	Column_Six,           //define the 6th column in the LCD
	Column_Seven,         //define the 7th column in the LCD
	Column_Eight,         //define the 8th column in the LCD
	Column_Nine,          //define the 9th column in the LCD
	Column_Ten,           //define the 10th column in the LCD
	Column_Eleven,        //define the 11th column in the LCD
	Column_Twelve,        //define the 12th column in the LCD
	Column_Thirteen,      //define the 13th column in the LCD
	Column_Fourteen,      //define the 14th column in the LCD
	Column_Fiveteen,      //define the 15th column in the LCD
	Column_Sixteen        //define the 16th column in the LCD

}LCD_Columns;   //the end of the enum

/* Declare an enum to define CGRAM's locations */
typedef enum
{
	Pattern_Address_One,     //define the 1st location in the CGRAM
	Pattern_Address_Two,     //define the 2nd location in the CGRAM
	Pattern_Address_Three,   //define the 3th location in the CGRAM
	Pattern_Address_Four,    //define the 4th location in the CGRAM
	Pattern_Address_Five,    //define the 5th location in the CGRAM
	Pattern_Address_Six,     //define the 6th location in the CGRAM
	Pattern_Address_Seven,   //define the 7th location in the CGRAM
	Pattern_Address_Eight    //define the 8th location in the CGRAM

}LCD_Patterns_Address;   //the end of the enum


/* Declare a structure for Character generator configuration parameters  */
typedef struct
{
	LCD_Patterns_Address No_Address;   //Declare a variable from type LCD_Patterns_Address
	u8 *Pattern;                       //Declare a pointer to hold the patterns
	LCD_Rows Row_Position;             //Declare a variable from type LCD_Rows
	LCD_Columns Column_Position;       //Declare a variable from type LCD_Columns
	u8 Loop;                           //Declare a variable to use it in a for loop

}LCD_Character_Generator;  //the end of the structure



void __LCD_Enable__(void);                                            //the prototype of the function that triggers the LCD's enable pin
void __LCD_Initialization__(void);                                    //the prototype of the function that initializes the LCD
void __LCD_Send_Character__(u8 Data);                                 //the prototype of the function that sends a character to LCD
void __LCD_Set_Position__(u8 Row,u8 Column);                          //the prototype of the function that sets position
void __LCD_Send_Character_Position__(u8 Data,u8 Row,u8 Column);       //the prototype of the function that sends a character with set position
void __LCD_Send_Data_Or_Command_To_LCD__(u8 Data_Command);            //the prototype of the function that sends the data or commands to the LCD
void __LCD_Send_Command__(u8 Command);                                //the prototype of the function that sends command to LCD
void __LCD_Send_String__(char *Data);                                 //the prototype of the function that sends a string to the LCD
void __LCD_Send_String_Position__(char *Data,u8 Row,u8 Column);       //the prototype of the function that sends a string to the LCD with set position
void __LCD_Clear__(void);                                             //the prototype of the function that clears the LCD
void __LCD_Return_Home__(void);                                       //the prototype of the function that makes LCD return to home
void __LCD_Shift_Cursor__(u8 Direction_Shift);                        //the prototype of the function that makes the cursor move to left or write
void __LCD_Shift_Display__(u8 Direction_Shift);                       //the prototype of the function that makes the letters move to left or write
void __Lcd_Character_Generator__(LCD_Character_Generator *Data);      //the prototype of the function that generates a pattern


#endif /* LCD_H_ */

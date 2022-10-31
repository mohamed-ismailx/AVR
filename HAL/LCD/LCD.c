/*
 * LCD.c
 *
 *  Created on: Jul 20, 2022
 *      Author: mohamed mohamed taha
 */

#include "Stdlib.h"
#include "GPIO.h"
#include "LCD.h"
#include <util/delay.h>


//	https://omerk.github.io/lcdchargen/    for design patterns

u8 Correct[Lcd_CGRAM_Pattern_Bits] =   //define an array to design the pattern of the correct sign
{
		0b00000,
		0b00000,
		0b00001,
		0b00010,
		0b10100,
		0b11000,
		0b10000,
		0b00000
};


#if LCD_Full_Mode    //check if the selection operation is full mode


		GPIO_Pin_Configuration LCD_Enable = {LCD_Enb_Port,LCD_Enb_Pin,Output};  //Initialization of the LCD's Enable(ENB) pin
		GPIO_Pin_Configuration LCD_RS = {LCD_RS_Port,LCD_RS_Pin,Output};  //Initialization of the LCD's Register Select(RS) pin
		GPIO_Pin_Configuration LCD_Data_Zero = {LCD_Data_Zero_Port,LCD_Data_Zero_Pin,Output}; //Initialization of the LCD's data zero pin
		GPIO_Pin_Configuration LCD_Data_One = {LCD_Data_One_Port,LCD_Data_One_Pin,Output};   //Initialization of the LCD's data one pin
		GPIO_Pin_Configuration LCD_Data_Two = {LCD_Data_Two_Port,LCD_Data_Two_Pin,Output};  //Initialization of the LCD's data two pin
		GPIO_Pin_Configuration LCD_Data_Three = {LCD_Data_Three_Port,LCD_Data_Three_Pin,Output}; //Initialization of the LCD's data three pin
		GPIO_Pin_Configuration LCD_Data_Four = {LCD_Data_Four_Port,LCD_Data_Four_Pin,Output};  //Initialization of the LCD's data four pin
		GPIO_Pin_Configuration LCD_Data_Five = {LCD_Data_Five_Port,LCD_Data_Five_Pin,Output};  //Initialization of the LCD's data five pin
		GPIO_Pin_Configuration LCD_Data_Six = {LCD_Data_Six_Port,LCD_Data_Six_Pin,Output};     //Initialization of the LCD's data six pin
		GPIO_Pin_Configuration LCD_Data_Seven = {LCD_Data_Seven_Port,LCD_Data_Seven_Pin,Output};  //Initialization of the LCD's data seven pin


/* Function to send data or command to the LCD in full mode  */
void __LCD_Send_Data_Or_Command_To_LCD__(u8 Data_Command) {


	if(Data_Command & 0x01)                 //Check if the 1st bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Zero);       //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Zero);     //else, clear this pin

	if(Data_Command & 0x02)                 //Check if the 2nd bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_One);        //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_One);      //else, clear this pin

	if(Data_Command & 0x04)                 //Check if the 3th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Two);        //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Two);      //else, clear this pin

	if(Data_Command & 0x08)                 //Check if the 4th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Three);      //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Three);    //else, clear this pin

	if(Data_Command & 0x10)                 //Check if the 5th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Four);       //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Four);     //else, clear this pin

	if(Data_Command & 0x20)                 //Check if the 6th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Five);       //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Five);     //else, clear this pin

	if(Data_Command & 0x40)                 //Check if the 7th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Six);        //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Six);      //else, clear this pin

	if(Data_Command & 0x80)                 //Check if the 8th bit of data is set.
		__GPIO_Set_Pin__(&LCD_Data_Seven);      //If that happens, this pin will be set.
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Seven);    //else, clear this pin

} //the end of the function



/* Function to Initialize the LCD in 8bit mode (full mode) */
void __LCD_Initialization__(void) {

	__GPIO_Set_Pin_Direction__(&LCD_Enable);             //Set the direction of the LCD's Enable pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_RS);    //Set the direction of the LCD's RS pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Zero);              //Set the direction of the LCD's data zero pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_One);               //Set the direction of the LCD's data one pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Two);               //Set the direction of the LCD's data two pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Three);             //Set the direction of the LCD's data three pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Four);              //Set the direction of the LCD's data four pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Five);              //Set the direction of the LCD's data five pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Six);               //Set the direction of the LCD's data six pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Seven);             //Set the direction of the LCD's data seven pin as output pin

	_delay_ms(30);         //wait 30 ms
	__LCD_Send_Command__(Entry_Mode);       //send the entry mode command to LCD
	__LCD_Send_Command__(Function_Set_8_Bit_Operating_Mode);   //send the full operation mode command to LCD
	__LCD_Send_Command__(Display_On_Cursor_Off);      //send this command to turn on display with out cursor
	__LCD_Send_Command__(Clear_Display);    //clear display
	__LCD_Send_Command__(Set_DDRAM_Address_First_Line);  //LCD starts from the first line

}  //the end of the function

/* function to send character to the LCD */
void __LCD_Send_Character__(u8 Data)
{
	__GPIO_Set_Pin__(&LCD_RS);                  //set the LCD's RS pin
	__LCD_Send_Data_Or_Command_To_LCD__(Data);  //send the data to LCD
	__LCD_Enable__();                           //trigger the enable pin
	_delay_ms(1);                               //wait 1 ms
}//the end of the function



/* function to send command to the LCD */
void __LCD_Send_Command__(u8 Command)
{
	__GPIO_Clear_Pin__(&LCD_RS);                //clear the LCD's RS pin
	__LCD_Send_Data_Command_To_Port__(Command); //send the command to LCD
	__LCD_Enable__();                           //trigger the enable pin
	_delay_ms(3);                               //wait 3 ms

} //the end of the function





#elif LCD_Half_Mode   //check if the selection operation is half mode


		GPIO_Pin_Configuration LCD_Enable = {LCD_Enb_Port,LCD_Enb_Pin,Output};  //Initialization of the LCD's Enable(ENB) pin
		GPIO_Pin_Configuration LCD_RS = {LCD_RS_Port,LCD_RS_Pin,Output};  //Initialization of the LCD's Register Select(RS) pin
		GPIO_Pin_Configuration LCD_Data_Zero = {LCD_Data_Zero_Port,LCD_Data_Zero_Pin,Output}; //Initialization of the LCD's data zero pin
		GPIO_Pin_Configuration LCD_Data_One = {LCD_Data_One_Port,LCD_Data_One_Pin,Output};   //Initialization of the LCD's data one pin
		GPIO_Pin_Configuration LCD_Data_Two = {LCD_Data_Two_Port,LCD_Data_Two_Pin,Output};  //Initialization of the LCD's data two pin
		GPIO_Pin_Configuration LCD_Data_Three = {LCD_Data_Three_Port,LCD_Data_Three_Pin,Output}; //Initialization of the LCD's data three pin


/* Function to send data or command to the LCD in half mode  */
void __LCD_Send_Data_Or_Command_To_LCD__(u8 Data_Command)
{

	u8 Most_Significant,Least_Significant;    //define the most significant and least significant

	Most_Significant = (Data_Command & 0xF0) >> 4;    //get the most significant from the data and save it
	Least_Significant = (Data_Command & 0x0F);        //get the least significant from the data and save it


	if(Most_Significant & 0x01)          //Check if the 1st bit of most significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Zero); //If that happens, this pin will be set.
	else                                  //else
		__GPIO_Clear_Pin__(&LCD_Data_Zero);

	if(Most_Significant & 0x02)          //Check if the 2nd bit of most significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_One); //If that happens, this pin will be set.
	else                                 //else
		__GPIO_Clear_Pin__(&LCD_Data_One);

	if(Most_Significant & 0x04)          //Check if the 3th bit of most significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Two); //If that happens, this pin will be set.
	else                                 //else
		__GPIO_Clear_Pin__(&LCD_Data_Two);

	if(Most_Significant & 0x08)          //Check if the 4th bit of most significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Three);//If that happens, this pin will be set.
	else                                  //else
		__GPIO_Clear_Pin__(&LCD_Data_Three);

	__LCD_Enable__();           //trigger the enable pin

	_delay_us(200);            //wait 200 us


	if(Least_Significant & 0x01)         //Check if the 1st bit of least significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Zero); //If that happens, this pin will be set.
	else                                 //else
		__GPIO_Clear_Pin__(&LCD_Data_Zero);//else, clear this pin

	if(Least_Significant & 0x02)        //Check if the 2nd bit of least significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_One); //If that happens, this pin will be set.
	else                                 //else
		__GPIO_Clear_Pin__(&LCD_Data_One); //else, clear this pin

	if(Least_Significant & 0x04)        //Check if the 3th bit of least significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Two); //If that happens, this pin will be set.
	else                                 //else
		__GPIO_Clear_Pin__(&LCD_Data_Two);  //else, clear this pin

	if(Least_Significant & 0x08)        //Check if the 4th bit of least significant data is set.
		__GPIO_Set_Pin__(&LCD_Data_Three); //If that happens, this pin will be set
	else                                    //else
		__GPIO_Clear_Pin__(&LCD_Data_Three);//else, clear this pin


	__LCD_Enable__();  //trigger the enable pin

	_delay_ms(2);  //wait 2 ms

}  //the end of the function


/* Function to Initialize the LCD in 4bit mode (half mode) */
void __LCD_Initialization__(void) {

	__GPIO_Set_Pin_Direction__(&LCD_Enable);          //Set the direction of the LCD's Enable pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_RS);              //Set the direction of the LCD's RS pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Zero);       //Set the direction of the LCD's data zero pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_One);        //Set the direction of the LCD's data one pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Two);        //Set the direction of the LCD's data two pin as output pin
	__GPIO_Set_Pin_Direction__(&LCD_Data_Three);      //Set the direction of the LCD's data three pin as output pin


	_delay_ms(30);  //wait 30 ms

	__LCD_Send_Command__(Function_Set_4_Bit_Operating_Mode_Two);  //send the half operation mode command to LCD
	__LCD_Send_Command__(Function_Set_4_Bit_Operating_Mode_One);  //send the half operation mode command to LCD
	__LCD_Send_Command__(Entry_Mode);     //send the entry mode command to LCD
	__LCD_Send_Command__(Function_Set_4_Bit_2_Lines);  //send the half operation mode command to LCD with two line mode
	__LCD_Send_Command__(Display_On_Cursor_Off);   //send this command to turn on display with out cursor
	__LCD_Send_Command__(Clear_Display);   //clear display
	__LCD_Send_Command__(Set_DDRAM_Address_First_Line);  //LCD starts from the first line


}  //the end of the function


/* function to send character to LCD in half mode  */
void __LCD_Send_Character__(u8 Data)
{
	__GPIO_Set_Pin__(&LCD_RS);                 //set the RS pin
	__LCD_Send_Data_Or_Command_To_LCD__(Data);   //send the data to the LCD
} //the end of the function

/* function to send commands to the LCD */
void __LCD_Send_Command__(u8 Command)
{
	__GPIO_Clear_Pin__(&LCD_RS);                //clear the RS pin
	__LCD_Send_Data_Or_Command_To_LCD__(Command); //send the command to the LCD
} //the end of the function



#endif

/* function to trigger the LCD's enable pin */
void __LCD_Enable__(void)
{
	__GPIO_Set_Pin__(&LCD_Enable);    //set the LCD's enable pin
	_delay_ms(1);                     //wait 1 ms
	__GPIO_Clear_Pin__(&LCD_Enable);  //clear the LCD's enable pin
} //the end of the function



/* function to clear the LCD */
void __LCD_Clear__(void)
{
	__LCD_Send_Command__(Clear_Display);   //send the command that clear the LCD
	__LCD_Send_Command__(Return_Home);     //send the command that make the LCD return to home (first line)
} //the end of the function


/* function to make LCD return to home */
void __LCD_Return_Home__(void)
{
	__LCD_Send_Command__(Return_Home);   //send the command that make the LCD return to home (first line)
} //the end of the function


/* function to move the cursor one column to left or right */
void __LCD_Shift_Cursor__(u8 Direction_Shift)
{
	__LCD_Send_Command__(Direction_Shift);   //send the command to move the cursor
} //the end of the function


/* function to move the letters one column to left or righr */
void __LCD_Shift_Display__(u8 Direction_Shift)
{
	__LCD_Send_Command__(Direction_Shift);   //send the command to move the letters
} //the end of the function


/* function to display any pattern */
void __Lcd_Character_Generator__(LCD_Character_Generator *Data)
{
							//0x40
							//0x48
	__LCD_Send_Command__(Set_CGRAM | (Data->No_Address * Lcd_CGRAM_Pattern_Bits));    //allocate the pattern's size to the CGRAM


	for(Data->Loop = Null;Data->Loop < Lcd_CGRAM_Pattern_Bits;Data->Loop++)   //for loop to save the each byte in CGRAM
	{
		__LCD_Send_Character__(*(Data->Pattern + Data->Loop));       //write the current pattern's byte in CGRAM
	} //the end of the for loop

	__LCD_Set_Position__(Data->Row_Position, Data->Column_Position);    //set the position to display the pattern on it
	__LCD_Send_Character__(Data->No_Address);      //display the pattern by its location in CGRAM

} //the end of the function

/* function to display a character with position selection */
void __LCD_Send_Character_Position__(u8 Data,u8 Row,u8 Column)
{
	u8 LCD_Line[LCD_Lines] = {Set_DDRAM_Address_First_Line,Set_DDRAM_Address_Second_Line};  //define an array to hold the command of selection lines

	__LCD_Send_Command__(LCD_Line[Row] + (Column));    //send the position to LCD

	__LCD_Send_Character__(Data);   //display the character

} //the end of the function


/* function to set the position  */
void __LCD_Set_Position__(u8 Row,u8 Column)
{

	u8 LCD_Line[LCD_Lines] = {Set_DDRAM_Address_First_Line,Set_DDRAM_Address_Second_Line};  //define an array to hold the command of selection lines

	__LCD_Send_Command__(LCD_Line[Row] + (Column));   //send the position to LCD

} //end of the function

/* function to send a string to the LCD */
void __LCD_Send_String__(char *Data)
{

	while(*Data != '\0')    //while the data's character not equal '\0' (null character) send the data's character
	{
		__LCD_Send_Character__(*Data); //send the current character
		Data++;  //go to the next character

	} //the end of the while loop

} //the end of the function


/* function to send a string to LCD with position */
void __LCD_Send_String_Position__(char *Data,u8 Row,u8 Column)
{

	u8 LCD_Line[LCD_Lines] = {Set_DDRAM_Address_First_Line,Set_DDRAM_Address_Second_Line}; //define an array to hold the command of selection lines

	__LCD_Send_Command__(LCD_Line[Row] + (Column));   //set the position

	while(*Data != '\0')  //while the data's character not equal '\0' (null character) send the data's character
	{
		__LCD_Send_Character__(*Data); //send the current data's character
		Data++;  //go to the next character
	} //the end of the while loop

} //the end of the function







/*
 *
 * Created: 11/24/2016 3:17:23 PM
 * Author: Moustafa
 * This software is designed for a small calcualtor (*, +, -, /) which calculate the result of two numbers with only one digit
 */ 

/*
keypad buttons referenced to keypad(SMALLCALC)
	 {7, 8, 9, 10},
	 {4, 5, 6, 11,},
	 {1, 2, 3, 12},
	 {16, 15, 14, 13}

NOTE: button no 16 assigned in this software 
*/


#define F_CPU 8000000
#include <avr/io.h>
#include "Keypad.h"
#include "LCD.h"
#include <stdio.h>
#include <util/delay.h>

// ASCII characters
// +  43
// -  45
// =  61
// *  42
// /  47

int main(void)
{ 
    init_Keypad();
	lcd_Init();
	unsigned char numbers[2];
	unsigned char res = 0;
	unsigned char keyButton, n = 0;
	unsigned char operation = 0;
    while(1)
	{
		keyButton = recognize_Key(); 
		if(n == 0) // enter first number once
		{
			
			if (keyButton >= 1 && keyButton <=9) // first number
			{
				lcd_gotoxy(1,1);
				lcd_Print(48+keyButton);
				numbers[0] = keyButton;
				++n;
			}
	    }
		
		  if (keyButton == 10)  // /
		  {
			  lcd_gotoxy(2,1);
			  lcd_Print(47);
			  operation = 1;
		  }
		  else if (keyButton == 11) // *
		  {
			  lcd_gotoxy(2,1);
			  lcd_Print(42);
			  operation = 2;
		  }
		 else if (keyButton == 12) // -
		  {
			  lcd_gotoxy(2,1);
			  lcd_Print(45);
			  operation = 3;
		  }
		  else if (keyButton == 13) // +
		  {
			  lcd_gotoxy(2,1);
			  lcd_Print(43);
			  operation = 4;
		  }	
		
		
		if(n == 1)   // enter second number once
		{
			keyButton = recognize_Key(); 
			if (keyButton >= 1 && keyButton <=9) // second number
			{
				lcd_gotoxy(3,1);
				lcd_Print(48+keyButton);
				numbers[1] = keyButton;
				++n;
			}
		}
		
		 if (keyButton == 14)  //equal sign
		{
			lcd_gotoxy(4,1);
			lcd_Print(61);
			if (operation == 3)  //subtraction operation
			{
			    res= numbers[0] - numbers[1];
				lcd_gotoxy(5,1);
				lcd_Print(res+48);
			}
			
			else if (operation == 1) // Division operation
			{
			   res = numbers[0] / numbers[1];
			   if (res > 9)
			   {
				   lcd_gotoxy(5,1);
				   lcd_Print((res/10)+48);
				   lcd_gotoxy(6,1);
				   lcd_Print((res%10)+48);
			   }
			   	  else
					 {
						 lcd_gotoxy(5,1);
						 lcd_Print(res+48);
					 }
			}
			else if (operation == 2)  // multiplication operation
			{
				res = numbers[0] * numbers[1];
				if (res > 9)
				{
					lcd_gotoxy(5,1);
					lcd_Print((res/10)+48);
					lcd_gotoxy(6,1);
					lcd_Print((res%10)+48);
				}
				else
				{
					lcd_gotoxy(5,1);
					lcd_Print(res+48);
				}
			}
			else if (operation == 4) // Addition oeration
			{
			    res = numbers[0] + numbers[1];
				if (res > 9)
				{
					lcd_gotoxy(5,1);
					lcd_Print((res/10)+48);
					lcd_gotoxy(6,1);
					lcd_Print((res%10)+48);
				}
				else
				{
					lcd_gotoxy(5,1);
					lcd_Print(res+48);
				}
			}
		}
		
	   
	}
	return 0;
}


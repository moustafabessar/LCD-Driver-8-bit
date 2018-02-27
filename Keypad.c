/*
 * Keypad.c
 *
 * Created: 10/28/2016 7:56:15 AM
 *  Author: Moustafa
 */ 
#define F_CPU 8000000
#include "Keypad.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

unsigned char keypad_arr[4][4] = {  {7, 8, 9, 10},
									{4, 5, 6, 11,},
									{1, 2, 3, 12},
									{16, 15, 14, 13}};
void init_Keypad()
{ 
	
   keyportddr = 0x0F;
   keyport    = 0xF0;
   asm volatile("nop");  // no operation for one clock cycle
}
	

 unsigned char recognize_Key()
{
	unsigned char i,key;
	for(i=0;i<4;i++){		//Loop for 4 rows
		keyport &=~(0x01<<i);	//Make rows low one by one
		//check COL1
		if(!(keyportpin & (1<<col1))){
			key = keypad_arr[i][0];
			
			while(!(keyportpin & (1<<col1)));   //wait for release
			return key;   //return pressed key value
		}
		//Check COL2
		if(!(keyportpin & (1<<col2))){
			
			key = keypad_arr[i][1];
			
			while(!(keyportpin & (1<<col2)));    //wait for release
			return key;    //return key value
		}
		//Check COL3
		if(!(keyportpin & (1<<col3))){
			
			key = keypad_arr[i][2];
			
			while(!(keyportpin & (1<<col3)));    //Wait for release
			return key;    //Return value
		}
		//check COL4
		if(!(keyportpin & (1<<col4))){
			
			key = keypad_arr[i][3];
			
			while(!(keyportpin & (1<<col4)));     //Wait for release
			return key;       //Return key value
		}
		//Next row
		keyport |= 0x01<<i;     //make read row high again
	}
	return FALSE;	//return false if no key pressed
  
}

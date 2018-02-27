/*
 * Keypad.h
 *
 * Created: 10/28/2016 7:56:33 AM
 *  Author: Moustafa
 * (keypad 4Ч4) Driver
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdio.h>


#define T1_msec      20   //Delay 20 ms
#define T2_msec      200 

#define keyport    PORTC		//Keypad Port
#define keyportddr DDRC		    //Data Direction Register
#define keyportpin PINC		    //Keypad Port Pins


#define col1 PA4		//Column1 PortA.4
#define col2 PA5		//Column2 PortA.3
#define col3 PA6		//Column3 PortA.2
#define col4 PA7		//Column4 PortA.1
#define led1 PB0

#define TRUE 1
#define FALSE 0


	
 void init_Keypad();
 unsigned char recognize_Key();
 

#endif /* KEYPAD_H_ */

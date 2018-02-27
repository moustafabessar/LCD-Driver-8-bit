/*
 * LCD.c
 *
 * Created: 11/25/2016 7:41:12 AM
 *  Author: Moustafa
 */ 

#define F_CPU 8000000
#include "LCD.h"
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>


void lcd_SendCommand(unsigned char cmd)
{
	
	LCD_CMD_PRT &= ~(1<<LCD_RS);
	LCD_CMD_PRT &= ~(1<<LCD_RW);
	_delay_us(100);
	LCD_PRT = cmd;
	LCD_CMD_PRT |= 1<<LCD_EN;
	_delay_us(1);
	LCD_CMD_PRT &= ~(1<<LCD_EN);
	_delay_us(100);
}

void lcd_SendData(unsigned char data)
{
	
	LCD_CMD_PRT |= (1<<LCD_RS);
	LCD_CMD_PRT &= ~(1<<LCD_RW);
	_delay_us(100);
	LCD_PRT = data;
	LCD_CMD_PRT |= 1<<LCD_EN;
	_delay_us(1);
	LCD_CMD_PRT &= ~(1<<LCD_EN);
	_delay_us(100);
}

void lcd_Init()
{
	LCD_DDR = 0xFF;
	LCD_CMD_DIR |= (1<<LCD_EN) | (1<<LCD_RW) | (1<<LCD_RS);
	LCD_CMD_PRT |= (1<<LCD_EN);
	_delay_ms(2);
	lcd_SendCommand(0x38);
	lcd_SendCommand(0x0E);
	lcd_SendCommand(0x01);
	_delay_ms(2);
	lcd_SendCommand(0x06);
}

void lcd_gotoxy(unsigned char x, unsigned char y)
{
	unsigned char lineAddresses[] = {0x80, 0xc0};
	lcd_SendCommand(lineAddresses[y-1] + (x-1));
	_delay_us(100);
}

void lcd_Print(unsigned char input)
{
	
	
		lcd_SendData(input);
	
}

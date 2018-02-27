/*
 * LCD.h
 *
 * Created: 11/25/2016 7:40:59 AM
 *  Author: Moustafa
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_PRT       PORTA
#define LCD_DDR       DDRA
#define LCD_PIN       PINA
#define LCD_CMD_PRT   PORTB
#define LCD_CMD_DIR   DDRB
#define LCD_EN        PB0
#define LCD_RW        PB1
#define LCD_RS        PB2


void lcd_SendCommand(unsigned char cmd);
void lcd_SendData(unsigned char data);
void lcd_Init();
void lcd_gotoxy(unsigned char x, unsigned char y);
void lcd_Print(unsigned char input);



#endif /* LCD_H_ */

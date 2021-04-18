#ifndef  _M_MAX7219_H
#define  _M_MAX7219_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>


//---------------------
uint8_t buffer[8];
//--- оголошення----

void max7219_Init(void);
void max7219_sendData(uint8_t addr, uint8_t data);
void max7219_Clear(void);
void initBuffer(void);
void shiftBuffer(uint8_t x);
void pushCharacter(uint8_t c);
void displayBuffer(void);
void displayMessage(char* text);
void setPixel(uint8_t x, uint8_t y, char value);
void rotateChar(uint8_t *buffer);

#endif 
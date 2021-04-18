#ifndef  _M_SPI_H
#define  _M_SPI_H

#include <avr/io.h>
//--- оголошення
void SPI_MasterInit(void);
void SPI_MasterTransmit(uint8_t cData);
void SPI_SlaveInit(void);
uint8_t SPI_SlaveReceive(void);

#endif
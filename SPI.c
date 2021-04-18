#include "SPI.h"
#include <avr/io.h>

void SPI_MasterInit(void)
{
    //  MOSI (PB3) & SCK (PB5) 
    DDRB |= (1 << PB3) | (1 << PB5);
    // SPI on , Master mode, fck/16
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void SPI_MasterTransmit(uint8_t cData)
{
    // Початок передачі
    SPDR = cData;
    // Чекати завершення передачі
    while (!(SPSR & (1 << SPIF)))
        ;
}

void SPI_SlaveInit(void)
{
    // Налаштувати пін MISO (PB4) на вивід
    // Решта пінів SPI будуть входами
    DDRB = 1 << PD4;
    DDRB &= ~((1 << PB3) | (1 << PB5));
    // Включити SPI
    SPCR = (1 << SPE);
}

uint8_t SPI_SlaveReceive(void)
{
    // Чекати завершення прийому даних
    while (!(SPSR & (1 << SPIF)))
        ;
    // повернути результат
    return SPDR;
}
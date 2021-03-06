#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"
#include "max7219_display.h"


const uint16_t HURTS[56] = {
    0x38, 0x7c, 0x7e, 0x3f, 0x3f, 0x7e, 0x7c, 0x38,
    0x0, 0x38, 0x3c, 0x1e, 0x1e, 0x3c, 0x38, 0x0,
    0x0, 0x0, 0x18, 0xc, 0xc, 0x18, 0x0, 0x0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0, 0x0, 0x18, 0xc, 0xc, 0x18, 0x0, 0x0,
    0x0, 0x38, 0x3c, 0x1e, 0x1e, 0x3c, 0x38, 0x0,
    0x38, 0x7c, 0x7e, 0x3f, 0x3f, 0x7e, 0x7c, 0x38};

int main(void)
{
  max7219_Init();
  initBuffer();

  while (1)
  {
    
  displayMessage("Shifted text");

for (size_t i = 0; i < 6; i++)
{
    for (uint8_t i = 1; i <= 56; i++)
    {
      shiftBuffer(HURTS[i - 1]);
      if (i % 8 == 0)
      {
        displayBuffer();
        _delay_ms(90);
      }
      else if (i == 8 || i == 56)
      {
        _delay_ms(50);
      }
    }
}
    // 10 ms thread --------
    _delay_ms(10);
  }
  return 0;
}

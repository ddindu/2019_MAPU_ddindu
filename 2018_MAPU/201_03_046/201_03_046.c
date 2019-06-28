/*
 * 201_03_046.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 2:24:02
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

void main(void)
{
    unsigned char led = 0xfe;
    DDRA = 0xff;
    DDRE = 0b00000010;
    PORTC = led;
    
    EICRB = 0b00000010;
    EIMSK = 0b00010000;
    SREG |= 0x80;
while (1)
    {
        do
          {
            PORTA = led;
            delay_ms(100);
            led <<= 1;
            led |= 0x01;
          }
        while (led!=0x7f);
        do
          {
          PORTA = led;
          delay_ms(100);
          led >>= 1;
          led |= 0x80;
          }
        while (led != 0xfe);
    }
}
interrupt [EXT_INT4] void external_int4 (void)
{
    while((PINE & 0b00010000) == 0);
}

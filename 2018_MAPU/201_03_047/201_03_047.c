/*
 * 201_03_047.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 2:29:44
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char led = 0xfe;

void main(void)
{
    DDRA = 0xff;
    DDRE = 0b00000010;
    
    PORTC = led;
    
    EICRB = 0b00000000;
    EIMSK = 0b00010000;
    
    SREG |= 0x80;
while (1);
}
interrupt [EXT_INT4] void external_int4 (void)
{
    led <<= 1;
    led |= 0x01;
    if(led == 0xff) led = 0xfe;
    PORTA = led;
    delay_ms(100);
}

/*
 * 201_03_044.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 2:04:51
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

interrupt [EXT_INT0] void ext_int0 (void)
{
    PORTA = 0b11110000;
    delay_ms(1000);
    PORTA = 0b00001111;
    delay_ms(1000);
}
interrupt [EXT_INT1] void ext_int1 (void)
{
    PORTA = 0b00111111;
    delay_ms(1000);
    PORTA = 0b00001111;
    delay_ms(1000);
    PORTA = 0b00000011;
    delay_ms(1000);
    PORTA = 0b00000000;
    delay_ms(1000);
}
void Init(void){
    DDRA = 0xff;
    PORTA = 0xff;
    PORTD = 0xff;
    DDRD = 0x00;
}

void main(void)
{
    Init();
    EICRA |= 0x0A;
    EIMSK = 0x03;
    #asm("sei");
while (1)
    {
        PORTA = 0xff;
        delay_ms(1000);
        PORTA=0x00;
        delay_ms(1000);

    }
}

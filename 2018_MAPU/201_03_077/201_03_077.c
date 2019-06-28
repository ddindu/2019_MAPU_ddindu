/*
 * 201_03_077.c
 *
 * Created: 2018-12-20 ¿ÀÈÄ 1:27:40
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char led=0xfe;

interrupt [TIM0_OVF] void timer0_ovf(void)
{
    PORTA=led;
    if(led==0x7f)
        led = 0xfe;
    else{
        led<<=1;
        led |= 1;
    }
}

void init(void)
{
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    TIMSK = 0x01;
    
    PORTA = 0xff;
    DDRA = 0xff;
}
void main()
{
    init();
    SREG |= 0x80;
    
    while (1);
}

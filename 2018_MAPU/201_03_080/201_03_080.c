/*
 * 201_03_080.c
 *
 * Created: 2018-12-20 ¿ÀÈÄ 1:54:58
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

interrupt [TIM0_COMP] void timer0_comp (void)
{

}

void init(void)
{
    TCCR0 = 0x1f;
    TCNT0 = 0x00;
    OCR0 = 255;
    TIMSK = 0x02;
    
    PORTB=0xff;
    DDRB=0xff;
    }

void main(void)
{

    init();
    SREG |= 0x80;
    
    while(1);
}


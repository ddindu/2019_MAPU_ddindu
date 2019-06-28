/*
 * 201_03_079.c
 *
 * Created: 2018-12-20 ¿ÀÈÄ 2:01:33
 * Author: Administrator
 */

#include <maga128.h>
#include <delay.h>

unsigned char count;

interrupt [TIM0_COMP] void timer0_comp_isr (void)
{
    count++;
    if (count == 250)
    {
        PORTA ^= 0xff;
        count = 0;
    }
        
}
    void initial(void)
    {
        PORTA=0xff;
        DDRA=0xff;
        TCCR0= 0x0E;
        TCNT0 = 0x00;
        OCR0 = 249;
        
        TIMSK = 0x02;
     }
     
     void main(void)
     {
        initial();
        PORTA = 0xff;
        SREG |= 0x80;
        while(1);
     }      
/*
 * 201_03_078.c
 *
 * Created: 2018-12-20 ¿ÀÈÄ 2:07:01
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char buff = 0xfe;
int tcnt =0;

interrupt [TIM0_OVF] void timer0_ovf_isr (void)
{
    tcnt +=1;
    if(tcnt == 100)
    {
        PORTA=buff;
        if(buff == 0x7f)
        buff= 0xfe;
        else
        {
        buff <<= 1;
        buff |= 1;
        }
        tcnt = 0;
    }
    
  void init(void)
  {
    TCCR0 = 0x07;
    TCNT0 = 99;
    TIMSK = 0x01;
    
    PORTA=0xff;
    DDRA=0xff;
          
}

void main()
{
    
    init();
    SREG |= 0x80;
    
    while(1);
    
    }



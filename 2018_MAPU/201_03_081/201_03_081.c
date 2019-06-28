/*
 * 201_03_081.c
 *
 * Created: 2018-12-20 ¿ÀÈÄ 1:50:17
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

char seg_pat[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98};

    void init(void)
    {
    TCCR2=0x06;
    TCNT2 = 0;
    TIMSK = 0x40;
    
    PORTA=0x00; DDRA=0xff;
    PORTB=0x00; DDRB=0xff;
    PORTD=0xff; DDRD=0xff;
    
    }

void main(void)
{

init();

while(1)
{
    
    if(TCNT2>9)
    TCNT2=0;
    
    PORTA=seg_pat[TCNT2];
}
  }
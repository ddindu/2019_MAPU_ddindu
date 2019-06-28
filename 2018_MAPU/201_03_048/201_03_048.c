/*
 * 201_03_048.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 2:38:30
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

char seg_pat[16] = {0xc0,0x9f,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98,0x88,0x83,0xc6,0xa1,0x86,0x8e};
char n1=0;
void main(void)
{
    DDRA = 0xff;
    DDRB = 0b11110000;
    
    EICRB = 0b00000010;
    EIMSK = 0b00010000;
    SREG |= 0x80;
    
    PORTB = 0b11100000;
while (1) PORTA = seg_pat[n1];
 }
interrupt [EXT_INT4] void external_int4(void)
{
    n1 = (n1+1)%10;
}

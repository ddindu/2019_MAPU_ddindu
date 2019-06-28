/*
 * 201_03_049.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 3:04:06
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

char seg_pat[16] = {0xc0,0x9f,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98,0x88,0x83,0xc6,0xa1,0x86,0x8e};

char n1=0,n10=0,n100=0,n1000=0;

void seg4_out(void);

void main(void)
{
    DDRA = 0xff;
    DDRB = 0b11110000;
    
    EICRB = 0b10101010;
    EIMSK = 0b11110000;
    SREG |= 0x80;
while (1) seg4_out();
}
void seg4_out(void){
    PORTB = 0b11100000;
    PORTA = seg_pat[n1];
    delay_ms(100);
    
    PORTB = 0b11010000;
    PORTA = seg_pat[n10];
    delay_ms(100);
    
    PORTB = 0b10110000;
    PORTA = seg_pat[n100];
    delay_ms(100);
    
    PORTB = 0b01110000;
    PORTA = seg_pat[n1000];
    delay_ms(100);
}
interrupt [EXT_INT4] void external_int4 (void)
{
    n1 = (n1+1)%10;
}
interrupt [EXT_INT5] void external_int5 (void)
{
    n1 = (n1+1)%10;
}
interrupt [EXT_INT6] void external_int6 (void)
{
    n1 = (n1+1)%10;
}
interrupt [EXT_INT7] void external_int7 (void)
{
    n1 = (n1+1)%10;
}

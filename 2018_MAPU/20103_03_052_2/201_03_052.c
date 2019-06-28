/*
 * 201_03_052.c
 *
 * Created: 2018-11-01 ¿ÀÀü 11:43:46
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>
char seg_pat[16] = {0xc0,0x9f,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98,0x88,0x83,0xc6,0xa1,0x86,0x8e};
  
char n1=0,n10=0, n100=0, n1000=0;
char pos=0;
char hour=0, min=0, sec=0;

void time_out(void);
void main(void)
{
    char i;
    
    DDRA = 0xff;
    DDRB = 0b11110000;
    
    EICRB = 0b00001010;
    EIMSK = 0b00110000;
    SREG |= 0x80;
while (1)
    {
        for(i=0;i<49;i++) time_out();
        sec = sec + 1;
        if(sec == 60){
            sec = 0;
            min = min+1;
            if(min ==60){
                min=0;
                hour=(hour+1)%24;
            }
        }

    }
}
void time_out(void){
    PORTB = 0b11100000;
    PORTA = seg_pat[min%10];
    delay_ms(5);  
    
    PORTB = 0b11010000;
    PORTA = seg_pat[min/10];
    delay_ms(5);
    
    PORTB = 0b10110000;
    PORTA = seg_pat[hour%10];
    delay_ms(5);
    
    PORTB = 0b01110000;
    PORTA = seg_pat[hour/10];
    delay_ms(5);   
}

interrupt [EXT_INT4] void external_int4 (void)
{
    n1 = min%10;
    n10 = min/10;
    n100 = hour%10;
    n1000 = hour/10;
    
    if(pos==0) n1=(n1+1)%10;
    else if (pos==1) n10 = (n10+1) %6;
    else if (pos==2){
        if(n1000 == 2) n100=(n100+1)%4;
        else n100 = (n100+1)%10;
    }else{
        if(n100<4) n1000 = (n1000+1)%3;
        else if(n1000 != 1)n1000 = (n1000+1)%3;
    }                                          
    hour = n1000*10 +n100;
    min = n10*10 + n1;
}

interrupt [EXT_INT5] void external_int5(void)
{
    pos=(pos+1)%4;
}

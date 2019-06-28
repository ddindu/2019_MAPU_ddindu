/*
 * 201_03_50.c
 *
 * Created: 2018-10-25 ¿ÀÈÄ 3:21:19
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

char seg_pat[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98,0x88,0x83,0xc6,0xa1,0x86,0x8e};

char n1=0,n10=0,n100=0,n1000=0;
char pos=0;

void seg4_out(void);
void sw_key1(void);
void sw_key2(void);


void main(void)
{

    unsigned char old_sw, sw;
    
    DDRA = 0xff;
    DDRB = 0b11110000;
    DDRE = 0b00000010;
    
    old_sw = (PINE&0xf0);
    
while (1)
    {
        seg4_out();
        sw = (PINE&0xf0);
        if(sw==old_sw) continue;
        
        if(old_sw == 0b11110000 && sw == 0b11100000){
            sw_key1();
        }             
        else if (old_sw == 0b11110000 && sw == 0b11010000){
            sw_key2();
        }
        old_sw = sw;     
        }

    }  
    void seg4_out(void){
        PORTB = 0b11100000;
        PORTA = seg_pat[n1];
        delay_ms(5);
        
        PORTB = 0b11010000;
        PORTA = seg_pat[n10];
        delay_ms(5);
        
        PORTB = 0b10110000;
        PORTA = seg_pat[n100];
        delay_ms(5);
        
        PORTB = 0b01110000;
        PORTA = seg_pat[n1000];
        delay_ms(5);
    }                  
    void sw_key1(void){
        if(pos==0) n1=(n1+1)%10;
        else if (pos==1) n10 = (n10+1)%10;
        else if (pos==2) n100 = (n100+1)%10;
        else n1000=(n1000+1)%10;
    }                           
    void sw_key2(void){
        pos=(pos+1)%4;
    }


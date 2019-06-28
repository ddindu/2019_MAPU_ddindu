/*
 * 201_03_062.c
 *
 * Created: 2018-12-04 ¿ÀÈÄ 5:03:38
 * Author: Administrator
 */

#include <mega128a.h>
#include <stdio.h>
#include <delay.h>

#define FUNCSET 0x28 // Function set
#define ENTMODE 0x06 // Entry mode set
#define ALLCLR 0x01 // All crear
#define DISPON 0x0c // Display on
#define DISPOFF 0x08 // Display off
#define LINE1 0x80 // 1nd line move
#define LINE2 0xc0 // 2nd line move
#define HOME 0x02 // cursor home
#define LSHIFT 0x18 // display LEFT shift

typedef unsigned char hangul;

hangul font_0[8] = {0x01,0x09,0x15,0x15,0x09,0x01,0x01,0x01};
hangul font_1[8] = {0x1d,0x0b,0x0b,0x1d,0x01,0x0e,0x0a,0x0e};
hangul font_2[8] = {0x09,0x1d,0x09,0x15,0x15,0x09,0x1d,0x09};

void lcd_init(void);
void lcd_string(char flash *);
void busy(void);
void command(unsigned char);
void data(unsigned char);

void main(void)
{
    int i; lcd_init();
    
    for(i=0;i<8;i++){
        command(0x40+i);
        data(font_0[i]);
    }
    for(i=0;i<8;i++){
        command(0x48+i);
        data(font_1[i]);
    }
    for(i=0;i<8;i++){
        command(0x50+i);
        data(font_2[i]);
    }
    command(HOME);
    lcd_string("My Name is ");
    data (0x00); data(0x01); data(0x02);
    while(1);
}


    //LCD initial
void lcd_init(void){
    DDRC = 0xff;
    PORTC &= 0xfb;
    delay_ms(15);
    command(0x20);
    delay_us(5);
    command(0x20);
    delay_us(100);
    command(0x20);
    command(FUNCSET);
    command(DISPON);
    command(ALLCLR);
    command(ENTMODE);
}
    //string print
void lcd_string(char flash *pStr){
    while(*pStr) data(*pStr++);
}
    //instruction write
void command(unsigned char byte){
    busy();
        // instruction upper byte
    PORTC = (byte & 0xf0);
    PORTC &= 0xfe;
    PORTC &= 0xfd;
    delay_us(1);
    PORTC |= 0x04;
    delay_us(1);
    PORTC &= 0xfb;
    
    //instruction lower byte
    PORTC = ((byte<<4) & 0xf0);
    PORTC &= 0xfe;
    PORTC &= 0xfd;
    delay_us(1);
    PORTC |= 0x04;
    delay_us(1);
    PORTC &= 0xfb;
}

    //data write function
void data(unsigned char byte){
    busy();  
    
    //data upper read fuction
    PORTC = ((byte<<4) & 0xf0);
    PORTC &= 0x01;
    PORTC &= 0xfd;
    delay_us(1);
    PORTC |= 0x04;
    delay_us(1);
    PORTC &= 0xfb;
    
}

    //busy flah check - > delay time
void busy(void){
    delay_ms(2);
}
/*
 * 201_03_075.c
 *
 * Created: 2018-12-06 ���� 2:56:15
 * Author: Administrator
 */
#include <mega128a.h>
#include <stdio.h>
#include <delay.h>

#define FUNCSET 0x28
#define ENTMODE 0x06
#define ALLCLR 0x01
#define DISPON 0x0c
#define DISPOFF 0x08
#define LINE1 0x80
#define LINE2 0xc0
#define HOME 0x02
#define LSHIFT 0x18
#define CURON 0x0f

typedef unsigned char BYTE;
int hour=12, min=0, sec=0;
BYTE tog=0, set=0;

void lcd_init(void);
void lcd_string1(char *str);
void busy(void);
void command(unsigned char);
void data(unsigned char);
void timer_inter_init(void);
void exter_inter_init(void);
void time_display(void);
void count_up(void);

void main(void)
{
    DDRB=0xff;
    lcd_init();
    timer_inter_init();
    exter_inter_init();
    time_display();
    SREG|=0x80;
    while (1);
}

void lcd_init(void) {
    DDRC=0xff;
    PORTC&=0xfb;
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

void lcd_string1(char *str) {
    while(*str) data(*str++);
}

void command(unsigned char byte) {
    busy();
    PORTC=(byte&0xf0);
    PORTC&=0xfe;
    PORTC&=0xfd;
    delay_us(1);
    PORTC|=0x04;
    delay_us(1);
    PORTC&=0xfb;
    PORTC=((byte<<4)&0xf0);
    PORTC&=0xfe;
    PORTC&=0xfd;
    delay_us(1);
    
    PORTC|=0x04;
    delay_us(1);
    PORTC&=0xfb;
}

void data(unsigned char byte) {
    busy();
    PORTC=(byte&0xf0);
    PORTC|=0x01;
    PORTC&=0xfd;
    delay_us(1);
    PORTC|=0x04;
    delay_us(1);
    PORTC&=0xfb;
    
    PORTC=((byte<<4)&0xf0);
    PORTC|=0x01;
    PORTC&=0xfd;
    delay_us(1);
    PORTC|=0x04;
    delay_us(1);
    PORTC&=0xfb;
}

void busy(void) {
    delay_ms(2);
}

void timer_inter_init(void) {
    ETIMSK = 0x01;
    TCCR1A = 0x04;
    TCCR1B = 0x05;
    TCNT1 = 0x0000;
    OCR1CH = (7812 & 0xff00)>>8;
    OCR1CL = 0b00110000;
}

void exter_inter_init(void) {
    EICRB = 0b00001010;
    EIMSK = 0b00110000;
}

void time_display(void) {
    char time_buff[16];
    sprintf(time_buff,"%02u : %02u : %02u",hour,min,sec);
    command(HOME);
    lcd_string1(time_buff);
}

void count_up(void) {
    if(sec!=59) sec++;
    else {
        sec=0;
        if(min!=59) min++;
        else {
            min=0;
            if(hour!=12) hour++;
            else hour = 1;
        }
    }                     
    time_display();
}

interrupt [TIM1_COMPC] void time1_com(void)
{
    TCNT1 = 0x0000;
    if(tog==0) tog++;
    else {
        tog=0;
        if(set==0) count_up();
    }                         
    if(set==1) command(0x88);
    else if(set==2) command(0x83);
}

interrupt [EXT_INT4] void external_int4(void)
{
    command(CURON);
    if(set!=2) set++;
    else set=0;
}

interrupt [EXT_INT5] void external_int5(void)
{
    if(set==1) {
        if(min!=59) min++;
        else min=0;
    }              
    else if(set==2) {
        if(hour!=12) hour++;
        else hour=1;
    }               
    time_display();
}
void busy(void){
    
}
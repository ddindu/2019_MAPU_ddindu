/*
 * 201_03_065.c
 *
 * Created: 2018-12-04 ¿ÀÈÄ 5:34:33
 * Author: Administrator
 */
#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm

#include <lcd.h>

 typedef unsigned char byte;

 flash byte char0[24] = 
  {0x01,0x09,0x15,0x15,0x09,0x01,0x01,0x01,
   0x1d,0x0b,0x0b,0x1d,0x01,0x0e,0x0a,0x0e,
   0x09,0x1d,0x09,0x15,0x15,0x09,0x1d,0x09}; 
   
    void define_char(byte flash *pc,byte char_code){
    byte i,a;
    a = char_code | 0x40;
    for(i=0;i<24;i++) lcd_write_byte(a++,*pc++);
 }       

void main(void)
{
    DDRC = 0xff;
    PORTC = 0xff;
    
    lcd_init(16);
    define_char(char0,0);
    lcd_gotoxy(0,0);
    lcd_putchar(0);
    lcd_gotoxy(1,0);
    lcd_putchar(1);
    lcd_gotoxy(2,0);
    lcd_putchar(2);
    while(1);
}

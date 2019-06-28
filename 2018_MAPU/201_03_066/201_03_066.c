/*
 * 201_03_066.c
 *
 * Created: 2018-12-04 ¿ÀÈÄ 5:36:47
 * Author: Administrator
 */
#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm

#include <lcd.h>

 typedef unsigned char byte;

 flash byte name[24] = 
  {0x01,0x09,0x15,0x15,0x09,0x01,0x01,0x01,
   0x1d,0x0b,0x0b,0x1d,0x01,0x0e,0x0a,0x0e,
   0x09,0x1d,0x09,0x15,0x15,0x09,0x1d,0x09};
    
  void munja(byte flash *pt,byte co){
    byte t,b;
    b = co | 0x40;
    for(t=0;t<24;t++) lcd_write_byte(b++,*pt++);
 }

void main(void)
{
    int i;
    lcd_init(16);
    DDRC = 0xff;
    PORTC = 0xff;
    
while (1)
    {
    //lcd_clear();
    munja (name,0);
    lcd_gotoxy(0,0);
    lcd_putsf("My Name is ");
    lcd_gotoxy(11,0);
    lcd_putchar(0);
    lcd_gotoxy(12,0);
    lcd_putchar(1);
    lcd_gotoxy(13,0);
    lcd_putchar(2);
    _lcd_ready();
    _lcd_write_data(0x02);
    
    for(i=0;i<16;i++){
        delay_ms(200);
        _lcd_ready();
        _lcd_write_data(0x1c);
        
        delay_ms(200);
    }                 
    for(i=16;i>0;i--){
        delay_ms(200);
        _lcd_ready();
        _lcd_write_data(0x18);
        delay_ms(200);
    }
    }
}

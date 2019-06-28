/*
 * 201_03_053.c
 *
 * Created: 2018-11-01 오전 11:53:28
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
.equ __lcd_port=0x15 //포트A:0x1B, 포트B:0x18, 포트C:0x15, 포트D:0x12, 포트E:0x03
#endasm

#include <lcd.h>


void main(void)
{
    char buff[17] = "AVR Atmega128";
    
    PORTC = 0xff;
    DDRC = 0xff;
    
    lcd_init(16);
    lcd_gotoxy(0,0);
    
    delay_us(500);
    lcd_puts(buff);
    
    lcd_gotoxy(0,1);
    lcd_puts("ROBOT SYSTEM");
while (1)
    {
    // Please write your application code here

    }
}

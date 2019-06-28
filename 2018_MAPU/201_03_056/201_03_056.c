/*
 * 201_03_056.c
 *
 * Created: 2018-11-01 ¿ÀÈÄ 12:11:18
 * Author: Administrator
 */

#include <mega128a.h>
#include <stdio.h>
#include <lcd.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm


void main(void)
{
    int i;
    char buff='O';
    
    PORTC = 0xff;
    DDRC = 0xff;
    lcd_init(16);
    lcd_gotoxy(0,0);
    delay_ms(500);
    lcd_putchar(buff);
while (1)
    {
    for(i=1;i<=15;i++){
        _lcd_ready();
        _lcd_write_data(0x1c);
        delay_ms(200);
    } 
    for(i=1;i<=15;i++){
        _lcd_ready();
        _lcd_write_data(0x18);
        delay_ms(200);
    }
    }
}

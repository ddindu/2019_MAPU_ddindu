/*
 * 2018_05_08_20209_lcd.c
 *
 * Created: 2018-05-08 ¿ÀÈÄ 8:15:48
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port=0x1B
#endasm

#include <lcd.h>
#include <stdio.h>

int i=0;
char sbuf[16];

void main(void)
{
    lcd_init(16);
    
    while (1)
    {
        lcd_gotoxy(0,0);
        lcd_putsf("Current Value");
        for(i=0;i<=1000;i++){
            sprintf(sbuf, "DATA=%4d",i);
            lcd_gotoxy(0,1);
            lcd_puts(sbuf);
            delay_ms(100);
        }

    }
} 


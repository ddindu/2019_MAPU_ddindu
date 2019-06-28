/*
 * 201_03_055.c
 *
 * Created: 2018-11-01 ¿ÀÈÄ 12:05:54
 * Author: Administrator
 */
 
#include <mega128a.h>
#include <stdio.h>
#include <lcd.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm

int i =0;
char sbuff[16];


void main(void)
{
    lcd_init(16);
while (1)
    {
    lcd_gotoxy(0,0);           
    lcd_putsf("Current Value");
    
     for(i=0;i<=1000;i++){
        sprintf(sbuff,"DATA = %4d",i);
        
        lcd_gotoxy(0,1);
        lcd_puts(sbuff);
        delay_ms(100);

    }
}       }

/*
 * 201_03_069.c
 *
 * Created: 2018-12-06 ¿ÀÈÄ 2:06:29
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
    .equ __port_lcd = 0x15
#endasm

#include <lcd.h>

void main(void)
{
    //int i;
    unsigned char keyin;
    lcd_init(16);
    DDRC = 0xff;
    PORTC = 0xff;
    DDRD = 0x00;
    PORTD = 0xff;
    
while (1)
    {  
        if(PIND.0 == 0)
        {
            lcd_clear();
            lcd_gotoxy(0,0);
            lcd_puts("Welcome");
        }
        else if(PIND.1==0)
        {
            lcd_gotoxy(9,0);
            lcd_puts("intech electron School");
        }
    }
}

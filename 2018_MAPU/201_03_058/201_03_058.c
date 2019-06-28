/*
 * 201_03_058.c
 *
 * Created: 2018-11-01 ¿ÀÈÄ 12:18:16
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
    unsigned char buff;
    PORTA = 0xff;
    DDRA = 0x00;
    PORTC = 0xff;
    DDRC = 0xff;
    lcd_init(16);
    lcd_gotoxy(0,0);
    delay_ms(500);
    lcd_putsf("  No Switch");  
    
while (1)
    {
    buff = PINA;
    buff &= 0b00001111;
    delay_ms(100);
    switch (buff)
           {
           case 0b00001110:
                lcd_clear();
                delay_ms(10);
                lcd_putsf("SW1 ON");
                break;

           case 0b00001101:
                lcd_clear();
                delay_ms(10);
                lcd_putsf("SW2 ON");
                break;
           case 0b00001011:
                lcd_clear();
                delay_ms(10);
                lcd_putsf("SW3 ON");
                break;
           case 0b00000111:
                lcd_clear();
                delay_ms(10);
                lcd_putsf("SW4 ON");
                break; 
                
                default:
                    lcd_clear();
                    delay_ms(10);
                    lcd_putsf("   No Switch");
                break;
           }

    }
}

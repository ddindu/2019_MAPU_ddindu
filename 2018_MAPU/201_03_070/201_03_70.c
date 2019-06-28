/*
 * 201_03_70.c
 *
 * Created: 2018-12-06 ���� 2:09:59
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port=0x15
#endasm

#include <lcd.h>

int cnt = 0;

void main(void)
{
    int i;
    lcd_init(16);
    DDRC = 0xff;
    PORTC = 0xff;
    DDRD = 0x00;
    PORTD = 0xff;
    
    EICRA = 0b00000010;
    EIMSK = 0b00000001;
    SREG |= 0x80;
    
while (1)
    {
        lcd_gotoxy(0,0);
        lcd_puts("welcome");
        
        for(i=0;i<16;i++)
        {
            delay_ms(400);
            _lcd_ready();
            _lcd_write_data(0x1c);
        }
        for(i=16;i>0;i--)
        {
            delay_ms(400);
            _lcd_ready();
            _lcd_write_data(0x18);
        }
    }
}
interrupt [EXT_INT0] void external_int0 (void)
{
    cnt++;
    if(cnt==5){
    lcd_gotoxy(0,1);
    lcd_puts("Inchun school");
    cnt=0;
    }
}

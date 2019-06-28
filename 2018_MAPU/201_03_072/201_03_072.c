/*
 * 201_03_072.c
 *
 * Created: 2018-12-06 ¿ÀÈÄ 2:19:30
 * Author: Administrator
 */
#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm

#include <lcd.h>
typedef unsigned char byte;

flash byte char0[64]=
{0x01,0x09,0x15,0x15,0x09,0x01,0x01,0x01,
 0x1d,0x0b,0x0b,0x1d,0x01,0x0e,0x0a,0x0e,
 0x09,0x1d,0x09,0x15,0x15,0x09,0x1d,0x09
};

void define_char(byte flash *pc,byte char_code){
    byte i,a;
    a = char_code | 0x40;
    for(i=0;i<24;i++) lcd_write_byte(a++,*pc++);
}

void main(void)
{
    int i;
    lcd_init(16);
    DDRC = 0xff;
    PORTC = 0xff;
    DDRD = 0x00;
    PORTD = 0xff;
    
    EICRA = 0b00101010;
    EIMSK = 0b00000111;
    SREG |= 0x80;
    
while (1)
    {          
        delay_ms(100);
        _lcd_ready();
        _lcd_write_data(0x02);
        lcd_gotoxy(0,0);
        lcd_puts("My name is ");       
    }
}
interrupt [EXT_INT0] void external_int0 (void)
{
    define_char(char0,0);
    lcd_gotoxy(11,0);
    lcd_putchar(0);
    lcd_gotoxy(12,0);
    lcd_putchar(1);
    lcd_gotoxy(13,0);
    lcd_putchar(2);
}
interrupt [EXT_INT1] void external_int1 (void)
{
    lcd_gotoxy(0,1);
    lcd_puts("lee pyong hwu");
}
interrupt [EXT_INT2] void external_int2 (void)
{
    lcd_clear();
    delay_ms(400);
    _lcd_ready();
    _lcd_write_data(0x02);
}


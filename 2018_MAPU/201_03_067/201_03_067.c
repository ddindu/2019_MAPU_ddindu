/*
 * 201_03_067.c
 *
 * Created: 2018-12-06 ¿ÀÈÄ 12:06:18
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

#asm
    .equ __lcd_port = 0x15
#endasm

#include <lcd.h>


void main(void)
{

    int i;
    unsigned char keyin;
    lcd_init(16);
    DDRC = 0xff;
    PORTC = 0xff;
    DDRD = 0x00;
    PORTD = 0xff;
    
while (1)
    {
        keyin = PIND & 0x0f;
        
        switch (keyin)
               {
               case 0x0e:
                    {
                        lcd_clear();
                        lcd_gotoxy(0,0);
                        lcd_puts("Welcome");
                    }
               break;

               case 0x0d :
                         {
                            lcd_gotoxy(8,0);
                            lcd_puts("intech electron School");
                         }
                         
               break;
               }
               for(i=0;i<4;i++){
                delay_ms(200);
                _lcd_ready();
                _lcd_write_data(0x1c);
                
                delay_ms(200);
               }              
               for(i=3;i>0;i--){
                delay_ms(200);
                _lcd_ready();
                _lcd_write_data(0x18);
                delay_ms(200);
               }
    }
}

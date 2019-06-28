/*
 * 201_03_fnd1.c
 *
 * Created: 2018-11-29 ¿ÀÈÄ 2:17:18
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>
#include <lcd.h>

#asm
    .equ __lcd_port=0x1B
#endasm

unsigned char number[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98};
unsigned char swclk;
unsigned char sw;
unsigned char click = 0xfe;
int cnt=0;

void main(void)
{
    DDRA = 0xff;
    DDRC = 0xff;
    DDRD = 0xff;
    DDRE = 0xff;
    
    lcd_init(16);
    lcd_gotoxy(0,0);
    lcd_printf("FND, LCD test");
    
while (1)
    {   
        swclk = PIND;
        
        while(PIND != 0xff) delay_ms(1);
        
        switch (swclk)
               {
               case 0xfe:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w0 = 0xfe");
                        sw = 0;     
               break;

               case 0xfd:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w1 = 0xfd");
                        sw = 1;     
               break;
               case 0xfb:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w2 = 0xfb");
                        sw = 2;     
               break;
               case 0xf7:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w3 = 0xf7");
                        sw = 3;     
               break;
               case 0xef:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w4 = 0xef");
                        sw = 4;     
               break;
               case 0xdf:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w5 = 0xdf");
                        sw = 5;     
               break;
               case 0xbf:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w6 = 0xbf");
                        sw = 6;     
               break; 
               case 0x7f:
                        lcd_gotoxy(0,1);
                        lcd_printf("s/w7 = 0x7f");
                        sw = 7;     
               break;
               }   
               
               while (PINE == 0xff){
                    PORTE = click;
                    for(cnt=0;cnt>5;cnt++){ 
                        if(sw == cnt){
                            PORTC = number[1];    
                        }else
                            PORTC = number[9];
                    }
                    if (sw==6){
                        lcd_clear;
                    }
                    click = (click<<1)| 0x01;
                    delay_ms(1);
                }                           
    }
}

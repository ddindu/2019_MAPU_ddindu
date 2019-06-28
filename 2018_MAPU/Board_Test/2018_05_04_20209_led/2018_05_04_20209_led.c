/*
 * 2018_05_04_20209_led.c
 *
 * Created: 2018-05-04 ¿ÀÈÄ 12:31:15
 * Author: Administrator
 */

#include <mega128a.h>
#include <stdio.h>
#include <delay.h>

void main(void)
{
    DDRA=0xff;
    while (1)
    {
        PORTA=0xff;
        delay_ms(1000);
        PORTA=0x00;
        delay_ms(1000);
    }
}

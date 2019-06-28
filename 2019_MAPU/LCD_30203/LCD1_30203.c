/*
 * LCD1_30203.c
 *
 * Created: 2019-04-15 오후 1:47:42
 * Author: Administrator
 */

#include <mega128a.h>   //atmega128을 사용하기 위함

#asm
    .equ __lcd_port=0x1b    //lcd 를 포트A로 사용
#endasm

#include <lcd.h>    //lcd 함수
#include <delay.h>  //delay 함수

void main(void)
{
lcd_init(16);   //lcd 모듈의 초기화함수
while (1)
    {        
        lcd_gotoxy(0,0);    //글자가 나올 위치 선정
        lcd_putsf("Hi");    //Hi 를 출력
        delay_ms(700);    //지연시간
        lcd_clear();    //lcd 클리어
        
        lcd_gotoxy(0,1);    //글자가 나올 위치 선정
        lcd_putsf("Kang Jin Su");   //Kang Jin Su 를 출력
        delay_ms(700);  //지연시간       
        _lcd_ready();   //lcd 모듈이 데이터 수신을 위한 준비
        _lcd_write_data(0x01);  //LCD IR에 데이터를 write함
        
    }
}

#include <mega128a.h>   //atmega128을 사용하기 위함

#asm
    .equ __lcd_port=0x1b    //lcd 를 포트A로 사용
#endasm

#include <lcd.h>    //lcd 함수
#include <delay.h>  //delay 함수
#include <stdio.h>  //stdio 함수

int i;  //숫자
char sbuf[16];  //문자

void main(void)
{
    
    while (1)
    {
        lcd_gotoxy(0,0);    //글자가 표시될 위치
        lcd_putsf("Current Value");    //Current Value 출력
        for(i=0;i<=100;i++){    //0~100까지
            sprintf(sbuf, "DATA=%4d",i);    //sbuf 에 데이터 저장
            lcd_gotoxy(0,1);    //글자가 표시될 위치
            lcd_puts(sbuf);    //sbuf 출력
            delay_ms(500);    //0.5초 딜레이
        }
    }
} 

#include <mega128a.h>   //atmega128을 사용하기 위함

#asm
    .equ __lcd_port=0x1b    //lcd 를 포트A로 사용
#endasm

#include <lcd.h>    //lcd 함수
#include <delay.h>  //delay 함수

void main(void){
    lcd_init(16);   //lcd 모듈의 초기화함수
    while (1){
            lcd_gotoxy(0,0);    //글자가 나올 위치 선정
            lcd_putsf("ddindu");    //ddindu 출력 
            _lcd_ready();   //lcd 모듈이 데이터 수신을 위한 준비
            delay_ms(500);  //0.5초 딜레이
            _lcd_write_data(0x1c);  //표시화면 전체를 우측으로 시프트
            delay_ms(500);  //0.5초 딜레이
            _lcd_write_data(0x18);  //표시화면 전체를 좌측으로 시프트
            delay_ms(500);  //0.5초 딜레이
            _lcd_write_data(0x08);  //화면표시off, 커서표시 x, 커서 위치에 있는 문자 점멸 x
            delay_ms(500);  //0.5초 딜레이
            _lcd_write_data(0x0f);  //화면표시on, 커서표시, 커서 위치에 있는 문자 점멸
    }
}
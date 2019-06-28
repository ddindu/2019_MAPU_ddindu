/*
 * Key_30203.c
 *
 * Created: 2019-06-28 오전 9:22:09
 * Author: Administrator
 */

#include <mega128a.h>

#asm
    .equ __lcd_port=0x1b    //lcd 를 포트A로 사용
#endasm

#include <lcd.h>    //lcd 함수
#include <delay.h>  //delay 함수
#include <stdio.h>  //stdio 함수

int KeyMatrix(unsigned char in);
char sbuf[16];  //문자
 int i=0;        
 
void main(void)
{

    int keyout;
    unsigned char matrix;

    DDRA=0xff; PORTA=0xff;          
    DDRB=0xff; PORTB=0xfe;          
    DDRC=0x0f; PORTC=0x00;   
    lcd_init(16);   //lcd 모듈의 초기화함수   
   
    
    while (1)
    {      
         keyout=0xfe; 
        lcd_gotoxy(0,0);    //글자가 표시될 위치
        lcd_putsf("ddindu");    //ddindu 출력      
        delay_ms(300);  
        for(i=0; i<=3; i++){
        PORTC=keyout;   
        matrix=PINC;
        sprintf(sbuf, "data = %3X",KeyMatrix(matrix));    //sbuf 에 데이터 저장  
        lcd_gotoxy(0,1);
        lcd_puts(sbuf);    //sbuf 출력
        delay_ms(10);    //0.5초 딜레이     
        keyout=(keyout<<1)+0x01;
        }  
    }
}
int KeyMatrix(unsigned char in){
    static unsigned char key=0;
    switch(in){
        case 0x7e: key=0;   break;
        case 0x7d: key=1;   break;
        case 0x7b: key=2;   break;
        case 0x77: key=3;   break;
        case 0xBE: key=4;   break;
        case 0xBD: key=5;   break;
        case 0xBB: key=6;   break;
        case 0xB7: key=7;   break;
        case 0xDE: key=8;   break;
        case 0xDD: key=9;   break;
        case 0xDB: key=0x0A;   break;
        case 0xD7: key=0x0B;   break;
        case 0xEE: key=0x0C;   break;
        case 0xED: key=0x0D;   break;
        case 0xEB: key=0x0E;   break;
        case 0xE7: key=0x0F;   break;
    }
    return key;
}
        

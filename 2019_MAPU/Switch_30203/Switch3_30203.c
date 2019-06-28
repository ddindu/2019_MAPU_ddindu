#include <mega128a.h>   //atmega128을 사용
#include <delay.h>  //delay 함수 사용

#define SW1 PINB.0  //sw1 을 PINB1 로 이용
#define SW2 PINB.1  //sw2 을 PINB2 로 이용
#define SW3 PINB.2  //sw3 을 PINB3 로 이용
#define SECOND 500 

int sun=0;  //sun 이라는 변수에 0 을 저장

unsigned char led = 0x00;   //led 에 0x00 저장      

void setled(void)   //setled 함수 생성
{
    switch (sun)    //switch case 문에 sun 변수 입력
    {
        case 1:     //sun 변수가 1일때   
        {   
            led = led<<1;   //led 가 1씩 좌로 시프트 
            if(led==0x00)   //led==0x00일때
            {
                led=0x01;   //led=0x01;
            }         
            PORTC = ~led;   //PORTC 에 LED 반전 입력
            delay_ms(SECOND);   //SECOND 즉 0.5초 만큼 딜레이
            break;  //탈출
        }
        case 2:     //sum 변수가 2일때
        {
            led = 0x00;     //led = 0x00
            PORTC = ~led;   //PORTC 에 led 반전 입력
            break;  //탈출
        }
           
        case 3:     //sun 변수가 3일때
        {
            led = led>>1;   //led 가 1씩 우로 시프트
            if(led==0x00)   //led 가 0x00일때
            {
                led = 0x80;     //led = 0x80
            }    
            PORTC = ~led;   //PORTC 에 led 반전 입력
            delay_ms(SECOND);   //SECOND 즉 0.5초 만큼 딜레이
            break;  //탈출
        }
    }   
}

void main(void)     //main 함수 실행
{
    DDRC = 0xff;    //출력으로 설정
    DDRB = 0xff;    //출력으로 설정
    PORTB = 0xff;   //PORTB 로 0xff 출력
    
    while (1)
    {       
        
        if(SW1==0)  //sw1이 눌릴 때
        {
            sun = 1;    //sun 변수가 1   
        }
    
        if(SW2==0)   //sw2이 눌릴 때
        {
            sun = 2;    //sun 변수가 2      
        }   
    
        if(SW3==0)   //sw3이 눌릴 때
        {          
            sun = 3;    //sun 변수가 3      
        }    
        setled();   //setled함수 실행
    }      
}


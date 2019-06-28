#include <mega128a.h>   //atmega128을 사용
#include <delay.h>  //delay 함수 사용

#define SW1 PINB.1  //sw1 을 PINB1 로 이용

unsigned char led = 0x7f;   //led 에 0x7f 저장

int i=0;    //i 에 0

void main(void)
{
    DDRC = 0xff;    //출력으로 설정
    PORTC = 0xff;   //PORTC로 0xff;
     
    while (1)
    {        
        if(SW1==0)  //스위치가 눌릴 때
        {       
            PORTC = led;    //PORTC 에 led 입력    
            led = led>>1|0x80;  //led 를 하나씩 시프트하며 0x80과 or 연산
            delay_ms(100);  //0.1초 딜레이 
            i++;    //i를 하나씩 증가
            if(i==8)    //i 가 8이되면
            {
                i=0;    //i=0
                led = 0x7f;    //led 는 0x7f
            }               
        }      
      
    }
}
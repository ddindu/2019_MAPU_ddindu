#include <mega128.h>  //atmega128을 사용하기 위함
#include <delay.h>    //딜레이함수를 사용하기 위함

unsigned char led = 0xfc;  //led 변수를 0xfc로 입력
int i;  //변수 i 선언
int dn;  //변수 dn 선언

void main(void)
{
    DDRF = 0xff;  //포트를 출력으로 설정
    while(1)   
    {          
        PORTF=led;  //PORTF 로 데이터 출력
        
        for(i=0;i<3;i++)  // i를 사용해서 반복
        {          
            PORTF = led;    //PORTF 로 데이터 출력
            led=(led<<2)|0x03;  //led를 2개 시프트하고 0x03가 OR연산    
            delay_ms(1000);  //1초 딜레이
        }
        for (dn=0;dn<3;dn++)  //dn 을 사용해서 반복
        {   
            PORTF=led;   //PORTF 로 데이터 출력
            led =led>>2|0xc0;  //led를 2개 시프트하고 0xc0과 OR연산
            delay_ms(1000);  //1초 딜레이    
        }                  
    

    }
}
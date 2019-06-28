/*
 * LED1_30203.c
 *
 * Created: 2019-03-15 오전 10:28:05
 * Author: Administrator
 */

#include <mega128a.h>  //atmega128을 사용
#include <delay.h>   // 딜레이를 사용하기 위함

unsigned char led=0xff;    //led 라는 변수를 사용 
 
void main(void)
{    
    DDRA = 0xff;   // 포트를 출력으로 설정
    while (1)
    {
        PORTA = led;   //포트 A로 led 변수의 값을 출력 (0xff는 led가 꺼짐)
        delay_ms(1000);      // 1초 딜레이
        PORTA = ~led;        // led 변수를 반전해서 킴  (반전을 해서 led가 켜짐)
        delay_ms(1000);      // 1초 딜레이
    }
}

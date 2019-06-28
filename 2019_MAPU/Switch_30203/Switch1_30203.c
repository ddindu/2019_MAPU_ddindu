/*
 * Switch.c
 *
 * Created: 2019-03-18 오후 1:50:35
 * Author: Administrator
 */

#include <mega128a.h>   //atmega128을 사용

#define SW0 PINB.0  //PINB0 는 스위치 0번사용
#define SW1 PINB.1  //PINB1 은 스위치 1번사용
#define SW2 PINB.2  //PINB2 은 스위치 2번사용
#define SW3 PINB.3  //PINB3 은 스위치 3번사용


void main(void)
{
    DDRC = 0xff;    //포트를 출력으로 설정
    PORTC=0xff ;                               
    DDRB=0xff;
    PORTB=0xff;
 
    while (1)
    {
        if(SW0==0)  //sw0 이 눌리면
        {   
            PORTC = 0x55;    //PORTC로 led 값 출력        
        }                   
        
        if(SW1==0)  //sw1이 눌리면
        {
            PORTC = 0xaa;    //PORTC로 led 값 출력   
        }
        
        if(SW2==0)  //sw2이 눌리면
        {          
            PORTC = 0xff;   //PORTC로 led 값 출력   
        }
        
        if(SW3==0)  //sw3이 눌리면
        {            
            PORTC = 0x00;    //PORTC로 led 값 출력   
        }
    }
}

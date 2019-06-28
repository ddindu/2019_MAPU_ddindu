/*
 * Int_30203.c
 *
 * Created: 2019-05-20 오후 2:05:51
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char led_1=0xfe; //led 초기값
unsigned char led_2=0x7f; //led 초기값
unsigned char fnd[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};  //0~F까지 
int i = 0;  //int i 에 0 


interrupt [EXT_INT0] void ext_int0_isr (void)   //인터럽트 0번
{   
    PORTA = led_1;  //PORTA = 0xfe
    led_1 = led_1<<1|0x01;  //led_1을 쉬프트 하며 0x01과 or 연산
    delay_ms(100);  //지연 
    i++;    //1증가
    if(i==8)    //i 가 8이되면
    {
        i=0;    //i=0
        led_1 = 0xfe;    //led 는 0x7f
    } 
}
interrupt [EXT_INT2] void ext_int2_isr (void)   //인터럽트 2번
{      
    PORTA = led_2;  //PORTA = 0x7f
    led_2 = led_2>>1|0x80;  //led_2를 1씩 쉬프트 하며 or 연산
    delay_ms(100);  //지연시간           
    i++;    //1씩 증가
    if(i==8)    //i 가 8이되면
    {
        i=0;    //i=0
        led_2 = 0x7f;    //led 는 0x7f
    } 
    
}
interrupt [EXT_INT4] void ext_int4_isr (void)   //인터럽트 4번
{   
    PORTA = 0x00;   //LED all on
    delay_ms(3000); //3s 지연
    PORTA = 0xff;   //LED all off 
}
interrupt [EXT_INT6] void ext_int6_isr (void)   //인터럽트 6번
{   
    PORTC = fnd[i]; //fnd[i] 킴
    i++;    //i 1씩 증가
    if(i==16)i=0;   //i가 16이면 i=0  
}
interrupt [EXT_INT7] void ext_int7_isr (void)   //인터럽트 7번
{   
    PORTA = 0xff;   //LED all off  
}


void main(void)
{
    DDRA = 0xff;    //LED 출력 
    DDRC = 0xff;    //FND 출력
    DDRF = 0xff;    //FND 제어
    
    PORTA = 0xff;   //LED 초기값 
    PORTC=fnd[0];   //FND 초기값
    PORTF = 0xfe;   //FND 출력 제어 
    
    EICRA = 0x20;   //인터럽트 방식
    EICRB = 0x93;   //인터럽트 방식
    EIMSK = 0xd5;   //인터럽트 인에이블
    SREG |= 0x80;   //전체 인터럽트 인에이블
    
    
while (1)
    {
        
    }
}

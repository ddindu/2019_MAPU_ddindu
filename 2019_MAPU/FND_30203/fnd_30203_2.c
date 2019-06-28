#include <mega128a.h>   //atmega128 헤더파일
#include <delay.h>  //딜레이 사용


unsigned char fnd[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0xfc,0xc6,0xa1,0x86,0x8e};  //0~F까지  


void output()   //output 사용자 정의함수
{
    int i,j; //변수
    
    for(i=0;i<99;i++){                
        for(j=0;j<45;j++){
                PORTC = fnd[((i%10)/2)*2];  //짝수 일의 자리 출력
                PORTF = 0xfe;   //FND제어
                delay_ms(1);    //지연시간

                PORTC = fnd[i/10];  //짝수 십의 자리 출력
                PORTF = 0xfd;   //FND제어
                delay_ms(1);    //지연시간 
                    
                PORTC = fnd[((i%10)/2)*2+1];  //홀수 일의 자리 출력
                PORTF = 0xfb;   //FND제어
                delay_ms(1);    //지연시간

                PORTC = fnd[i/10];  //홀수 십의 자리 출력
                PORTF = 0xf7;   //FND제어
                delay_ms(1);    //지연시간
        }
    }
}
 
void main(void)
{

    DDRF = 0xff; PORTF = 0x00;  //F포트의 출력,초기값 
    DDRC = 0xff; PORTC = 0xff;  //C포트의 출력,초기값 
    
    while (1)
        {
            output();   //사용자 정의 함수
        }
}

#include <mega128a.h>   //atmega128 헤더파일
#include <delay.h>  //딜레이 사용


unsigned char fnd[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90};  //0~9까지  
unsigned char fnd_ch[4] = {0xfe,0xfd,0xfb,0xf7};    //fnd 선택 변수
unsigned char n1 = 0, n10 = 0, n100 = 0, n1000 = 0;     //자리수 지정 변수
unsigned char status = 0;   //fnd 선택변경을 위한 변수

#define SW1 PINB.0  //sw1 을 PINB1 로 이용
#define SW2 PINB.1  //sw2 을 PINB2 로 이용

void outpost()
{
    PORTC=fnd[n1%10];      //1의 자리수 출력
    PORTF=fnd_ch[0];    //FND1 
    delay_ms(1);    //지연시간++++
           
    PORTC=fnd[n10%10];     //10의 자리수 출력
    PORTF=fnd_ch[1];    //FND2 
    delay_ms(1);    //지연시간
    
    PORTC=fnd[n100%10];    //100의 자리수 출력
    PORTF=fnd_ch[2];    //FND3 
    delay_ms(1);    //지연시간
        
    PORTC=fnd[n1000%10];    //1000의 자리수 출력
    PORTF=fnd_ch[3];    //FND4
    delay_ms(1);    //지연시간
    
    PORTF = 0xff;   //버튼을 누르면 fnd가 다 꺼짐   

}                                

void main(void)
{
    DDRC = 0xff;    //포트 C 출력설정  
    DDRD = 0x00;    //포트 D 출력설정
    DDRF = 0xff;    //포트 F 출력설정
    
    while (1)                       
    {       
        outpost();  //사용자 정의 함수
          
        if(SW1==0){    //SW1눌리면               
            delay_ms(50);   //지연시간
            
            while(SW1!=1);  //SW1이 눌린 동안 동작 안하고, 떼면 동작
            
            switch (status%4+1)    //현재 자리수 변수값에 따라
            {
                case 1: n1 = n1+1; break;   //1인경우 1의 자리수를 +1 
                case 2: n10 = n10+1; break;   //2인경우 10의 자리수를 +1
                case 3: n100 = n100+1; break;   //3인경우 100의 자리수를 +1
                case 4: n1000 = n1000+1; break;   //4인경우 1000의 자리수를 +1
                    
                default: break;                     
            }                 
        }                       
        if(SW2==0){   //SW2이 눌리면            
            delay_ms(50);   //지연시간
            
            while(SW2!=1);     //SW2가 눌린 동안 동작을 안하고, 떼면 동작
            status = status + 1;    //자리수 위치 +1       
        }            
    }
}

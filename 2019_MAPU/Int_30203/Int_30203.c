/*
 * Int_30203.c
 *
 * Created: 2019-05-20 ���� 2:05:51
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char led_1=0xfe; //led �ʱⰪ
unsigned char led_2=0x7f; //led �ʱⰪ
unsigned char fnd[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};  //0~F���� 
int i = 0;  //int i �� 0 


interrupt [EXT_INT0] void ext_int0_isr (void)   //���ͷ�Ʈ 0��
{   
    PORTA = led_1;  //PORTA = 0xfe
    led_1 = led_1<<1|0x01;  //led_1�� ����Ʈ �ϸ� 0x01�� or ����
    delay_ms(100);  //���� 
    i++;    //1����
    if(i==8)    //i �� 8�̵Ǹ�
    {
        i=0;    //i=0
        led_1 = 0xfe;    //led �� 0x7f
    } 
}
interrupt [EXT_INT2] void ext_int2_isr (void)   //���ͷ�Ʈ 2��
{      
    PORTA = led_2;  //PORTA = 0x7f
    led_2 = led_2>>1|0x80;  //led_2�� 1�� ����Ʈ �ϸ� or ����
    delay_ms(100);  //�����ð�           
    i++;    //1�� ����
    if(i==8)    //i �� 8�̵Ǹ�
    {
        i=0;    //i=0
        led_2 = 0x7f;    //led �� 0x7f
    } 
    
}
interrupt [EXT_INT4] void ext_int4_isr (void)   //���ͷ�Ʈ 4��
{   
    PORTA = 0x00;   //LED all on
    delay_ms(3000); //3s ����
    PORTA = 0xff;   //LED all off 
}
interrupt [EXT_INT6] void ext_int6_isr (void)   //���ͷ�Ʈ 6��
{   
    PORTC = fnd[i]; //fnd[i] Ŵ
    i++;    //i 1�� ����
    if(i==16)i=0;   //i�� 16�̸� i=0  
}
interrupt [EXT_INT7] void ext_int7_isr (void)   //���ͷ�Ʈ 7��
{   
    PORTA = 0xff;   //LED all off  
}


void main(void)
{
    DDRA = 0xff;    //LED ��� 
    DDRC = 0xff;    //FND ���
    DDRF = 0xff;    //FND ����
    
    PORTA = 0xff;   //LED �ʱⰪ 
    PORTC=fnd[0];   //FND �ʱⰪ
    PORTF = 0xfe;   //FND ��� ���� 
    
    EICRA = 0x20;   //���ͷ�Ʈ ���
    EICRB = 0x93;   //���ͷ�Ʈ ���
    EIMSK = 0xd5;   //���ͷ�Ʈ �ο��̺�
    SREG |= 0x80;   //��ü ���ͷ�Ʈ �ο��̺�
    
    
while (1)
    {
        
    }
}

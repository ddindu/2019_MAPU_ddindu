#include <mega128a.h>   //atmega128�� ���
#include <delay.h>  //delay �Լ� ���

#define SW1 PINB.1  //sw1 �� PINB1 �� �̿�

unsigned char led = 0x7f;   //led �� 0x7f ����

int i=0;    //i �� 0

void main(void)
{
    DDRC = 0xff;    //������� ����
    PORTC = 0xff;   //PORTC�� 0xff;
     
    while (1)
    {        
        if(SW1==0)  //����ġ�� ���� ��
        {       
            PORTC = led;    //PORTC �� led �Է�    
            led = led>>1|0x80;  //led �� �ϳ��� ����Ʈ�ϸ� 0x80�� or ����
            delay_ms(100);  //0.1�� ������ 
            i++;    //i�� �ϳ��� ����
            if(i==8)    //i �� 8�̵Ǹ�
            {
                i=0;    //i=0
                led = 0x7f;    //led �� 0x7f
            }               
        }      
      
    }
}
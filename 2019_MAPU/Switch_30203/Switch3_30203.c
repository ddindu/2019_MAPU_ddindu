#include <mega128a.h>   //atmega128�� ���
#include <delay.h>  //delay �Լ� ���

#define SW1 PINB.0  //sw1 �� PINB1 �� �̿�
#define SW2 PINB.1  //sw2 �� PINB2 �� �̿�
#define SW3 PINB.2  //sw3 �� PINB3 �� �̿�
#define SECOND 500 

int sun=0;  //sun �̶�� ������ 0 �� ����

unsigned char led = 0x00;   //led �� 0x00 ����      

void setled(void)   //setled �Լ� ����
{
    switch (sun)    //switch case ���� sun ���� �Է�
    {
        case 1:     //sun ������ 1�϶�   
        {   
            led = led<<1;   //led �� 1�� �·� ����Ʈ 
            if(led==0x00)   //led==0x00�϶�
            {
                led=0x01;   //led=0x01;
            }         
            PORTC = ~led;   //PORTC �� LED ���� �Է�
            delay_ms(SECOND);   //SECOND �� 0.5�� ��ŭ ������
            break;  //Ż��
        }
        case 2:     //sum ������ 2�϶�
        {
            led = 0x00;     //led = 0x00
            PORTC = ~led;   //PORTC �� led ���� �Է�
            break;  //Ż��
        }
           
        case 3:     //sun ������ 3�϶�
        {
            led = led>>1;   //led �� 1�� ��� ����Ʈ
            if(led==0x00)   //led �� 0x00�϶�
            {
                led = 0x80;     //led = 0x80
            }    
            PORTC = ~led;   //PORTC �� led ���� �Է�
            delay_ms(SECOND);   //SECOND �� 0.5�� ��ŭ ������
            break;  //Ż��
        }
    }   
}

void main(void)     //main �Լ� ����
{
    DDRC = 0xff;    //������� ����
    DDRB = 0xff;    //������� ����
    PORTB = 0xff;   //PORTB �� 0xff ���
    
    while (1)
    {       
        
        if(SW1==0)  //sw1�� ���� ��
        {
            sun = 1;    //sun ������ 1   
        }
    
        if(SW2==0)   //sw2�� ���� ��
        {
            sun = 2;    //sun ������ 2      
        }   
    
        if(SW3==0)   //sw3�� ���� ��
        {          
            sun = 3;    //sun ������ 3      
        }    
        setled();   //setled�Լ� ����
    }      
}


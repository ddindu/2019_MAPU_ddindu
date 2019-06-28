#include <mega128.h>  //atmega128�� ����ϱ� ����
#include <delay.h>    //�������Լ��� ����ϱ� ����

unsigned char led = 0xfc;  //led ������ 0xfc�� �Է�
int i;  //���� i ����
int dn;  //���� dn ����

void main(void)
{
    DDRF = 0xff;  //��Ʈ�� ������� ����
    while(1)   
    {          
        PORTF=led;  //PORTF �� ������ ���
        
        for(i=0;i<3;i++)  // i�� ����ؼ� �ݺ�
        {          
            PORTF = led;    //PORTF �� ������ ���
            led=(led<<2)|0x03;  //led�� 2�� ����Ʈ�ϰ� 0x03�� OR����    
            delay_ms(1000);  //1�� ������
        }
        for (dn=0;dn<3;dn++)  //dn �� ����ؼ� �ݺ�
        {   
            PORTF=led;   //PORTF �� ������ ���
            led =led>>2|0xc0;  //led�� 2�� ����Ʈ�ϰ� 0xc0�� OR����
            delay_ms(1000);  //1�� ������    
        }                  
    

    }
}
#include <mega128a.h>   //atmega128 �������
#include <delay.h>  //������ ���


unsigned char fnd[16] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0xfc,0xc6,0xa1,0x86,0x8e};  //0~F����  


void output()   //output ����� �����Լ�
{
    int i,j; //����
    
    for(i=0;i<99;i++){                
        for(j=0;j<45;j++){
                PORTC = fnd[((i%10)/2)*2];  //¦�� ���� �ڸ� ���
                PORTF = 0xfe;   //FND����
                delay_ms(1);    //�����ð�

                PORTC = fnd[i/10];  //¦�� ���� �ڸ� ���
                PORTF = 0xfd;   //FND����
                delay_ms(1);    //�����ð� 
                    
                PORTC = fnd[((i%10)/2)*2+1];  //Ȧ�� ���� �ڸ� ���
                PORTF = 0xfb;   //FND����
                delay_ms(1);    //�����ð�

                PORTC = fnd[i/10];  //Ȧ�� ���� �ڸ� ���
                PORTF = 0xf7;   //FND����
                delay_ms(1);    //�����ð�
        }
    }
}
 
void main(void)
{

    DDRF = 0xff; PORTF = 0x00;  //F��Ʈ�� ���,�ʱⰪ 
    DDRC = 0xff; PORTC = 0xff;  //C��Ʈ�� ���,�ʱⰪ 
    
    while (1)
        {
            output();   //����� ���� �Լ�
        }
}

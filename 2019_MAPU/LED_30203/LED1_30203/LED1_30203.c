/*
 * LED1_30203.c
 *
 * Created: 2019-03-15 ���� 10:28:05
 * Author: Administrator
 */

#include <mega128a.h>  //atmega128�� ���
#include <delay.h>   // �����̸� ����ϱ� ����

unsigned char led=0xff;    //led ��� ������ ��� 
 
void main(void)
{    
    DDRA = 0xff;   // ��Ʈ�� ������� ����
    while (1)
    {
        PORTA = led;   //��Ʈ A�� led ������ ���� ��� (0xff�� led�� ����)
        delay_ms(1000);      // 1�� ������
        PORTA = ~led;        // led ������ �����ؼ� Ŵ  (������ �ؼ� led�� ����)
        delay_ms(1000);      // 1�� ������
    }
}

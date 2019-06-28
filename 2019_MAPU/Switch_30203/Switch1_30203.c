/*
 * Switch.c
 *
 * Created: 2019-03-18 ���� 1:50:35
 * Author: Administrator
 */

#include <mega128a.h>   //atmega128�� ���

#define SW0 PINB.0  //PINB0 �� ����ġ 0�����
#define SW1 PINB.1  //PINB1 �� ����ġ 1�����
#define SW2 PINB.2  //PINB2 �� ����ġ 2�����
#define SW3 PINB.3  //PINB3 �� ����ġ 3�����


void main(void)
{
    DDRC = 0xff;    //��Ʈ�� ������� ����
    PORTC=0xff ;                               
    DDRB=0xff;
    PORTB=0xff;
 
    while (1)
    {
        if(SW0==0)  //sw0 �� ������
        {   
            PORTC = 0x55;    //PORTC�� led �� ���        
        }                   
        
        if(SW1==0)  //sw1�� ������
        {
            PORTC = 0xaa;    //PORTC�� led �� ���   
        }
        
        if(SW2==0)  //sw2�� ������
        {          
            PORTC = 0xff;   //PORTC�� led �� ���   
        }
        
        if(SW3==0)  //sw3�� ������
        {            
            PORTC = 0x00;    //PORTC�� led �� ���   
        }
    }
}

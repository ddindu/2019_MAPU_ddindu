#include <mega128a.h>   //atmega128�� ����ϱ� ����

#asm
    .equ __lcd_port=0x1b    //lcd �� ��ƮA�� ���
#endasm

#include <lcd.h>    //lcd �Լ�
#include <delay.h>  //delay �Լ�
#include <stdio.h>  //stdio �Լ�

int i;  //����
char sbuf[16];  //����

void main(void)
{
    
    while (1)
    {
        lcd_gotoxy(0,0);    //���ڰ� ǥ�õ� ��ġ
        lcd_putsf("Current Value");    //Current Value ���
        for(i=0;i<=100;i++){    //0~100����
            sprintf(sbuf, "DATA=%4d",i);    //sbuf �� ������ ����
            lcd_gotoxy(0,1);    //���ڰ� ǥ�õ� ��ġ
            lcd_puts(sbuf);    //sbuf ���
            delay_ms(500);    //0.5�� ������
        }
    }
} 
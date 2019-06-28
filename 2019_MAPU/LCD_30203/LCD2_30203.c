
#include <mega128a.h>   //atmega128�� ����ϱ� ����

#asm
    .equ __lcd_port=0x1b    //lcd �� ��ƮA�� ���
#endasm

#include <lcd.h>    //lcd �Լ�
#include <delay.h>  //delay �Լ�

void main(void){
    lcd_init(16);   //lcd ����� �ʱ�ȭ�Լ�
    while (1){
            lcd_gotoxy(0,0);    //���ڰ� ���� ��ġ ����
            lcd_putsf("ddindu");    //ddindu ��� 
            _lcd_ready();   //lcd ����� ������ ������ ���� �غ�
            delay_ms(500);  //0.5�� ������
            _lcd_write_data(0x1c);  //ǥ��ȭ�� ��ü�� �������� ����Ʈ
            delay_ms(500);  //0.5�� ������
            _lcd_write_data(0x18);  //ǥ��ȭ�� ��ü�� �������� ����Ʈ
            delay_ms(500);  //0.5�� ������
            _lcd_write_data(0x08);  //ȭ��ǥ��off, Ŀ��ǥ�� x, Ŀ�� ��ġ�� �ִ� ���� ���� x
            delay_ms(500);  //0.5�� ������
            _lcd_write_data(0x0f);  //ȭ��ǥ��on, Ŀ��ǥ��, Ŀ�� ��ġ�� �ִ� ���� ����
    }
}
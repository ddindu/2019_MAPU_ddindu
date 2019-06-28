/*
 * 2018_05_08_20209_keymatrix.c
 *
 * Created: 2018-05-08 ¿ÀÈÄ 7:40:06
 * Author: Administrator
 */

#include <mega128a.h>
#include <delay.h>

unsigned char fnd[16]={0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x98, 0x88, 0x83,0xc6, 0xa1, 0x86, 0x8e};
int KeyMatrix(unsigned char in);

void main(void)
{
    int keyout;
    int i;
    unsigned char matrix;
    DDRA=0xff; PORTA=0xff;
    DDRB=0xff; PORTB=0xfe;
    DDRC=0x0f; PORTC=0x00;
    while (1){
        keyout=0xfe;
        for(i=0; i<=3; i++){
            PORTC=keyout;
            matrix=PINC;
            PORTA=fnd[KeyMatrix(matrix)];
            delay_ms(1);
            keyout=(keyout<<1)+0x01;
        }
    }
}

int KeyMatrix(unsigned char in){
    static unsigned char key=0;
    switch(in){
        case 0x7e: key=0;   break;
        case 0x7d: key=1;   break;
        case 0x7b: key=2;   break;
        case 0x77: key=3;   break;
        case 0xBE: key=4;   break;
        case 0xBD: key=5;   break;
        case 0xBB: key=6;   break;
        case 0xB7: key=7;   break;
        case 0xDE: key=8;   break;
        case 0xDD: key=9;   break;
        case 0xDB: key=0x0A;   break;
        case 0xD7: key=0x0B;   break;
        case 0xEE: key=0x0C;   break;
        case 0xED: key=0x0D;   break;
        case 0xEB: key=0x0E;   break;
        case 0xE7: key=0x0F;   break;
    }
    return key;
}
        
#include <mega128a.h>
#include <delay.h>

#define Q0  PORTB.0
#define Q1  PORTB.1
#define Q2  PORTB.2
#define Q3  PORTB.3
#define Q4  PORTB.4
#define Q5  PORTB.5

unsigned char fnd[10]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x98};
int a=0,b=0,c=0,d=0,e=0,f=0,am=1,pm=0;
int s=0,m=0,h=0,x;

interrupt [EXT_INT0] void ext_int0 (void){
    while(PIND.0==0){
        delay_ms(1);
        while(PIND.0!=1){
            Q0=0,Q1=1,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[a];delay_ms(1); 
            Q0=1,Q1=0,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[b];delay_ms(1);
            Q0=1,Q1=1,Q2=0,Q3=1,Q4=1,Q5=1;PORTA=fnd[c];delay_ms(1);
            Q0=1,Q1=1,Q2=1,Q3=0,Q4=1,Q5=1;PORTA=fnd[d];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=0,Q5=1;PORTA=fnd[e];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=1,Q5=0;PORTA=fnd[f];delay_ms(1);
            if(am==1)PORTC=0x01;
            if(pm==1)PORTC=0x02;
            if(pm==2)PORTC=0x02;
            }
            s++;
            }
            }
            interrupt [EXT_INT1] void ext_int1 (void)
            {
                while(PIND.1==0){
                delay_ms(1);
                while(PIND.1!=1){
            Q0=0,Q1=1,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[a];delay_ms(1); 
            Q0=1,Q1=0,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[b];delay_ms(1);
            Q0=1,Q1=1,Q2=0,Q3=1,Q4=1,Q5=1;PORTA=fnd[c];delay_ms(1);
            Q0=1,Q1=1,Q2=1,Q3=0,Q4=1,Q5=1;PORTA=fnd[d];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=0,Q5=1;PORTA=fnd[e];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=1,Q5=0;PORTA=fnd[f];delay_ms(1);  
            if(am==1)PORTC=0x01;
            if(pm==1)PORTC=0x02;
            if(pm==2)PORTC=0x02;
            } 
            m++;
            }
            }
            interrupt [EXT_INT2] void ext_int2 (void)
            {
                while(PIND.2==0){
                delay_ms(1);
                while(PIND.2!=1){
                 Q0=0,Q1=1,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[a];delay_ms(1); 
            Q0=1,Q1=0,Q2=1,Q3=1,Q4=1,Q5=1;PORTA=fnd[b];delay_ms(1);
            Q0=1,Q1=1,Q2=0,Q3=1,Q4=1,Q5=1;PORTA=fnd[c];delay_ms(1);
            Q0=1,Q1=1,Q2=1,Q3=0,Q4=1,Q5=1;PORTA=fnd[d];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=0,Q5=1;PORTA=fnd[e];delay_ms(1); 
            Q0=1,Q1=1,Q2=1,Q3=1,Q4=1,Q5=0;PORTA=fnd[f];delay_ms(1);  
            if(am==1)PORTC=0x01;
            if(pm==1)PORTC=0x02;
            if(pm==2)PORTC=0x02;
            }
            h++;
}
}
void main(void){

    EICRA = 0x2a;
    EIMSK=0x07;
    #asm("sei");
    
    PORTB=0x00;
    DDRB=0xff;
    PORTC=0x00;
    DDRC=0xff;
    
    PORTA=0x00;
    DDRA=0xff;
    
    while(1){
        a=(h%100)/10;
        b=(h%10)/1;
        c=(m%100)/10;
        d=(m%10)/1;
        e=(s%100)/10;
        f=(s%10)/1;
        
        Q0=0,Q1=1,Q2=1,Q3=1,Q4=1,Q5=1;
        PORTA=fnd[a];
        delay_ms(1); 
        
        Q0=1,Q1=0,Q2=1,Q3=1,Q4=1,Q5=1;
        PORTA=fnd[b];
        delay_ms(1);
        
        Q0=1,Q1=1,Q2=0,Q3=1,Q4=1,Q5=1;
        PORTA=fnd[c];
        delay_ms(1);
        
        Q0=1,Q1=1,Q2=1,Q3=0,Q4=1,Q5=1;
        PORTA=fnd[d];
        delay_ms(1);
        
        Q0=1,Q1=1,Q2=1,Q3=1,Q4=0,Q5=1;
        PORTA=fnd[e];
        delay_ms(1);
        
        Q0=1,Q1=1,Q2=1,Q3=1,Q4=1,Q5=0;
        PORTA=fnd[f];
        delay_ms(1);
         if(am==1)PORTC=0x01;
         if(pm==1)PORTC=0x02;
         if(pm==2)PORTC=0x02;   
         x++;
         if(x==166)
         {
         x=1;s++;
         }
         
         if(s>59){
         m++;
         s=0;
         }
         if(m>59){
         h++;
         m=0;
         }
         if(am==1&h>=12){
            am=0;pm=1;
            h=12;
            }
         if(pm==1&h>=13){
            h=1;pm=2;
            }
            if(pm==2&h>=12){
            am=1;pm=0;
            h=0;
            }
            }
            }



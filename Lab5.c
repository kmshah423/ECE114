#include <p18f4321.h>
#include <stdio.h>
#include <math.h>
#include <usart.h>

#pragma config OSC = INTIO2
#pragma config WDT=OFF
#pragma config LVP=OFF
#pragma config BOR =OFF 

#define delay 5
#define DP PORTEbits.RE2

void wait_half_sec();
void gen_short_beep ();
void gen_long_beep ();
void do_init();

void main()
{
    PORTC = 0;
do_init();
while (1)
{
gen_short_beep();
wait_half_sec();
gen_long_beep();
}
}
void gen_short_beep (void)
{
PR2 = 0x0B7C; // values for short beep
CCPR1L = 0x3E;
CCP1CON = 0x1C;
T2CON = 0x05; // Turn T2 on here
wait_half_sec(); // Wait half-second
T2CON = 0x00; // Turn T2 off here
wait_half_sec();
}
void gen_long_beep (void)
{
PR2 = 0x0B; // values for short beep
CCPR1L = 0x0B52;
CCP1CON = 0x1C;
T2CON = 0x05; // Turn T2 on here
wait_half_sec(); // Wait half-second
T2CON = 0x00; // Turn T2 off here
wait_half_sec();
}

void do_init()
{
    TRISA = 0x00;                         //Set TRISA as output
    TRISB = 0xFF;                         //Set TRISB as input
    TRISC = 0x00;                         //Set TRISD as output
        ADCON0=0x11;
    ADCON1=0x19;
    ADCON2=0xA9;
}

void wait_half_sec()
{
    for(int I = 0; I < 9000; I++);       //I runs through loop 18000 times
}
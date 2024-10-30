#include <msp430.h>

#include "GPIO_Driver.h"

//--------------------------------------------------------------------------
int main(void)
{
WDTCTL = WDTPW | WDTHOLD;

PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                           // to activate previously configured port settings

gpioInitIn(4,BIT1); //input
gpioInitIn(2,BIT3); //input
gpioInitOut(2,BIT0); //output //2.0
gpioInitOut(6,BIT6); //output

unsigned char value = 0;
while(1){
    value = gpioInitStatus(4, BIT1);

        if(value == 0x00){
            _delay_cycles(5000);

            gpioWrite(2, BIT0, 1); }

            else
            gpioWrite(2, BIT0, 0);
        _delay_cycles(5000);

}
return 0;
}
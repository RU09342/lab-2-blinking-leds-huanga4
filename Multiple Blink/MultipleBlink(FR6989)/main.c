#include <msp430.h> 


/**
 * main.c
 * Multiple Blink
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;               // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;                         // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction
    P9OUT &= ~BIT7;                        // Clear P1.1 output latch
    P9DIR |= BIT7;                          // Set p1.1 output latch

    P1DIR &= ~BIT1;
    P1REN |= BIT1;
    P1OUT |= BIT1;

    PM5CTL0 &= ~LOCKLPM5;                   // Disable the GPIO power-on default high-impedance mode
                                            // to activate previously configured port settings

    while(1)
    {
        P1OUT ^= BIT0;                      // Toggle LED
        P9OUT ^= BIT7;                      //Toggle LED
        __delay_cycles(500000);             //Adjust speed
        P9OUT ^= BIT7;                      //Toggle one of the two LED at different rate
        __delay_cycles(500000);             //Adjust speed
    }
}

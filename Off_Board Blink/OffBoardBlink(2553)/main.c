#include <msp430.h> 


/**
 * Austin Huang
 * main.c
 * OffBoardBlink
 */
#include <msp430.h>

int main(void)
    {
  WDTCTL = WDTPW + WDTHOLD;                 // Stop Watchdog Timer


  P1DIR |= BIT0;                            // Set P1.0 to output direction
  P1DIR |= BIT6;                          // Set P1.6 to output direction


  while(1)
  {

    volatile unsigned int i;
    volatile unsigned int j;
    P1OUT ^= BIT0;                          // Toggle P1.0


    i = 10000;                              // Delay using variable
    do (i--);
    while (i != 0);
    j++;      //increment j
        if(j % 6 == 0)     //j is divisible by 6
            {
                P1OUT ^= BIT6;                      // Toggle P1.6
            }
    }
}

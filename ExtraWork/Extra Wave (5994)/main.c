//******************************************************************************
//  MSP430FR5x9x
//      Extra work
//  Description: LED1 dims as LED2 gets brighter. When button is held,
//                  the reverse happens.

//   Austin Huang

//   Built with IAR Embedded Workbench V6.30 & Code Composer Studio V6.1
//******************************************************************************
#include <msp430.h>

int main(void)
{

    WDTCTL = WDTPW+WDTHOLD;                   // Stop WDT

    // Configure GPIO
    P1OUT &= ~BIT0;      // Clear P1.0 output latch for a defined power-on state
    P1DIR |= BIT0;                          // Set P1.0 to output direction

    P4OUT &= ~BIT7;      // Clear P1.1 output latch for a defined power-on state
    P4DIR |= BIT7;                          // Set P1.1 to output direction

    P2DIR &= ~BIT1;                         // Set P2.1 to input direction
    P2REN |= BIT1;                          // Enable resistor for P2.1
    P2OUT |= BIT1;                          // Enables pull down resistor for P2.1

    while (1)
    {
         const int duty = 500;              //initialize duty
         int cnt;                          //initialize cnt

         for (cnt = 0; cnt < duty ; cnt++)   //Cnt counts until duty
         {
             int i;                           //initialize i

             for (i = 0; i < duty; i ++)
             {
                 if(!(P2IN & BIT1))    //Button held down, so new function
                 {
                     if(i < cnt)

                       {
                          P4OUT &= ~BIT7;   //P4.7 is turned off.
                          P1OUT |= BIT0;    //P1.0 is turned on.

                       }
                     else
                        {
                          P4OUT |= BIT7;    //P4.7 is turned on.
                          P1OUT &= ~BIT0;   //P1.0 turned on.

                        }

                 }
                 else                 //While button is not held down, other function occurs
                 {
                     if(i > cnt)   //P1.0 is turned on, dims over time.
                           {
                               P4OUT &= ~BIT7; //P4.7 is turned off.
                               P1OUT |= BIT0;  //P1.0 is turned on.
                           }
                     else
                           {
                               P4OUT |= BIT7;  //P4.7 is turned on.
                               P1OUT &= ~BIT0; //P1.0 is turned off.
                           }
                 }
             }
         }
   }
}

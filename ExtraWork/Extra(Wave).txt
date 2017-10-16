# Extra Work LED Wave
##Author: Austin Huang    Co op: Matt Rodriguez, Thai Nghiem
#Summary
Uses two leds. The program originally starts out at one state. LED1 gets brighter as LED2 gets dimmer. When the button is held down,
the LEDs' roles reverse. LED1 will get dimmer as LED2 becomes brighter. This simulates the effect of a PWM by using variables to model
duty cycles.
##Notes
The first thing this program does is stop the watch dog timer, this is done to ensure that the processor will not reset. This is done with the following statement:

 WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD

The pins are first initialized to determine which are inputs and outputs. 
Example:

 //Inputs:
 PXDIR &= ~BITX; //Sets this pin as an input.
    PXREN |= BITX;  //Sets this pin to use a pull up/down resistor.
    PXOUT |= BITX;  //Sets this pin to use a pull up resistor.
 //Outputs:
 PXOUT &= ~X; //Clears this pin(for safety).
    PXDIR |= BITX;  //Sets this pin as an output.


#How it works
The program is kept in an infinite loop. Duty is a constant int of 500. Cnt increments by 1 from 0 to 500. There is also int i which also
increments by 1 from 0 to 500. While i is less than the cnt, the LED will turn on. While i is greater than the cnt, the LED will turn off.
This acts as a PWM, because the frequency at which each light is on will vary depending on the value of cnt, since it is always changing.
Thus, this changing ratio causes the PWM behavior allowing for the lights to dim back and forth depending on whether or not the button is
pressed.

## How to implement the code
Use a C compiler to run the code and upload it to an MSP430. You can now see the LEDs move in a "back and forth wave" hold the button on the MSP430 to change the directing
the wave travels.
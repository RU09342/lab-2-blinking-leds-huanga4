# Multiple Blink
## @author: Austin Huang Co-op: Matthew Rodriguez, Seamus Plunkett
## Summary
This program will blink two LEDs at different rates.(One twice as fast as the other)
##Notes
This program can run on different MSP430 boards that have different pin assignments, so the specific pin numbers will be labeled as a variable "X" (i.e. PXOUT ^= BITX;)
This program begins by stopping the watch dog timer. This is done to keep the processor from resetting. Hence the following statement:

 WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD


The pins are first initialized to determine which are inputs and outputs. 
Example:
```c
 //Inputs:
 PXDIR &= ~BITX; //Sets this pin as an input.
    PXREN |= BITX;  //Sets this pin to use a pull up/down resistor.
    PXOUT |= BITX;  //Sets this pin to use a pull up resistor.
 //Outputs:
 PXOUT &= ~X; //Clears this pin(for safety).
    PXDIR |= BITX;  //Sets this pin as an output.
```

The program is run in an infinite loop using while(1). It toggles the LED between the delays which allows for different toggle rates.
Example:
```c
 while(1)         //Creates an infinite loop so the program will repeat forever.
    {
        P1OUT ^= BIT0;                      //Toggle LED1 on and off.
        P1OUT ^= BIT1;                      //Toggle LED2 on and off.
        __delay_cycles(500000);             //Adjust speed
        P1OUT ^= BIT1;                      //Toggle LED2 at a different rate
        __delay_cycles(500000);             //Adjust speed
    }
```


##Differences between boards
All the boards have different pin assignments.
##Implementation
Use a C compiler to run the code and upload it to an MSP430.(select proper board) The LEDs will begin blinking at different rates.(One twice as fast as the other)
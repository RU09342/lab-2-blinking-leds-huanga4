# Simple Blink
## @author: Austin Huang Co-op: Matthew Rodriguez, Seamus Plunkett
## Summary
The program will make an LED blink at a constant rate.(half duty cycle)
##Notes
This program can run on different MSP430 boards that have different pin assignments, so the specific pin numbers will be labeled as a variable "X" (i.e. PXOUT ^= BITX;)
This program begins by stopping the watch dog timer. This is done to keep the processor from resetting. Hence the following statement:
```c
 WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD
```

The program is run in an infinite loop using while(1).
```c
    while(1)     // Keeps the program running in a infinite loop.
    {
        P1OUT ^= BIT0;          // Toggles the LED on and off.
        __delay_cycles(100000); //Creates a delay so the LED will stay on/off for a certain amount of times.
    }
```


##Differences between boards
All the boards have different pin assignments.
##Implementation
Use a C compiler to run the code and upload it to an MSP430.(select proper board) The LED will then begin blinking.
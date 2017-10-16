# Button Blink(as Extra)
## @author Austin Huang Co-op: Matthew Rodriguez, Seamus Plunkett
## Summary 
Initially an LED is powered and turned on and blinking, when a button is pressed the LED that is being powered will turn off and a different LED with a different
color will turn on and blink. The button essentially acts as a switch.
##Notes
The extra done for this lab is also used to demonstrate the initial objective in this lab. The initial objective was to create a switch to toggle the state of an LED. This program's 
ability to switch between two LED's blinking shows the capability to easily implement the initial objective as well.
This program can run on different MSP430 boards that have different pin assignments, so the specific pin numbers will be labeled as a variable "X" (i.e. PXOUT ^= BITX;)
This program begins by stopping the watch dog timer. This is done to keep the processor from resetting. Hence the following statement:
```c
 WDTCTL = WDTPW + WDTHOLD or WDTCTL = WDTPW | WDTHOLD
```
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
##How the code works
This program uses polling to check whether or not the button has been pressed. The majority of the code is in an infinite while loop.
The loop detects a button press by using an if statement checking whether or not the button is pressed and executes the code to switch the LED.
Example:
```c while(1){

    while(lSelect == 1)//This while loop will continuously loop allowing the bottom if statement to constantly check if the button is being pressed.
    {
        P1OUT ^= BIT0;            //Toggle the LED on or off.
        __delay_cycles(500000);   //Speed of the LED blinking on and off.
        if(!(P5IN & BIT6)){    //Checks if the button has been pressed.
             lSelect = 0;   
             P1OUT &= ~BIT0;      //Turns off the LED;
            }
    }

 //The following works the same as the above code.
    while(lSelect == 0){
        P1OUT ^= BIT1;            
        __delay_cycles(100000);             
        if(!(P5IN & BIT6)){
                 lSelect = 1;
                 P1OUT &= ~BIT1;
                }
        }
    }
```

##Differences between the boards
All the boards have different pin assignments.
##Implementation
Use a C compiler to run the code and upload it to an MSP430.(select proper board) An LED will be blinking initially, press the button to switch which LED is blinking.
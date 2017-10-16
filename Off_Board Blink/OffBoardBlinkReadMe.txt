# Off Board Blink
##Author: Austin Huang  Co op: Matthew Rodriguez, Seamus Plunkett
##Summary
The CPU of the MSP430G2553 was coded to make two LEDs blink at different rates.
It can then be placed on a bread board to make the two external LEDs blink accordingly.

## Explaination
The chip from the MSP430G2553 was placed on a bread board which was powered by an arduino supplying about 3.3V.
Resistor values of 1k were placed in series with two LEDs to prevent the LED from frying.
A 10k resistor is then placed in series with VCC and the RST pin of the circuit. This prevents the chip from resetting.

##Implementing
Run code using a C compiler and upload to the G2553 chip. Place chip on a breadboard. Wire breadboard according to given schematic in repository.

#include <avr/io.h>
#include "serial.h"
#include "led.h"


void main (void) {
// D8 är kopplad til PB0, bit 0 i PORTB registret
    DDRB |= (1 << PB0); // sätter PB0 till output

    blink();
    
}

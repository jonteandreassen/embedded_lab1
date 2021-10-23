#include <avr/io.h>
#include "serial.h"
#include "led.h"


void main (void) {

/*
    D8 är kopplad til PB0, bit 0 i PORTB registret
    Sätter D8 som output genom motsvarande bit i DDRB
    Vill man ändra färg på leden så måste man ändra från PB2 i DDRB deklarationen.
    vill man byta färg ändra enligt [PB1 = BLÅ PB2 = GRÖN PB3 = RÖD]
*/

 DDRB |= (1 << PB2);
    while(1){
    PORTB |= (1 << PB2); // ORAR in en 1a på "led Biten" i PORTB registret
    _delay_ms(500); // delay 500 ms
    PORTB &= ~(1 << PB2); // Inverterar 1an på masken ovan, 1 blir 0
    _delay_ms(500); // delay 500 ms
    }
    
}

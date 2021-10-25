#include <avr/io.h>
#include <util/delay.h> 
#include "led.h"

void blink(){
/*   
    Vill man ändra färg på leden så måste man ändra från PB2 i DDRB deklarationen.
    vill man byta färg ändra enligt [PB1 = BLÅ PB2 = GRÖN PB3 = RÖD]
*/
 DDRB |= (1 << PB2);
    while(1){
    PORTB |= (1 << PB2); // ORAR in en 1a på "led Biten" i PORTB registret
    _delay_ms(500); 
    PORTB &= ~(1 << PB2); // Inverterar 1an på masken ovan, 1 blir 0
    _delay_ms(500); 
    }
}



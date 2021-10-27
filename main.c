#include <avr/io.h>
#include "serial.h"
#include "led.h"
#include <util/delay.h> 

int main (void) {
// D8 är kopplad til PB0, bit 0 i PORTB registret
    DDRB |= (1 << PB0); // sätter PB0 till output

    //blink();
    //char *test = "Jonte Andreassen\n";
    //uart_init();
    
    while(1){
        //uart_putchar('\n');   // gör ett radbryte för beroende på hastigheten i _delay_ms()
        //uart_putstr(test);    // Skriver ut test och bryter rad beroende på hastigheten i _delay_ms()
        //uart_echo();   
        _delay_ms(500);
    }
    return 0;
}

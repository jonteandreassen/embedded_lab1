#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#define FOSC 16000000 // Clock Speed
#define BAUD 38400 // Referens från uppgiften
# define ubrrn (FOSC/(16*BAUD) -1)
// KOLLA VAD _BV gör, det står för bitvise, gissar att det är ett macro för att shifta

void uart_init(void){
    UBRR0H = (ubrrn>>8);
    UBRR0L = ubrrn;
    // Enable receiver and transmitter 
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    // Set frame format: 8data, 2stop bit */
    UCSR0C = (1<<USBS0)|(0<<UCSZ00);


/* OSCARS EXEMPEL 
    UCSR0B |= _BV(TXEN0); // Sätter på transmitter
    UCSR0B |= _BV(RXEN0); // Sätter på receivern

    // 8N1 kolla kapitel 24.12.4 
    UCSR0C |=   _BV(UCSZ01); // Kolla vad dessa gör
    UCSR0C |=  ~_BV(UCSZ00); 

    UCSR0C &= ~_BV(UPM01); // UPM är för paritet
    UCSR0C &= ~_BV(UPM00);
    
    UCSR0C &= ~_BV(USBS0); // Kolla

    UBRR0H = ubrrn & 0xFF00;
    UBRR0L = ubrrn & 0x00FF;
    UBRR0 = ubrrn;
*/
}






/*
void uart_putchar(char chr){

}
void uart_putstr(const char *str){

}

char uart_getchar(void){

}

void uart_echo(void){
    
}
*/
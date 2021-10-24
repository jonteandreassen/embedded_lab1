#include <avr/io.h>
#include <util/delay.h>

#include "serial.h"
#define FOSC 16000000 // Clock Speed
#define BAUD 38400 // Referens från uppgiften

// KOLLA VAD _BV gör, det står för bitvise, gissar att det är ett macro för att shifta

void uart_init(void){
    uint16_t ubrrn = FOSC/(16*BAUD) -1;
    UBRR0H = (ubrrn>>8); // sätter UBRR0H till dem första 8 bitarna
    UBRR0L = ubrrn; // Sätter UBRR0L till dem sista 4 bitarna
    // Enable receiver and transmitter 
    UCSR0B |= (1<<RXEN0);
    UCSR0B |= (1<<TXEN0);
    // 8N1 mode: Kolla datablad 24.12.4 
    UCSR0C |=  (1<<UCSZ01); // sätter UCSR0C till 8 bitars character size
    UCSR0C | = (1<<UCSZ00); 
    // No parity 
    UCSR0C &= ~(1<<UPM01);
    UCSR0C &= ~(1<<UPM00);
    // Sätt 1 stop bit
    UCSR0c &= ~(1<<USBS0);
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
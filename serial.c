#include <avr/io.h>
#include <util/delay.h>
#include "serial.h"

#define FOSC 16000000 // Clock Speed
#define BAUD 38400 // Referens från uppgiften


void uart_init(void){
    uint16_t ubrrn = FOSC/(16*BAUD) -1;
    UBRR0H = (ubrrn>>8); // sätter UBRR0H till dem första 8 bitarna (high baud)
    UBRR0L = ubrrn; // Sätter UBRR0L till dem sista 4 bitarna (low baud)

/* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0) | (1<<TXEN0); 

/* 8N1 mode: sätter UCSZ00 & 01 till en 1a (8 bitars character size)  */
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00); 

// Sätt 1 stop bit genom att maska in en 0 i USBS0
    UCSR0C &= ~(1<<USBS0); // maskar in en 0a
/* No parity */
    UCSR0C &= ~(1<<UPM01); // maskar in en 0a 
    UCSR0C &= ~(1<<UPM00); // maskar in en 0a
}


void uart_putchar(char chr){
/* 
    Om chr == '\n' så sätt radbryte 
    UDR0 sätts till '\r'
*/
if(chr =='\n'){
    while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = '\r';
            while (!(UCSR0A & (1 << UDRE0)));
            UDR0  = '\n';
    }
    else{
        while (!(UCSR0A & (1 << UDRE0)));
        UDR0 = chr;
    }
}
// returnerar chr från buffern
char uart_getchar(void){
char chr;
    while(!(UCSR0A & (1<<RXC0)));
    chr = UDR0;
return chr;
}

void uart_putstr(const char *str){
/*
    # Loopar igenom inparamter char pekaren (arrayen)
    # Så länge inte strängen har en noll terminator skriv ut varje element i arrayen
      genom uart_putchar() och stega vidare för varje varv.
*/
int i = 0;
    while(str[i] !='\0'){
    uart_putchar(str[i]);
    i++;
    }
}

// kör funktionen putchar med getchar som inparameter för att 
// returnera samma char man skickar till serial.
void uart_echo(void){
    uart_putchar(uart_getchar());
}


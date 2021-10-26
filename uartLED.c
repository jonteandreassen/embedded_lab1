#include <avr/io.h>
#include "led.h"
#include "serial.h"
#include <string.h> // för strcmp



void uartLED(char *buffer){
    /* 
        Av någon anledning så fungerar koden enbart på detta sätt
        Har det med PWM att göra som när vi skrev arduino kod, att LOW == HIGH ??
    */
    DDRB |= (1 << PB2);
    if(strcmp(buffer, "off\r\n") == 0){
        PORTB |= (1 << PB2);    
    }
    else if(strcmp(buffer, "on\r\n") == 0){
        PORTB &= ~(1 << PB2);   
    }
    else if(strcmp(buffer, "\r\n") == 0){ }
}

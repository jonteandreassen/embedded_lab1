#include <avr/io.h>
#include "led.h"
#include "serial.h"
#include <string.h> // för strcmp



void uartLED(char *buffer){
    if(strcmp(buffer, "on\r\n") == 0){
        PORTB |= (1 << PB2);    
    }
    else if(strcmp(buffer, "off\r\n") == 0){
        PORTB &= ~(1 << PB2);   
    }
    else if(strcmp(buffer, "\r\n") == 0){ }
}

## 1.4.1 DELUPPGIFT 1: BLINKA LED
- [x] Läs databladen för tillhandahållen LED och resistorer och räkna ut en lämplig resistorstorlek
- [x] Koppla in LED och lämplig resistor till pinne 8 på Arduinons expansionsport med hjälp av
    kopplingsdäck och kablar
- [x] Använd elschemat för Arduinon för att lista ut vilken port och pinne på ATMegan detmotsvarar
- [x] Konfigurera upp pinnen som utgång
- [x] Skapa en oändlig loop i main(), och omväxlande tänd/släck LEDen med 500 ms av- respektive
    på-tid.
- [x] Städa upp din kod och skapa en git-commit med ovanstående och redogör för resistorberäkningen i
commit- meddelandet

## 1.4.2 DELUPPGIFT 2: KONFIGURERA UPP UART FÖR SÄNDNING (TX)
Samtliga nämnda funktioner deklareras i serial.h och implementeras i serial.c.
- [x] Implementera funktionen uart_init så att den konfigurerar upp USART0 för sändning (TX) enligt 8N1 i 38400 baud.
- [x] Implementera funktionen uart_putchar så att den skickar ett enskilt tecken över USART0, och lägger till tecknet ’\r’     (radretur) om tecknet vi vill skicka är ’\n’ (radbrytning).
- [x] Testa funktionen med hjälp av en serieterminal på din dator — anropa periodiskt uart_putchar från din loop i main.
- [x] Implementera funktionen uart_putstr så att den med hjälp av uart_putchar skriver ut en hel sträng på serieterminalen.
- [x] Visa att funktionen fungerar genom att anropa uart_putstr från main med ditt namn + radbrytning som argument.
- [-] Städa upp din kod och skapa en git-commit med ovanstående förändringar.

## 1.4.3 DELUPPGIFT 3: KONFIGURERA UPP UART FÖR MOTTAGNING (RX)
- [x] Ändra implementationen av uart_init så att den även medger mottagning (RX).
- [-] Implementera funktionen uart_getchar så att den tar emot ett enskilt tecken.
- [-] Visa att funktionen fungerar genom att implementera uart_echo så att den väntar på ett inkommande tecken med hjälp av uart_getchar,
   och direkt skickar tillbaka samma tecken med uart_putchar. Anropa funktionen från main.
- [-] Städa upp din kod och skapa en git-commit med ovanstående förändringar.



Embedded systems &amp; Design Jonathan Andreassen


/**
 * @file morse.c
 *
 * @brief Source code for the Morse code utilities.
 *
 * @author Justin Rowbotham
 */

#include "morse.h"
#include "led.h"

#include <ctype.h>

void morseSymbol(const char sym)
{
    switch (sym)
    {
        case 'A':
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'B':
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'C':
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'D':
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'E':
            ledOn(1);
            break;
        case 'F':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'G':
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'H':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'I':
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'J':
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case 'K':
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'L':
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'M':
            ledBlink(3,1);
            ledOn(3);
            break;
        case 'N':
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'O':
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case 'P':
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'Q':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'R':
            ledBlink(1,1);
            ledBlink(3,1);
            ledOn(1);
            break;
        case 'S':
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case 'T':
            ledOn(3);
            break;
        case 'U':
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'V':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'W':
            ledBlink(1,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case 'X':
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case 'Y':
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case 'Z':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case '0':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case '1':
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case '2':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(3);
            break;
        case '3':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(3,1);
            ledBlink(3,1);
            break;
        case '4':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(3);
            break;
        case '5':
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case '6':
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case '7':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(1,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case '8':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(1,1);
            ledOn(1);
            break;
        case '9':
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledBlink(3,1);
            ledOn(1);
        default:
            break;
    }
    ledOff(0);  // Turn LED off.
}

void morsePhrase(const char* str)
{
    while (*str) // Convey the phrase in Morse code.
    {
        if (isspace(*str)) // Handle space between words.
        {
            ledOff(7);
            do {str++;} while (isspace(*str));
        }

        morseSymbol(*str++); // Handle a symbol.
        ledOff(3);
    }
}

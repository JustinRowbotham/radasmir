/**
 * @file led.c
 *
 * @brief Source code for LED controls.
 *
 * @author Justin Rowbotham
 */

#include "led.h"

#include <avr/io.h>
#include <util/delay.h>

void ledInit(void)
{
    DDRB |= (1 << PB7); // Set PB7 as an output.
}

void ledOn(unsigned int cycles)
{
    PORTB |= (1 << PB7);    // Turn LED on.
    for (unsigned int i = 0; i < cycles; i++)
        _delay_ms(LED_UNIT_TIME);
}

void ledOff(unsigned int cycles)
{
    PORTB &= ~(1 << PB7);   // Turn LED off.
    for (unsigned int i = 0; i < cycles; i++)
        _delay_ms(LED_UNIT_TIME);
}

void ledBlink(unsigned int onCyc, unsigned int offCyc)
{
    PORTB |= (1 << PB7);    // Turn on.
    for (unsigned int i = 0; i < onCyc; i++)
        _delay_ms(LED_UNIT_TIME);
    PORTB &= ~(1 << PB7);   // Turn off.
    for (unsigned int i = 0; i < offCyc; i++)
        _delay_ms(LED_UNIT_TIME);
}

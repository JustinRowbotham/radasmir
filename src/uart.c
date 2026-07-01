/**
 * @file uart.c
 *
 * @brief Source file for UART utilities.
 *
 * @author Justin Rowbotham
 */

#include "uart.h"

#include <avr/io.h>

void uartInit(void) 
{
    UBRR0H = (UBRR_VAL >> 8); // Set BAUD high bit.
    UBRR0L = UBRR_VAL;        // Set BAUD low bit.
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Enable rcvr. and trnsmttr.
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Set 8-bit char.
}

unsigned char uartReceiveByte(void)
{
    while (!(UCSR0A & (1 << RXC0)));    // Wait until buffer fills.
    return UDR0;                        // Return byte from buffer.
}

void uartReceiveString(int size, char* str)
{
    for (int i = 0; i < size; i++) // Construct the string.
        *(str+i) = (char)uartReceiveByte();
    *(str+size) = '\0';
}

void uartSendByte(unsigned char byte)
{
    while (!(UCSR0A & (1 << UDRE0)));   // Wait until buffer empties.
    UDR0 = byte;                        // Write byte to buffer.
}

void uartSendString(const char* str)
{
    while (*str)
        uartSendByte(*str++);
}

void uartSendUInt(unsigned long value)
{
    // Base case.
    if (value == 0) {
        uartSendByte('0');
        return;
    }

    char bfr[20]; // Character buffer.
    int i = 0; // Index.
    
    // Store the digits in little-endian form
    while (value > 0)
    {
        bfr[i++] = '0' + (value % 10);
        value /= 10;
    }

    // Send the digits in big-endian form.
    for (int j = i - 1; j >= 0; j--)
    {
        uartSendByte(bfr[j]);
    }
}

/**
 * @file fun.c
 * @brief A fun program to run on the microcontroller.
 *
 * @author Justin Rowbotham
 */

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>

#define F_CPU 16000000UL // The clock rate.
#define BAUD 9600 // The baud rate.
#define UBRR_VAL (F_CPU / 16 / BAUD - 1) // The USART Baud Rate Register.

/* AVR UTILITIES */

/**
 * @brief Initializes registers for UART.
 */
void uartInit(void) 
{
    UBRR0H = (UBRR_VAL >> 8); // Set BAUD high bit.
    UBRR0L = UBRR_VAL;        // Set BAUD low bit.
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);   // Enable rcvr. and trnsmttr.
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Set 8-bit char.
}

/**
 * @brief Receives a byte over UART.
 *
 * @return A received byte.
 * @retval  byte    The byte received.
 */
char uartReceiveByte(void)
{
    while (!(UCSR0A & (1 << RXC0)));    // Wait until buffer fills.
    return UDR0;                        // Return byte from buffer.
}

/**
 * @brief Receives a string over UART.
 *
 * @param[in]   size    The string's size.
 * @param[out]  str     The string.
 */
void uartReceiveString(int size, char* str)
{
    for (int i = 0; i < size; i++) // Construct the string.
        *(str+i) = uartReceiveByte();
    *(str+size) = '\0';
}

/**
 * @brief Sends a byte over UART.
 *
 * @param[in]   byte    The byte to transmit.
 */
void uartSendByte(unsigned char byte)
{
    while (!(UCSR0A & (1 << UDRE0)));   // Wait until buffer empties.
    UDR0 = byte;                        // Write byte to buffer.
}

/**
 * @brief Sends a string over UART.
 *
 * @param[in]   str The string.
 */
void uartSendString(const char* str)
{
    while (*str)
        uartSendByte(*str++);
}

/**
 * @brief Sends an unsigned int over UART.
 *
 * @param[in]   value   The number to transmit.
 */
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

/* MATH FUNCTIONS */

/**
 * @brief The factorial function.
 *
 * @param[in]   id  The number to take the factorial of.
 * @return The factorial of the number.
 */
unsigned long factorial(int id)
{
    unsigned long result = 1; // The output.
    
    // Multiply the input by itself and decrement until it's burned.
    while (id > 1)
        result *= id--;

    return result;
}

/* MAIN LOOP */

/**
 * @brief The main function.
 *
 * @return 0 upon successful execution.
 */
int main(void)
{
    /* INITIALIZATION */
    uartInit();

    /* REPETITION */
    while (1) {
        // Welcome the user.
        uartSendString("***********************\r\n"
                       "* Welcome to RADASMIR *\r\n"
                       "***********************\r\n"
                       "What do you seek?\r\n");
        char op = uartReceiveByte();

        switch (op)
        {
            case 'a':
                uartSendString("FACTORIAL\r\nEnter your number: ");
                char num[3];
                uartReceiveString(2, num);
                int id = atoi(num);
                uartSendString("\r\nResult: ");
                uartSendUInt(factorial(id));
                break;
            default:
                uartSendString("Invalid action...\r\n");
        }

        uartSendString("\r\n\r\n");
    }

    return 0;
}

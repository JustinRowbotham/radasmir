/**
 * @file fun.c
 * @brief A fun program to run on the microcontroller.
 *
 * @author Justin Rowbotham
 */

#include <avr/io.h>

#define F_CPU 16000000UL // The clock rate.
#define BAUD 9600 // The baud rate.
#define UBRR_VAL (F_CPU / 16 / BAUD - 1) // The USART Baud Rate Register.

/* AVR UTILITIES */

/**
 * @brief Initializes registers for UART.
 */
void uartInit(void) 
{
    UBRR0H = (UBRR_VAL >> 8);
    UBRR0L = UBRR_VAL;
    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

/**
 * @brief Sends a byte over UART.
 *
 * @param[in]   byte    The byte to transmit.
 */
void uartSendByte(unsigned char byte)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = byte;
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

    char buf[20]; // Character buffer.
    int i = 0; // Index.
    
    // Store the digits in little-endian form
    while (value > 0)
    {
        buf[i++] = '0' + (value % 10);
        value /= 10;
    }

    // Send the digits in big-endian form.
    for (int j = i - 1; j >= 0; j--)
    {
        uartSendByte(buf[j]);
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
    uartInit();

    // Run the factorial program.
    unsigned long result = factorial(10);

    // Transmit the result over UART0.
    uartSendString("Result: ");
    uartSendUInt(result);
    uartSendString("\r\n");

    while (1) {}
}

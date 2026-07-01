/**
 * @file uart.h
 *
 * @brief Interface for UART functionalities. Allows communication
 *        between the microcontroller and a terminal.
 *
 * @author Justin Rowbotham
 */

#ifndef UART_H
#define UART_H

#define F_CPU 16000000UL // The clock rate.
#define BAUD 9600 // The baud rate.
#define UBRR_VAL (F_CPU / 16 / BAUD - 1) // The USART Baud Rate Register.

/**
 * @brief Initializes registers for UART.
 */
void uartInit(void);

/**
 * @brief Receives a byte over UART.
 *
 * @return A received byte.
 * @retval  byte    The byte received.
 */
unsigned char uartReceiveByte(void);

/**
 * @brief Receives a string over UART.
 *
 * @param[in]   size    The string's size.
 * @param[out]  str     The string.
 */
void uartReceiveString(int size, char* str);

/**
 * @brief Sends a byte over UART.
 *
 * @param[in]   byte    The byte to transmit.
 */
void uartSendByte(unsigned char byte);

/**
 * @brief Sends a string over UART.
 *
 * @param[in]   str The string.
 */
void uartSendString(const char* str);

/**
 * @brief Sends an unsigned int over UART.
 *
 * @param[in]   value   The number to transmit.
 */
void uartSendUInt(unsigned long value);

#endif /* UART_H */

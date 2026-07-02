/**
 * @file fun.c
 * @brief A fun program to run on the microcontroller.
 *
 * @author Justin Rowbotham
 */

#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "led.h"
#include "math.h"
#include "morse.h"

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
    ledInit();

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
            case 't':
                uartSendString("Testing 1 second light on, 2 second off, "
                        "1 on...");
                ledBlink(5,10);
                ledOn(5);
                ledOff(0);
                break;
            case '!':
                uartSendString("FACTORIAL\r\nEnter your number: ");
                char num[3];
                uartReceiveString(2, num);
                int id = atoi(num);
                uartSendString("\r\nResult: ");
                uartSendUInt(factorial(id));
                break;
            case '.':
                uartSendString("MORSE\r\nEnter your phrase: ");
                char str[21];
                uartReceiveString(20, str);
                uartSendString("\r\nWatch the LED for your message!");
                morsePhrase(str);
                break;
            default:
                uartSendString("Invalid action...\r\n");
        }

        uartSendString("\r\n\r\n");
    }

    return 0;
}

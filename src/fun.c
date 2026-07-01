/**
 * @file fun.c
 * @brief A fun program to run on the microcontroller.
 *
 * @author Justin Rowbotham
 */

#include <stdio.h>
#include <stdlib.h>

#include "uart.h"
#include "math.h"

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

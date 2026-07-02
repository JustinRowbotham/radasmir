/**
 * @file led.h
 *
 * @brief Interface for controlling the onboard LED.
 *
 * @author Justin Rowbotham
 */

#ifndef LED_H
#define LED_H

#define LED_UNIT_TIME 200 // The unit time for LED cycles.

/**
 * @brief Initializes the LED for control over Port B, pin 7 (PB7).
 */
void ledInit(void);

/**
 * @brief Turns on the LED and waits for some period.
 *
 * @param[in]   cycles  Number of LED cycles to wait.
 */
void ledOn(unsigned int cycles);

/**
 * @brief Turns off the LED and waits for some period.
 *
 * @param[in]   cycles  Number of LED cycles to wait.
 */
void ledOff(unsigned int cycles);

/**
 * @brief Turns the LED on and off again.
 *
 * @param[in]   onCyc   The on LED cycles.
 * @param[in]   offCyc  The off LED cycles.
 */
void ledBlink(unsigned int onCyc, unsigned int offCyc);

#endif /* LED_H */

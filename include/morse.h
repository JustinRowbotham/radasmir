/**
 * @file morse.h
 *
 * @brief Interface for communicating in Morse code via the onboard LED.
 *
 * @author Justin Rowbotham
 */

#ifndef MORSE_H
#define MORSE_H

/**
 * @brief Communicates a symbol in Morse code via the LED.
 *
 * @param[in]   sym The symbol.
 */
void morseSymbol(const char sym);

/**
 * @brief Communicates a word in Morse code via the LED.
 *
 * @param[in]   str The word.
 */
void morsePhrase(const char* str);

#endif /* MORSE_H */

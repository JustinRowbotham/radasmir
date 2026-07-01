/**
 * @file math.c
 *
 * @brief Source code for math utilities.
 *
 * @author Justin Rowbotham
 */

unsigned long factorial(int id)
{
    unsigned long result = 1; // The output.
    
    // Multiply the input by itself and decrement until it's burned.
    while (id > 1)
        result *= id--;

    return result;
}

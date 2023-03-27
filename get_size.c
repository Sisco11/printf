// This code defines the function get_size which is used to extract the size modifier from a
// format string in order to determine the appropriate data type for the corresponding argument.
// The function takes a formatted string and the current position as input,
// and returns the size of the modifier found. The size can be either S_LONG, S_SHORT, or 0 if no size modifier is present.
#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
    int curr_i = *i + 1;
    int size = 0;

    if (format[curr_i] == 'l')
        size = S_LONG;
    else if (format[curr_i] == 'h')
        size = S_SHORT;

    if (size == 0)
        *i = curr_i - 1;
    else
        *i = curr_i;

    return (size);
}
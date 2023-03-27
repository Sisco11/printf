// This code defines the function get_width which takes a formatted string format,
// a pointer i and a variable arguments list list.The function calculates and returns the width of the field to be printed.
// The width can be explicitly specified in the format string,
// or passed as an argument using the *character.If no width is specified, the function returns 0.
#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
    int curr_i;
    int width = 0;

    for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            width *= 10;
            width += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (width);
}
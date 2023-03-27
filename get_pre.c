// The code defines the function get_precision which calculates the precision for printing according to the format string.
//  If the format specifies a precision, the function parses it and returns the value.
//  If the precision is not specified, the function returns -1.
//  The precision can be either a number or an asterisk indicating that the value should be obtained from the variadic argument list.
#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
    int curr_i = *i + 1;
    int precision = -1;

    if (format[curr_i] != '.')
        return (precision);

    precision = 0;

    for (curr_i += 1; format[curr_i] != '\0'; curr_i++)
    {
        if (is_digit(format[curr_i]))
        {
            precision *= 10;
            precision += format[curr_i] - '0';
        }
        else if (format[curr_i] == '*')
        {
            curr_i++;
            precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *i = curr_i - 1;

    return (precision);
}
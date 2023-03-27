/*To go into the test folder after compilation*/
#include "main.h"

int print_string(char *string)
{

    int count = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {

        count += _putchar(string[i]);
    }

    return (count);
}
#include "main.h"

/**
 * new_get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @new_i: List of arguments to be printed.
 *
 * Return: Size.
 */
int new_get_size(const char *format, int *new_i)
{
    int new_curr_i = *new_i + 1;
    int new_size = 0;

    if (format[new_curr_i] == 'l')
        new_size = S_LONG;
    else if (format[new_curr_i] == 'h')
        new_size = S_SHORT;

    if (new_size == 0)
        *new_i = new_curr_i - 1;
    else
        *new_i = new_curr_i;

    return new_size;
}

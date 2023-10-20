#include "main.h"

/**
 * new_get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @new_i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Width.
 */
int new_get_width(const char *format, int *new_i, va_list list)
{
    int new_curr_i;
    int new_width = 0;

    for (new_curr_i = *new_i + 1; format[new_curr_i] != '\0'; new_curr_i++)
    {
        if (new_is_digit(format[new_curr_i]))
        {
            new_width *= 10;
            new_width += format[new_curr_i] - '0';
        }
        else if (format[new_curr_i] == '*')
        {
            new_curr_i++;
            new_width = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *new_i = new_curr_i - 1;

    return new_width;
}

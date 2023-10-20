#include "main.h"

/**
 * new_get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @new_i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: Precision.
 */
int new_get_precision(const char *format, int *new_i, va_list list)
{
    int new_curr_i = *new_i + 1;
    int new_precision = -1;

    if (format[new_curr_i] != '.')
        return new_precision;

    new_precision = 0;

    for (new_curr_i += 1; format[new_curr_i] != '\0'; new_curr_i++)
    {
        if (new_is_digit(format[new_curr_i]))
        {
            new_precision *= 10;
            new_precision += format[new_curr_i] - '0';
        }
        else if (format[new_curr_i] == '*')
        {
            new_curr_i++;
            new_precision = va_arg(list, int);
            break;
        }
        else
            break;
    }

    *new_i = new_curr_i - 1;

    return new_precision;
}

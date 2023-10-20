#include "main.h"

/**
 * new_get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @new_i: take a parameter.
 * Return: Flags:
 */
int new_get_flags(const char *format, int *new_i)
{
    /* - + 0 # ' ' */
    /* 1 2 4 8  16 */
    int j, curr_i;
    int new_flags = 0;
    const char new_FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
    const int new_FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

    for (curr_i = *new_i + 1; format[curr_i] != '\0'; curr_i++)
    {
        for (j = 0; new_FLAGS_CH[j] != '\0'; j++)
            if (format[curr_i] == new_FLAGS_CH[j])
            {
                new_flags |= new_FLAGS_ARR[j];
                break;
            }

        if (new_FLAGS_CH[j] == 0)
            break;
    }

    *new_i = curr_i - 1;

    return new_flags;
}

#include "main.h"

/**
 * new_is_printable - Evaluates if a char is printable
 * @new_c: Char to be evaluated.
 *
 * Return: 1 if new_c is printable, 0 otherwise
 */
int new_is_printable(char new_c)
{
    if (new_c >= 32 && new_c < 127)
        return (1);

    return (0);
}

/**
 * new_append_hexa_code - Append ASCII in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @new_i: Index at which to start appending.
 * @new_ascii_code: ASCII code.
 * Return: Always 3
 */
int new_append_hexa_code(char new_ascii_code, char buffer[], int new_i)
{
    char map_to[] = "0123456789ABCDEF";
    /* The hexa format code is always 2 digits long */
    if (new_ascii_code < 0)
        new_ascii_code *= -1;

    buffer[new_i++] = '\\';
    buffer[new_i++] = 'x';

    buffer[new_i++] = map_to[new_ascii_code / 16];
    buffer[new_i] = map_to[new_ascii_code % 16];

    return (3);
}

/**
 * new_is_digit - Verifies if a char is a digit
 * @new_c: Char to be evaluated
 *
 * Return: 1 if new_c is a digit, 0 otherwise
 */
int new_is_digit(char new_c)
{
    if (new_c >= '0' && new_c <= '9')
        return (1);

    return (0);
}

/**
 * new_convert_size_number - Casts a number to the specified size
 * @new_num: Number to be casted.
 * @new_size: Number indicating the type to be casted.
 *
 * Return: Casted value of new_num
 */
long int new_convert_size_number(long int new_num, int new_size)
{
    if (new_size == S_LONG)
        return (new_num);
    else if (new_size == S_SHORT)
        return ((short)new_num);

    return ((int)new_num);
}

/**
 * new_convert_size_unsgnd - Casts a number to the specified size
 * @new_num: Number to be casted
 * @new_size: Number indicating the type to be casted
 *
 * Return: Casted value of new_num
 */
long int new_convert_size_unsgnd(unsigned long int new_num, int new_size)
{
    if (new_size == S_LONG)
        return (new_num);
    else if (new_size == S_SHORT)
        return ((unsigned short)new_num);

    return ((unsigned int)new_num);
}

#include "main.h"
/**
 * new_handle_print - Prints an argument based on its type
 * @new_fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @new_ind: Ind.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags
 * @new_width: Get width.
 * @new_precision: Precision specification
 * @new_size: Size specifier
 * Return: 1 or 2;
 */
int new_handle_print(const char *new_fmt, int *new_ind, va_list list, char buffer[],
    int flags, int new_width, int new_precision, int new_size)
{
    int i, unknow_len = 0, printed_chars = -1;
    fmt_t new_fmt_types[] = {
        {'c', new_print_char}, {'s', new_print_string}, {'%', new_print_percent},
        {'i', new_print_int}, {'d', new_print_int}, {'b', new_print_binary},
        {'u', new_print_unsigned}, {'o', new_print_octal}, {'x', new_print_hexadecimal},
        {'X', new_print_hexa_upper}, {'p', new_print_pointer}, {'S', new_print_non_printable},
        {'r', new_print_reverse}, {'R', new_print_rot13string}, {'\0', NULL}
    };
    for (i = 0; new_fmt_types[i].fmt != '\0'; i++)
        if (new_fmt[*new_ind] == new_fmt_types[i].fmt)
            return (new_fmt_types[i].fn(list, buffer, flags, new_width, new_precision, new_size));

    if (new_fmt_types[i].fmt == '\0')
    {
        if (new_fmt[*new_ind] == '\0')
            return (-1);
        unknow_len += write(1, "%%", 1);
        if (new_fmt[*new_ind - 1] == ' ')
            unknow_len += write(1, " ", 1);
        else if (new_width)
        {
            --(*new_ind);
            while (new_fmt[*new_ind] != ' ' && new_fmt[*new_ind] != '%')
                --(*new_ind);
            if (new_fmt[*new_ind] == ' ')
                --(*new_ind);
            return (1);
        }
        unknow_len += write(1, &new_fmt[*new_ind], 1);
        return (unknow_len);
    }
    return (printed_chars);
}

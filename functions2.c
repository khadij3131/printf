#include "main.h"

void print_buffer(char buffer[], int *new_buff_ind);

/****************** PRINT POINTER ******************/

int new_print_pointer(va_list new_types, char buffer[],
    int new_flags, int new_width, int new_precision, int new_size)
{
    char new_extra_c = 0, new_padd = ' ';
    int new_ind = BUFF_SIZE - 2, new_length = 2, new_padd_start = 1; /* length=2, for '0x' */
    unsigned long new_num_addrs;
    char new_map_to[] = "0123456789abcdef";
    void *new_addrs = va_arg(new_types, void *);

    UNUSED(new_width);
    UNUSED(new_size);

    if (new_addrs == NULL)
        return write(1, "(nil)", 5);

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(new_precision);

    new_num_addrs = (unsigned long)new_addrs;

    while (new_num_addrs > 0)
    {
        buffer[new_ind--] = new_map_to[new_num_addrs % 16];
        new_num_addrs /= 16;
        new_length++;
    }

    if ((new_flags & F_ZERO) && !(new_flags & F_MINUS))
        new_padd = '0';
    if (new_flags & F_PLUS)
        new_extra_c = '+', new_length++;
    else if (new_flags & F_SPACE)
        new_extra_c = ' ', new_length++;

    new_ind++;

    return new_write_pointer(buffer, new_ind, new_length,
        new_width, new_flags, new_padd, new_extra_c, new_padd_start);
}

/************************* PRINT NON PRINTABLE **************************/

int new_print_non_printable(va_list new_types, char buffer[],
    int new_flags, int new_width, int new_precision, int new_size)
{
    int new_i = 0, new_offset = 0;
    char *new_str = va_arg(new_types, char *);

    UNUSED(new_flags);
    UNUSED(new_width);
    UNUSED(new_precision);
    UNUSED(new_size);

    if (new_str == NULL)
        return write(1, "(null)", 6);

    while (new_str[new_i] != '\0')
    {
        if (new_is_printable(new_str[new_i]))
            buffer[new_i + new_offset] = new_str[new_i];
        else
            new_offset += new_append_hexa_code(new_str[new_i], buffer, new_i + new_offset);

        new_i++;
    }

    buffer[new_i + new_offset] = '\0';

    return write(1, buffer, new_i + new_offset);
}

/************************* PRINT REVERSE **************************/

int new_print_reverse(va_list new_types, char buffer[],
    int new_flags, int new_width, int new_precision, int new_size)
{
    char *new_str;
    int new_i, new_count = 0;

    UNUSED(buffer);
    UNUSED(new_flags);
    UNUSED(new_width);
    UNUSED(new_size);

    new_str = va_arg(new_types, char *);

    if (new_str == NULL)
    {
        UNUSED(new_precision);

        new_str = ")Null(";
    }
    for (new_i = 0; new_str[new_i]; new_i++)
        ;

    for (new_i = new_i - 1; new_i >= 0; new_i--)
    {
        char new_z = new_str[new_i];

        write(1, &new_z, 1);
        new_count++;
    }
    return new_count;
}

/************************* PRINT A STRING IN ROT13 **************************/

int new_print_rot13string(va_list new_types, char buffer[],
    int new_flags, int new_width, int new_precision, int new_size)
{
    char new_x;
    char *new_str;
    unsigned int new_i, new_j;
    int new_count = 0;
    char new_in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char new_out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    new_str = va_arg(new_types, char *);
    UNUSED(buffer);
    UNUSED(new_flags);
    UNUSED(new_width);
    UNUSED(new_precision);
    UNUSED(new_size);

    if (new_str == NULL)
        new_str = "(AHYY)";
    for (new_i = 0; new_str[new_i]; new_i++)
    {
        for (new_j = 0; new_in[new_j]; new_j++)
        {
            if (new_in[new_j] == new_str[new_i])
            {
                new_x = new_out[new_j];
                write(1, &new_x, 1);
                new_count++;
                break;
            }
        }
        if (!new_in[new_j])
        {
            new_x = new_str[new_i];
            write(1, &new_x, 1);
            new_count++;
        }
    }
    return new_count;
}

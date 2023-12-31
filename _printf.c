#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
<<<<<<< HEAD
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = new_get_flags(format, &i);
			width = new_get_width(format, &i, list);
			precision = new_get_precision(format, &i, list);
			size = new_get_size(format, &i);
			++i;
			printed = handle_new_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
=======
void print_buffer(char buffer[], int *new_buff_ind);
>>>>>>> f2be051e6ec7ba37855720473e7ebac1e7253bd0

int new_printf(const char *new_format, ...)
{
    int new_i, new_printed = 0, new_printed_chars = 0;
    int new_flags, new_width, new_precision, new_size, new_buff_ind = 0;
    va_list new_list;
    char new_buffer[BUFF_SIZE];

    if (new_format == NULL)
        return (-1);

    va_start(new_list, new_format);

    for (new_i = 0; new_format && new_format[new_i] != '\0'; new_i++)
    {
        if (new_format[new_i] != '%')
        {
            new_buffer[new_buff_ind++] = new_format[new_i];
            if (new_buff_ind == BUFF_SIZE)
                print_buffer(new_buffer, &new_buff_ind);
            new_printed_chars++;
        }
        else
        {
            print_buffer(new_buffer, &new_buff_ind);
            new_flags = get_flags(new_format, &new_i);
            new_width = get_width(new_format, &new_i, new_list);
            new_precision = get_precision(new_format, &new_i, new_list);
            new_size = get_size(new_format, &new_i);
            ++new_i;
            new_printed = handle_print(new_format, &new_i, new_list, new_buffer,
                new_flags, new_width, new_precision, new_size);
            if (new_printed == -1)
                return (-1);
            new_printed_chars += new_printed;
        }
    }

    print_buffer(new_buffer, &new_buff_ind);

    va_end(new_list);

    return (new_printed_chars);
}

void print_buffer(char new_buffer[], int *new_buff_ind)
{
    if (*new_buff_ind > 0)
        write(1, &new_buffer[0], *new_buff_ind);

    *new_buff_ind = 0;
}

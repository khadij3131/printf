#include "main.h"

void print_buffer(char buffer[], int *new_buff_ind);

/************************* PRINT CHAR *************************/

int new_print_char(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	char new_c = va_arg(new_types, int);

	return (new_handle_write_char(new_c, buffer, new_flags, new_width, new_precision, new_size));
}

/************************* PRINT A STRING *************************/

int new_print_string(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	int new_length = 0, new_i;
	char *new_str = va_arg(new_types, char *);

	UNUSED(buffer);
	UNUSED(new_flags);
	UNUSED(new_width);
	UNUSED(new_precision);
	UNUSED(new_size);

	if (new_str == NULL)
	{
		new_str = "(null)";
		if (new_precision >= 6)
			new_str = "      ";
	}

	while (new_str[new_length] != '\0')
		new_length++;

	if (new_precision >= 0 && new_precision < new_length)
		new_length = new_precision;

	if (new_width > new_length)
	{
		if (new_flags & F_MINUS)
		{
			write(1, &new_str[0], new_length);
			for (new_i = new_width - new_length; new_i > 0; new_i--)
				write(1, " ", 1);
			return (new_width);
		}
		else
		{
			for (new_i = new_width - new_length; new_i > 0; new_i--)
				write(1, " ", 1);
			write(1, &new_str[0], new_length);
			return (new_width);
		}
	}

	return (write(1, new_str, new_length));
}

/************************* PRINT PERCENT SIGN *************************/

int new_print_percent(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	UNUSED(new_types);
	UNUSED(buffer);
	UNUSED(new_flags);
	UNUSED(new_width);
	UNUSED(new_precision);
	UNUSED(new_size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/

int new_print_int(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	int new_i = BUFF_SIZE - 2;
	int new_is_negative = 0;
	long int new_n = va_arg(new_types, long int);
	unsigned long int new_num;

	new_n = new_convert_size_number(new_n, new_size);

	if (new_n == 0)
		buffer[new_i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	new_num = (unsigned long int)new_n;

	if (new_n < 0)
	{
		new_num = (unsigned long int)((-1) * new_n);
		new_is_negative = 1;
	}

	while (new_num > 0)
	{
		buffer[new_i--] = (new_num % 10) + '0';
		new_num /= 10;
	}

	new_i++;

	return (new_write_number(new_is_negative, new_i, buffer, new_flags, new_width, new_precision, new_size));
}

/************************* PRINT BINARY *************************/

int new_print_binary(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	unsigned int new_n, new_m, new_i, new_sum;
	unsigned int new_a[32];
	int new_count;

	UNUSED(buffer);
	UNUSED(new_flags);
	UNUSED(new_width);
	UNUSED(new_precision);
	UNUSED(new_size);

	new_n = va_arg(new_types, unsigned int);
	new_m = 2147483648; /* (2 ^ 31) */
	new_a[0] = new_n / new_m;
	for (new_i = 1; new_i < 32; new_i++)
	{
		new_m /= 2;
		new_a[new_i] = (new_n / new_m) % 2;
	}
	for (new_i = 0, new_sum = 0, new_count = 0; new_i < 32; new_i++)
	{
		new_sum += new_a[new_i];
		if (new_sum || new_i == 31)
		{
			char new_z = '0' + new_a[new_i];

			write(1, &new_z, 1);
			new_count++;
		}
	}
	return (new_count);
}

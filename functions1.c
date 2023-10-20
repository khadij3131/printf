#include "main.h"

void print_buffer(char buffer[], int *new_buff_ind);

/************************* PRINT UNSIGNED NUMBER *************************/

int new_print_unsigned(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	int new_i = BUFF_SIZE - 2;
	unsigned long int new_num = va_arg(new_types, unsigned long int);

	new_num = new_convert_size_unsgnd(new_num, new_size);

	if (new_num == 0)
		buffer[new_i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (new_num > 0)
	{
		buffer[new_i--] = (new_num % 10) + '0';
		new_num /= 10;
	}

	new_i++;

	return (new_write_unsgnd(0, new_i, buffer, new_flags, new_width, new_precision, new_size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/

int new_print_octal(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{

	int new_i = BUFF_SIZE - 2;
	unsigned long int new_num = va_arg(new_types, unsigned long int);
	unsigned long int new_init_num = new_num;

	UNUSED(new_width);

	new_num = new_convert_size_unsgnd(new_num, new_size);

	if (new_num == 0)
		buffer[new_i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (new_num > 0)
	{
		buffer[new_i--] = (new_num % 8) + '0';
		new_num /= 8;
	}

	if (new_flags & F_HASH && new_init_num != 0)
		buffer[new_i--] = '0';

	new_i++;

	return (new_write_unsgnd(0, new_i, buffer, new_flags, new_width, new_precision, new_size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

int new_print_hexadecimal(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	return (new_print_hexa(new_types, "0123456789abcdef", buffer,
		new_flags, 'x', new_width, new_precision, new_size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

int new_print_hexa_upper(va_list new_types, char buffer[],
	int new_flags, int new_width, int new_precision, int new_size)
{
	return (new_print_hexa(new_types, "0123456789ABCDEF", buffer,
		new_flags, 'X', new_width, new_precision, new_size));
}

/************** PRINT HEXX NUM IN LOWER OR UPPER **************/

int new_print_hexa(va_list new_types, char map_to[], char buffer[],
	int new_flags, char flag_ch, int new_width, int new_precision, int new_size)
{
	int new_i = BUFF_SIZE - 2;
	unsigned long int new_num = va_arg(new_types, unsigned long int);
	unsigned long int new_init_num = new_num;

	UNUSED(new_width);

	new_num = new_convert_size_unsgnd(new_num, new_size);

	if (new_num == 0)
		buffer[new_i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (new_num > 0)
	{
		buffer[new_i--] = map_to[new_num % 16];
		new_num /= 16;
	}

	if (new_flags & F_HASH && new_init_num != 0)
	{
		buffer[new_i--] = flag_ch;
		buffer[new_i--] = '0';
	}

	new_i++;

	return (new_write_unsgnd(0, new_i, buffer, new_flags, new_width, new_precision, new_size));
}

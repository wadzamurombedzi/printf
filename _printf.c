#include "main.h"

void print_buffer(char buffer[], int *buff _ind);

/**
 * _printf - Printf function
 * @format: format
 * Return: Printed chars
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff _ind = 0;
	va_list list;
	char buffer[BUFF _SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff _ind++] = format[i];
			if (buff _ind == BUFF _SIZE)
				print_buffer(buffer, &buff _ind);
			/* write(1, &format[i], 1;*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff _ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff _ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff _ind: Index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff _ind)
{
	if (*buff _ind > ))
		write(1, &buffer[0], *buff _ind);

	*buff _ind = 0;
}

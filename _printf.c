#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Prints a formatted string to stdout
 * @format: A string containing zero or more format specifiers
 * @...: Zero or more additional arguments to be printed
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
				count += print_char(args);
			else if (format[i + 1] == 's')
				count += print_string(args);
			else if (format[i + 1] == '%')
				count += write(1, "%", 1);
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
				count += print_integer(args);
			i += 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);

	return (count);
}


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - emulates original printf
 * @format: list of arguments
 *
 * Return: 0 for SUCCESS
 */
int _printf(const char *format, ...)
{
	int size = 0, count = 0, n, i;
	char *s, c, v, u[12];
	va_list call;

	va_start(call, format);

	while (format && format[count])
	{
		if (format[count] == '%')
		{
			count++;
			switch (format[count])
			{
				case 's':
					s = va_arg(call, char*);
					_string(s);
					break;
				case 'c':
					v = va_arg(call, int);
					_char(v);
					break;
				case '%':
					v = va_arg(call, int);
					_char('%');
					break;
				case 'd':
				case 'i':
				{
					n = va_arg(call, int);
					i = 0;
					do
					{
						u[i++] = (n % 10) + '0';
					}
					while ((n /= 10) > 0);
					while (--i >= 0)
						size += write(1, &u[i], 1);
				}
					break;
					default:
						break;
			}
		}
		else
		{
			c = format[count];
			write(STDOUT_FILENO, &c, 1);
			size++;
		}
		count++;
	}
	va_end(call);
	return (size);
}

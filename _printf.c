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
	int size = 0, count = 0/*, n, i*/;
	char *s, c, v/*, u[12]*/;
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
					while (*s)
					{
						write(STDOUT_FILENO, s, 1);
						s++;
						size++;
					}
					break;
				case 'c':
					v = va_arg(call, int);
					write(STDOUT_FILENO, &v, 1);
					size++;
					break;
				case '%':
					v = va_arg(call, int);
					write(STDOUT_FILENO, "%", 1);
					size++;
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
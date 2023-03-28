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
	int size = 0, count = 0, n, num, i = 0, j = 0;
	char *s, c, v, *x, u[11];
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
				case 'i':
					n = va_arg(call, int);
					x = malloc(11 * sizeof(char));
					if (!x)
					return (-1);
					while (n != 0)
					{
						num = n % 10;
						u[i++] = num + '0';
						n /= 10;
					}
					u[i++] = '\0';
					while (i >= 0)
					{
						x[j++] = u[i--];
					}
					_string(x);
					free(x);
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

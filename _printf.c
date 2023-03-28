#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...)
{
<<<<<<< HEAD
	va_list args;
	va_start(args, format);
	int count = 0;
=======
	int size = 0, count = 0/*, n, i*/;
	char *s, c, v/*, u[12]*/;
	va_list call;
>>>>>>> 8bad50ec434f891097ae5571b3f86ca079048622

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
<<<<<<< HEAD
				char *s = va_arg(args, char*);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
=======
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
>>>>>>> 8bad50ec434f891097ae5571b3f86ca079048622
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
<<<<<<< HEAD

	va_end(args);
	return (count);
}
=======
	va_end(call);
	return (size);
}	
>>>>>>> 8bad50ec434f891097ae5571b3f86ca079048622

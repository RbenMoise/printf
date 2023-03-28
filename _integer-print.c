#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_integer - Prints an integer to stdout
 * @arg: A va_list containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(va_list arg)
{
	int num = va_arg(arg, int);
	unsigned int absolute = num < 0 ? -num : num;
	char buffer[12];
	char *pos = buffer + sizeof(buffer) - 1;
	unsigned int digit;

	*pos = '\0';
	do {
		digit = absolute % 10;
		*(--pos) = digit + '0';
		absolute /= 10;
	} while (absolute != 0);
	if (num < 0)
		*(--pos) = '-';

	return (write(1, pos, strlen(pos)));
}

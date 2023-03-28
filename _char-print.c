#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a character to stdout
 * @arg: A va_list containing the character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	return (write(1, &c, 1));
}

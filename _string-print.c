#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * print_string - Prints a string to stdout
 * @arg: A va_list containing the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";;

	return (write(1, str, strlen(str)));
}

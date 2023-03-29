#include <string.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * print_binary - Prints an unsigned integer in binary format to stdout
 * @arg: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
/**
 * print_binary - Prints an unsigned integer in binary format to stdout
 * @arg: A va_list containing the unsigned integer to be printed
 *
 * Return: The number of characters printed
 */
int print_binary(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	char buffer[33];
	char *pos = buffer + sizeof(buffer) - 1;
	unsigned int mask = 1;

	*pos = '\0';
	do {
		*(--pos) = (num & mask) ? '1' : '0';
		mask <<= 1;
	} while (mask != 0);

	while (*pos == '0' && *(pos + 1) != '\0')
		pos++;

	return (write(1, pos, strlen(pos)));
}

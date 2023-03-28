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
int _char(char v)
{
	int size = 0;
	write(STDOUT_FILENO, &v, 1);
	size++;
	return (size);
}

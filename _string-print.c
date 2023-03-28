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
int _string(char *s)
{
	int size = 0;	
	while (*s)
	{
	write(STDOUT_FILENO, s, 1);
	s++;
	size++;
	}
	return (size);
}

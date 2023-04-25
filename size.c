#include "main.h"
/**
 * getsize - Calculates the size to cast the argument
 * @format: Formatted string to print the arguments
 * @i: List of arguments to be printed.
 * Return: size
 */
int getsize(const char *format, int *i)
{
	int k = *i + 1;
	int size = 0;

	if (format[k] == 'l')
		size = SLONG;
	else if (format[k] == 'h')
		size = SSHORT;

	if (size == 0)
		*i = k - 1;
	else
		*i = k;

	return (size);
}

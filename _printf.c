#include "main.h"
#include <stdarg.h>

void printbuffer(char buffer[], int *buffind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printedchars = 0;
	int flag, width, precision, size, buffind = 0;
	va_list list;
	char buffer[BUFSIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffind++] = format[i];
			if (buffind == BUFSIZE)
				printbuffer(buffer, &buffind);
			printedchars++;
		}
		else
		{
			printbuffer(buffer, &buffind);
			flag = getflag(format, &i);
			width = getwidth(format, &i, list);
			precision = getprecision(format, &i, list);
			size = getsize(format, &i);
			++i;
			printed = print(format, &i, list, buffer,
				flag, width, precision, size);
			if (printed == -1)
				return (-1);
			printedchars += printed;
		}
	}

	printbuffer(buffer, &buffind);

	va_end(list);

	return (printedchars);
}

/**
 * printbuffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buffind: Index at which to add next char, represents the length.
 */
void printbuffer(char buffer[], int *buffind)
{
	if (*buffind > 0)
		write(1, &buffer[0], *buffind);

	*buffind = 0;
}

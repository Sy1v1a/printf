#include "main.h"
/**
 * getwidth - Calculates the width for printing
 * @format: Formatted string to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 * Return: width
 */
int getwidth(const char *format, int *i, va_list list)
{
	int k;
	int width = 0;

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		if (isdigit(format[k]))
		{
			width *= 10;
			width += format[k] - '0';
		}
		else if (format[k] == '*')
		{
			k++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = k - 1;

	return (width);
}

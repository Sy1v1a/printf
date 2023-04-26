#include "main.h"
/**
 * print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: 1 or 2
 */
int print(const char *fmt, int *ind, va_list list, char buffer[],
	int flag, int width, int precision, int size)
{
	int i, unknowlen = 0, printedchars = -1;
	fmtt fmttypes[] = {
		{'c', printchars}, {'s', printstring}, {'%', printpercent},
		{'i', printint}, {'d', printint}, {'b', printbinary},
		{'u', printunsigned}, {'o', printoctal}, {'x', printhexadecimal},
		{'X', printhexaupper}, {'p', printpointer}, {'S', printnonprintable},
		{'r', printreverse}, {'R', printrot13string}, {'\0', NULL}
	};
	for (i = 0; fmttypes[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmttypes[i].fmt)
			return (fmttypes[i].fn(list, buffer, flag, width, precision, size));

	if (fmttypes[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknowlen += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknowlen += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknowlen += write(1, &fmt[*ind], 1);
		return (unknowlen);
	}
	return (printedchars);
}

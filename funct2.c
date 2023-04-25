#include "main.h"
/**
 * printpointer - print the value of a variable
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char to be printed
 */
int printpointer(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	char extrac = 0, pat = ' ';
	int ind = BUFSIZE - 2, length = 2, patstart = 1; /* length=2, for '0x' */
	unsigned long numaddrs;
	char mapto[] = "0123456789abcdef";
	void *addrs = va_arg(type, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFSIZE - 1] = '\0';
	UNUSED(precision);

	numaddrs = (unsigned long)addrs;

	while (numaddrs > 0)
	{
		buffer[ind--] = mapto[numaddrs % 16];
		numaddrs /= 16;
		length++;
	}

	if ((flag & T_ZERO) && !(flag & T_MINUS))
		pat = '0';
	if (flag & T_PLUS)
		extrac = '+', length++;
	else if (flag & T_SPACE)
		extrac = ' ', length++;

	ind++;

	return (writepointer(buffer, ind, length,
		width, flag, pat, extrac, patstart));
}

/**
 * printnonprintable - print ascii code in hexadecimal
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char to be printed
 */
int printnonprintable(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (isprintable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += appendhexacode(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * printreverse - print reverse string
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char to be printed
 */
int printreverse(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(type, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}

/**
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char to be printed
 */
int printrot13string(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	char r;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(type, char *);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				r = out[j];
				write(1, &r, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			r = str[i];
			write(1, &r, 1);
			count++;
		}
	}
	return (count);
}

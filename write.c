#include "main.h"
/**
 * writechar - Prints a string
 * @c: char types.
 * @buffer: Buffer array
 * @flag:  Calculates active flags.
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int writchar(char c, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = 0;
	char pat = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flag & T_ZERO)
		pat = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFSIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFSIZE - i - 2] = pat;

		if (flag & T_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFSIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFSIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/**
 * writenumber - Prints a string
 * @isnegative: Lista of arguments
 * @ind: char types.
 * @buffer: Buffer array
 * @flag:  Calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int writenumber(int isnegative, int ind, char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFSIZE - ind - 1;
	char pat = ' ', extrach = 0;

	UNUSED(size);

	if ((flag & T_ZERO) && !(flag & T_MINUS))
		pat = '0';
	if (isnegative)
		extrach = '-';
	else if (flag & T_PLUS)
		extrach = '+';
	else if (flag & T_SPACE)
		extrach = ' ';

	return (writenum(ind, buffer, flag, width, precision,
		length, pat, extrach));
}

/**
 * writenum - Write a number using a bufffer
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flag: Flags
 * @width: width
 * @precision: Precision specifier
 * @length: Number length
 * @pat: Pading char
 * @extrac: Extra char
 * Return: Number of printed chars.
 */
int writenum(int ind, char buffer[],
	int flag, int width, int precision,
	int length, char pat, char extrac)
{
	int i, patstart = 1;

	if (precision == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (precision == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pat = ' '; 
	if (precision > 0 && precision < length)
		pat = ' ';
	while (precision > length)
		buffer[--ind] = '0', length++;
	if (extrac != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pat;
		buffer[i] = '\0';
		if (flag & T_MINUS && pat == ' ')
		{
			if (extrac)
				buffer[--ind] = extrac;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & T_MINUS) && pat == ' ')
		{
			if (extrac)
				buffer[--ind] = extrac;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flag & T_MINUS) && pat == '0')
		{
			if (extrac)
				buffer[--patstart] = extrac;
			return (write(1, &buffer[patstart], i - patstart) +
				write(1, &buffer[ind], length - (1 - patstart)));
		}
	}
	if (extrac)
		buffer[--ind] = extrac;
	return (write(1, &buffer[ind], length));
}

/**
 * writeunsgnd - Writes an unsigned number
 * @isnegative: Number indicating if the num is negative
 * @ind: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flags specifiers
 * @width: Width specifier
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of written chars.
 */
int writeunsgnd(int isnegative, int ind,
	char buffer[],
	int flag, int width, int precision, int size)
{
	int length = BUFSIZE - ind - 1, i = 0;
	char pat = ' ';

	UNUSED(isnegative);
	UNUSED(size);

	if (precision == 0 && ind == BUFSIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		pat = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flag & T_ZERO) && !(flag & T_MINUS))
		pat = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = pat;

		buffer[i] = '\0';

		if (flag & T_MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * writepointer - Write a memory address
 * @buffer: Arrays of chars
 * @ind: Index at which the number starts in the buffer
 * @length: Length of number
 * @width: Width specifier
 * @flag: Flags specifier
 * @pat: Char representing the padding
 * @extrac: Char representing extra char
 * @patstart: Index at which padding should start
 * Return: Number of written chars.
 */
int writepointer(char buffer[], int ind, int length,
	int width, int flag, char pat, char extrac, int patstart)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = pat;
		buffer[i] = '\0';
		if (flag & T_MINUS && pat == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extrac)
				buffer[--ind] = extrac;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & T_MINUS) && pat == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (extrac)
				buffer[--ind] = extrac;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flag & T_MINUS) && pat == '0')
		{
			if (extrac)
				buffer[--patstart] = extrac;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[patstart], i - patstart) +
				write(1, &buffer[ind], length - (1 - patstart) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (extrac)
		buffer[--ind] = extrac;
	return (write(1, &buffer[ind], BUFSIZE - ind - 1));
}

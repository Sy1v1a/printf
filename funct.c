#include "main.h"
/**
 * printchar - prints char
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char printed 
 */
int printchar(va_list type, char buffer[], int flag, int width, int precision, int size)
{
	char c = va_arg(type, int);
	return (writechar(c, buffer, flag, width, precision, size));
}

/**
 * printstring
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char printed
 */
int printstring(va_list types, char buffer[], int flag, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(type, char*);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flag & T_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * printpercent - prints a percent sign
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char printed
 */
int printpercentt(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(type);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * printint - prints int
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags  * @width: width
 * @precision: precisision spec 
 * @size: size specifier
 * return; number of char printed
 */
int printint(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	int isnegative = 0;
	long int n = va_arg(type, long int);
	unsigned long int num;

	n = convertsizenumber(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		isnegative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writenumber(isnegative, i, buffer, flag, width, precision, size));
}

/**
 * printbinary - prints unsigned number
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: numbers of char printed
 */
int printbinary(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	unsigned int b, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	b = va_arg(type, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = b / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (b / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

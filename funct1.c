#include "main.h"
/**
 * printunsigned - prints an unsigned number
  * @type: list of argument
  * @buffer: buffer array
  * @flag: calculate flags
  * @width: width
  * @precision: precisision spec
  * @size: size specifier
  * return: number of char printed
  */
int printunsigned(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeunsgnd(0, i, buffer, flag, width, precision, size));
}

/**
 * printoctal - prints unsigned number in octal
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: number of char printed
 */
int printoctal(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{

	int i = BUFSIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & T_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (writeunsgnd(0, i, buffer, flag, width, precision, size));
}

/**
 * printhexadecimal - prints an unsigned number in hexadecimal
 * @type: list of argument
 * @buffer: buffer array
 * @flag: calculate flags
 * @width: width
 * @precision: precisision spec
 * @size: size specifier
 * return: nuber of char printed
 */
int printhexadecimal(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	return (printhexa(type, "0123456789abcdef", buffer,
		flag, 'x', width, precision, size));
}

/**
 * printhexaupper - Prints an unsigned number in upper hexadecimal
 * @type: List of argument
 * @buffer: Buffer array
 * @flag:  Calculate flags
 * @width: width
 * @precision: Precision spec
 * @size: Size specifier
 * Return: Number of chars printed
 */
int printhexaupper(va_list type, char buffer[],
	int flag, int width, int precision, int size)
{
	return (printhexa(type, "0123456789ABCDEF", buffer,
		flag, 'X', width, precision, size));
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
int printhexa(va_list type, char mapto[], char buffer[],
	int flag, char flagch, int width, int precision, int size)
{
	int i = BUFSIZE - 2;
	unsigned long int num = va_arg(type, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convertsizeunsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFSIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = mapto[num % 16];
		num /= 16;
	}

	if (flag & T_HASH && init_num != 0)
	{
		buffer[i--] = flagch;
		buffer[i--] = '0';
	}

	i++;

	return (writeunsgnd(0, i, buffer, flag, width, precision, size));
}

#include "main.h"
/**
 * isprintable - Evaluates if a char is printable
 * @c: Char to be evaluated.
 * Return: 1 if c is printable, 0 otherwise
 */
int isprintable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * appendhexacode - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @asciicode: ASSCI CODE.
 * Return: Always 3
 */
int appendhexacode(char asciicode, char buffer[], int i)
{
	char mapto[] = "0123456789ABCDEF";
	if (asciicode < 0)
		asciicode *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = mapto[asciicode / 16];
	buffer[i] = mapto[asciicode % 16];

	return (3);
}

/**
 * isdigit - Verify if a char is a digit
 * @c: Char to be evaluated
 * Return: 1 if c is a digit, 0 otherwise
 */
int isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convertsizenumber - Casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 * Return: Casted value of num
 */
long int convertsizenumber(long int num, int size)
{
	if (size == SLONG)
		return (num);
	else if (size == SSHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convertsizeunsgnd - Cast a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 * Return: Casted value of num
 */
long int convertsizeunsgnd(unsigned long int num, int size)
{
	if (size == SLONG)
		return (num);
	else if (size == SSHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

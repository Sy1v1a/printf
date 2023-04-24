#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - A function that produces output according to a format.
 * @format: A Character string
 * Return: The number of characters printed;
 */
int _printf(const char *format, ...)
{
	char *str;
	int num = 0;
	va_list print;

	va_start(print, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			_putchar(*format);
			num += 1;
			continue;
		}
		switch (*++format)
		{
			case 'c':
				_putchar(va_arg(print, int));
				num += 1;
				break;
			case 's':
				str = va_arg(print, char *);
				while (*str)
					_putchar(*str++);
					num += 1;
				break;
			default:
				_putchar('%');
				_putchar(*format);
				num += 2;
				break;
		}
	}
	return (num);
}

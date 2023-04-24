#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - A function that produces output according to a format.
 * @format: A Character string
 * Return: 0;
 */
int _printf(const char *format, ...)
{
	char *str;
	va_list print;

	va_start(print, format);
	for (; *format; ++format)
	{
		if (*format != '%')
		{
			_putchar(*format);
			continue;
		}

		switch (*++format)
		{
			case 'c':
				_putchar(va_arg(print, int));
				break;
			case 's':
				str = va_arg(print, char *);
				while (*str)
					_putchar(*++str);
				break;
			default:
				_putchar('%');
				_putchar(*format);
				break;
		}
	}
	return (0);
}

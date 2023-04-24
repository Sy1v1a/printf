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
	int num = 0;
	va_list print;

	va_start(print, format);
	for (; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			_putchar(*format);
			num++;
			continue;
		}
		switch (*++format)
		{
			case 'c':
				_putchar(va_arg(print, int));
				num++;
				break;
			case 's':
				str = va_arg(print, char *);
				while (*str)
					_putchar(*str++);
					num++;
				break;
			default:
				_putchar('%');
				_putchar(*format);
				num++;
				break;
		}
	}
	return (num);
}

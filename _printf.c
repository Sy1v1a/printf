#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
 * _printf - produces output according to a format
 * @format: a character string
 * return: the number of character printed excluding NULL
 */
int _printf(const char *format, ...)
{
int i = 0;
va_list print;
va_start(print, format);

while (format[i])
{
if (format[i] == '%')
{
	i++;
switch (format[i])
{
case 'c':
{
int r = va_arg(print, int);
printf("%c", r);
break;
}
case 'd':
{
int r = va_arg(print, int);
printf("%d", r);
break;
}
case 'i':
{
int r = va_arg(print, int);
printf("%d", r);
break;
}
case 's':
{
char *r = va_arg(print, char*);
printf("%s", r);
break;
}
case '%':
putchar('%');
break;

default:
putchar(format[i]);
break;
}
}
else
{
putchar(format[i]);
}
i++;
}
va_end(print);
return 0;
}

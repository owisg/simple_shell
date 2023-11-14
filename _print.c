#include "shell.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * _print - custom printf function
 * @format: format string
 * Return: the number of characters printed
 */
int _print(const char *format, ...)
{
int i = 0, count = 0;
va_list args;
char *str;
va_start(args, format);
while (format[i])
{
if (format[i] != '%')
{
_putchar(format[i]);
count++;
}
else if (format[i + 1])
{
i++;
switch (format[i])
{
case 'c':
count++;
_putchar(va_arg(args, int));
break;
case 's':
str = va_arg(args, char *);
if (str == NULL)
str = "(null)";
while (*str)
count++;
_putchar(*str);
str++;
break;
default:
count++;
_putchar('%');
_putchar(format[i]);
break;
}
}
i++;
}
va_end(args);
return (count);
}

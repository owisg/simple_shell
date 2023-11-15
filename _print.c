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
char *str;
int i = 0, count = 0;
va_list args;
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
if (format[i] == 'c')
{
count++;
_putchar(va_arg(args, int));
}
else if (format[i] == 's')
{
str = va_arg(args, char *);
while (*str)
{
count++;
_putchar(*str);
str++;
}
}
else
{
count++;
_putchar('%');
_putchar(format[i]);
}
}
i++;
}
va_end(args);
return (count);
}

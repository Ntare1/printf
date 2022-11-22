#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _printf - prints the arguments
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int size = 0, y;
	int (*x)(va_list);
	va_list args;

	va_start(args, format);
	y = 0;
	if (format[0] == '%' && format[1] == '\0')
		return (-1);
	while (format != NULL && format[y] != '\0')
	{
		if (format[y] == '%')
		{
			if (format[y + 1] == '%')
			{
				size += _putchar(format[y]);
				y++;
			}
			else
			{
				x = get_ch(format[y + 1]);
				if (x)
					size += x(args);
				else
					size = _putchar(format[y]) + _putchar(format[y + 1]);
				y += 2;
			}
		}
		size += _putchar(format[y]);
		y++;
		}
	_putchar('\n');
	va_end(args);
	return (size);
}


#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * get_ch - finds the formats
 * @z: formats
 * Return: 0
 */
int (*get_ch(char z))(va_list args)
{
	int y = 0;
	spec arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{NULL, NULL}
	};
	while (arr[y].valid)
	{
		if (z == arr[y].valid[0])
			return (arr[y].f);
		y++;
	}
	return (0);
}

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


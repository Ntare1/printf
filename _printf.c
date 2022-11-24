#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>

/**
 * get_ch - finds the formats
 * @format: formats
 * Return: 0
 */
int (*get_ch(const char *format))(va_list)
{
	unsigned int y = 0;
	spec arr[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percentage}
	};
	while (arr[y].sc[0])
	{
		if (arr[y].sc[0] == (*format))
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
	va_list args;
	int (*x)(va_list);
	unsigned int y = 0, size = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[y])
	{
		while (format[y] != '%' && format[y])
		{
			_putchar(format[y]);
			size++;
			y++;
		}
		if (format[y] == '\0')
			return (y);
		f = get_ch(&format[y + 1]);
		if (f != NULL)
		{
			y += f(args);
			y += 2;
			continue;
		}
		if (!format[y + 1])
			return (-1);
		_putchar(format[y]);
		size++;
		if (format[y + 1] == '%')
			y += 2;
		else
			y++;
	}
	va_end(args);
	return (size);
}


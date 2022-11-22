#include "main.h"
/**
 * _printf - returns number of  characters printed
 * @char: input sentence
 * @format: character string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int size;
	va_list argptr;

	if (format == NULL)
	return (-1);

	size = _strlen(format);
	if (size < 0)
		return (0);

	va_start(argptr, format);
	size = handler(argptr, format);

	_putchar(-1);
	va_end(argptr);
	return (size);
}

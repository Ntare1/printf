#include "main.h"
/**
 * handler - format controller
 * @str: string format
 * @list: List of arguments
 *
 * Return: Total size of arguments with the total size of the base string
 */
int handler(const char *str, va_list list)
{
	int size, a, auxiliary;

	size  = 0;
	for (a = 0; str[a] != 0; i++)
	{
		if (str[a] == '%')
		{
			auxiliary = percent_handler(str, list, &a);
			if (auxiliary == -1)
				return (-1);

			size += auxiliary;
			continue;
		}

		_putchar(str[a]);
		size = size + 1;
	}

	return (size);
}

/**
 * percent_handler - Controller for percent format
 * @str: string format
 * @list: list of arguments
 * @i: iterator
 *
 * Return: size of the numbers of the elemetns printed
 */

int percent_handler(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char},
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer},
		{'r', print_rev_string}, {'R', print_rot}
	};

	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);

	if (str[*i] == '%')
	{
		_putchar ('%');
		return (1);
	}

	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}

	}
	_putchar('%'), _putchar(str[*i]);

	return (2);
}


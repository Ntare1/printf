#include "main.h"

/**
 * get_ch - finds the format
 * @format: format
 * Return: 0
 */
int (*get_ch(const char *format))(va_list)
{
	int y = 0;
	spec arr[] = {
		{"c", print_c},
		{"s", print_s},
		{"%", print_percent},
		{NULL, NULL}
	}
	while (arr[y].sc[0])
	{
		if (arr[y].sc[0] == (*format))
			return (arr[y].f);
		y++;
	}
	return (NULL);
}

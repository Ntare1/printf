#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_string- prints strings
 * @s: string
 * Return: 1
 */
int print_string(va_list s)
{
	char *string;
	int  y = 0;

	string = va_arg(s, char *);
	if (string == NULL)
		string = "(null)";
	while (string[y])
	{
		_putchar(string[y]);
		y++;
	}
	return (y);
}

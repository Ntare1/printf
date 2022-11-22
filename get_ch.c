#include "main.h"

/**
 * get_ch - finds the specifiers
 * @z: input
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

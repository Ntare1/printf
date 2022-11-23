#include "main.h"
/**
 * _putchar - write te character to the stdout
 * @c: The character to display
 * Return: 1 on success
 * On error, -1 is returned, errno set properly
 */
int _putchar(char c)
{
	return (buffer(c));
}

/**
 * buffer - save the character in the buffer
 * @c: input character
 *
 * Return: 1 on success
 */
int buffer(char c)
{
	static char bufferring[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write(1, bufferring, i);
	}
	if (c != -1)
		bufferring[i++] = c;

	return (1);

}

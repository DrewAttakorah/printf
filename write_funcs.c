#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * if there is an error, -1 is returned, and errno is set.
 * Description: ...
 * drew_attakorah
 */
int _putchar(char c)
{
	static char buff[1024];
	static int i;

	if (c == -1 || i >= 1024)
	{
		write(1, &buff, i);
		i = 0;
	}
	if (c != -1)
	{
		buff[i] = c;
		i++;
	}
	return (1);
}

/**
 * _puts - prints a string to stdout
 * @str: pointer to the string to print
 * Return: ...
 * drew_attakorah
 */
int _puts(char *str)
{
	register int i;

	i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - This function is to print the formatted
 * string to the standard
 * @format: format string containing the characters and the specifiers
 * Description: this function will call the get_print() function that will
 * determine which printing function to call depending
 * on the conversion specifiers contained into a format
 * Return: length of the formatted output string
 */

int _printf(const char *format, ...)
{
	/** Declaring or initializing variables */
	int (*myp_func)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	/** Declare integer my_count */
	register int my_count = 0;

	/** The va_start macro is called to initialize arguments */
	/* with the variable arguments passed to the function */
	va_start(arguments, format);

	/** The function checks for invalid format strings */
	/* and returns -1 if any are found */

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	/** The function iterates through the format string */
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{

				my_count +=_putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			myp_func = get_print(*p);
			my_count += (myp_func)
				? myp_func(arguments, &flags)
				: _printf("%%%c", *p);
		} else

			my_count += _putchar(*p);
	}

	/** The function cleans up the va_list and */
	/* returns the total number of characters printed */
	_putchar(-1);
	va_end(arguments);
	return (my_count);
}

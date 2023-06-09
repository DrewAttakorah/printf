#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - outputs depending on a format
 * @format: format string contains the characters and the specifiers
 * Description: the function will call the get_print() function that will
 * specify which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: length of formatted output string
 * drew_attakorah
 */

int _printf(const char *format, ...)
{
	/** Initializing variables */
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list arguments;
	flags_t flags = {0, 0, 0};

	register int count = 0;

	/** Begins variable argument list */
	va_start(arguments, format);
	/** Check for edge cases */
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	/** Loop through each character in the format string */
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				/** If next character is % output % */
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			pfunc = get_print(*p);
			count += (pfunc)
				? pfunc(arguments, &flags)
				: _printf("%%%c", *p);
		} else
			/** If character is != & output as it is */
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);
}

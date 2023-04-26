#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Description: this function will call the _print() function that will
* determine which printing function to call depending on the conversion
* specifiers contained into format
* Return: length of the formatted output string
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c;
	va_start(args, format);
	while ((c = *format++))
	{
		if (c == '%')
		{
			c = *format++;
			switch (c)
			{
				case 'c':
					{
						char ch = (char)va_arg(args, int);
						_putchar(ch);
						count++;
						break;
					}
				case 's':
					{
						  const char *str = va_arg(args, const char *);
						  while (*str)
						  {
							  _putchar(*str++);
							  count++;
						  }
						  break;
					}
				case '%':
					{
						_putchar('%');
						count++;
						break;
					}
				default:
					_putchar('%');
					_putchar(c);
					count += 2;
					break;
			}
		}
		else
		{
			_putchar(c);
			count++;
		}
	}
	va_end(args);
	return count;
}

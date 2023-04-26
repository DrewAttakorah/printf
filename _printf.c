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
    int count = 0;
    va_list args;
    va_start(args, format);

    for (const char *ptr = format; *ptr != '\0'; ptr++)
    {
        if (*ptr == '%')
	{
            ptr++;
            switch (*ptr)
	    {
                case 'c': {
                    char c = (char) va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    const char *str = va_arg(args, const char*);
                    for (; *str != '\0'; str++) 
		    {
                        putchar(*str);
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    break;
            }
        } else {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);
    return count;
}

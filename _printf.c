#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Outputs a formatted string.
 * @format: Character string to print - may contain directives.
 *
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	int a, display = 0, display_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list args;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	int display_chars = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];
	va_list args;
	va_start(args, format);

	int a = 0;
	while (format[a] != '\0') {
            if (format[a] != '%') {
                buffer[buff_ind++] = format[a];
                if (buff_ind == BUFF_SIZE) {
                        print_buffer(buffer, &buff_ind);
                }
                display_chars++;
                }
                else {
                        print_buffer(buffer, &buff_ind);
                a++;
                int flags = g_flags(format, &a);
                int width = get_width(format, &a, args);
                int precision = _precision(format, &a, args);
                int size = _size(format, &a);
                int display = handle_print(format, &a, args, buffer, flags, width, precision, size);
                if (display == -1) {
                        return -1;
                }
                display_chars += display;
                }
                a++;
                }
                print_buffer(buffer, &buff_ind);
                va_end(args);
                return display_chars;
}

/**
 * print_buffer - display the values of the buffer if it exist.
 * @buff_ind: Index at which to add next char, represents the length.
 * @buffer: A pointer to a character array
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}

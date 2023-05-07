#include "main.h"

/**
 * print_int - prints an integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags which determines
 * when a flag is passed to _printf
 * Return: number of char printed
 * drew_attakorah
 */
int print_int(va_list l, flags_t *f)
{
	int n = va_arg(l, int);
	int result = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		result += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		result += _putchar('+');
	if (n <= 0)
		result++;
	print_number(n);
	return (result);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags which determines
 * when a flag is passed to _printf
 * Return: number of char printed
 * drew_attakorah
 */
int print_unsigned(va_list l, flags_t *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - this is a helper function which loops through
 * an integer and prints all digits
 * @n: integer to be printed
 * drew_attakorah
 */
void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n;
	}
	else
		n1 = n;

	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 * for _printf
 * @i: integer to eval
 * Return: number of digits
 * drew_attakorah
 */
int count_digit(int i)
{
	unsigned int d = 0;
	unsigned int u;

	if (i < 0)
		u = i * -1;
	else
		u = i;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}

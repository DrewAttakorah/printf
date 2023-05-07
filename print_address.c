#include "main.h"

/**
 * print_address - prints address of input in a hexadecimal format
 * @l: va_list arguments from _printf
 * @f: pointer to the struct flags which determines
 * when a flag is passed to the _printf
 * Return: number of char printed
 * drew-attakorah
 */

int print_address(va_list l, flags_t *f)
{
	char *str;
	unsigned long int p = va_arg(l, unsigned long int);

	register int count = 0;

	/** prevents an unused parameter warning */
	(void)f;

	if (!p)
		/** prints nil for NULL pointer */
		return (_puts("(nil)"));
	/** convert pointer to hexadecimal string */
	str = convert(p, 16, 1);
	/** prints the leading '0x' */
	count += _puts("0x");
	/** prints the hexadecimal string */
	count += _puts(str);
	return (count);
}

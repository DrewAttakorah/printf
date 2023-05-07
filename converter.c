#include "main.h"

/**
 * convert - converts number and base into string
 * @num: input a number
 * @base: input a base
 * @lowercase: flag if hexadecimal values need to be lowercase
 * Return: result string
 * drew-attakorah
 */

char *convert(unsigned long int num, int base, int lowercase)
{
	/** Static variables for base xters and results in string buffer */
	static char *rep;
	static char buff[50];
	char *ptr;

	/** Set hexadecimal xters depending on lowercase flag */
	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';
	/** does the conversion */
	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}

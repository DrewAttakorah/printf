#include "main.h"

/**
 * convert - converts number and base into string
 * @numb: inputs number
 * @base: inputs base
 * @lowercase: flag if hexadecimal values need to be lowercases
 * Return: the result string
 */

char *convert(unsigned long int numb, int base, int lowercase)
{
	/** A static variables for base chtrs and resulting string buffer */
	static char *reps;
	static char buff[50];
	char *ptrs;

	/** This set hexadecimal characters based on lowercase flag */
	reps = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptrs = &buff[49];
	*ptrs = '\0';
	/** This perform the conversion */
	do {
		*--ptrs = reps[num % base];
		numb /= base;
	} while (numb != 0);

	return (ptrs);
}

#include "main.h"

/**
 * get_flag - turns on flags if _printf finds
 * a flag modifier in format string
 * @s: character which holds the flag specifier
 * @f: pointer to struct flags in which we on turn flags
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int get_flag(char s, flags_t *f)
{
	int i = 0;

	/** using switch case to check which flag is specified */
	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}

	/** this will code returns 1 if a flag is turned on, else 0 */
	return (i);
}

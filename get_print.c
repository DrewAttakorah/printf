#include "main.h"

/**
 * get_print - will select the appropriate printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function will loop through the structs array
 * funct_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */

int (*get_print(char s))(va_list, flags_t *)
{
	/** struct array that maps specifiers to function */
	phandler funct_arr[] = {
		{'i', print_int},
		{'s', print_string},
		{'c', print_char},
		{'d', print_int},
		{'u', print_unsigned},
		{'x', print_hex},
		{'X', print_hex_big},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', print_rev},
		{'S', print_bigS},
		{'p', print_address},
		{'%', print_percent}
		};

	int flags = 14;

	register int i;

	/** While loop through the array to find a match and return appro funct. */
	i = 0;
    while (i < flags) {
        if (func_arr[i].c == s) {
            return (func_arr[i].f);
        }
        i++;
    }
    return (NULL);
}

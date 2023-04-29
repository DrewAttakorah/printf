#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: a flag for the '+' character in c
 * @space: a flag for the ' ' character in c
 * @hash: a flag for the '#' character in c
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: a format specifier
 * @f: a pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/* This is print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* This is print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* This is converter */
char *convert(unsigned long int num, int base, int lowercase);

/* This is _printf function */
int _printf(const char *format, ...);

/* This is get_print */
int (*get_print(char s))(va_list, flags_t *);

/* This is get_flag */
int get_flag(char s, flags_t *f);

/* This is print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* This write_funcs writes functions */
int _putchar(char c);
int _puts(char *str);

/* This is print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* This is print_address */
int print_address(va_list l, flags_t *f);

/* This is print_percent */
int print_percent(va_list l, flags_t *f);

#endif

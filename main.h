#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_percentage(void);
int (*get_ch(const char *format))(va_list);
int _putchar(char c);
#endif /* MAIN.H */

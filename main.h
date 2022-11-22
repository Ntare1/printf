#ifndef MAIN_H
#define MAIN_H

/*libraries*/
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* functions to utilise */
int _strlen(const char *);
int print(char *);
char itoa(long int, int);

/*handler*/
int handler(const char *, va_list);
int percent_handler(const char *, va_list, int *);

/*putchar.c*/
int _putchar(char);
int buffer(char);
/*printf.c */
int _printf(const char *format, ...);

#endif

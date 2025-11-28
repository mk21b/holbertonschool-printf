#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_string(char *str);
int print_integer(int n);
int print_unsigned(unsigned int n);

#endif /* MAIN_H */
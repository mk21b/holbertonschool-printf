#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes a character to stdout
 * @c: character to print
 * Return: 1 on success
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _print_string - prints a string to stdout
 * @s: string to print
 * Return: number of characters printed
 */
int _print_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s++);
		count++;
	}

	return (count);
}

/**
 * _print_int - prints an integer using recursion
 * @n: integer to print
 * Return: number of characters printed
 */
int _print_int(int n)
{
	unsigned int num;
	int count = 0;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += _print_int(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * _printf - formatted output to stdout
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				break;
			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _print_string(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += _print_int(va_arg(args, int));
					break;
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
			i++;
		}
		else
		{
			count += _putchar(format[i]);
			i++;
		}
	}

	va_end(args);

	return (count);
}


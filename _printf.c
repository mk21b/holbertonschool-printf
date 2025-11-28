#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. On error, -1 is returned, and errno is set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_string - prints a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str != '\0')
	{
		_putchar(*str);
		count++;
		str++;
	}

	return (count);
}

/**
 * _print_unsigned_helper - helper to print unsigned int recursively
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
static int _print_unsigned_helper(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += _print_unsigned_helper(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_integer - prints an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	count += _print_unsigned_helper(num);

	return (count);
}

/**
 * print_unsigned - prints an unsigned integer to stdout
 * @n: The unsigned integer to print
 *
 * Return: The number of characters printed
 */
int print_unsigned(unsigned int n)
{
	return (_print_unsigned_helper(n));
}

/**
 * _printf - produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (count);
			}

			switch (format[i])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += print_integer(va_arg(args, int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(format[i]);
					break;
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(args);

	return (count);
}

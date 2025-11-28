#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1. On error, -1 is returned.
 */
static int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_char - prints a character
 * @c: The character to print
 *
 * Return: 1
 */
static int print_char(char c)
{
	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
static int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		count += _putchar(*str);
		str++;
	}

	return (count);
}

/**
 * print_integer - prints an integer
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
static int print_integer(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += _putchar('-');
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
		count += print_integer(num / 10);

	count += _putchar((num % 10) + '0');

	return (count);
}

/**
 * _printf - produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(ap);
				return (count);
			}

			if (format[i] == 'c')
				count += print_char(va_arg(ap, int));
			else if (format[i] == 's')
				count += print_string(va_arg(ap, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_integer(va_arg(ap, int));
			else if (format[i] == '%')
				count += _putchar('%');
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
		{
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(ap);

	return (count);
}

#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i++;

            /* Case: string ends right after %  → error */
            if (format[i] == '\0')
            {
                va_end(args);
                return (-1);
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
                    /* Holberton requirement: print % + invalid specifier */
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

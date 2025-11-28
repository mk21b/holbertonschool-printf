#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * is_digit - checks if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}